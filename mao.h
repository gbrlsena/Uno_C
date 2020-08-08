#ifndef MAO_H
#define MAO_H
#include "baralho.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

void gotoxy(int x, int y) // Função para gerar coordenadas (Pura estética do menu e creditos)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
  
}
struct lista {  // Criação da Lista em struct (lista simplesmente encadeada)
 carta c;
 struct lista* prox;
};
typedef struct lista Lista;

Lista* inicializa (void){  //Iniciar a lista, trazendo as "cartas" do baralho para a mão (Já que a lista representa a mão)
 return NULL;
}

Lista* insere (Lista* l, carta c){ // Ação de inserir a carta na lista "Mão"
 Lista* novo = (Lista*) malloc(sizeof(Lista));
 novo->c = c;
 novo->prox = l;
 return novo;
}

int vazia (Lista* l) {  // Ação de verificar se a lista Mão está vazia ou não (Se não tem cartas na mão, ele vence a partida).
 if (l == NULL) {
 return 1;
 }else
 return 0;
}


void imprime (Lista* l) { // Ação de imprimir a lista, ou no caso do uno, mostrar a mão do jogador
 Lista* p; 
 for (p = l; p != NULL; p = p->prox) {
 		if (p->c.numero == 66) {
        	printf("Cor = %d Numero = Block  \n",p->c.cor); // Caso da carta especial Bloqueio
		}
		if (p->c.numero == 82) {
        	printf("Cor = %d Numero = Reverse \n",p->c.cor); // Caso da carta especial de Reverter
		}
		if (p->c.numero == 77) {
        	printf("Cor = %d Numero = Mais 4 \n",p->c.cor); // Caso da carta especial para cavar quatro cartas (e trocar a cor)
		}
		if (p->c.numero == 43) {
        	printf("Cor = %d Numero = +2 \n",p->c.cor);    // Caso da carta especial para cavar duas cartas
		}
		if (p->c.numero == 84) {
        	printf("Cor = %d Numero = Troca de cor \n",p->c.cor);  // Caso da carta especial coringa (trocar a cor)
		}
		if (p->c.numero < 10) {
        	printf("Cor = %d Numero = %d \n",p->c.cor, p->c.numero); // Caso das cartas normais
		}
		} 
}
/*
bool busca_l (Lista* l, int cor , char num) { // Ação de buscar uma informação específica, no caso do uno, verificar se o jogador possui a carta que jogou
////////// Essa função foi criada mais não consegiumos implementar no jogo 
	Lista* p;
	p = l;
	int nume = num;
	if ( nume > 47 ){
	if ( nume <= 57) {
	nume = nume - 48;	
		}
	}
	while((p!=NULL) && (p->c.cor!=cor)) { // Verificar a cor da carta
		p=p->prox;
	}
	
	while((p!=NULL) && (p->c.numero!=nume)) { // Verificar o numero da carta
		p=p->prox;
	}
	if (p==NULL){
	return false;
	} 
	
	if(p->c.cor == cor && p->c.numero == nume ){ // Se as duas tiverem certas, a carta é lançada na mesa
	return true;
}
}
*/
int tamanho(Lista* l, int id) { // Contar e mostar em tela quantas cartas tem a lista
    int cont=0;
    
    Lista* p;
    p = l;
    
    while (p!=NULL) {
        cont++;
        p=p->prox;
    }
	printf("Numero de cartas: %d\n\n", cont);
	
	if ( cont == 0 ){ // Se não tiver nenhuma carta na mão ( no caso lista ), o jogador ganha 
		system("cls");
		gotoxy(65,22);
		printf("UNO!!\n");
		gotoxy(65,23);
		printf("Jogador %d Ganhou!!\n\n",id); // O id é para mostar em tela qual dos dois ganhou
		exit(0); // Fecha o jogo
	}
	return cont;
}

Lista* acao(tp_pilha *baralho,Lista *jogador,int numero){ // Se o numero for 43 ou 77 ele entra na função das cartas "+2" e "+4"
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
	if ( cor == 4 || num == 84 || num == 77){ //Função para jogar a carta de cor "4" 
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

 while (p != NULL && (p->c.numero != c.numero)  ) {	// Verificar a cor 
 ant = p;
 p = p->prox;
}


while (p != NULL && (p->c.cor != c.cor ) ) { // Verificar o numero		  
 ant = p;
 p = p->prox;
}


		pop(mesa,&c); // Tira a carta da mesa para verificar 
	if(p->c.cor != c.cor && p->c.numero != c.numero ){  //Caso esteja errada, ele recebe essa frase e perde a vez
		push(mesa,c); // Se tiver errado ela pega a carta de volta
		printf("Nao tente roubar jogue somente a carta certa!\n\n");
		pop(baralho,&c);
		jogador = insere(jogador,c);
		Sleep(3000);
	 return jogador;
	
	} else { // Se estiver certo 
	c.cor = cor; 	// A carta é inseirda da pilha
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


Lista* criar_mao(tp_pilha *baralho, Lista *jogador) { // Função que cria a mão dos jogadores (tira a carta do baralho e coloca na mão) [tira o elemento da pilha e coloca na lista]
	carta c;
	jogador = inicializa(); 
		
	for (int i = 0 ; i < 7 ; i++) {
		pop(baralho,&c);
		jogador = insere(jogador,c);
	}	
	
	return jogador;
}



#endif
