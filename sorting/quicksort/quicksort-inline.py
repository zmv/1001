# coding: utf-8
"""
Quicksort
Autor:
    C.A.R. Hoare
Colaborador:
    Adriano Melo (adriano@adrianomelo.com)
Tipo:
    sorting
Descrição:
    Quicksort é um algorítmo de ordenação de vetores cuja estratégia é
    dividir para conquistar. Basicamente o algorítmo organiza os elementos
    dos vetores de forma que os menores estejam antes dos maiores.
    Esse passo é feito recursivamente até que a lista completa esteja ordenada.
Complexidade:  
    O(n log(n)) - Melhor caso e médio caso.
    O(n²) - Pior caso.
Dificuldade:
    facil
Referências: (opcional)
    http://pt.wikipedia.org/wiki/Quicksort
"""
from random import randint
def partition (array, inicio, fim):
	pivot = randint(inicio, fim)

	array[fim], array[pivot] = array[pivot], array[fim]

	indice = inicio
	for i in xrange(inicio, fim):
		if array[i] <= array[pivot]:
			array[indice], array[i] = array[i], array[indice]
			indice = indice + 1

	array[indice], array[fim] = array[fim], array[indice]

	return indice

def quicksort (array, inicio, fim):

	if fim > inicio:
		pivot_index = partition (array, inicio, fim)
		quicksort (array, inicio, pivot_index - 1)
		quicksort (array, pivot_index + 1, fim)

	return array

integers = [randint(-5000, 5000) for i in xrange(50)]
print quicksort (integers, 0, len(integers) - 1)

