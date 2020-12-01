#include <stdio.h>
#include <stdlib.h>


int convertebinario( int dec)
{
int i = 0,q[80],r[80];

  while (dec != 1){     
   q[i]= dec / 2;  
   r[i] = dec % 2; 
   dec=q[i];       
   i++;
   }

 
  while (i>=0){  
     if (q[i] == 1) printf("1%d",r[i]);
          else printf("%d",r[i]);  
   i--;
   }
printf("\n");
return 0;
}

/*
int main()
{
	int valor, base;
	float f;
	char hexa[10], octal[10];

	scanf("%f %d", &f, &base);

	valor = (int)f;

    if(base == 16){
	sprintf(hexa, "%x", valor);
	printf("%s\n", hexa);
    }

    if(base == 8){
	sprintf(octal, "%o", valor);
	printf("%s\n", octal);
    }

	if(base == 2){
	convertebinario(valor);
	}
}
*/
