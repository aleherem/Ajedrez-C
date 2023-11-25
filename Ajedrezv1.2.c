#include<stdio.h> 
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<wchar.h>
#include<windows.h>
HANDLE wHnd;
void juego(char menu[5], int num, int swmenu);
int val_number(char menu[]);
void tablero(char [][8]);
void mostrar_tablero(char [][8]);
int turno_jugador(int turno);
int terminar_juego(char a[8][8]);
void leer_jugada(int jugador, char a[][8]);
void mover_pieza(char a[][8], int i_inicial, int j_inicial, int i_final, int j_final);
int caballo(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final);
int alfil(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final);
int torre(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final);
int peon(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final);
int rey(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final);
int dama(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final);

int main(){
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE)
    {
        return GetLastError();
    }
    DWORD dwMode = 0;
    if (!GetConsoleMode(hOut, &dwMode))
    {
        return GetLastError();
    }
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, dwMode))
    {
        return GetLastError();
	}

	wHnd = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT windowSize = {0, 0, 50, 30};
    SetConsoleWindowInfo(wHnd, 1, &windowSize);
	
    char a[8][8], menu[5]; 
	int i_inicial, j_inicial, i_final, j_final; 
	int turno = 0, chess = 1, jugador, num,swmenu;
	
	menu:
	juego(menu, num, swmenu);
	tablero(a);
	
	while(chess == 1){
        system("cls");
        mostrar_tablero(a);
   		wprintf(L"\x1b[30;43m\n\n -Si desea cambiar la pieza que eligio, coloque j9.- ");
        jugador = turno_jugador(turno);
        leer_jugada(jugador, a );
        chess = terminar_juego(a);
        getch();
        turno+=1;
}
	wprintf(L"\x1b[1;31;40mJuego Terminado\n");
	if(turno = 1){
		wprintf(L"\x1b[1;34;40mGana Azules");
		getch();
		goto end;
	}
	if(turno = 2){
		wprintf(L"\x1b[1;31;40mGana Rojas");
		goto end;
		getch();
	}
	
	end:
	system("cls");
	do{
	wprintf(L"\x1b[1;31;40mSi desea volver a jugar, ingrese 1\n");
	wprintf(L"\x1b[1;31;40mSi desea salir, ingrese 2\n");
	wprintf(L"\x1b[1;31;40m\n\t=== SELECCIONA UNA OPCION ===\n\t\t");
	fflush(stdin);
	scanf("%s", menu);
	num = val_number(menu);
	}while(num == 0);
    swmenu=atoi(menu);
    
    switch(swmenu){
    	case 1:
    		goto menu;
    		break;
    	case 2:
    		exit(EXIT_SUCCESS);
    		break;
    	default:
    		system("pause");
			system("cls");
			break;
	}
}

int val_number(char menu[]){
	int i;
	for (i=0; i<strlen(menu); ++i){
		if(!(isdigit(menu[i]))){
				printf("\t   ERROR: OPCION NO VALIDA\n\n");
		system("pause");
		system("cls");
			return 0;
		}
	}
	return 1;
}

void juego(char menu[5], int num, int swmenu){
	do{
	system("cls");
		wprintf(L"\x1b[1;32;40m\n\t*************************");
		wprintf(L"\x1b[1;32;40m\n\t*       CHESS.COM       *");
		wprintf(L"\x1b[1;32;40m\n\t*************************");
		wprintf(L"\x1b[1;31;40m\n\t*************************");
		wprintf(L"\x1b[1;31;40m\n\t*        1. JUGAR       *");
		wprintf(L"\x1b[1;31;40m\n\t*        2. SALIR       *");
		wprintf(L"\x1b[1;31;40m\n\t*************************");
		wprintf(L"\x1b[1;31;40m\n\t=== SELECCIONA UNA OPCION ===\n\t\t");
			fflush(stdin);
			scanf("%s",menu);
		wprintf(L"\x1b[0m");
		num = val_number(menu);	
	}
	while(num==0);
	swmenu=atoi(menu);
	switch (swmenu){
		case 1: 
			break;
		case 2:
    		exit(EXIT_SUCCESS);
    		break;
    	default:
    		system("pause");
			system("cls");
			break;
	}
}

