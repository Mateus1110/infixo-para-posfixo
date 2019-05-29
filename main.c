#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Posfixo.h"

/* Função Principal */
int main(void){
	char infixo[20], posfixo[20]="";
/* Chama a função que converte de infixo para posfixo */
	converteParaPosfixo(infixo, posfixo);
	infixo[strlen(infixo)-2]='\0';
/* Imprime o resultado */
	imprimeResultado(infixo, posfixo);

return 0;
}
