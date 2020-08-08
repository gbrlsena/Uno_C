#ifndef MAO_H
#define MAO_H
#include "baralho.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  
}
struct lista {
 carta c;
 struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa (void){
 return NULL;
}

Lista* insere (Lista* l, carta c){
 Lista* novo = (Lista*) malloc(sizeof(Lista));
 novo->c = c;
 novo->prox = l;
 return novo;
}

int vazia (Lista* l) {
 if (l == NULL) {
 return 1;
 }else
 return 0;
}


void imprime (Lista* l) {
 Lista* p; 
 for (p = l; p != NULL; p = p->prox) {
 		if (p->c.numero == 66) {
        	printf("Cor = %d Numero = Block  \n",p->c.cor);
		}
		if (p->c.numero == 82) {
        	printf("Cor = %d Numero = Reverse \n",p->c.cor);
		}
		if (p->c.numero == 77) {
        	printf("Cor = %d Numero = Mais 4 \n",p->c.cor);
		}
		if (p->c.numero == 43) {
        	printf("Cor = %d Numero = +2 \n",p->c.cor);
		}
		if (p->c.numero == 84) {
        	printf("Cor = %d Numero = Troca de cor \n",p->c.cor);
		}
		if (p->c.numero < 10) {
        	printf("Cor = %d Numero = %d \n",p->c.cor, p->c.numero);
		}
		} 
}

bool busca_l (Lista* l, int cor , char num) {
	Lista* p;
	p = l;
	int nume = num;
	if ( nume > 47 ){
	if ( nume <= 57) {
	nume = nume - 48;	
		}
	}
	while((p!=NULL) && (p->c.cor!=cor)) {
		p=p->prox;
	}
	
	while((p!=NULL) && (p->c.numero!=nume)) {
		p=p->prox;
	}
	if (p==NULL){
	return false;
	} 
	
	if(p->c.cor == cor && p->c.numero == nume ){
	return true;
}
}


int tamanho(Lista* l, int id) {
    int cont=0;
    
    Lista* p;
    p = l;
    
    while (p!=NULL) {
        cont++;
        p=p->prox;
    }
	printf("Numero de cartas: %d\n\n", cont);
	
	if ( cont == 0 ){
		system("cls");
		gotoxy(65,22);
		printf("UNO!!\n");
		gotoxy(65,23);
		printf("Jogador %d Ganhou!!\n\n",id);
		exit(0);
	}
	return cont;
}

Lista* acao(tp_pilha *baralho,Lista *jogador,int numero){
	carta c;
	if (numero == 43){
	for (int i = 0 ; i < 2 ; i++){
	pop(baralho,&c);
	jogador = insere(jogador ,c);
		}
	}
	
	if (numero == 77){
	for (int i = 0 ; i < 4 ; i++){
	pop(baralho,&c);
	jogador = insere(jogador ,c);
		}
	}
	
	return jogador; 
}

Lista* retiracarta (Lista* jogador, carta c, tp_pilha *mesa, tp_pilha *baralho,int cor, int num) {

 Lista* ant = NULL;
 Lista* p = jogador; 
/*
	if ( cor == 4 || num == 84 || num == 77){
 		pop(mesa,&c);
 		do {
 		 printf("Mudar para qual cor?: ");
 		 scanf("%d", &cor); 
		 } while ( cor > 3);
		 c.cor = cor; 	
 		 c.numero = num;
		 push(mesa,c);
		 system ("cls");
		 if (p == NULL)
 	return jogador; 
 	if (ant == NULL) {
 	jogador = p->prox;
 	}
 	else {
 	ant->prox = p->prox;
 	}
 	free(p);
 	return jogador;
 	
} else {
*/

 while (p != NULL && (p->c.numero != c.numero)  ) {	
 ant = p;
 p = p->prox;
}


while (p != NULL && (p->c.cor != c.cor ) ) {		 
 ant = p;
 p = p->prox;
}


		pop(mesa,&c);
	if(p->c.cor != c.cor && p->c.numero != c.numero ){
		push(mesa,c);
		printf("Nao tente roubar jogue somente a carta certa!\n\n");
		pop(baralho,&c);
		jogador = insere(jogador,c);
		Sleep(3000);
	 return jogador;
	
	} else {
	c.cor = cor;	
	c.numero = num;
	push(mesa,c); 
	
 // verifica se achou elemento 
 if (p == NULL)
 return jogador; // não achou: retorna lista original 
 // retira elemento 
 if (ant == NULL) {
 // retira elemento do inicio 
 jogador = p->prox;
 }
 else {
 // retira elemento do meio da lista 
 ant->prox = p->prox;
 }
 free(p);
 return jogador;
}
}
//}


Lista* criar_mao(tp_pilha *baralho, Lista *jogador) {
	carta c;
	jogador = inicializa(); 
		
	for (int i = 0 ; i < 7 ; i++) {
		pop(baralho,&c);
		jogador = insere(jogador,c);
	}	
	
	return jogador;
}



#endif
