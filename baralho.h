#ifndef BARALHO_H
#define BARALHO_H
#define MAX 108
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct {
    int numero;
    int cor;
} carta;

typedef struct {
    int topo;
    carta c[MAX];
} tp_pilha;

void inicializa_pilha(tp_pilha *p){
    p->topo = -1;
}

int pilha_vazia(tp_pilha *p){
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int pilha_cheia(tp_pilha *p){
    if(p->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int push(tp_pilha *p, carta c){
    if(pilha_cheia(p)){
        return 0;
    }else{
        p->topo++;
        p->c[p->topo] = c;
        return 1;
    }
}

int pop(tp_pilha *p, carta *c){
    if(pilha_vazia(p)){
        return 0;
    }else{
        *c = p->c[p->topo];
        p->topo--;
        return 1;
    }
}

int altura_pilha(tp_pilha *p){
	printf("%d", p->topo+1);
    return p->topo+1;
}

void carta_mesa (tp_pilha *mesa, tp_pilha *baralho){
	inicializa_pilha(mesa);
	carta c;
	pop(baralho,&c);
	push(mesa,c);
}

void imprime_pilha(tp_pilha p){
    carta c;
    printf("\n");
    while(!pilha_vazia(&p)){
        pop(&p,&c);
        if (c.numero == 66) {
        	printf("Cor = %d Numero = Block  \n",c.cor);
		}
		if (c.numero == 82) {
        	printf("Cor = %d Numero = Reverse \n",c.cor);
		}
		if (c.numero == 77) {
        	printf("Cor = %d Numero = Mais 4 \n",c.cor);
		}
		if (c.numero == 43) {
        	printf("Cor = %d Numero = +2 \n",c.cor);
		}
		if (c.numero == 84 ){
        	printf("Cor = %d Numero = Troca de cor \n",c.cor);
		}
		if (c.numero < 10) {
        	printf("Cor = %d Numero = %d \n",c.cor, c.numero);
		}
		} 
        //printf("Cor = %d Numero = %d\n",c.cor,c.numero);
    }
                     
bool Existe ( int valores[] , int tam , int valor ){
	for ( int i = 0 ; i < tam ; i++){
		if(valores[i] == valor )
		return true;	
	}	
	return false;
}	
	
void GerarNumerosAmarelo (int numerosAmarelo[], int quantNumeros , int limiteAmarelo ){
		
		
		int vAmarelo;
		for ( int z = 0 ; z < quantNumeros ; z++){
			vAmarelo = rand() % limiteAmarelo;
			//printf("%d ", vAmarelo);
			while (Existe(numerosAmarelo,z,vAmarelo)) {
				vAmarelo = rand() % limiteAmarelo;
			}
			if ( vAmarelo != 10) {
			numerosAmarelo[z] = vAmarelo;
		} else {
			z--;
	}
	}
}

void GerarNumerosAzul (int numerosAzul[], int quantNumeros , int limiteAzul ){
		
		
		int vAzul;
		for ( int x = 0 ; x < quantNumeros ; x++){
			vAzul = rand() % limiteAzul;
		//	printf("%d ", vAzul);
			while (Existe(numerosAzul,x,vAzul)) {
				vAzul = rand() % limiteAzul;
			}
			if ( vAzul != 10) {
			numerosAzul[x] = vAzul;
			
		} else {
			x--;
		}
	}
}

void GerarNumerosVermelho (int numerosVermelho[], int quantNumeros , int limiteVermelho ){
		
		
		int vVermelho;
		for ( int c = 0 ; c < quantNumeros ; c++){
			vVermelho = rand() % limiteVermelho;
		//	printf("%d ", vVermelho);
			while (Existe(numerosVermelho,c,vVermelho)) {
				vVermelho = rand() % limiteVermelho;
			}
			if ( vVermelho != 10) {
			numerosVermelho[c] = vVermelho;
			
		} else {
			c--;
		}
	}
}

void GerarNumerosVerde (int numerosVerde[], int quantNumeros , int limiteVerde ){
		
		
		int vVerde;
		for ( int i = 0 ; i < quantNumeros ; i++){
			vVerde = rand() % limiteVerde;
		//	printf("%d ", vVerde);
			while (Existe(numerosVerde,i,vVerde)) {
				vVerde = rand() % limiteVerde;
			}
			if ( vVerde != 10) {
			numerosVerde[i] = vVerde;
			
		} else {
			i--;
		}
	}
}

int criar_baralho (tp_pilha *baralho) {
	carta c;
	tp_pilha amarelo, azul, vermelho, verde, preto,especiais;
	inicializa_pilha(&amarelo);
	inicializa_pilha(&azul);
	inicializa_pilha(&vermelho);
	inicializa_pilha(&verde);
	inicializa_pilha(&preto);
	inicializa_pilha(&especiais);
	inicializa_pilha(baralho);
//	char lista[5][19] = {"Yellow", "Blue", "Red", "Green", "Black"};
	
	srand(time(NULL));
///////////////////////////////////////////////////////// Amarelo
	for ( int w = 0 ; w < 2 ; w++){
		c.cor =0;
		c.numero = 66; 
		push(&especiais, c);
}
	for ( int w = 0 ; w < 2 ; w++){
		c.cor = 0; 
		c.numero = 82;
		push(&especiais, c);
}
		int numerosAmarelo[19];
		GerarNumerosAmarelo(numerosAmarelo , 19 , 20);
		c.cor = 0;
		for ( int i = 0 ; i < 19 ; i++){
			
			if ( numerosAmarelo[i] > 10){
				numerosAmarelo[i] = numerosAmarelo[i] - 10;
			//	printf("%d  ", numerosAmarelo[i]);
				c.numero = numerosAmarelo[i];
				push(&amarelo, c);
			} else {
	
		c.numero = numerosAmarelo[i];
		push(&amarelo, c); }
	}
		for ( int w = 0 ; w < 2 ; w++){
		c.cor = 0;
		c.numero = 43; 
		push(&especiais, c);
}
///////////////////////////////////////////////////////// Azul
		for ( int w = 0 ; w < 2 ; w++){
		c.cor = 1;
		c.numero = 43;
		push(&especiais, c);
}
		int numerosAzul[19];
	 	GerarNumerosAzul(numerosAzul , 19 , 20);
		c.cor = 1;
		for ( int i = 0 ; i < 19 ; i++){
			if ( numerosAzul[i] > 10){
		numerosAzul[i] = numerosAzul[i] - 10;	
		c.numero = numerosAzul[i];
		push(&azul, c);
			} else {
	
		c.numero = numerosAzul[i];
		push(&azul, c); }
	}

		for ( int w = 0 ; w < 2 ; w++){
		c.cor = 1;
		c.numero = 66;
		push(&especiais, c);
}
	for ( int w = 0 ; w < 2 ; w++){
		c.cor = 1;
		c.numero = 82;
		push(&especiais, c);
}
///////////////////////////////////////////////////////// Vermelho
		for ( int w = 0 ; w < 2 ; w++){
		c.cor = 2;
		c.numero = 66;
		push(&especiais, c);
}
	for ( int w = 0 ; w < 2 ; w++){
		c.cor = 2;
		c.numero = 82;
		push(&especiais, c);
}
	int numerosVermelho[19];
		GerarNumerosVermelho(numerosVermelho , 19 , 20);
		c.cor = 2;
		for ( int i = 0 ; i < 19 ; i++){
			if ( numerosVermelho[i] > 10){
		numerosVermelho[i] = numerosVermelho[i] - 10;	
		c.numero = numerosVermelho[i];
		push(&vermelho, c);
			} else {
		c.numero = numerosVermelho[i];
		push(&vermelho, c); }
	}
		for ( int w = 0 ; w < 2 ; w++){
		c.cor = 2;
		c.numero = 43;
		push(&especiais, c);
}
	
///////////////////////////////////////////////////////// Verde
		for ( int w = 0 ; w < 2 ; w++){
		c.cor = 3;
		c.numero = 43;
		push(&especiais, c);
}

	int numerosVerde[19];
		GerarNumerosVerde(numerosVerde , 19 , 20);
		c.cor = 3;
		for ( int i = 0 ; i < 19 ; i++){
			if ( numerosVerde[i] > 10){
		numerosVerde[i] = numerosVerde[i] - 10;	
		c.numero = numerosVerde[i];
		push(&verde, c);
			} else {
		c.numero = numerosVerde[i];
		push(&verde, c); }
	}
		for ( int w = 0 ; w < 2 ; w++){
		c.cor = 3;
		c.numero = 66;
		push(&especiais, c);
}
	for ( int w = 0 ; w < 2 ; w++){
		c.cor = 3;
		c.numero = 82;
		push(&especiais, c);
}
///////////////////////////////////////////////////////// Preto
	int contW = 4;
    int contM = 4;
    int auxp = 0;
	for(int m=0 ; m<8 ; m++){
        auxp = rand()%2;
       //  printf("%d - %d - %d  ///   ", auxp, contW , contM);
    if(auxp == 0){
    	if(contW > 0  ){
        	c.cor = 4;
        	c.numero = 84; 
            push(&preto,c);
            contW--;
        }
		else { 
		m--;	 
	}
}	
	else
			
	if(auxp == 1){
    	if(contM > 0){
        	c.cor = 4;
        	c.numero = 77;  
            push(&preto,c);
            contM--;
    		} 	
	else { 
		m--;	 
	}
	}
				
}
//imprime_pilha(especiais); 
/////////////////////////////////////////////////Printar as pilhas até aqui

/*
imprime_pilha(amarelo); 
imprime_pilha(vermelho);
imprime_pilha(azul);
imprime_pilha(verde);
imprime_pilha(especiais); 
imprime_pilha(preto);


printf("\n\n");
altura_pilha(&amarelo);
printf("\n\n");
altura_pilha(&azul);
printf("\n\n");
altura_pilha(&vermelho);
printf("\n\n");
altura_pilha(&verde);
printf("\n\n");
altura_pilha(&preto);
printf("\n\n");

*/
///////////////////////////////////////////Inserir a carta na pilha do Baralho
srand(time(NULL));
int aux = 0;
    for(int i=0 ; i<108;i++){
    aux = rand()%6;
   // printf("%d ", aux);
    if(aux == 0){
    	if(!pilha_vazia(&vermelho)){
        	pop(&vermelho,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
			else
			
	if(aux == 1){
    	if(!pilha_vazia(&azul)){
        	pop(&azul,&c);
            push(baralho,c);
    	}
		else { 
		i--;
		}
}
			else
			
    if(aux == 2){
        if(!pilha_vazia(&amarelo)){
        	pop(&amarelo,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
			else
            
	if(aux == 3){
    	if(!pilha_vazia(&verde)){
        	pop(&verde,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}

	if(aux == 4){
    	if(!pilha_vazia(&preto)){
        	pop(&preto,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
	if(aux == 5){
    	if(!pilha_vazia(&especiais)){
        	pop(&especiais,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
}
  

}

#endif
