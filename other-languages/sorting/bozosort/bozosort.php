<?php
	
/*
Bozosort (a.k.a Bogosort)
Autor: 
	Bozo
Colaborador:
    Maur�cio Sipmann (sipmann@gmail.com)
Tipo: 
	sorting
Descri��o: 
	Ordena um array a fim de ficar em ordem crescente.
Complexidade:
	O(infinito)
Dificuldade:
	facil
Refer�ncias:
	http://pt.wikipedia.org/wiki/Bogosort
*/

	function bogo($valores) {
		$ordenado = false;
		$certo = $valores;
		sort($certo);
		
		$i = 0;
		
		while(!$ordenado) {
			shuffle($valores);
			if( $valores == $certo) {
				$ordenado = true;
			}
			$i++;
			echo "Tentativa ".$i." <br>";
			print_r(($ordenado==true)? $valores: "");
		}
		
	}
	
	// Passando um array com valores a serem ordenados
	bogo(array(3,5,2,1));
	
?>
