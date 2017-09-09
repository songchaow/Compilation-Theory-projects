/*
    作业原要求为：
    手工编写能识别输入串中多个满足该NFA的记号的词法分析程序。
    我目前把要求理解并实现为：
        找出输入字符串中所有匹配给定正则表达式的子串，功能类似python的re.search。
        匹配的子串尽可能达到最大长度，即使更小的长度也能达到正规式的要求。
*/
#include <stdio.h>
int match(char* a)
// return the length that matched
{
    if(*a=='a')
    {
        int i=1;
        while(*++a=='a')
            i++;
        return i;
    }
    else if(*a=='b')
    {
        int i=1;
        while(*++a=='b')
            i++;
        return i;
    }
    else return 0;
}

int main()
{
    // aa*|bb*
    char a[100];
    printf("Input a string:\n");
    gets(a);
    char* p,*it;
    for(p=a;*p!=0;p++)
    {
        int len;
        if(len=match(p))
            printf("match the re at position %d, with length %d:",p-a,len);
            for(it=p;it<=p+len-1;it++)
                putchar(*it);
            putchar('\n');
    }
    system("pause");
    return 0;
    
}