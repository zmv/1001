/*
Torre de Hanói
Autor:
    ?
Colaborador:
    Ramon Caldeira (ramoncaldeira_328@hotmail.com)
Tipo:
    ?
Descrição:
    O algoritmo resolve recursivamente o
    puzzle Torre de Hanói para n discos.
Complexidade:  
    ?
Dificuldade:
    médio
*/

#include <iostream>

const char* pino[3] = {
      "pino inicial", 
      "pino auxiliar", 
      "pino destino"
};

/*
  @param nDiscos => número de discos que a torre inicialmente contém
  @param pInicial => pino onde se colocam os discos inicialmente
  @param pAuxiliar => pino usado momentâneamente para trocar os discos de pino
  @param pDestino =>  pino aonde os discos terminam
  
  a idéia é basicamente resolver a torre para menos discos usando o pino
  auxiliar como destino e resolvê-la novamente.
  
  o caso base: resolver a torre com um disco  
*/
void hanoi(int nDiscos, int pInicial = 0, 
     int pAuxiliar = 1, int pDestino = 2) 
{
   if(!nDiscos) return;
   
   hanoi(nDiscos - 1, pInicial, pDestino, pAuxiliar);
   std::cout << "move disco do " << pino[pInicial]
             << " ao " << pino[pDestino] << std::endl;
   hanoi(nDiscos - 1, pAuxiliar, pInicial, pDestino);
}

/* rotina de teste */
int main() {
   int discos = 3;
   hanoi(discos);
   
   std::cin.get();
   return EXIT_SUCCESS;
}
