/*
Algoritimo de troca de vari�veis
Autor:
    ?
Colaborador:
    Jos� Ivan Bezerra Vilarouca Filho (ivanfilho2204@hotmail.com)
Tipo:
    bitwise
Descri��o:
    Algoritimo que tem objetivo de trocar os valores
	de duas vari�veis sem o uso de uma vari�vel tempor�ria
	usando apenas o operdador boolean "ou exclusivo".
	Lembrando que esse algor�timo s� funciona se as vari�veis
	tiverem em locais diferentes na mem�ria
Complexidade:
    O(1)
Dificuldade:
    f�cil
Refer�ncias:
	http://en.wikipedia.org/wiki/XOR_swap_algorithm
*/

#include <stdio.h>

void swap(int* a, int* b) {

	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

int main(int argc, char* argv[]) {

	int var1 = 22;
	int var2 = 4;
	printf("Valores antes da troca: var1=%d var2=%d\n", var1, var2);
	swap(&var1, &var2);
	printf("Valores depois da troca: var1=%d var2=%d\n", var1, var2);
	
	return 0;
}