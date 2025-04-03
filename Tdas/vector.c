#include "vector.h"

typedef struct _vector{
    
    t_elem_vector* a; //array de T_Elem
    int size; //tam actual
    int maxsize; //tam maximo
}vector;


vector* vector_init(int max)
{
    vector* v = (vector*)malloc(sizeof(vector));
    v->a=(t_elem_vector*)malloc(max*sizeof(t_elem_vector));
    v->size=0;
    v->maxsize=max;
    return v;
}


void vector_free(vector* v)
{
    free(v->a);
    free(v);
}

int vector_size(vector*v)
{
    if (v==NULL) return -1;

    return v->size;
}

int vector_max_size(vector*v)
{
    if (v==NULL) return -1;

    return v->maxsize;
}

int vector_isfull(vector* v)
{
    if (v==NULL) return -1;

    if(v->size==v->maxsize)
    {
        return 1;
    }
    return 0;
}

int vector_isempty(vector* v)
{
    if (v==NULL) return -1;

    if(v->size==0)
    {
        return 1;
    }
    return 0;
}


t_elem_vector vector_get(vector* v, int index)
{
    
//    if(v==NULL)return -1;
//    if(index >= v->maxsize)return -2;
//    if(index<0)return -3;
    return v->a[index];
}

void vector_set(vector* v, int index, t_elem_vector value) 
{
 //   if(v==NULL)return -1;
 //   if(index >= v->maxsize)return -2;
 //   if(index<0)return -3;

    v->a[index]=value;

//    return 0;

}

void vector_add(vector* v, t_elem_vector value)
{
    if(v==NULL)return ;

    if(!vector_isfull(v))
    {
        v->a[v->size] = (t_elem_vector)value;
        v->size++;
    }else{
        v->a = (t_elem_vector*)realloc(v->a,  sizeof(v->a) + (v->maxsize + 1) * sizeof(t_elem_vector));
        v->maxsize = v->maxsize + 1;
        v->a[v->size] = (t_elem_vector)value;
        v->size = v->size + 1;
    }



}

void vector_resize(vector** v)
{
    if(*v==NULL) return;

    //int i=vector_size(*v);

    if(vector_isfull(*v))
    {
        vector* temp = (vector*) realloc(*v, sizeof(vector) + ((*v)->maxsize + 1) * sizeof(int));
        *v=temp;
        (*v)->maxsize=(*v)->maxsize+1;
    

    }
}

void vector_remove(vector*v, int index)
{
    if(v==NULL)return ;

    for(int i = index; i < v->size - 1; i++)
    {
        v->a[i] = v->a[i + 1];
    }

    v->size--;
    
}
/*
int vector_insert(vector* v, T_Elem value, int index)
{
    if(v==NULL)return -1;
    int dim=vector_size(v);
    if(vector_isfull(v))
    {
        vector_resize(&v);
        for(int j=dim; j>index; j--)
        {
         v->a[j]=v->a[j-1];
        }
    }else{
        for(int i = dim; i>index; i--)
        {
            v->a[i]=v->a[i-1];
        }
        vector_set(v,index,value);
    }



    return 1;

}

int vector_value_pos(vector* v, int index)
{
    if(v==NULL) return -1;
    int i=0;
    vector* aux=v;
    int flag=0;

    while(i!=v->size && flag==0)
    {
        if(aux->a[i]!=v->a[index])
        {
            flag=1;

        }
        i++;
    }

    if(flag)
    {
        return i-1;
    }
    return 0;
}



void vector_print(vector* v, void (*print)(T_Elem)) {
    for (int i = 0; i < v->size; i++) {
        print(v->a[i]); // Se imprime cada elemento usando la función pasada
    }
    printf("\n");
}
*/
void vector_print2(vector* v) {
    for (int i = 0; i < v->size; i++) {
        printf("|%d|", v->a[i]); // Se imprime cada elemento usando la función pasada
    }
    printf("\n");
}

void vector_add_random2(vector* v)
{
    if (v==NULL)return;

    while(!vector_isfull(v))
    {
        t_elem_vector value1=rand()%10;
        vector_add(v,value1);
    }

}
//8.
//a.
t_elem_vector vector_max_elem_recursive(vector* v, int index)
{
    if(index==0) return vector_get(v,index);


    t_elem_vector temp= vector_get(v,index);
    t_elem_vector major = vector_max_elem_recursive(v,index-1);
     if(major<temp)
     {
        major=temp;
     }
    return major;
 
}
//b.
t_elem_vector vector_min_elem_recursive(vector* v, int index)
{
    if(index==0) return vector_get(v,index);


    t_elem_vector temp= vector_get(v,index);
    t_elem_vector minor = vector_max_elem_recursive(v,index-1);
     if(minor>temp)
     {
        minor=temp;
     }
    return minor;
 
}
//c.
t_elem_vector vector_sum_elem_recursive(vector* v, int index)
{
    if(index==0) return vector_get(v,index);


    t_elem_vector result= vector_get(v,index);

    return vector_sum_elem_recursive(v,index-1)+result;
    
}
//d.
t_elem_vector vector_prom_elem_recursive(vector* v, int index)
{
    if(index==0) return 0;

    t_elem_vector result= vector_sum_elem_recursive(v,index);

    return result/vector_size(v);
    
}

//e.

void vector_print_recursive_in_order(vector*v, int index)
{
    if(index==0)
    {
        printf("|%d|",vector_get(v,index));
        return;
    }else
        {
            vector_print_recursive_in_order(v,index-1);
            printf("|%d|",vector_get(v,index));
        }

}

//e.
void vector_print_recursive_reverse(vector*v, int index)
{
    if(index==0)
    {
        printf("|%d|",vector_get(v,index));
        return;
    }else
        {
            printf("|%d|",vector_get(v,index));
            vector_print_recursive_reverse(v,index-1);

        }

}
//9
int vector_search_elem_recursive(vector* v, int index, int value)
{

    if(index<0)return -1;

    int pos=index;
    if(vector_get(v,index)==value)
    {   
        return index;
         
    }
 
    return  vector_search_elem_recursive(v,index-1,value);

}
//b.
int _bin_search(vector* v, int elem, int low, int high)
{
    printf("\n%d %d %d",elem,low,high);
    if(high-low==1)return -2;
    int pivote= (low+high)/2;
    printf("\n%d",pivote);
    int temp=vector_get(v,pivote);
    printf("\n%d",temp);
    if(temp==elem) return pivote;


    if(elem < temp)
    {
        return _bin_search(v,elem,low,pivote);
    }
    
    if(elem > temp)
    {
        return _bin_search(v,elem,pivote,high);
    }

    return -1;
}


int bin_search(vector* v, int elem)
{
    return _bin_search(v,elem,0,vector_size(v)-1); //"vector_size(v)-1" aca le estoy pasando el indice en la posicion final
}

void swap(t_elem_vector* a, t_elem_vector* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}


void bubble_sort_v2(vector* v, int n) {
    char swapped = 1;
    while ((swapped != 0) && (n > 0)) {
        swapped = 0;
        for (int i = 1; i < n; i++) {

            t_elem_vector value1=vector_get(v,i - 1);
            t_elem_vector value2=vector_get(v,i);
            if (value1 > value2) {
                swap(&v->a[i - 1], &v->a[i]);
                swapped = 1;
            }
        }
        n--;
    }
}