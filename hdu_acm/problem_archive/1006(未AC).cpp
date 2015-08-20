//说明：
//一天日夜各12h是一样的，算12h制即可，以0点0分0秒为起点，11点59分59秒为终点，顺时针计算角度


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define haldDayTime 12*60*60

bool fun(int hour,int min,int sec,int D)//hour:min:sec
{
    //printf("%d,%d,%d\n",hour,min,sec);
    
    double secAngle = (double)(6*sec);//360/60=6
    double minAngle = (double)(6*min + 0.1*sec);//360/60/60=0.1
    double hourAngle = (double)(30*hour + 0.5*min + 0.008333*sec);
    //360/12=30;30/60=0.5;0.5/60=0.008333
    //printf("%f,%f,%f\n",hourAngle,minAngle,secAngle);
    
    double res1 = secAngle - minAngle;
    res1 = fabs(res1);
    if (res1 > 180)
        res1 = 360 - res1;
    double res2 = secAngle - hourAngle;
    res2 = fabs(res2);
    if (res2 > 180)
        res2 = 360 - res2;
    double res3 = minAngle - hourAngle;
    res3 = fabs(res3);
    if (res3 > 180)
        res3 = 360 - res3;
    //printf("%f,%f,%f,%d\n",res1,res2,res3,D);
    
    if (res1>=D and res2>=D and res3>=D)
    {
        //printf("true\n");
        //getchar();
        return true;
    }
    else
    {
        //printf("flase\n");
        //getchar();
        return false;
    }
}

int main()
{
    int D = 0;
    while (scanf("%d",&D) != EOF)
    {
    	if (D == -1)
    		exit(0);
    	
        int count = 0;
        for (int hour=0; hour<12; hour++)
        {
            for (int min=0; min<60; min++)
            {
                for (int sec=0; sec < 60; sec++)
                {
                    if (fun(hour,min,sec,D))
                        count++;
                }
            }
        }
        //printf("count:%d\n",count);
        double percent = (double)count/43200*100;
        
        printf("%3.3f\n",percent);
    }
    return 0;
}
