/*
    作业原要求为：
    手工编写能识别输入串中多个满足该NFA的记号的词法分析程序。
    我目前把要求理解并实现为：
        找出输入字符串中所有匹配给定正则表达式的子串，功能类似python的re.search。
        匹配的子串尽可能达到最大长度，即使更小的长度也能达到正规式的要求。
    9.10 更新：
    根据公告修改：
    程序原则上仅匹配一个正则表达式(即给定的aa*bb*)，且从开头匹配，在遇到非法字符后会报错，而不是跳过、重新开始匹配。
    程序会parse出所有的词法单元(即被匹配的字符串中，对应的aa*和bb*两部分)
*/
#include <stdio.h>
int match(char* a)
// return the length that matched
{
    char* begin = a; //beginning of the possible match
    char* curr = a; //current
    char* it;
    while(*begin)
    {
        curr = begin;
        if((*curr !='a')&&(*curr != 'b')) 
        {
            printf("Omitting an invalid character...\n");
            begin++;
            continue;
        }
        // test according to variable begin
        if(*curr =='a')
            while(*++curr=='a');
        else
            while(*++curr=='b');
        // output when encounter other characters
        printf("Find matching lexical unit: ");
        for(it=begin;it<curr;it++)
            putchar(*it);
        putchar('\n');
        begin = curr;
    }
    return 0;
}
    /* //deal with inrelevant letters
    while((*a!='a') && (*a!='b') ) {printf("Encounter a invalid character, skip...\n");a++;p++;}
    if(*a=='a')
    {
        int i=1;
        while(*++a=='a')
            i++;
        printf("find lexical unit: ");
        for(;p<a;p++)
            putchar(*p);
        putchar('\n');
        
    }
    while((*a!='a') && (*a!='b') ) {printf("Encounter a invalid character, skip...\n");a++;p++;}

    if(*a=='b')
    {
        while(*++a=='b');
        printf("find lexical unit: ");
        for(;p<a;p++)
            putchar(*p);
        putchar('\n');
    }
    else
        printf("Error parsing the string.\n");
    return 0; */

int main()
{
    // aa*|bb*
    char a[100];
    printf("Input a string:\n");
    gets(a);
    /* char* p,*it;
    for(p=a;*p!=0;p++)
    {
        int len;
        if(len=match(p))
            printf("match the re at position %d, with length %d:",p-a,len);
            for(it=p;it<=p+len-1;it++)
                putchar(*it);
            putchar('\n');
    } */
    match(a);
    system("pause");
    return 0;
    
}