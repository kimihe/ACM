//
//  main.cpp
//  tmp
//
//  Created by 周祺华 on 15/8/19.
//  Copyright (c) 2015年 周祺华. All rights reserved.
//

//思路为桶排序

#include <stdio.h>
#define BOOKLEN 101

int n,tmp,i,min,max;
int book[BOOKLEN];

int main(int argc, const char * argv[])
{
    while (scanf("%d",&n) != EOF)
    {
        for (i=0; i<BOOKLEN; i++)
            book[i] = 0;//初始化数组，0表示没有这个数，下标i对应数值
        
        for (i=0; i<n; i++)
        {
            scanf("%d",&tmp);
            book[tmp] = 1;//1表示有这个数
        }
        
        for (i=0; i<BOOKLEN; i++)//从头扫描找min
        {
            if (book[i] == 1)
            {
                min = i;
                break;
            }
        }
        
        for (i=BOOKLEN-1; i>=0; i--)//从尾扫描找max
        {
            if (book[i] == 1)
            {
                max = i;
                break;
            }
        }
        printf("%d %d\n",max,min);
    }
    
    return 0;
}
