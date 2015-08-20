#include <stdio.h>
#include <stdlib.h>

bool leapTest (int year)
{
    if ((year%4==0 && year%100!=0) or year%400==0)
        return true;
    else
        return false;
}

int leapCompute (int start, int Nth)
{
    //if year Y is a leap year,the 1st leap year is year Y
    if (leapTest(start))
        Nth--;
    //else year Y is not a leap year, forward to make year Y multiple of 4 
    else				
    {   int res = start%4;
        start-=res;
    }

    while (Nth > 0)
    {
        start+=4;
        if (leapTest(start))
            Nth--;
    }
    return start;
}

int main(int argc, const char * argv[])
{
    int n = 0;
    while (scanf("%d",&n) != EOF)
    {
        int start = 0;
        int Nth = 0;
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&start);
            scanf("%d",&Nth);
            int end = leapCompute(start, Nth);
            printf("%d\n", end);
        }        
    }
    return 0;
}