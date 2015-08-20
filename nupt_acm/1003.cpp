//
//  main.cpp
//  tmp
//
//  Created by 周祺华 on 15/8/19.
//  Copyright (c) 2015年 周祺华. All rights reserved.
//

#include <stdio.h>

int main ()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int pre = 0;//F(0)
        int next = 1;//F(1)
        int res = 1;//F(2)
        
        if (n < 2)
            printf("%d\n",n);//F(0)=0;F(1)=1;
        else if (n ==2)
            printf("1\n");//F(2)=1;
        else
        {
            while (n>2)//从3开始,F(3)=2
            {
                pre = next;
                next = res;
                res = pre+next;
                n--;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}