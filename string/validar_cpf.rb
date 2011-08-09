#encoding: utf-8

=begin
 Validador de CPF
Autor:
    Tiago Carvalho
Colaborador:
    ticarvalhocosta@gmail.com
Tipo:
    string operations
Descrição:
    Este algoritmo recebe um cpf como string e diz se o cpf é valido ou não
Complexidade:
    O(n)
Dificuldade:
    medio
=end

class Cpf
    def initialize(cpf_numero)
      @cpf_numero = cpf_numero
    end

    def processar
      dgtos_iniciais, dgtos_verificadores = @cpf_numero.split('-')
      dgtos_iniciais = dgtos_iniciais.gsub('.','')

      digito_um = calcular_primeiro_digito(dgtos_iniciais, dgtos_verificadores)
      digito_dois = calcular_segundo_digito(dgtos_iniciais, dgtos_verificadores, digito_um)

      if digito_um == dgtos_verificadores[0].to_i and digito_dois == dgtos_verificadores[1].to_i
        puts "O cpf #{@cpf_numero} é Válido !!"
      else
        puts "O cpf #{@cpf_numero} não é Valido !!"
      end
    end

    def calcular_primeiro_digito (dgtos_iniciais, dgtos_verificadores)
      multiplicador = 2
      soma = 0

      dgtos_iniciais.reverse.each_char do |c|
        soma += c.to_i*multiplicador
        multiplicador += 1
      end
     return 0 if (soma % 11) < 2
     return (11 - (soma % 11)) if (soma % 11) >= 2
    end

    def calcular_segundo_digito (dgtos_iniciais, dgtos_verificadores, digito_um)
      multiplicador = 2
      soma = 0
      dgtos_iniciais << digito_um.to_s

      dgtos_iniciais.reverse.each_char do |c|
        soma += c.to_i*multiplicador
        multiplicador += 1
      end
      return 0 if (soma % 11) < 2
      return (11 - (soma % 11)) if (soma % 11) >= 2
   end
end

#cpf = Cpf.new('222.333.444-15')
#cpf.processar

