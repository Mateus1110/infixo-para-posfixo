/* Includes necessários */

/* Constantes */
#define VERDADEIRO 1
#define FALSO 0

/* Estrutura para a pilha */
typedef struct{
    char dados[20]; /* Matriz para armazenar as informações da pilha */
    int topo; /* Topo da pilha */
} PILHA;


/* Prototipação das funções */
void iniciaPilha(PILHA *pilha);
void pega_infixo(char infixo[]);
void converteParaPosfixo(char infixo[], char posfixo[]);
int eOperador(char c);
int precedencia(char operador1, char operador2);
int precedenciaNivel(char ch);
void colocaNaPilha(PILHA *pilha, char value);
char tiraDaPilha(PILHA *pilha);
char topoDaPilha(PILHA *pilha);
int estaVazia(PILHA *pilha);
int estaCheia(PILHA *pilha);
void imprimeResultado(char infixo[], char posfixo[]);
