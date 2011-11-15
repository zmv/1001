<?php
/*
Selection Sort
Autor: 
    ?
Colaborador:
    Maur�cio Sipmann (sipmann@gmail.com)
Tipo: 
    sorting
Descri��o: 
    � um algoritmo de ordena��o que consiste em pesquisar o menor elemento
    e colocar na primeira posi��o, o segundo menor e colocar na segunda 
    posi��o e assim sucessivamente, at� que a sequ�ncia esteja ordenada.
    � uma excelente escolha quando h� necessidade quando o custo de 
    escrita � alto, pois ele realiza em torno de 2n opera��es de escrita. [2]
Complexidade de tempo: 
    O(n�)
Dificuldade: 
    facil
Refer�ncias:
    [1] http://en.wikipedia.org/wiki/Selection_sort
    [2] http://en.wikipedia.org/wiki/Selection_sort#Comparison_to_other_sorting_algorithms
*/

function selection_sort($a) {
    
    for ($i = 0; $i < count($a)-1; $i++) {
        $min = $i;
		
        for ($j = $i + 1; $j < count($a); $j++)
            if ( $a[$j] < $a[$min] )
                $min = $j;
                
        $temp = $a[$i];
        $a[$i] = $a[$min];
        $a[$min] = $temp;
    }
	
	return $a;
}

$a = array(6, -2, 3, 5, 7, 4, 3);
$a = selection_sort($a);
    
for($i = 0; $i < 7; $i++)
	echo $a[$i] ."<br>";

?>