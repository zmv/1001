#include <stdio.h>
#include <math.h>

/**
 * Desarranjo
 * Autor:
 *    Fabio Emilio Costa
 * Tipo:
 *    math
 * Descrição:
 *    Algoritmo que calcula permutação caótica. Baseado na versao Python
 * Dificuldade:
 *    facil
 * Complexidade:
 *    ?
 * Referência:
 *    http://pt.wikipedia.org/wiki/Desarranjo
 * Licenca: GPL
 */

float fatorial (float a)
{
  return a<=1?1:a*fatorial(a-1);
}

int main (void)
{
  float n=5,x;
  float d=0;
  for (x=0;x<n;x++)
      d=d+(pow(-1,x)/fatorial(x));
  printf("%10.0f\n",fatorial(n)*d);
  return(0);
}
