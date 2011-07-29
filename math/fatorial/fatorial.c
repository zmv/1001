#include <stdio.h>
#define MAX_FAT 18
/**
 * Calculo de fatorial
 * Autor:
 *     ?
 * Colaborador:
 *     Bruno Lara Tavares <bruno.exz@gmail.com>
 * Tipo:
 *     math
 * Descricao:
 *     Calcula o fatorial de um numero - usando recursao
 * Complexidade:  
 *     ?
 * Dificuldade:
 *     facil
*/

unsigned long int fatorial(unsigned long int a)
{
  return a<=1?a=1:a*fatorial(a-1);
}

int main(void)
{
  unsigned long int x;

  for (x=1;x<MAX_FAT;x++)
    {
      printf("O fatorial de %2u e %5u\n",x,fatorial(x));
    }

  return(0);
}
