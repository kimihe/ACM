#include <stdio.h>
#include <stdlib.h>

bool triangleTest(int *a, int *b, int *c)
{
    int tmp = 0;
    if (*b > *a) //make a >= b
    {
        tmp = *b;
        *b = *a;
        *a = tmp;
    }
    
    if (*c > *b) //make b >= c
    {
        tmp = *c;
        *c = *b;
        *b =tmp;
    }
    
    if (*b > *a) //make a >= b, now (a,b,c) is (max,mid,min)
    {
        tmp = *b;
        *b = *a;
        *a = tmp;
    }
    
    if ((*b+*c) > *a)
        return true;
    else
        return false;
}

void triangleClassify(int a,int b,int c) //(a,b,c) is (max,mid,min)
{
    if (a*a == b*b + c*c)
        printf("good\n");
    else if (b == c or a==b)
        printf("perfect\n");
    else
        printf("just a triangle\n");
}

int main(int argc, const char * argv[])
{
    int n = 0;
    while (scanf("%d",&n) != EOF)
    {
        for (int i = 0;i < n;i++)
        {
            int a,b,c = 0;
            scanf("%d%d%d",&a,&b,&c);
            if (triangleTest(&a,&b,&c))
                triangleClassify(a,b,c);
            else
                continue;
        }
    }
    return 0;
}