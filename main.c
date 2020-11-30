#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int floatToInt(float );
void decToBin(int );
char *decToHex(int );
char *decToOct(int );

int main(int argc, char const *argv[])
{
    int a = 10;

    decToBin(a);
    return 0;
}

int floatToInt(float n) {
    return floor(n);
}

void decToBin(int n) {
    char num[16];
    char numBin[16];
    int count;
    int naux;

    count = 0;
    naux = n;

    while (naux >= 2) //add condição ou mair que 16
    {
        if (naux % 2 == 1)
        {
            num[count] = '1';
        }
        else {
            num[count] = '0';
        }

        count++;
        naux = naux / 2;
    }

    if (naux == 1)
    {
        num[count] = '1';
    }
    else 
    {
        num[count] = '0';
    }

    count++;
    
    for (int i = 0; i < count; i++)
    {
        numBin[i] = num[(count - i) - 1];
    }

    printf("%s", numBin);
}
