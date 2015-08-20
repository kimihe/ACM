
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int n = 0;
    n = scanf("%d",&n);
    
    int a,b = 0;
    //int *res = (int *)malloc(n);
    
    for (int i = 0;i < n && scanf("%d%d",&a,&b) != EOF;i++)
    {
        //res[i] = a+b;
        printf("%d",a+b);
    }
    
    //for (int i = 0;i < n;i++)
        //printf("%d\n",res[i]);
    
    return 0;
}