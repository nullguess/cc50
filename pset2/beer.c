#include <stdio.h>

int
main(void)
{
    int b = 10;
    
    int i = 10;
    for(i = 10; i > 2; i--)
    {
	    printf("%d garrafas de cerveja no muro, bebo uma, jogo no lixo, %d garrafas no muro...\n", b, b-1);
	    b--;
    }

    if(b == 2)
    {
	    printf("%d garrafas de cerveja no muro, bebo uma, jogo no lixo, %d garrafa no muro...\n", b, b-1);
	    b--;
    }

    printf("%d garrafas de cerveja no muro, bebo uma, jogo no lixo, nenhuma garrafa no muro...\n", b);

    return 0;
}
