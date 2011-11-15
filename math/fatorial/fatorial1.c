#include <stdio.h>
#include <stdlib.h>
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
 *     Calcula o fatorial de um numero - usando ponteiros
 * Complexidade:  
 *     ?
 * Dificuldade:
 *     facil
*/

int main(void)
{
  unsigned long int x,*fatoriais=(unsigned long int*)malloc(MAX_FAT*sizeof(unsigned long int));
  unsigned long int *fat1;

  if(!fatoriais)
    {
      printf("Nao pude alocar memoria! Saindo");
      return(1);
    }

  fat1=fatoriais;
  *fat1=1;
  
  for (x=2;x<=MAX_FAT;x++)
    {
      fat1++; // Avanca um item;
      *fat1=x*(*(fat1-1)); // importante isolar o primeiro * - multiplicacao, do segundo - apontar
    }

  fat1=fatoriais;

  for (x=0;x<MAX_FAT;x++)
    {
      printf("O fatorial de %2u e %5u\n",x+1,*(fat1+x));
    }

  free(fat1);
  
  return(0);
}
