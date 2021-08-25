#include <cc50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int
main(void)
{
    // seed do PRNG
    srand(time(NULL));

    // escolhe número pseudo-aletorio entre [0, 1023]
    int skittles = rand() % 1024;
    //variavel do GetInt
    int i;

    //apresenta as regras ao usuario
    printf("Sou uma maquina de doces virtual, tenho de 0 a 1023 doces, adivinhe quantos doces eu tenho: ");
    i = GetInt();

    //apresenta as dicas ao usuario, permitindo que o mesmo tente novamente
    if (i != skittles)
{
    do
    {
	if (i > skittles)
	printf("Tenho menos doces do que isso. Tente novamente: ");

	if (i < skittles)
	printf("Tenho mais doces do que isso. Tente novamente: ");

	i = GetInt();
    }

    //o pedido é feito ate o usuario acertar o valor
    while(i != skittles);
}
    //o programa parabeniza o usuario pelo acerto
    printf("Parabéns, voce acertou, tenho %d doces! \n", skittles);
}


