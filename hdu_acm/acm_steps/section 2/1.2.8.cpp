#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int test (char c)
{
    int res = 0;
    if (c>='a' && c<='z')
        res = 1;
    if (c>='A' && c<='Z')
        res = 2;
    return res;
}

void fun (char *c)
{   
    int res = 0;
    if (*c=='a' or *c=='e' or *c=='i' or *c=='o' or *c=='u' or
        *c=='A' or *c=='E' or *c=='I' or *c=='O' or *c=='U')
    {
        res = test(*c);//vowel to uppercase
        if (res == 1)
            *c = *c - 0x20;
    }
    else
    {
        res = test(*c);//other characters tp lowercase
        if (res == 2)
            *c = *c + 0x20;
    } 
}

int main()
{
    int n = 0;
    char str[1024];
    scanf("%d ",&n);//%d后面的空格不要丢了，要不然enter会被gets函数读入。
                    //控制串的空白字符使在输入流中跳过一个或多个空白字符.
    while (n--)
    {
        gets(str);
        char *p = str;
        int len = strlen(str);
        while (len--)
        {
            fun(p);
            p++;
        }
        str[len] = '\0';
        printf("%s\n", str);
    }
    return 0;
}