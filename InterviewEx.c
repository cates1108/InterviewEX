
#include "stdio.h"

void main(void)
{
	char a = 100;
	char *p = &a;
	char **pp = &p;
	
	printf("addr a:0x%x\n",&a);
	printf("addr p:0x%x,size p:%d\n",p,sizeof(p));
	printf("addr &p:0x%x\n",&p);
	printf("addr pp:0x%x\n",pp);
	printf("addr *pp:0x%x\n",*pp);
	printf("addr **pp:0x%x\n",**pp);	//100

	//little-end ex
	int ex2 = 0x12345678;
	int *pex2 = &ex2;
	printf("%d\n",*(pex2));
	printf("%x\n",*((char*)pex2));
	printf("%x\n",*(((char*)pex2)+1));	//little-end
	printf("%x\n",*(((char*)pex2)+2));
	printf("%x\n",*(((char*)pex2)+3));

	//or
	union data
	{
		int i;
		char c[4];
	};
	union data u;
	u.i = 0x12345678;
	printf("%x\n",u.c[0]);

	//Andes
	int a1[10];
	int *b1[10];	//10 pointer 
	int (*c1)[10];	//1 pointer to 10 int integer
	int *p1;
	p1 = a1;
	//c1 = a1;

	int i;
	for(i=0;i<10;i++)
	{
		a1[i] = i;	
		b1[i] = &a1[i];
		//*(c1)[i] = i;
	}
	printf("a[1]:%d,b[1]:%d, c[1]:%d,p1:%d\n",a1[1],*b1[1],*(++p1));

}
	
