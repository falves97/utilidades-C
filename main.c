#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int floatToInt(float );
void decToBin(int );
void decToHex(int );
void decToOct(int );

int main(int argc, char const *argv[])
{
		float n;
    int nInt, base;

		scanf("%f%d", &n, &base);

		nInt = floatToInt(n);

		switch(base) {
			case 2:
				decToBin(nInt);
			break;
			case 8:
				decToOct(nInt);
			break;
			case 16:
				decToHex(nInt);
			break;
		}
    return 0;
}

int floatToInt(float n) {
    return (int) floor(n);
}

void decToBin(int n) {
    char num[16];
    char numBin[16];
    int count;
    int naux;

    count = 0;
    naux = n;

		char binCaracteres[2] = {'0', '1'};

    while (naux >= 2) //add condição ou mair que 16
    {
        num[count] = binCaracteres[naux % 2];
        count++;
        naux = naux / 2;
    }

    num[count] = binCaracteres[naux % 2];
		count++;

		numBin[count] = '\0';

    for (int i = 0; i < count; i++)
    {
        numBin[i] = num[(count - i) - 1];
    }

    printf("%s\n", numBin);
}

void decToHex(int n) {
    char num[16];
    char numHex[16];
    int count;
    int naux;

    count = 0;
    naux = n;

		char hexCaracteres[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};


    while (naux >= 16) //add condição ou mair que 16
    {
        num[count] = hexCaracteres[naux % 16];
        count++;
        naux = naux / 16;
    }

    num[count] = hexCaracteres[naux % 16];
		count++;

		numHex[count] = '\0';

    for (int i = 0; i < count; i++)
    {
        numHex[i] = num[(count - i) - 1];
    }

    printf("%s\n", numHex);
}

void decToOct(int n) {
    char num[16];
    char numOct[16];
    int count;
    int naux;

    count = 0;
    naux = n;

		char hexCaracteres[8] = {'0', '1', '2', '3', '4', '5', '6', '7'};


    while (naux >= 8) //add condição ou mair que 16
    {
        num[count] = hexCaracteres[naux % 8];
        count++;
        naux = naux / 8;
    }

    num[count] = hexCaracteres[naux % 8];
		count++;

		numOct[count] = '\0';

    for (int i = 0; i < count; i++)
    {
        numOct[i] = num[(count - i) - 1];
    }

    printf("%s\n", numOct);
}