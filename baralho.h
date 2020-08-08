#ifndef BARALHO_H
#define BARALHO_H
#define MAX 108
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

typedef struct { //criação da struct carta 
    int numero;
    int cor;
} carta;

typedef struct {  // cria o tipo tp_pilha
    int topo;
    carta c[MAX];
} tp_pilha;

void inicializa_pilha(tp_pilha *p){ // inicializa o tp_pilha
    p->topo = -1;
}

int pilha_vazia(tp_pilha *p){ // Verifica se a pilha está vazia
    if(p->topo == -1){
        return 1;
    }else{
        return 0;
    }
}

int pilha_cheia(tp_pilha *p){  // Verifica se a pilha está cheia
    if(p->topo == MAX-1){
        return 1;
    }else{
        return 0;
    }
}

int push(tp_pilha *p, carta c){ // Inserindo novo elemento no topo da pilha
    if(pilha_cheia(p)){
        return 0;
    }else{
        p->topo++;
        p->c[p->topo] = c;
        return 1;
    }
}

int pop(tp_pilha *p, carta *c){ // Removendo elemento do topo da pilha
    if(pilha_vazia(p)){
        return 0;
    }else{
        *c = p->c[p->topo];
        p->topo--;
        return 1;
    }
}

int altura_pilha(tp_pilha *p){ // Imprime quantas cartas tem e retorna essa quantidade
	printf("%d", p->topo+1);
    return p->topo+1;
}

void carta_mesa (tp_pilha *mesa, tp_pilha *baralho){ // Remove do baralho a carta e insere na mesa ( esta separado somente para organizção )
	inicializa_pilha(mesa);
	carta c;
	pop(baralho,&c);
	push(mesa,c);
}

void imprime_pilha(tp_pilha p){ // Imprime a pilha 
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
    }
                     
bool Existe ( int valores[] , int tam , int valor ){  // Verificar se a carta já foi inserida no baralho e retorna true ou false
	for ( int i = 0 ; i < tam ; i++){
		if(valores[i] == valor )
		return true;	
	}	
	return false;
}	
	
void GerarNumerosAmarelo (int numerosAmarelo[], int quantNumeros , int limiteAmarelo ){ // Função para gerar os numeros Amarelos
		
		
		int vAmarelo;
		for ( int z = 0 ; z < quantNumeros ; z++){ // Passa no for 19 vezes ( que é a quantNumeros )
			vAmarelo = rand() % limiteAmarelo; // Gera numeros aleatorios entre 0 e 19
			//printf("%d ", vAmarelo);
			while (Existe(numerosAmarelo,z,vAmarelo)) { // Verfica se a carta ja existe 
				vAmarelo = rand() % limiteAmarelo;
			}
			if ( vAmarelo != 10) { // Se a carta for diferente de 10 ela é inserida 
			numerosAmarelo[z] = vAmarelo;
		} else {
			z--; // Se for igual a 10 ele n entra 
	}
	}
}

// A função ira gerar numeros entre 0 e 19, menos a carta 10 e o porque disso é explicado na main 

void GerarNumerosAzul (int numerosAzul[], int quantNumeros , int limiteAzul ){ // A mesma coisa é aplicada para todas as cores, foi colocado 4 vezes, 
                                                                              // pois assim as caras são geradas mais aleatorias e não fica parecido
		
		
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

int criar_baralho (tp_pilha *baralho) { // Funcao para criar o baralho
	carta c;
	tp_pilha amarelo, azul, vermelho, verde, preto,especiais; // cria as pilhas de cores 
	//// Inicializa as pilhas de cor ///// 
	inicializa_pilha(&amarelo);
	inicializa_pilha(&azul);
	inicializa_pilha(&vermelho);
	inicializa_pilha(&verde);
	inicializa_pilha(&preto);
	inicializa_pilha(&especiais);
	inicializa_pilha(baralho);
	
	srand(time(NULL));
///////////////////////////////////////////////////////// Amarelo
	for ( int w = 0 ; w < 2 ; w++){ // Inserindo carta especial Bloqueio, inserindo na pilha especial 
		c.cor =0;
		c.numero = 66; 
		push(&especiais, c);
}
	for ( int w = 0 ; w < 2 ; w++){ // Inserindo carta especial Reverse, inserindo na pilha especial
		c.cor = 0; 
		c.numero = 82;
		push(&especiais, c);
}
		int numerosAmarelo[19]; 
		GerarNumerosAmarelo(numerosAmarelo , 19 , 20); // Chama a função de gerar as cores e numeros
		c.cor = 0;
		for ( int i = 0 ; i < 19 ; i++){ 
			
			if ( numerosAmarelo[i] > 10){ // Se a os numeros forem maiores que 10
				numerosAmarelo[i] = numerosAmarelo[i] - 10; // Ele é subtraido por 10
			//	printf("%d  ", numerosAmarelo[i]);           // O motivo disso é que como gera de 0 a 19, assim teremos 2 numeros 1, 2 numeros 2 ....
				c.numero = numerosAmarelo[i];                  // Não temos o numero 10, pois no Uno so existe uma carta numero 0
				push(&amarelo, c);
			} else {
	
		c.numero = numerosAmarelo[i]; // Se não for maior que 10, entra normal
		push(&amarelo, c); }
	}
		for ( int w = 0 ; w < 2 ; w++){ // Inserindo carta especial +2, inserindo na pilha especial
		c.cor = 0;
		c.numero = 43; 
		push(&especiais, c);
}
///////////////////////////////////////////////////////// Azul
///////////////////////////////////////////////////////// A mesma coisa que acontece com o amarelo, acontece com as outras cores
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
///////////////////////////////////////////////////////// A mesma coisa que acontece com o amarelo, acontece com as outras cores
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
///////////////////////////////////////////////////////// A mesma coisa que acontece com o amarelo, acontece com as outras cores
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
	for(int m=0 ; m<8 ; m++){  // função pra inserir carta Troca de cor e +4
        auxp = rand()%2; // De forma aleatoria entre 0 e 1
    if(auxp == 0){ 
    	if(contW > 0  ){
        	c.cor = 4;
        	c.numero = 84; // Carta T = Troca de cor 
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
        	c.numero = 77;  // Carta M = +4 
            push(&preto,c);
            contM--;
    		} 	
	else { 
		m--;	 
	}
	}
				
}
//imprime_pilha(especiais); 
///////////////////////////////////////////////// Printar as pilhas até aqui

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
    	if(!pilha_vazia(&vermelho)){ //Se a pilha vermelha não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
        	pop(&vermelho,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
			else
			
	if(aux == 1){
    	if(!pilha_vazia(&azul)){//Se a pilha azul não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
        	pop(&azul,&c);
            push(baralho,c);
    	}
		else { 
		i--;
		}
}
			else
			
    if(aux == 2){
        if(!pilha_vazia(&amarelo)){//Se a pilha amarela não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
        	pop(&amarelo,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
			else
            
	if(aux == 3){
    	if(!pilha_vazia(&verde)){//Se a pilha verde não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
        	pop(&verde,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}

	if(aux == 4){
    	if(!pilha_vazia(&preto)){ //Se a pilha de cartas pretas não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
        	pop(&preto,&c);
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
	if(aux == 5){
    	if(!pilha_vazia(&especiais)){ //Se a pilha das cartas especiais não estiver vazia, ele retirará da pilha e adicionará (de forma aleatória) na pilha baralho
        	pop(&especiais,&c); // Lembrando que essa pilha, guarda as especiais de todas as cores 
            push(baralho,c);
        } 
		else { 
		i--;
		}
}
}
  

}

#endif
