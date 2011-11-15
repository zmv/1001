/*
Media
Autor:
    ?
Colaborador:
    Guilherme Carlos (@guiessence)
Tipo:
    math
Descrição:
    Calcula a média de numeros inseridos pelo usuário
Complexidade:  
    0(1)
Dificuldade:
    facil
<<<<<<< HEAD
<<<<<<< HEAD
=======

>>>>>>> 9bb9c79831232255550163f21f9098b8060bfae3
=======
>>>>>>> 62710a111e226a41df12bb70083ba34062e6f92e
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    float media, num;
    int qtd, i, cont = 0;

    printf("Digite a quantidade de numeros:\n");
    scanf("%d", &qtd);

    for(i = 0; i < qtd; i++){
        printf("Digite um numero:\n");
        scanf("%f", &num);
        media = media + num;
        cont++;
    }

    media = media/cont;
    printf("Media: %.2f: \n",media);
}
