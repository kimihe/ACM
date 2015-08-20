#include <stdio.h>
#include <stdlib.h>

#define up 6
#define down 4
#define stop 5

int main(int argc, const char * argv[])
{
    int n = 0;
    while (scanf("%d",&n) != EOF)
    {
        if (n == 0)
        	exit(0);

        int current = 0;
        int next = 0;
        int sum = 0;
        
        for (int i = 0;i < n;i++)
        {
            scanf("%d",&next);
            if (next > current)
            {
            	sum += (next - current)*up;
            	sum += stop;
            	current = next;
            }
            else if (next < current)
            {
            	sum += (current - next)*down;
            	sum += stop;
            	current = next;
            }
            else
            	sum += stop;//stop at the same floor will also cost 5 mins! - -                     	
        }	
        printf("%d\n",sum); 
    }
    return 0;
}