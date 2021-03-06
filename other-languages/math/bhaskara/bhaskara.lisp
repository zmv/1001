#|
Formula de Bhaskara 
Autor:
    Bhaskara Akaria
Colaborador:
    Daniel Valio
Tipo:
    math
Descricao:
    Calcula as raizes de uma equacao de segundo grau 
Complexidade:
    O(1)
Dificuldade:
    facil
|#

(defun delta-calc (a b c)
  "A funcao DELTA-CALC calcula o delta de uma equacao."
  (- (expt b 2) (* a c 4)))
(defun achar-raizes (a b delta)
  "A funcao ACHAR-RAIZES acha as raizes de uma equacao."
  (list (/ (- delta b) (* a 2))
	      (/ (- (+ delta b)) (* a 2))))
(defun bhaskara (a b c)
  "A funcao BHASKARA e' um \"frontend\" para as funcoes DELTA-CALC
  e ACHAR-RAIZES."
  (unless (< (delta-calc a b c) 0)
    (achar-raizes a b (delta-calc a b c))))
