#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    while (scanf("%d",&n) != EOF)
       {
            if (n == 0)
                exit(0);

            int sum = 0;
            for (int i=0;i<n;i++)
            {
                int a = 0;
                scanf("%d",&a);
                sum += a;
            }
            printf("%d\n",sum );
    
       }    
    return 0;
}