#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "baralho.h"
#include "mao.h"
#include "menu.h"


void jogar (tp_pilha *baralho, tp_pilha *mesa, Lista *jogador1,Lista *jogador2, int vez){
	carta c;
	int cor,cor2;
	char num,num2;
	vez = 1;
	int id = 1; 
	int id2 = 2;
/////////////////////////////////////////////////////////////////////////	
	 for( ; ; ){ //for em loop
/////////////////////////////////////////////////////////////////////////		
	if ( vez == 1) {
	do {
	printf("\n");
	tamanho(jogador1,id); //a função tamanho servirá para mostrar em tela a quantidade de cartas e o id é so para mostar em tela quem ganhou
	printf("Carta na Mesa:");
	imprime_pilha(*mesa); // mostra em tela a carta que esta na mesa
	printf("\n");
	printf("Mao Jogador1:\n");
	imprime(jogador1);  // mostra em tela as cartas que esta na mao do jogador1
	printf("\n\nEscolha a carta: ");
	scanf("%d " "%c" , &cor , &num); 
	if ( num > 47 ){
	if ( num <= 57) {
	num = num - 48;	 //Na tabela ASCII os numeros 48 a 57 são subtraídos pelo 48 para achar os numeros de 0-9 correspondentes
		}
	}
	if ( num > 97 ){
		if ( num <= 115) {
		num = num - 32; //Na tabela ASCII os numeros 97 a 105 são subtraídos pelo 32 para obter o alfabeto em maiusculo
		}
	}
	system ("cls");
	}while (cor > 6);
	if ( num == 77 || num == 82 || num == 84 || num == 66 || num == 43|| num < 10) {
	if ( cor == 5) {  //ao inserir cor 5 e a letra D, o jogador irá cavar ( o D é somente por estética
		pop(baralho,&c);
		jogador1 = insere(jogador1,c);
		vez++;
	} else {  //jogador não cavou, o jogo prossegue normal
	c.cor = cor;
	c.numero = num;
	jogador1 = retiracarta(jogador1,c,mesa,baralho,c.cor,c.numero);	// retira a carta da mão do jogador
	jogador2 = acao(baralho,jogador2,num); // se a carta for + (43) ou M (77), o proximo jogador cava
	vez++;	// logo depois da jogada vez recebe +1 para ser a vez do proximo jogador
	if ( num == 66 || num == 82){ //Na tabela ASCII, 66 e 82 são B e R, ou seja, a carta Block e Reverse
			vez = 1; // se o jogador bloquear o proximo, ele jogda novamente ( se fosse 4 jogaodores vez receberia +2 )
			}
	tamanho(jogador1,id); //a função tamanho servirá também para mostrar o vencedor
	fflush(stdin);
	system ("cls");	
}
} else {
	vez = 1; // se a carta jogada não for as predefinidas, não acontece a ação e ele cava novamente
}
}


////////////////////////////////////////////// As açoes feitas pelo jogador1 se repetem para o jagador2
 ////////////////////////////////////////////// ( tivemos que mudar as variaveis pois estavamos tendo alguns problemas)
	if ( vez == 2) {
	do {
	tamanho(jogador2,id2);
	printf("\n");
	printf("Carta na Mesa: ");
	imprime_pilha(*mesa);
	printf("\n");
	printf("Mao Jogador2: \n");
	imprime(jogador2);
	printf("\n\nEscolha a carta: ");
	scanf("%d", &cor2); 	
	scanf("%s",&num2); 	
	printf("%d %d /" , cor2, num2);
	if ( num2 > 47 ){
	if ( num2 < 58) {
	num2 = num2 - 48;	
		}
	}
	if ( num2 > 97 ){
		num2 = num2 -32;
	}
	system ("cls");
	}while (cor2 > 6 && num > 10);
	if ( num == 77 || num == 82 || num == 84 || num == 66 || num == 43|| num < 10) {
	if ( cor2 == 5) {
		pop(baralho,&c);
		jogador2 = insere(jogador2,c);
		vez--;
	} else {
	c.cor = cor2;
	c.numero = num2;
	jogador2 = retiracarta(jogador2,c,mesa,baralho,c.cor,c.numero);
	jogador1 = acao(baralho,jogador1,num2);
	vez--;
	if ( num2 == 66 || num2 == 82){
			vez = 2;
			}
	tamanho(jogador2,id2);
	fflush(stdin);
	system ("cls");
/////////////////////////////////////////////////////////////////////////		
}
} else {
	vez = 2;
}
}
}
}
int main () {
/////////////////////////Esses keyboards são para deixar em tela cheia//////////////////////////////
	keybd_event ( VK_MENU, 0x36, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
/////////////////////////Declarando as variáveis do struct, pilhas e listas////////////////////////
	tp_pilha mesa;
	tp_pilha baralho;
	Lista* jogador1;
	Lista* jogador2;
	int vez;
/////////////////////////////////////////Logo e menu///////////////////////////////////////////////				
char opc=1;

printf("\n\n");
gotoxy(65,22);
printf("      VCulture Dev. \n"); 
Sleep(1000);
gotoxy(65,23);
printf("       Apresenta \n");
gotoxy(65,24);
printf("     *");
Sleep(200);
printf("*");
Sleep(500);
printf("***");
Sleep(100);
printf("**");
Sleep(500);
printf("*");
Sleep(600);
printf("*****");
Sleep(200);
system("cls");
do {
printf("\n\n");
gotoxy(55,19);
printf("       dP     dP 888888ba   .88888.  \n");
gotoxy(55,20);
printf("       88     88 88    `8b d8'   `8b \n");
gotoxy(55,21);
printf("       88     88 88     88 88     88        1- Jogar  \n");
gotoxy(55,22);
printf("       88     88 88     88 88     88        2- Como Jogar\n");
gotoxy(55,23);
printf("       Y8.   .8P 88     88 Y8.   .8P        3- Creditos \n");
gotoxy(55,24);
printf("       Y8.   .8P 88     88 Y8.   .8P        4- Sair \n");
gotoxy(55,25);
printf("       `Y88888P' dP     dP  `8888P'   \n");
gotoxy(55,26);
printf("       oooooooooooooooooooooooooooooo      Escolha:");                   
scanf("%c", &opc);
//////////////////////////////Seleção do menu///////////////////////////////////////
switch (opc) {
	case 49 : { //Numeros 49-52 correspondentes na tabela ASCII a 1-4
		system("cls");  
		criar_baralho(&baralho); //criando o baralho passando a pilha de variável baralho
	 	carta_mesa(&mesa,&baralho);	 //criando a carta que aparecerá na mesa no início da partida
		jogador1 = criar_mao(&baralho,jogador1); //cria as cartas para o jogador 1
		jogador2 = criar_mao(&baralho,jogador2); //cria as cartas para o jogador 2
		printf("\n");
			imprime_pilha(&baralho); 
}
		jogar (&baralho,&mesa,jogador1,jogador2,vez); //função jogar passando o baralho, a mesa e os jogadores
		Sleep(3000);
		break;
	}
	case 50: {
		system("cls");
		manual(opc); // chama a função Manual ( esta em função para fins de organização na main )
		system("PAUSE");
		system("cls");
		break;
	}
	case 51: {
		system("cls");
		creditos(opc); // chama a função Creditos ( esta em função para fins de organização na main )
		system("cls");

	}
	case 52: {
		system("cls");
		return 0; // fecha o jogo
		break;
	}

	default: {
		printf("  Erro: Escolha uma opcao valida");
		Sleep(500);
		system("cls");
	}
	
}
} while (opc != 52);
}

