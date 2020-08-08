#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <windows.h>


void manual (int opc){

setlocale(LC_ALL,"");
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
		printf("|                                         Como Jogar:                                                                                           |\n");
		printf("|    Cada N�mero entre 0 a 4 representa uma cor e as cartas s�o representadas por seus n�meros (no caso das especiais primeira letra do efeito) |\n");
		printf("|    E cada numero entre 0 a 9 representa sua pr�pria numera��o                                                                                 |\n");
		printf("|                       ----------------------------------         --------------------------------------                                       |\n");
		printf("|                       |         Cores:                 |         |      Especiais:                    |                                       |\n");
		printf("|                       |       0- Amarelo               |         |    +2 - Cave duas cartas           |                                       |\n");
		printf("|                       |       1- Azul                  |         |     B - Bloqueio                   |                                       |\n");
		printf("|                       |       2- Vermelho              |         |     R - Inverter ordem de jogada   |                                       |\n");
		printf("|                       |       3- Verde                 |         |     T - Coringa, ou trocar de cor  |                                       |\n");
		printf("|                       |       4- Preto (Troca cor)     |         |    +4 - Cave 4  e troca de cor     |                                       |\n");
		printf("|                       ----------------------------------         --------------------------------------                                       |\n");
		printf("|                                         Para cavar utulize: COR = 5 e NUMERO 5                                                                |\n");
		printf("|    Para jogar, basta digitar o n�mero da carta, e o n�mero (ou letra) que queira jogar, se a carta estiver em sua m�o.                        |\n");
		printf("|                                         Por fim, Divirta-se!!                                                                                 |\n");
		printf("-------------------------------------------------------------------------------------------------------------------------------------------------\n");
	}

void creditos (int opc){  
			printf("-------------------------------------------------   ------------------------------------------\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |                                        |\n");
			printf("|                                               |   |________________________________________|\n");
			printf("|                                               |\n");
			printf("|                                               |\n");
			printf("|                                               |\n");
			printf("|                                               |\n");
			printf("|                                               |\n");
			printf("|                                               |\n");
			printf("|                                               |\n");
			printf("|                                               |\n"); 
			printf("|                                               |\n");
			printf("|                                               |\n");   
			printf("|                                               |\n");
			printf("|_______________________________________________|\n");  
	
gotoxy(58,03)   ;            
printf(">L"); 
Sleep(150); 
printf("I");
Sleep(150); 
printf("S");
Sleep(150); 
printf("T");
Sleep(150);            
printf(" P");
Sleep(150); 
printf("E");	
Sleep(150); 
printf("R");
Sleep(150); 
printf("S");
Sleep(150);             
printf("O");
Sleep(150); 
printf("N");
Sleep(150); 
printf("N");
Sleep(150); 
printf("E");
Sleep(150); 
printf("L");
Sleep(150); 
	gotoxy(3,1)   ; 
	Sleep(1000);
	printf("Forms FORM 777 ||  Unijorge CC 2020 - 3s \n");
gotoxy(57,6)   ; 
Sleep(1000);
printf("Gabriel Sena\n");
	gotoxy(3,2);   
	Sleep(1000);
	printf("Personal File Urubu Crew  \n");	
	gotoxy(3,3) ;  
	Sleep(1000);
	printf("Text Assessment Report  \n");
	gotoxy(2,8)  ; 
	Sleep(2000);
	printf("This was a triumph    \n");
	gotoxy(2,9)  ; 
	Sleep(2000);
	printf("I'm making a note here:\n| HUGE SUCCESS\n");
gotoxy(57,12)  ; 
Sleep(1000);
printf("Professor: Marcio ");

	gotoxy(2,11)  ; 
	Sleep(1000);
	printf("It's hard to overstate\n");
	gotoxy(2,12)  ; 
	Sleep(500);
	printf("My satisfaction   \n");
	gotoxy(2,14)  ; 
	Sleep(3000);
	printf("Aperture Science:  \n");
	gotoxy(2,15)  ; 
	Sleep(2000);
	printf("We do what we must \n");
	gotoxy(2,16)  ; 
	Sleep(500);
	printf("Because we can \n");
	gotoxy(2,17)  ; 
	Sleep(3000);
	printf("For the good of all of us \n");
	Sleep(1000);
	gotoxy(2,18)  ; 
	Sleep(1000);
	printf("Except the ones who are dead \n");
	gotoxy(2,20)  ; 
	Sleep(1000);
	printf("But there's no sense crying \n");
	gotoxy(2,21)  ; 
	Sleep(1000);
	printf("Over every mistake \n");
	gotoxy(2,22)  ; 
	Sleep(1000);
	printf("You just keep on trying\n");
	gotoxy(2,23)  ; 
	Sleep(1000);
	printf("Till you run out of uno\n");
	gotoxy(2,24)  ; 
	Sleep(1000);
	printf("And the science gets done \n");
	gotoxy(2,25)  ; 
	Sleep(1000);
	printf("And you make a neat gun \n");
	gotoxy(2,26)  ; 
	Sleep(1000);
	printf("For the people who are \n");
	gotoxy(2,28)  ; 
	Sleep(1000);
	printf("Still alive \n");
	gotoxy(1,31);
	system("PAUSE");

}
#endif