#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int floatToInt(float);
void decToBinHexOct(int, int);
int sumElementos(int *, int);
int positionMax(int *, int);
int entrarCedulas(int *);
int contains(int, int *, int);
void trocar100(int *);
int validarEntrada(int, int *, int);

int main(int argc, char const *argv[])
{
	int v[5];

	trocar100(v);
}

int floatToInt(float n)
{
	return (int)floor(n);
}

void decToBinHexOct(int n, int base)
{
	char num[16];
	char numConvertido[16];
	int count;
	int naux;

	count = 0;
	naux = n;

	char caracteres[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

	while (naux >= base) //add condição ou mair que 16
	{
		num[count] = caracteres[naux % base];
		count++;
		naux = naux / base;
	}

	num[count] = caracteres[naux % base];
	count++;

	numConvertido[count] = '\0';

	for (int i = 0; i < count; i++)
	{
		numConvertido[i] = num[(count - i) - 1];
	}

	printf("%s\n", numConvertido);
}

int sumElementos(int *v, int len)
{
	int sum = 0;

	for (int i = 0; i < len; i++)
	{
		sum = sum + v[i];
	}

	return sum;
}

int positionMax(int *v, int len)
{
	int max = 0;

	for (int i = 1; i < len; i++)
	{
		if (v[i] > v[max])
		{
			max = i;
		}
	}

	return max;
}

int validarEntrada(int n, int *v, int len)
{
	if (n == 2 || n == 5 || n == 10 || n == 20 || n == 50)
	{
		if (contains(n, v, len) == 0)
		{
			return 1;
		}
	}

	return 0;
}

int contains(int n, int *v, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (n == v[i])
		{
			return 1;
		}
	}
	return 0;
}

int entrarCedulas(int *v)
{
	int cedula;
	int i;

	i = 0;
	do
	{
		scanf("%d", &cedula);
		if (validarEntrada(cedula, v, i) == 1)
		{
			v[i] = cedula;
			i++;
		}
	} while ((i < 5 && cedula != 0) || i <= 0);

	return i;
}

void trocar100(int *v)
{
	int valor;
	int sum;
	int i;
	int pos;
	int cedulas[2][5];
	int len = entrarCedulas(v);

	valor = 100;

	i = 0;
	do
	{
		pos = positionMax(v, len);
		cedulas[0][i] = v[pos];
		sum = sumElementos(v, len);

		if (valor % cedulas[0][i] >= sum - cedulas[0][i])
		{
			cedulas[1][i] = valor / cedulas[0][i];
		}
		else
		{
			if(cedulas[0][i] % (sum - cedulas[0][i]) != 0) {
				cedulas[1][i] = valor / sum;
			}
			else {
				cedulas[1][i] = (valor / cedulas[0][i]) - 1;
			}
		}

		valor = valor - cedulas[0][i] * cedulas[1][i];

		v[pos] = 0;
		i++;

		pos = positionMax(v, len);
	} while (v[pos] > 0);

	if (valor == 0)
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = cedulas[1][i]; j > 0; j--)
			{
				printf("%d\n", cedulas[0][i]);
			}
		}
	}
	else
	{
		printf("troca não permitida\n");
	}
}
