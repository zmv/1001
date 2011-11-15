<?php
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

function swap(&$a, &$b) {

	$a = $a ^ $b;
	$b = $a ^ $b;
	$a = $a ^ $b;
}

$var1 = 1991;
$var2 = 1989;

echo "Valores antes da troca: \$var1=$var1 \$var2=$var2<br />";
swap($var1, $var2);
echo "Valores despois da troca: \$var1=$var1 \$var2=$var2<br />";
?>