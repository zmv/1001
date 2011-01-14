'''
DDA (Digital Differential Analyzer)
Autor:
    ?
Colaborador:
    Jos� Ivan Bezerra Vilarouca Filho (ivanfilho2204@hotmail.com)
Tipo:
	math
Descri��o:
    DDA � um algoritmo de interpola��o linear entre dois pontos, inicial e final.
	Ele � muito usado na �rea de Computa��o Gr�fica para rasterizar linhas e pol�gonos.
Complexidade:  
    O(n)
Dificuldade:
    facil
Refer�ncias:
    http://www.dca.fee.unicamp.br/courses/IA725/1s2006/notes/n4.pdf
	http://en.wikipedia.org/wiki/Digital_Differential_Analyzer_(graphics_algorithm)
'''

import math

def DDA(x1, y1, x2, y2):
	
	points = [] #Guardar� os pontos criados na forma (x, y)
	
	if (math.fabs(x2 - x1) >= math.fabs(y2 - y1)):
		
		len = math.fabs(x2 - x1)
	else:
		
		len = math.fabs(y2 - y1)
	
	deltax = (x2 - x1) / len
	deltay = (y2 - y1) / len
	x = x1 + math.copysign(0.5, deltax)
	y = y1 + math.copysign(0.5, deltay)
	
	for i in range(int(len)) :
	
		points.append((math.floor(x), math.floor(y)))
		x += deltax
		y += deltay
	
	points.append((math.floor(x), math.floor(y)))
	
	return points

if __name__ == "__main__" :
	
	print DDA(-1, -1, 12, 9)