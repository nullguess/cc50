#include <cc50.h>
#include <stdio.h>

int
main(void)
{

     printf("M procurando F: ");
     int i = GetInt();
     while (i < 1)
     {
	printf("Um numero positivo, por favor: ");
	i = GetInt();
     }

     printf("F procurando M: ");
     int j = GetInt();
     while (j < 1)
     {
	printf("Um numero positivo, por favor: ");
	j = GetInt();
     }

     printf("F procurando F: ");
     int k = GetInt();
     while (k < 1)
     {
	printf("Um numero positivo, por favor: ");
	k = GetInt();
     }

     printf("M procurando M: ");
     int l = GetInt();
     while(l < 1)
     {
	printf("Um numero positivo, por favor: ");
	l = GetInt();
     }

     int total = i + j +k + l;

     float mf = ((float) i / total) * 80;
     float fm = ((float) j / total) * 80;
     float ff = ((float) k / total) * 80;
     float mm = ((float) l / total) * 80;

     int a = (int) mf + 0.5;
     int b = (int) fm + 0.5;
     int c = (int) ff + 0.5;
     int d = (int) mm + 0.5;

     printf("\n");
     printf("Quem procura quem?\n");
     printf("\n");

     printf("M procurando F\n");
     for (int n = 0; n < a; n++)
     {
	printf("#");
     }
     printf("\n");

     printf("F procurando M\n");
     for (int n = 0; n < b; n++)
     {
	printf("#");
     }
     printf("\n");

     printf("F procurando F\n");
     for (int n = 0; n < c; n++)
     {
	printf("#");
     }
     printf("\n");

     printf("M procurando M\n");
     for (int n = 0; n < d; n++)
     {
	printf("#");
     }
     printf("\n");

     return 0;
}

