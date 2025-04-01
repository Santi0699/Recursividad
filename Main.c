#include <stdlib.h>
#include <stdio.h>

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

int main ()
{

    int result=0;
    result=sum_recursive(4);
    printf("%d\n",result);
    result=mult_recursive(2,5);
    printf("%d\n",result);

    print_fibonacci(4);

    puts(" ");

    print_fibonacci_2(4);


    return 0;

}