void tablero(char a[][8]){
    int i,j;
    for(i=0;i<8;i++){
        
        for(j=0;j<8;j++){
          	//Fichas Torres     
            if((i==0 && j==0) || (i==0 && j==7)){
				a[i][j] = 'T';
			} 
			else if((i==7 && j==0) || (i==7 && j==7)){
				a[i][j] = 't';
			}  
    		//FICHAR CABALLO
            else if((i==0 && j==1) || (i==0 && j==6)){
           		a[i][j] = 'C';
			}
			else if((i==7 && j==1) || (i==7 && j==6)){
				a[i][j] = 'c';
			}
			//FICHAS ALFILES
            else if((i==0 && j==2) || (i==0 && j==5)){
           		a[i][j] = 'A';
			}  
			else if((i==7 && j==2) || (i==7 && j==5)){
				a[i][j] = 'a';
			}
			//FICHAS REINA
            else if((i==0 && j==3)){
           		a[i][j] = 'R';
			}
			else if((i==7 && j==3)){
				a[i][j] = 'r';
			}
			//FICHAS REY
            else if((i==0 && j==4)){
            	a[i][j] = 'D';
			}
			else if((i==7 && j==4)){
				a[i][j] = 'd';
			}
			//FICHAS PEONES 
            else if((i==1 && (j>=0 || j<=7))){
           		a[i][j] = 'P';
			}
			else if((i==6 && (j>=0 || j<=7))){
				a[i][j] = 'p';
			}
			//ESPACIOS VACIOS
            else a[i][j]='-';  
        }
        
    }
    
}

void mostrar_tablero(char a[8][8]){
    
    int i,j;
    char l={'a'};
    
    wprintf(L"\x1b[30;43m\t   TABLERO DE AJEDREZ   ");
    		wprintf(L"\x1b[0m");
    printf("\n\n\t   ");
        
    for(i=0;i<8;i++){
        wprintf(L"\x1b[43m %c ",l);
        l++;
    }   
        
   printf("\n");
        
    for(i=0;i<8;i++){
        wprintf(L"\x1b[0;43m\t %d ",i+1);
        
        for(j=0;j<8;j++){
        //Ciclo para validar cada espacio del tablero
        	//Valida Piezas Rojas(Blancas) 
        	if(isupper(a[i][j])){
        		if ((i+1+j+1)%2==0){
				wprintf(L"\x1b[1;31;47m %c ",a[i][j]);
                 
				}
				else
				wprintf(L"\x1b[1;31;40m %c ",a[i][j]);
			}
			//Valida Piezas Azules(Negras)
			if(islower(a[i][j])){
        		if ((i+1+j+1)%2==0){
				wprintf(L"\x1b[1;34;47m %c ",a[i][j]);
                 
				}
				else
				wprintf(L"\x1b[1;34;40m %c ",a[i][j]);
			}
			//Valida Espacios Vacios
			if(a[i][j] == '-'){
       		if ((i+1+j+1)%2==0){
				wprintf(L"\x1b[0;47m %c ",a[i][j]);
                 
			}
			else
				wprintf(L"\x1b[0;40m %c ",a[i][j]);
			}
		}
		wprintf(L"\x1b[0;43m %d ",i+1);
		printf("\n");
	}
	wprintf(L"\x1b[0m\t   ");
	char h={'a'};
	
	for(i=0;i<8;i++){
        wprintf(L"\x1b[43m %c ",h);
        h++;
    }   

}

int turno_jugador(int turno){
	if(turno % 2 == 0){
		wprintf(L"\x1b[0;0m\n\n\t    Juegan Rojas: \n");
		return 1;
	}
	else{
		wprintf(L"\x1b[0;0m\n\n\t   Juegan Azules: \n");
		return 2;
	}
}

int terminar_juego(char a[8][8]){
	int reyes = 0, game = 0,i, j;
	
	for(i=0;i<8;i++){
        
        for(j=0;j<8;j++){
        	
 				if(a[i][j] == 'r' || a[i][j] == 'R'){
 					reyes++;
				 }
		}

		printf("\n");
	}
	
	if(reyes == 2){
		game=1;
	}
	else{
		game=0;
	}
	return game;
}

