#include <stdlib.h>
#include <stdio.h>
#include "Tdas/vector.h"
#include "Tdas/Matrix.h"
#include "Tdas/Fraction.h"
#include "time.h"
//1
int sum_recursive(int n)
{
    if(n==0)
    {
        return n;
    }

    return sum_recursive(n-1)+n;

}

//2
int mult_recursive(int n1, int n2)
{
    if(n2==1)
    {
        return n1;
    }

    return mult_recursive(n1,n2-1)+n1;

}
//3
int fibonacci(int n){
    int result = 1;
    if (n > 1) {
        result = fibonacci(n - 1) + fibonacci(n - 2);
    }
    return result;
}
//a.
void print_fibonacci(int n)
{
    int value=fibonacci(n);
    if(n<0)
    {
        return;
    }

    print_fibonacci(n-1);
    printf("%d\n",value);

}
//b.
void print_fibonacci_2(int n)
{
    if(n<1)
    {
        return;
    }
    print_fibonacci_2(n-1);
    int value=fibonacci(n-1);
    printf("%d\n",value);




 //   printf("%d\t",value);

}
//4
float pow_recursive(int x, int n)
{

    if(n==0)
    {
        return 1;
    }

    float result=x;


    if(n>0)
    {
        
        return pow_recursive(x,n-1)*result;
    }

    if(n<0)
    {
        return (1.0 / (pow_recursive(x, -(n-1)) * x));

        //return ((1/pow_recursive(x,n+1)) * (1/result));
        //return (1/(pow_recursive(x,n+1)*x));
    }

    return result;

}
//7

void print_piramid(int n)//Para imprimir una secuencia de numeros sin tener un vector uso un bucle for
{
    if(n==0)
    {
        return;
    }
    
    for(int i=n; i>=1; i--)
    {
        printf("%d",i);
    }
    puts(" ");

        
        print_piramid(n-1);
        for(int i=n; i>=1; i--)
        {
            printf("%d",i);
        }
        puts(" ");
}

int main ()
{
    srand(time(NULL));
    //int result=0;
   // result=sum_recursive(4);
    //printf("%d\n",result);
    //result=mult_recursive(2,5);
   // printf("%d\n",result);

   // print_fibonacci(4);

    //puts(" ");

   // print_fibonacci_2(4);

   // puts(" ");

    //float pepon=0;
    //pepon=pow_recursive(2,-4);
    //printf("%.3f\n",pepon);

    //print_piramid(4);

    vector* vectorsin=vector_init(8);
    //vector_add_random2(vectorsin);
    vector_add(vectorsin,10);
    vector_add(vectorsin,41);
    vector_add(vectorsin,12);
    vector_add(vectorsin,17);
    vector_add(vectorsin,24);
    vector_add(vectorsin,32);
    vector_add(vectorsin,15);
    vector_add(vectorsin,18);
    vector_print2(vectorsin);

    t_elem_vector max_value=vector_max_elem_recursive(vectorsin,vector_size(vectorsin)-1);

    printf("%d",(int)max_value);

    t_elem_vector min_value=vector_min_elem_recursive(vectorsin,vector_size(vectorsin)-1);

    printf("\n%d",(int)min_value);

    t_elem_vector sum_elem=vector_sum_elem_recursive(vectorsin, vector_size(vectorsin)-1);

    printf("\n%d",(int)sum_elem);

    t_elem_vector prom_elem=vector_prom_elem_recursive(vectorsin, vector_size(vectorsin)-1);

    printf("\n%.3f",(float)prom_elem);
    puts("");
    vector_print_recursive_in_order(vectorsin,vector_size(vectorsin)-1);
    puts("");
    vector_print_recursive_reverse(vectorsin,vector_size(vectorsin)-1);


    t_elem_vector number=vector_search_elem_recursive(vectorsin,vector_size(vectorsin)-1,1);
    printf("\n %d",number);

    bubble_sort_v2(vectorsin,vector_size(vectorsin));
    puts(" ");
    vector_print2(vectorsin);

    int pos=bin_search(vectorsin,100);
    printf("\n%d",pos);
    


/*
    Matrix* matrison=matrix_new(3,6);
    matrix_add_random(matrison);
    matrix_print2(matrison);

    int cant=matrix_row_count_element(matrison, 3, matrix_rows(matrison),matrix_columns(matrison));
    printf("\nLa cantidad de elementos repetidos por fila par es: %d",cant);
*/
    return 0;

}