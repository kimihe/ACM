#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[])
{
    
    double sum = 0;
    int count = 0;
    bool err_flag = false;
    double gpa = 0;
    char c = 0;
    while (scanf("%c",&c) != EOF)
    {
        if ('\n' == c)
        {
            if (err_flag)
                printf("Unknown letter grade in input\n");
            else
                printf("%4.2f\n",gpa);
            sum = 0;
            count = 0;
            err_flag = false;
            gpa = 0;
            continue;
        }
        
        if (' ' == c)
            continue;
        
        if (c=='A')
            sum += 4;
        else if (c=='B')
            sum += 3;
        else if (c=='C')
            sum += 2;
        else if (c=='D')
            sum += 1;
        else if (c=='F')
            sum += 0;
        else
        {
            err_flag = true;//other characters:"Unknown letter grade in input"
            continue;
        }
        
        count++;
        gpa = sum/count;
        //printf("count=%d\n",count);
        //printf("sum=%f\n",sum);
        //printf("gpa=%f\n",gpa);
    }
    return 0;
}