void leer_jugada(int jugador, char a[][8]) {
    char desde[5], hasta[5];
    	
    int i_inicial, j_inicial, i_final, j_final, estado;
    
    inicio:
    	
	printf("Posicion Actual de la pieza a mover :");
	fflush(stdin);
	scanf("%s", desde);

    i_inicial= desde[0] - 'a';
    j_inicial= desde[1] - '0';
    
    j_inicial= j_inicial-1;	
    
    if(j_inicial == 8 && i_inicial== 9){
    	goto inicio;
	}
    
    destino:
    	
   	printf("Posicion a donde mover la pieza:");
	fflush(stdin);
	scanf("%s", hasta);   
    i_final= hasta[0] - 'a';
    j_final= hasta[1] - '0';
    
    j_final= j_final -1;
    
    if(j_final == 8 && i_final== 9){
    	goto inicio;
	}
    
if  (jugador == 1 && (isupper(a[j_inicial][i_inicial]))){
	switch (a[j_inicial][i_inicial]){
		case 'T': printf("\t  Torre Roja\n");
		estado = torre(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'T';
				a[j_inicial][i_inicial] = '-';
		}
			break;
			
		case 'C': printf("\t  Caballo Rojo\n") ;
		estado = caballo(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'C';
				a[j_inicial][i_inicial] = '-';
		}
			break;
			
		case 'A': printf("\t Alfil Rojo\n");
		estado = alfil(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'A';
				a[j_inicial][i_inicial] = '-';
	}
			break;
			
		case 'D': printf("\t  Dama Roja\n");
		estado = dama(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'D';
				a[j_inicial][i_inicial] = '-';
		}
			break;
		case 'R': printf("\t  Rey Rojo\n");
		estado = rey(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'R';
				a[j_inicial][i_inicial] = '-';
		}
			break;
		case 'P': printf("\t  Peon Rojo\n");
		estado = peon(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'P';
				a[j_inicial][i_inicial] = '-';
		}
			break;
		}
}

else if  (jugador == 2 && (islower(a[j_inicial][i_inicial]))){
	switch (a[j_inicial][i_inicial]){
		case 't': printf("\t  Torre Azul\n");
		estado = torre(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 't';
				a[j_inicial][i_inicial] = '-';
		}
			break;
			
		case 'c': printf("\t  Caballo Azul\n") ;
		estado = caballo(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'c';
				a[j_inicial][i_inicial] = '-';
		}
			break;
			
		case 'a': printf("\t Alfil Azul\n");
		estado = alfil(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'a';
				a[j_inicial][i_inicial] = '-';
	}
			break;
			
		case 'd': printf("\t  Dama Azul\n");
		estado = dama(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'd';
				a[j_inicial][i_inicial] = '-';
		}
			break;
		case 'r': printf("\t  Rey Azul\n");
		estado = rey(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'r';
				a[j_inicial][i_inicial] = '-';
		}
			break;
		case 'p': printf("\t  Peon Azul\n");
		estado = peon(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
		if (estado == 1){
			printf("\t  Movimiento Invalido\n");
			goto destino;
		}
		else{
				a[j_final][i_final] = 'p';
				a[j_inicial][i_inicial] = '-';
		}
			break;
		}
}
else{
	wprintf(L"\x1b[30;43m\n Error: No hay pieza en esta posicion \n o no es el color del turno correspondiente\n\n");
	wprintf(L"\x1b[0m");
	goto inicio;
}
    

}
int caballo(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final){
	int estado;
	estado = 2;
		if (isupper(a[j_final][i_final])){
			estado=1;
			return estado ;
		}
		if(a[j_final][i_final]== '-' || (islower(a[j_final][i_final]))){
				if(((i_final == i_inicial + 1) && (j_final == j_inicial + 2)) ||
        			((i_final == i_inicial + 2) && (j_final == j_inicial + 1)) ||
        			((i_final == i_inicial - 1) && (j_final == j_inicial + 2)) ||
        			((i_final == i_inicial - 2) && (j_final == j_inicial + 1)) ||
       				((i_final == i_inicial + 1) && (j_final == j_inicial - 2)) ||
        			((i_final == i_inicial + 2) && (j_final == j_inicial - 1)) ||
        			((i_final == i_inicial - 1) && (j_final == j_inicial - 2)) ||
        			((i_final == i_inicial - 2) && (j_final == j_inicial + 1)) )
						{
        					estado = 2;	
						}
					else{
							estado = 1;	
					}
			}
   return estado;     		
	
}
int alfil(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final){
	int estado;
	int dig_i,dig_j, diagonal_i, diagonal_j ;
	
	estado = 2;
	
		if (isupper(a[j_final][i_final])){
			estado=1;
			return estado ;
		}
		else{
			if(i_inicial<i_final){
				dig_i=1;	
			}
			else{
				dig_i=-1;
			}
			if(j_inicial<j_final){
				dig_j=1;
			}
			else{
				dig_j=-1;
			}
			diagonal_i= i_inicial+dig_i;
			diagonal_j= j_inicial+dig_j;
			
			while(diagonal_i!=i_final && diagonal_j!=j_final){
				if(a[diagonal_j][diagonal_i]!='-'){
					estado = 1;
				}	
					diagonal_i += dig_i; 
					diagonal_j += dig_j;
			}
			if(j_final!= diagonal_j || i_final!= diagonal_i){
				estado = 1;
			}
		}
		return estado;
}
int peon(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final){
	
	int estado;
	estado = 1;
			if (isupper(a[j_final][i_final])){
					estado = 1;
					return estado ;
			}
			else{
				if((j_inicial==1 && (i_inicial>=0 || i_inicial<=7)) && i_inicial == i_final && j_final == j_inicial + 2){
					estado = 2;		
				}	
				if(i_final == i_inicial && j_final == j_inicial + 1 && a[j_final][i_final]=='-'){
					estado = 2;
					}
			
				}
	
			if(i_final == i_inicial -1 || i_final == i_inicial + 1){
				if(islower(a[j_final][i_final])){
					estado = 2;
				}
			}
			return estado;
				
}
int torre(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final){
	int estado, i;
	estado = 2;
			if (isupper(a[j_final][i_final])){
					estado = 1;
					return estado ;
			}
			if(i_final != i_inicial && j_final != j_inicial){
					estado = 1;
					return estado ;
			}
			if(j_inicial == j_final && i_inicial < i_final){
				for (i = i_inicial+1; i < i_final; i++){
					if(a[j_inicial][i] != '-'){
						estado = 1;
					}
				}
			}
			if(j_inicial == j_final && i_inicial > i_final){
				for (i = i_inicial-1; i > i_final; i--){
					if(a[j_inicial][i] != '-'){
						estado = 1;
					}
				}
			}
			if(j_inicial < j_final && i_inicial == i_final){
				for (i = j_inicial + 1; i < j_final; i++){
					if(a[i][j_inicial] != '-'){
						estado = 1;
					}
				}
			}
			if(j_inicial > j_final && i_inicial == i_final){
				for (i = j_inicial - 1; i > j_final; i--){
					if(a[i][j_inicial] != '-'){
						estado = 1;
					}
				}
			}
			
			return estado;
}
int rey(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final){
	
	int estado = 1;
	
		if(( j_final == j_inicial + 1 && i_final == i_inicial +1)||
			(j_final == j_inicial + 1 && i_final == i_inicial 	)||
			(j_final == j_inicial + 1 && i_final == i_inicial -1)||
			(j_final == j_inicial     && i_final == i_inicial +1)||
			(j_final == j_inicial     && i_final == i_inicial 	)||
			(j_final == j_inicial     && i_final == i_inicial -1)||
			(j_final == j_inicial - 1 && i_final == i_inicial +1)||
			(j_final == j_inicial - 1 && i_final == i_inicial   )||
			(j_final == j_inicial - 1 && i_final == i_inicial -1)){
				
				if (!isupper(a[j_final][i_final])){
					estado = 2;
			}
		}
		return estado;
}
int dama(char a[][8], char desde[5], char hasta[5], int i_inicial, int j_inicial, int i_final, int j_final){
	int estado = 1, mov_torre, mov_alfil;
	
	mov_torre = torre(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
	mov_alfil = alfil(a, desde, hasta, i_inicial, j_inicial, i_final, j_final);
	
	if(mov_torre == 2 || mov_alfil == 2){
		estado = 2;
	}
	
	return estado;
}