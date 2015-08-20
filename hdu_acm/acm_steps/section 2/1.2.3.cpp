#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    char c = 0;
    int sum = 0;
    int n = 1;
    int tmp = 0;
    while (scanf("%c",&c) != EOF)
    {
        if ('#' == c)
            exit(0);

        if ('\n' == c)
        {
            printf("%d\n",sum);
            sum = 0;
            n = 1;
            continue;
        }
        
        if (' ' == c)//space
            tmp = 0;
        else      
            tmp = (int)c - 64;//A-Z:65-90
        sum += n*tmp;
        n++;
    }
    return 0;
}