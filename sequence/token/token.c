#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * Token
 * Autor:
 *    Fabio Emilio Costa <fabiocosta0305@gmail.com>
 * Tipo:
 *     sequence
 * Descriçãoo:
 *     Gera um token aleatorio
 * Complexidade:
 *     ?
 * Dificuldade:
 *     intermediario
*/

char *token(int tamanho)
{
  // Retorna um ponteiro nulo caso nao tenha sido possivel alocar memoria para o token
  char caracteres[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  char *meuToken=(char*)malloc(tamanho*sizeof(char)),*moveChar;
  int i;
  if (!meuToken)
    return meuToken;
  memset(meuToken,'\0',tamanho+1); // Limpando por seguranca
  moveChar=meuToken;
  for (i=0;i<tamanho;i++)
    {
      // subtracao por 1 no tamanho necessaria pois, caso contrario, intercepta e adiciona o caracter nulo
      *(moveChar++)=caracteres[rand()%(sizeof(caracteres)-1)]; 
    }
  return meuToken;
}

int main(void)
{
  srand(time(NULL)); // Regenerando a tabela de numeros aleatorios.
  printf("Token com tamanho 5 = %s\n",token(5));
  printf("Token com tamanho 10 = %s\n",token(10));
  printf("Token com tamanho 20 = %s\n",token(20));
  printf("Token com tamanho 50 = %s\n",token(50));
  printf("Token com tamanho 1000 = %s\n",token(1000));
  return(0);
}
