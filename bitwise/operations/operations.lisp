#|
Operacoes bitwise
Autor:
    ?
Colaborador:
    Daniel Valio <valium97@mail.com>
Tipo:
    bitwise
Descricao:
    Coletanea de algoritmos bitwise
Complexidade:
    O(1)
Dificuldade:
    Facil
|#

(defun my-oddp (n)
  "Determina se um numero e' impar."
  (= 1 (boole boole-and n 1)))

