#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n = 0;
    while (scanf("%d",&n) != EOF && n!= 0)
    {
    	char str[1000][16];//只对各不相同的颜色进行存储
    	memset(str,0,sizeof(str));//all set to be NUL
    	char tmp[16];
    	int count[1000] = {0};//对应每个str[i]统计个数
    	int len = 0;//str长度

    	for (int i=0; i<n; i++)
    	{
    		scanf("%s",tmp);
    		int tmplen = strlen(tmp);
    		if (len == 0)//first color
    		{
    			strncpy(str[0],tmp,tmplen);
    			len = 1;
    			count[0] = 1;
    			continue;
    		}

    		for (int i=0; i<len; i++)
    		{
    			if (strcmp(str[i],tmp) == 0)//str[i]和tmp同色，则对应count[i]++
    			{
    				count[i]++;
    				break;
    			}

    			if (i == len-1)//之前所有的str[i]和tmp都不同色，添加新色str[len]
    			{
    				strncpy(str[len],tmp,tmplen);
    				count[len] = 1;
    				len++;
    				break;//注意此处要break，否则最后一次匹配len++，会导致for额外循环一次！
    			}			
    		}
    	}

    	int max = count[0];
    	int pos = 0;
    	for (int i=0; i<len; i++)
    	{
    		//printf("%s:%d\n", str[i],count[i]);
    		if (count[i] > max)
    		{
    			max = count[i];
    			pos = i;
    		}
    	}
    	printf("%s\n",str[pos]);	
    }		
    return 0;
}