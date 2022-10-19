#include <stdio.h>

int main()
{
    int a;
    float b;
    float c;
    
    printf("Enter loan principal:", a);
    scanf("%d",&a);
    printf("Enter interest rate:", b);
    scanf("%f",&b);
    printf("Enter term of loan in days:", c);
    scanf("%f",&c);
    float d=a*b*(c/365);
    printf("The interest charge is:%f",d);
    return 0;
    
}
