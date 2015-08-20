#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(char *a, char *b,char *sum)//字符串a要比字符串b长，或相等
{
    int len_a = strlen(a);
    int len_b = strlen(b);
    char tmp[len_a];
    int offset = len_a-len_b;
    strncpy(tmp+offset,b,len_b);//后面len_b长度复制，前面offset长度填充字符‘0’
    for (int i=0; i<offset; i++)
        tmp[i]='0';
    //tmp[len_a] = '\0';
    //printf("tmp=%s\n", tmp);
    
    int flag = 0;
    int top = 0;
    for (int i=len_a-1; i>=0; i--)
    {
        int res = (a[i]-48) + (tmp[i]-48) + flag;
        if (res >= 10)
        {
            flag = 1;
            res -= 10;
        }
        else
            flag = 0;
        
        sum[i] = res+48;
        if (i == 0)//设置最高位是1还是0，并作为返回值，控制main函数中是否打印出来
        {
            if (flag == 1)
                top = 1;
            else
                top = 0;
        }
    }
    sum[len_a] = '\0';
    if (top == 1)//最高位为1打印出来，否则不打印
        printf("%d%s\n",top,sum);
    else
        printf("%s\n",sum);
}

int main()
{
    int n = 0;
    scanf("%d ",&n);//%d后面的空格不要丢了，要不然enter会被gets函数（如果用）读入。
    				//控制串的空白字符使在输入流中跳过一个或多个空白字符.
    for (int i=0; i<n; i++)
    {
        char a[1000];
        char b[1000];
        char sum[1000];
        scanf("%s %s",a,b);//scanf自动在a,b结尾加'\0',若输入把a,b塞满了则NUL在数组外面+1位置
        //printf("a=%s\nb=%s\n", a,b);
        
        printf("Case %d:\n",i+1);
        printf("%s + %s = ",a,b);
        int len_a = strlen(a);
        int len_b = strlen(b);
        if (len_a >= len_b)
            add(a,b,sum);
        else
            add(b,a,sum);
        if (i<n-1)
            printf("\n");
    }
    return 0;
}