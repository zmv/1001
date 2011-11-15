# coding: utf-8
"""
Número do zeros a direita do fatorial.
Autor: 
    ?
Colaborador:
    Luiz Guilherme P. Santos | luizgpsantos (at) gmail (dot) com
Tipo:
    math
Descrição: 
    Calcula o número de zeros a direita de um fatorial. Os zeros a direita são
    resultado do par 5 e 2, pelo fato de 5 * 2 = 10. Para contar os pares basta
    contar o número de múltiplos de 5. Enquanto 5 contribui uma vez, 25 
    contribui 2 vezes (25 = 5 * 5).
Complexidade de tempo: 
    O(n)
Dificuldade: 
    médio
"""
def numero_zeros_direita(numero):
    contador = 0
    if(numero < 0):
        print "Fatorial não é definido para números negativos."
        return

    i = 5
    while(numero / i > 0):
        contador = contador + (numero / i)
        i = i * 5
    return contador

print "Número de zeros a direita do fatorial de -10: ", numero_zeros_direita(-10)
print "Número de zeros a direita do fatorial de 26: ", numero_zeros_direita(26)
print "Número de zeros a direita do fatorial de 30: ", numero_zeros_direita(30)
print "Número de zeros a direita do fatorial de 35: ", numero_zeros_direita(35)
print "Número de zeros a direita do fatorial de 40: ", numero_zeros_direita(40)
