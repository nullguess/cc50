#include <cc50.h>
#include <stdio.h>

int main(void) 
{
    printf("Ola! Quanto de troco te devemos?\n");
    float i = GetFloat();

    while (i <= 0)
    {
   	printf("Ahnn, tente de novo.\n");
	i = GetInt();
    }
    int j;
    j = i * 100;

    int moeda25 = 0;
    int moeda10 = 0;
    int moeda5 = 0;
    int moeda1 = 0;

    while (j >= 25)
    {
	moeda25++;
	for (int diminuij = 0; diminuij < 25; diminuij++)
	{
		j--;
	}
    }

    while (j < 25 && j >= 10)
    {
	moeda10++;
	for (int diminuij = 0; diminuij < 10; diminuij++)
	{
		j--;
	}
    }

    while (j < 10 && j >= 5)
    {
	moeda5++;
	for (int diminuij = 0; diminuij < 5; diminuij++)
	{
		j--;
	}
    }

    while (j < 5 && j >= 1)
    {
	moeda1++;
	j--;
    }

    int total = moeda25 + moeda10 + moeda5 + moeda1;
    printf("%d moeda(s)\n", total);
}
