#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    int n1 = 0;
    while (scanf("%d",&n1) != EOF)
    {
        for (int i = 0;i < n1;i++)
        {
            int n2 = 0;
            scanf("%d",&n2);
            
            int sum = 0;
            for (int j = 0;j < n2;j++)
            {
                int a = 0;
                scanf("%d",&a);
                sum += a;
            }
            (i<n1-1)?printf("%d\n\n",sum):printf("%d\n",sum);
            //最后一次输出不要有空行!
        }
    }
    return 0;
}