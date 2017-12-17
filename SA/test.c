#include <stdio.h>
void sayHello()
{
    printf("Hello!\n");
}
void sayBye()
{
    printf("Bye!\n");
}
int main()
{
    int i = 5;
    for(;i>0;i--)
    {
        sayHello();
    }
    sayBye();
}