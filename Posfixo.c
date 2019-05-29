#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Posfixo.h"

/* Inicializa a pilha */
void iniciaPilha(PILHA *pilha){
	pilha->topo = -1; /* Inicia vazia */
}

/* Pega a expressão infixa */
void pega_infixo(char infixo[]){
	int i;
	printf("Digite a expressao infixa: ");
	fflush(stdin); /*Captura a entrada*/
/* Lendo os caracteres */
	for ( i=0; i<18; ){
	    if ((infixo[i]=getchar())=='\n'){ //Se no final, sai
		i++;
		break;
	    }else if (!(isspace(infixo[i]))) //Se não é espaço, continua
	           i++;
	}
	infixo[i] = '\0';
}

/* Converte de infixo para posfixo */
void converteParaPosfixo(char infixo[], char posfixo[]){
	int i, tamanho;
	int j=0;
	char topo_ch;
	PILHA pilha;

	iniciaPilha(&pilha); /* Inicializa a pilha */
	pega_infixo(infixo); /* Chama a funão que captura os caracteres */
	tamanho = strlen(infixo);

/* Se o tamanho for maior que zero */
	if (tamanho){
	    colocaNaPilha(&pilha,'(');
	    strcat(infixo,")"); //Concatena
	    tamanho++;

	    for (i=0;i<tamanho;i++){
/* Se é dígito */
		if (isdigit(infixo[i]) || isalpha(infixo[i])){
		    posfixo[j++] = infixo[i];
		}
/* Se é parêntese esquerdo */
		else if (infixo[i]=='('){
		    colocaNaPilha(&pilha,'(');
		}
/* Se é operador */
		else if (eOperador(infixo[i])){
		    while (VERDADEIRO){
/* Pega o Topo */
			topo_ch = topoDaPilha(&pilha);

/* Critica */
			if (topo_ch=='\0'){
			    printf("\nExpressao invalida\n");
			    exit(1);
			}else{
			     if (eOperador(topo_ch)){
				if (precedenciaNivel(topo_ch)>=precedenciaNivel(infixo[i]))
				    posfixo[j++] = tiraDaPilha(&pilha);
				else
				    break;
			    }else
				break;
			}
		    }
		colocaNaPilha(&pilha, infixo[i]);
		}
/* Se é parêntese direito */
		else if (infixo[i]==')'){
		     while (VERDADEIRO){
/* Pega o topo */
			topo_ch=topoDaPilha(&pilha);

/* Critica */
			if (topo_ch=='\0'){
			     printf("\nExpressao invalida\n");
			     exit(1);
			}else{
			     if (topo_ch!='('){
			         posfixo[j++] = topo_ch;
			         tiraDaPilha(&pilha);
			     }else{
			          tiraDaPilha(&pilha);
				  break;
			     }
			}
		     }
		     continue;
		}
	    }
	}
	posfixo[j] = '\0';
}

/* Verifica qual é o operador */
int eOperador(char o){
	if (o=='+'||o=='-'||o=='*'||o=='/'||o=='%'||o=='^'){	
	    return VERDADEIRO;
	}else
	    return FALSO;
}

/* Veririca o nível de precedência */
int precedenciaNivel(char p){
	if (p=='+'||p=='-')
	    return 1;
	    else if (p=='^')
	        return 3;
	    else
                return 2;
}

/* Veririca se a precedência do Operador1 é Menor, Igual ou Maior que a precedência
do Operador2 */
int precedencia(char operador1, char operador2){
	if (precedenciaNivel(operador1)>precedenciaNivel(operador2))
	    return 1;
	    else if (precedenciaNivel(operador1)<precedenciaNivel(operador2) )
	        return -1;
	    else
		return 0;
}

/* Push */
void colocaNaPilha(PILHA *pilha, char valor){
	if (!(estaCheia(pilha))){ 
	    (pilha->topo)++;
	    pilha->dados[pilha->topo]=valor;
	}
}

/* Pop */
char tiraDaPilha(PILHA *pilha){
	char c;
	if (!(estaVazia(pilha))){ 
	    c = pilha->dados[pilha->topo];
	    (pilha->topo)--;
	    return c;
	}else
	    return '\0';
}

/* Retorna o topo da pilha sem retirar o elemento do topo */
char topoDaPilha(PILHA *pilha){
	if (!(estaVazia(pilha))) 
	    return pilha->dados[pilha->topo];
	else
	    return '\0';
}

/* Verifica se a pilha está vazia */
int estaVazia(PILHA *pilha){
	if (pilha->topo==-1)
	    return VERDADEIRO;
	else
    	    return FALSO;
}

/* Verifica se a pilha está cheia */
int estaCheia(PILHA *pilha){
	if (pilha->topo==19)
	    return VERDADEIRO;
	else
	    return FALSO;
}

/* Mostra o resultado da Notação Pos-fixa */
void imprimeResultado(char infixo[], char posfixo[]){
	printf("\n");
	printf("Notacao Pos-fixa: %s\n\n", posfixo);
}

	
