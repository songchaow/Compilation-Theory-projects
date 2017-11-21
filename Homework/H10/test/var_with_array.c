#include <stdio.h>
int main()
{
	int array[10];
	int i,j,k;
	// assign values for three variables
	i=1; j=2; k=3;
	int *p=array;
	for(;p<array+10;p++)
		*p = (int)p;
	p=array+10;
	*p = 888;
	
	printf("i=%d\n",i);
	printf("j=%d\n",j);
	printf("k=%d\n",k);
	return 0;
}
