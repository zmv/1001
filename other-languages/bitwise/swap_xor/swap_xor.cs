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

using System;

public sealed class SwapXor {

	public static void swap(ref int a, ref int b) {
	
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	
	public static void Main() {
	
		int var1 = 1234;
		int var2 = 5678;
		
		Console.WriteLine("Valores antes da troca: var1 = {0} var2 = {1}", var1, var2);
		SwapXor.swap(ref var1, ref var2);
		Console.WriteLine("Valores depois da troca: var1 = {0} var2 = {1}", var1, var2);
	}
}