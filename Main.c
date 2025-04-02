#include <stdlib.h>
#include <stdio.h>
#include "vector.h"
#include "Matrix.h"
#include "Fraction.h"
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

    //int result=0;
   // result=sum_recursive(4);
    //printf("%d\n",result);
    //result=mult_recursive(2,5);
   // printf("%d\n",result);

   // print_fibonacci(4);

    //puts(" ");

   // print_fibonacci_2(4);

   // puts(" ");

    float pepon=0;
    pepon=pow_recursive(2,-4);
    printf("%.3f\n",pepon);

    print_piramid(4);

    return 0;

}