#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int a,b = 0;
    while (scanf("%d%d",&a,&b) != EOF)
    {    
        printf("%d\n\n",a+b);
    }
    return 0;
}