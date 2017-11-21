#include <stdio.h>
#include <stdlib.h>
int main()
{
    char *p = malloc(sizeof(char));
    printf("now the address is: %d, char is %d\n",p,*(p++));
    printf("Press any key to continue.\n");
    getchar();
    for(;;)
    {
        printf("now the address is: %d, char is %d\n",p,*(p++));
    }

}