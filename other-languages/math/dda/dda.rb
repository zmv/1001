# -*- encoding: utf-8 -*-

=begin
DDA (Digital Differential Analyzer)
Autor:
    ?
Colaborador:
	Bruno Lara Tavares <bruno.exz@gmail.com>
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
=end


def DDA(x1, y1, x2, y2)
	
	points = [] #Guardar� os pontos criados na forma (x, y)
	
	if ((x2 - x1).abs >= (y2 - y1).abs)
		
		len = (x2 - x1).abs
	else
		
		len = (y2 - y1).abs
	end
		
	deltax = (x2 - x1).to_f / len
	deltay = (y2 - y1).to_f / len
	x = x1.to_f
	y = y1.to_f
	
	(0..len).each do |i|
		points.push [x.floor, y.floor]
		x += deltax
		y += deltay
	end
	
	points.push [x.floor, y.floor]
end

	
puts DDA(-1, -1, 12, 9).inspect
