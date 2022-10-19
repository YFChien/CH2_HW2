#include <stdio.h>

int main()
{
    int a;
    float b;
    float c;
    float d;
    float e;
    printf("Enter account nrmber:",a);
    scanf("%d",&a);
    printf("Enter beginning balance:",b);
    scanf("%f",&b);
    printf("Enter total charges:",c);
    scanf("%f",&c);
    printf("Enter total credits:",d);
    scanf("%f",&d);
    printf("Enter credit limit:",e);
    scanf("%f",&e);
    float f=b+d;
    printf("Account:%d\n",a);
    printf("Credit limit:%f\n",e);
    printf("Balance:%f\n",f);
    
    if(e< f)
    {
        printf("Credit Limit Exceeded");
    }
    return 0;
}
