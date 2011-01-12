#|
Calculo de juros compostos
Autor:
    ?
Colaborador:
    Daniel Valio <valium97@mail.com>
Tipo:
    economics
Descricao:
    Varias formas de se calcular varias modalidades de
    juros compostos.
Complexidade:
    O(1)
Dificulade:
    Facil
|#

;;;; Nota: os juros sao colocados em fracoes decimais,
;;;; e nao porcentagens.

(defun juros-compostos-continuos (capital juros tempo)
  "A funcao JUROS-COMPOSTOS-CONTINUOS calcula o retorno de um emprestimo
  a juros continuos."
  (* capital (exp (* juros tempo))))
