/*
nums2words
Autor:
    ? 
Colaborador:
    Stanislaw Pusep 
Tipo:
    lang
Descri��o:
    Conversor de n�meros inteiros em strings de numerais cardinais em portugu�s.
    Exemplo:
        9223372036854775807 (maior inteiro positivo de 64 bits) => "nove quinqualh�es e duzentos e vinte e tr�s quatrilh�es e trezentos e setenta e dois trilh�es e trinta e seis bilh�es e oitocentos e cinq�enta e quatro milh�es e setecentos e setenta e cinco mil e oitocentos e sete"
Complexidade:
    ?
Dificuldade:
    medio
Refer�ncias: 
    [1] http://sysd.org/stas/node/20
    [2] http://pt.wikipedia.org/wiki/Nomes_dos_n%C3%BAmeros
    [3] http://pt.wikipedia.org/wiki/Escalas_curta_e_longa
*/

#include <malloc.h>
#include <stdio.h>
#include <string.h>

// tamanhos dos buffers
#define MAXRES_S		512
#define MAXTERN_S		64

// formato da estrutura da tabela de transi��o
typedef struct {
    unsigned int n;
    char *w;
} node;

/*
 * Expande blocos de milhares.
 * Os n�meros maiores do que mil s�o "quebrados" em ternas que depois recebem um multiplicador.
 */
char *ext999 (unsigned int n) {
    unsigned int i, x, y;
    char *buf;
    // mapeamento n�mero => nome
    node rel[] = {
        {900,	"novecentos"},	{800,	"oitocentos"},
        {700,	"setecentos"},	{600,	"seiscentos"},
        {500,	"quinhentos"},	{400,	"quatrocentos"},
        {300,	"trezentos"},	{200,	"duzentos"},
        {100,	"cento"},	    {90,	"noventa"},
        {80,	"oitenta"},	    {70,	"setenta"},
        {60,	"sessenta"},	{50,	"cinquenta"},
        {40,	"quarenta"},	{30,	"trinta"},
        {20,	"vinte"},	    {19,	"dezenove"},
        {18,	"dezoito"},	    {17,	"dezessete"},
        {16,	"dezesseis"},	{15,	"quinze"},
        {14,	"quatorze"},	{13,	"treze"},
        {12,	"doze"},	    {11,	"onze"},
        {10,	"dez"},		    {9,	    "nove"},
        {8,	    "oito"},	    {7,	    "sete"},
        {6,	    "seis"},	    {5,	    "cinco"},
        {4,	    "quatro"},	    {3,	    "tr�s"},
        {2,	    "dois"},	    {1,	    "um"},
    };

    buf = (char *) malloc(MAXTERN_S);
    buf[0] = '\0';

    // casos especiais
    if (!n) {
        strcpy(buf, "zero");
        return buf;
    } else if (n == 100) {
        strcpy(buf, "cem");
        return buf;
    }

    // faz a redu��o do n�mero fatorando pelos �ndices do mapeamento
    while (n) {
        for (i = 0; i < sizeof(rel); i++) {
            x = rel[i].n;
            y = n % x;
            if (x + y == n) {
                n = y;
                strcat(buf, rel[i].w);
                if (n)
                    strcat(buf, " e ");
                break;
            }
        }
    }

    return buf;
}

char *nums2words (long n) {
    unsigned long x;
    unsigned int y;

    int i, j, k;
    char *res, *p;

    // mapeamento dos multiplicadores para inteiros 'signed' de 64 bits
    char *ord[] = {
        NULL,		    NULL,
        "mil",		    "mil",
        "milh�o",  	    "milh�es",
        "bilh�o",	    "bilh�es",
    	"trilh�o",	    "trilh�es",
       	"quatrilh�o",	"quatrilh�es",
        "quinqualh�o",  "quinqualh�es",
    };
    // array para armazenamento das ternas pr�-processadas
    unsigned int tern[(sizeof(ord) / sizeof(char *)) / 2];

    res = (char *) malloc(MAXRES_S);
    res[0] = '\0';

    // trata n�meros negativos
    if (n < 0) {
        n *= -1;
        strcat(res, "menos ");
    }

    if (n < 1000) {
        // n�meros menores do que mil: caso mais simples
        strcat(res, ext999(n));
    } else {
        // quebra o n�mero em ternas
        x = n;
        for (j = 0; x; j++) {
            y = x % 1000;
            x /= 1000;

            tern[j] = y;
        }

        // obt�m string para cada terna e concatenta no resultado
        for (i = j - 1; i >= 0; i--) {
            if (y = tern[i]) {
                // concatena a respectiva terna
                p = ext999(y);
                strcat(res, p);
                free(p);

                // trata singular ou plural do multiplicador
                k = i * 2;
                if (y != 1)
                    k++;

                // concatena o multiplicador
                if (p = ord[k]) {
                    strcat(res, " ");
                    strcat(res, p);
                }

                // nem sempre o 'e' � necess�rio; por�m desconhe�o a regra correta :(
                strcat(res, " e ");
            }
        }
        res[strlen(res) - 3] = '\0';
    }

    return res;
}


int main (void) {
    long n;
    char *p;

    do {
        printf("Digite um n�mero (0 para sair): ");
        scanf("%ld", &n);
        fflush(stdin);

        p = nums2words(n);
        printf("voc� digitou \"%s\"\n", p);
        free(p);
    } while (n);

    return 0;
}
