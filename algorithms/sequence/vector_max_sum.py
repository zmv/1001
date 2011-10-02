#!/usr/bin/env python
# -*- coding: UTF-8 -*-

"""
Máxima soma de um array.

Autor:
    ?
Colaborador:
    luizgpsantos (at) gmail (dot) com
Tipo:
    Sequence
Descrição:
    Calcula a maior soma de um subarray.
Complexidade:
    O(n)
Dificuldade:
    Médio
"""

def soma_maxima(vetor):
    maximo_parcial = 0
    maximo_local = 0

    for i in vetor:
        maximo_local = max(0, maximo_local + i)
        maximo_parcial = max(maximo_parcial, maximo_local)
    return maximo_parcial

print soma_maxima([3, 1, -4, 5, -3, 2, -3, -1, 3])
print soma_maxima([-3, 2, -1, 5, 1, -3, 1, 1, 1])
