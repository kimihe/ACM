#include <stdio.h>
#include <stdlib.h>
//此题容易超时，要寻找周期化简。怎么找？
int main()
{
    int A,B,n = 0;
    while (scanf("%d%d%d",&A,&B,&n) != EOF)
    {
    	if (A == 0 && B == 0 && n == 0)
    		exit(0);
    	
        int f[50];//直觉告诉你周期再怎么样也应该不会超过50，但是怎么知道的？
        f[1] = f[2] = 1;
        int i = 0;
        for (i=3; i<=50; i++)
        {
            f[i] = (A*f[i-1] + B*f[i-2])%7;
            if (i>=4 && f[i]==f[3] && f[i-1]==f[2] && f[i-2]==f[1])
                break;
        }
        
        int t = i-3;//周期是t=i-3
        n = n%t;
        if (n==0)//如果n是周期整数倍，取模为0，因为f[i]是从1开始的，所以把n换成t
            n=t;
        printf("%d\n",f[n]);
    }
    return 0;
}

//以下是别人AC的代码
//#include<stdio.h>
//int main()
//{
//    char f[100];
//    int a,b,n;
//    int i;
//    f[1]=1;f[2]=1;
//    while(scanf("%d%d%d",&a,&b,&n)!=EOF&&(a||b||n)){
//        for(i=3;i<=100;i++){
//            f[i]=(a*f[i-1]+b*f[i-2])%7;
//            if(i>5&&f[i]==f[3]&&f[i-1]==f[2]&&f[i-2]==f[1]) break;
//            
//        }
//        n=n%(i-3);
//        if(n==0) n=i-3;
//        printf("%d\n",f[n]);
//    }
//    return 0;
//}