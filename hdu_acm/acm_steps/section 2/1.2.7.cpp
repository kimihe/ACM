#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define ID_card_len 18

void fun (char *buf)
{
	int areaFlag = 0;
    areaFlag = (buf[0] - 0x30)*10 + buf[1] - 0x30;
    
    char *p = buf;
    int i = 0;
	    char year[4+1];
    for (i=0,p=&buf[6]; i<4; i++,p++)
    {
        year[i] = *p;
    }
    year[4] = '\0';
    
    char month[2+1];
    month[0] = buf[10];
    month[1] = buf[11];
    month[2] = '\0';
    
    char day[2+1];
    day[0] = buf[12];
    day[1] = buf[13];
    day[2] = '\0';
    
    char area[21];
    switch (areaFlag)
    {
        case 33:
            strcpy(area,"Zhejiang\0");
            break;
        case 11:
            strcpy(area,"Beijing\0");
            break;
        case 71:
            strcpy(area,"Taiwan\0");
            break;
        case 81:
            strcpy(area,"Hong kong\0");
            break;
        case 82:
            strcpy(area,"Macao\0");
            break;
        case 54:
            strcpy(area,"Tibet\0");
            break;
        case 21:
            strcpy(area,"Liaoning\0");
            break;
        case 31:
            strcpy(area,"Shanghai\0");
            break;
        default:
            break;
    }
    printf("He/She is from %s,and his/her birthday is on %s,%s,%s based on the table.\n",
           area,month,day,year);
}

int main(int argc, const char * argv[])
{
    int n = 0;
    while (scanf("%d",&n) != EOF)
    {
        getchar();
        char buf[ID_card_len+2]; //contain '\n',and ad2d '\0'
    	for (int i=0;i<n;i++)
    	{
        	fgets(buf,ID_card_len+2,stdin);
        	//printf("%s\n", buf);
        	fun (buf);
    	}
    }
    return 0;
}