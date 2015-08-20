#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int a,b = 0;
    while (scanf("%d%d",&a,&b) != EOF && scanf("%d",&a) != 0 && scanf("%d",&b) != 0)
    {
        printf("%d",a+b);
    }
    return 0;
}