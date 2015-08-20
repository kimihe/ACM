#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int lowestBit (int number)
{
    int count = 0;
    while ((number%2) == 0)
    {
        //printf("number=%d\n",number);
        number = number >> 1;
        count++;
    }
    return pow(2,count);
}

int main(int argc, const char * argv[])
{
    int number = 0;
    while (scanf("%d",&number) != EOF)
    {
        if (number == 0)
            exit(0);
        int res = lowestBit(number);
        printf("%d\n", res);
    }
    return 0;
}