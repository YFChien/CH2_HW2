int main()
{
    int a;
    printf("Enter # of hours worked:\n",a);
    scanf("%d",&a);
    printf("Enter hourly rate of the worker:10\n");
    int c=a*10;
    float e=400+(a-40)*1.5*10;
    if(a <= 40)
    {
        printf("Salary is %d\n",c);
    }
    if(a > 40)
    {
        printf("Salary is %f\n",e);
    }
    system("pause");
    return 0;
}
