#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>
#include "baralho.h"
#include "mao.h"


void jogar (tp_pilha *baralho, tp_pilha *mesa, Lista *jogador1,Lista *jogador2, int vez){
	carta c;
	int cor,cor2;
	char num,num2;
	vez = 1;
	int id = 1; 
	int id2 = 2;
/////////////////////////////////////////////////////////////////////////	
	 for( ; ; ){
/////////////////////////////////////////////////////////////////////////		
	if ( vez == 1) {
	do {
	printf("\n");
	tamanho(jogador1,id);
	printf("Carta na Mesa:");
	imprime_pilha(*mesa);
	printf("\n");
	printf("Mao Jogador1:\n");
	imprime(jogador1);
	printf("\n\nEscolha a carta: ");
	scanf("%d " "%c" , &cor , &num); 
	if ( num > 47 ){
	if ( num <= 57) {
	num = num - 48;	
		}
	}
	if ( num > 97 ){
		num = num -32;
	}
	system ("cls");
	}while (cor > 6 && num > 10);
	if ( num == 77 || num == 82 || num == 84 || num == 66 || num == 43|| num < 10) {
	if ( cor == 5) {
		pop(baralho,&c);
		jogador1 = insere(jogador1,c);
		vez++;
	} else { 
	c.cor = cor;
	c.numero = num;
	jogador1 = retiracarta(jogador1,c,mesa,baralho,c.cor,c.numero);	
	jogador2 = acao(baralho,jogador2,num);
	vez++;	
	if ( num == 66 || num == 82){ 
			vez = 1;
			}
	tamanho(jogador1,id);
	fflush(stdin);
	system ("cls");	
}
} else {
	vez = 1;
}
}


/////////////////////////////////////////////////////////////////////////
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
/////////////////////////////////////////////////////////////////////////	
	keybd_event ( VK_MENU, 0x36, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
	keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
	keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
/////////////////////////////////////////////////////////////////////////	
	carta c;
	tp_pilha mesa;
	tp_pilha baralho;
	Lista* jogador1;
	Lista* jogador2;
	int vez;
/////////////////////////////////////////////////////////////////////////		
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
for ( int j = 1 ; j < 2 ; j++){
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

switch (opc) {
	case 49 : {
		system("cls");
		inicializa_pilha(&mesa);
		criar_baralho(&baralho);
	 	carta_mesa(&mesa,&baralho);	
		jogador1 = criar_mao(&baralho,jogador1);
		jogador2 = criar_mao(&baralho,jogador2);
		printf("\n");
		jogar (&baralho,&mesa,jogador1,jogador2,vez);
		Sleep(3000);
		break;
	}
	case 50: {
		system("cls");
		manual(opc);
		system("PAUSE");
		system("cls");
		j--;
		break;
	}
	case 52: {
		system("cls");
		return 0;
		break;
	}
		case 51: {
		system("cls");
		creditos(opc);
		system("cls");
		j--;
		//return 0;
		//break;
	}
	default: {
		printf("  Erro: Escolha uma opcao valida");
		Sleep(500);
		system("cls");
	//	system("exit");
	}
	
}
} while (opc != 52);
}
}


