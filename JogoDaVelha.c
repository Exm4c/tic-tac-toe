#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
 
typedef struct Velha
{
 int partida;          //número da partida (Ex: primeira(1), segunda(2), terceira(3), …., partida)
 char JogVelha[3][3];  // Tabuleiro do jogo. Armazenará as jogadas
 char resultado;       // Resultado da Partida: X, 0 ou V(equivale a Velha - empate)
} Partida;
Partida x;
 
char velha[3][3];
int dificuldade = 0;
int casa=0,casa2=0,casa3=0,casa4=0;

int criar_bin(char *nomearq, Partida h  ){
FILE *f;
 
    if((f = fopen(nomearq, "ab"))== NULL)
    {
    printf("O arquivo não pode ser aberto!");
   
    return 0;
 }  else    {
    fwrite(&h,sizeof(Partida),1,f);
    fclose(f);
    //printf("Gravou certin!!\n");
    return 1;
 
 }
fclose(f);
}
int pesquisa(char *nomearq, Partida h, char *nome1,char *nome2,char simb1,char simb2){
int p,i,j,t=0;
char tent1[21];
    FILE *f = fopen(nomearq,"rb");
    if (!f){
        printf("Erro na leitura\n");
    }  
    else {
    printf("\nQual jogo voce quer ver? ");
    
    scanf("%*c%i\n",&p);
    t=p;
    rewind(f);
    fseek (f , (p-1)*sizeof(struct Velha) , SEEK_SET );
    (fread(&h,sizeof(Partida),1,f));
  printf("\nPartida Nº %i\n",h.partida+1);
        printf("   1   2   3   \n");
   printf(" 1 %c | %c | %c \n",h.JogVelha[0][0],h.JogVelha[0][1],h.JogVelha[0][2]);
   printf("  ---|---|--- \n ");
   printf("2 %c | %c | %c \n",h.JogVelha[1][0],h.JogVelha[1][1],h.JogVelha[1][2]);
   printf("  ---|---|--- \n ");
   printf("3 %c | %c | %c \n",h.JogVelha[2][0],h.JogVelha[2][1],h.JogVelha[2][2]);
       
	    printf("%c Vencedor\n",h.resultado);
       
    }
    fclose(f); 
	  
	FILE *o= fopen("Jogadores.txt","r");
	rewind(o);
	if (!o){
		printf("Erro na leitura do txt\n");
	}
	else {
	fseek(o,(t-1)*21*sizeof(char),SEEK_SET);
	   (fread(&tent1,(t-1)*21*sizeof(char),1,o));
		printf("%s %c %s %c",nome1,simb1,nome2,simb2);
		}
			
	}

int abrir_bin(char *nomearq,Partida h){
    int i,j;
    FILE *f = fopen(nomearq,"rb");
    if (!f){
        printf("Erro na leitura\n");
    }
 
    while (fread(&h,sizeof(Partida),1,f)){
        printf("\nPartida Nº %i\n",h.partida+1);
        printf("   1   2   3   \n");
   printf(" 1 %c | %c | %c \n",h.JogVelha[0][0],h.JogVelha[0][1],h.JogVelha[0][2]);
   printf("  ---|---|--- \n ");
   printf("2 %c | %c | %c \n",h.JogVelha[1][0],h.JogVelha[1][1],h.JogVelha[1][2]);
   printf("  ---|---|--- \n ");
   printf("3 %c | %c | %c \n",h.JogVelha[2][0],h.JogVelha[2][1],h.JogVelha[2][2]);
       
	    printf("%c Vencedor\n",h.resultado);
    }
    fclose(f);
}
 
 
void basico(char pc){
    int linha,coluna,i,j,validacao;
   
    do{
    for(i=1;i<4;i++){  
    linha = rand() % 3;
    coluna = rand() % 3;
    }  
        if(velha[linha][coluna] == 'X' || velha[linha][coluna] == 'O'){
            validacao = 1;
        }else if(linha > 3 || coluna >3 || linha < 0 || coluna < 0 ){
            validacao = 2;
        }
        else{
            velha[linha][coluna] = pc;
            validacao = 0;
        }
    }while(validacao != 0);
 
}
 
void intermediario(char pc,int jogada){
    int linha,coluna,i,j,validacao;
   
    do{
    jogada = rand() % 100;  
    if(jogada < 33){
    for(i=1;i<10;i++){  
    linha = rand() % 3;
    coluna = rand() % 3;}
     if(velha[linha][coluna] == 'X' || velha[linha][coluna] == 'O'){
            validacao = 1;
        }else if(linha > 3 || coluna >3 || linha < 0 || coluna < 0 ){
            validacao = 2;
        }
        else{
            velha[linha][coluna] = pc;
            validacao = 0;
        }  
    }else if(jogada>=33 ||jogada <=66){
        for(i=1;i<20;i++){  
        linha = rand() % 3;
        coluna = rand() % 3;}
        if(velha[linha][coluna] == 'X' || velha[linha][coluna] == 'O'){
            validacao = 1;
        }else if(linha > 3 || coluna >3 || linha < 0 || coluna < 0 ){
            validacao = 2;
        }
        else{
            velha[linha][coluna] = pc;
            validacao = 0;
        }      
    }
    else{
        for(i=1;i<15;i++){  
    linha = rand() % 3;
    coluna = rand() % 3;}
     if(velha[linha][coluna] == 'X' || velha[linha][coluna] == 'O'){
            validacao = 1;
        }else if(linha > 3 || coluna >3 || linha < 0 || coluna < 0 ){
            validacao = 2;
        }
        else{
            velha[linha][coluna] = pc;
            validacao = 0;
        }  
    }  
    }while(validacao != 0 || jogada < 5);
 
}
 
 
 
void avancado(char pc,int jogada){
    char jog;
    int lin,col,validacao;
    if(pc == 'X'){
        jog = 'O';
    }else{
        jog = 'X';
    }
    
    if(jogada == 1){
        if(velha[1][1] != ' '){
            lin = rand() % 3;
            col = rand() % 3;
            velha[lin][col] = pc;
        }else{
            if(velha[1][1] == ' '){
            	velha[1][1] = pc;}
        }
    
    if(velha[0][0] == jog){
    casa = 1;
}
    if(velha[0][1] == jog){
    casa = 2;
}
    if(velha[0][2] == jog){
    casa = 3;}
    if(velha[1][0] == jog){
    casa = 4;
	}
    if(velha[1][1] == jog){
    casa = 5;
}
    if(velha[1][2] == jog){
    casa = 6;
}
    if(velha[2][0] == jog){
    casa = 7;
}
    if(velha[2][1] == jog){
    casa = 8;
}
    if(velha[2][2] == jog){
    casa = 9;
}
}
    
    if(jogada == 2){
    	velha[2][2] = ' ';
       if(casa == 1){
       		if(velha[0][1] == jog){
       			velha[0][2] = pc;
       			casa2 = 2;
	   		}
	   		else if(velha[0][2] == jog){
       			velha[0][1] = pc;
       			casa2 = 3;
	  	 	}
	   		else if(velha[1][0] == jog){
       			velha[2][0] = pc;
       			casa2 = 4;
       		}
       		else if(velha[2][0] == jog){
       			velha[1][0] = pc;
       			casa2 = 7;
       		}
       		else if(velha[2][1] == jog){
       			velha[1][0] = pc;
       			casa2 = 8;
			}
			else if(velha[2][2] == jog){
       			velha[1][0] = pc;
       			casa2 = 9;
			}
			else if(velha[1][2] == jog){
       			velha[0][2] = pc;
       			casa2 = 6;
			}
       		
	   	}
		   
	if(casa == 3){
       		if(velha[0][1] == jog){
       			velha[0][0] = pc;
       			casa2 = 2;
	   		}
	   		else if(velha[0][0] == jog){
       			velha[0][1] = pc;
       			casa2 = 1;
	  	 	}
	   		else if(velha[1][0] == jog){
       			velha[0][1] = pc;
       			casa2 = 4;
       		}
       		else if(velha[2][0] == jog){
       			velha[1][0] = pc;
       			casa2 = 7;
       		}
       		else if(velha[2][1] == jog){
       			velha[1][0] = pc;
       			casa2 = 8;
			}
			else if(velha[2][2] == jog){
       			velha[1][2] = pc;
       			casa2 = 9;
			}
			else if(velha[1][2] == jog){
       			velha[2][2] = pc;
       			casa2 = 6;
			}
       		
	   	}	  
		   
	if(casa == 7){
       		if(velha[1][0] == jog){
       			velha[0][0] = pc;
       			casa2 = 4;
	   		}
	   		else if(velha[0][0] == jog){
       			velha[1][0] = pc;
       			casa2 = 1;
	  	 	}
	   		else if(velha[0][1] == jog){
       			velha[1][0] = pc;
       			casa2 = 2;
       		}
       		else if(velha[0][2] == jog){
       			velha[1][0] = pc;
       			casa2 = 3;
       		}
       		else if(velha[1][2] == jog){
       			velha[2][1] = pc;
       			casa2 = 6;
			}
			else if(velha[2][2] == jog){
       			velha[2][1] = pc;
       			casa2 = 9;
			}
			else if(velha[2][1] == jog){
       			velha[2][2] = pc;
       			casa2 = 8;
			}
       		
	   	}
	   	
	if(casa == 9){
       		if(velha[1][0] == jog){
       			velha[0][1] = pc;
       			casa2 = 4;
	   		}
	   		else if(velha[0][0] == jog){
       			velha[0][1] = pc;
       			casa2 = 1;
	  	 	}
	   		else if(velha[0][1] == jog){
       			velha[1][0] = pc;
       			casa2 = 2;
       		}
       		else if(velha[0][2] == jog){
       			velha[1][2] = pc;
       			casa2 = 3;
       		}
       		else if(velha[1][2] == jog){
       			velha[0][2] = pc;
       			casa2 = 6;
			}
			else if(velha[2][0] == jog){
       			velha[2][1] = pc;
       			casa2 = 7;
			}
			else if(velha[2][1] == jog){
       			velha[2][0] = pc;
       			casa2 = 8;
			}
       		
	}
	if(casa == 2){
		if(velha[0][0] == jog){
       			velha[0][2] = pc;
       			casa2 = 1;
	   		}
	   		else if(velha[0][2] == jog){
       			velha[0][0] = pc;
       			casa2 = 3;
	  	 	}
	   		else if(velha[1][0] == jog){
       			velha[0][0] = pc;
       			casa2 = 4;
       		}
       		else if(velha[1][2] == jog){
       			velha[0][2] = pc;
       			casa2 = 6;
       		}
       		else if(velha[2][0] == jog){
       			velha[1][0] = pc;
       			casa2 = 7;
			}
			else if(velha[2][1] == jog){
       			velha[1][0] = pc;
       			casa2 = 8;
			}
			else if(velha[2][2] == jog){
       			velha[1][2] = pc;
       			casa2 = 9;
			}	
	}
	else if (casa !=1&&casa!=2&&casa !=3&&casa!=7&&casa !=9){
		lin = rand()%3;
		col = rand()%3;
		velha[lin][col] = pc;
		}		    	
}
	   
	if(jogada == 3){
	 	if(casa == 1){
	 		if(casa2 == 2){
	 			if(velha[2][0] == ' '){
	 				velha[2][0] = pc;
	 			}else{
	 				velha[1][0] = pc;
					 casa3=7;}	
			 }else if(casa2 == 3){
			 	if(velha[2][1] == ' '){
			 		velha[2][1] = pc;
			 	}else{
			 		velha[1][0] = pc;
			 		casa3=8;}
			 }else if(casa2 == 4){
			 	if(velha[0][2] == ' '){
			 		velha[0][2] = pc;
			 	}else{
			 		velha[0][1] = pc;
			 		casa3=3;}
			}else if(casa2 == 6){
			 	if(velha[2][0] == ' '){
			 		velha[2][0] = pc;
			 	}else{
			 		velha[1][0] = pc;
			 		casa3=7;}
	 		}else if(casa2 == 7){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 	}else{
			 		velha[0][1] = pc;
			 		casa3=6;}
	 		}else if(casa2 == 8){
			 	if(velha[0][2] == ' '){
			 		velha[0][2] = pc;
			 		casa3=6;
			 	}
	 		}else if(casa2 == 9){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 	}else{
			 		velha[0][2] = pc;
			 		casa3=6;}
	 		}
		}
		
		if(casa == 3){
	 		if(casa2 == 2){
	 			if(velha[2][2] == ' '){
	 				velha[2][2] = pc;
	 			}else{
	 				velha[1][2] = pc;
					 casa3=9;}	
			 }else if(casa2 == 1){
			 	if(velha[2][1] == ' '){
			 		velha[2][1] = pc;
			 	}else{
			 		velha[1][0] = pc;
			 		casa3=8;}
			 }else if(casa2 == 4){
			 	if(velha[2][1] == ' '){
			 		velha[2][1] = pc;
			 	}else{
			 		velha[2][2] = pc;
			 		casa3=8 ;}
			}else if(casa2 == 6){
			 	if(velha[0][0] == ' '){
			 		velha[0][0] = pc;
			 	}else{
			 		velha[0][1] = pc;
			 		casa3=1;}
	 		}else if(casa2 == 7){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 	}else{
			 		velha[2][2] = pc;
			 		casa3=6;}
	 		}else if(casa2 == 8){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 }else{
			 		velha[2][2] = pc;
			 		casa3=6;
			 	}
	 		}else if(casa2 == 9){
			 	if(velha[1][0] == ' '){
			 		velha[1][0] = pc;
			 	}else{
			 		velha[2][1] = pc;
			 		casa3=4;}
	 		}
		}
		
		if(casa == 7){
	 		if(casa2 == 1){
	 			if(velha[1][2] == ' '){
	 				velha[1][2] = pc;
	 			}else{
	 				velha[0][1] = pc;
					 casa3=6;}	
			 }else if(casa2 == 2){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 	}else{
			 		velha[0][0] = pc;
			 		casa3=6;}
			 }else if(casa2 == 3){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 	}else{
			 		velha[2][2] = pc;
			 		casa3=6;}
			}else if(casa2 == 4){
			 	if(velha[2][2] == ' '){
			 		velha[2][2] = pc;
			 	}else{
			 		velha[2][1] = pc;
			 		casa3=9;}
	 		}else if(casa2 == 6){
			 	if(velha[0][1] == ' '){
			 		velha[0][1] = pc;
			 	}else{
			 		velha[0][0] = pc;
			 		casa3=2;}
	 		}else if(casa2 == 8){
			 	if(velha[0][0] == ' '){
			 		velha[0][0] = pc;
			 }else{
			 		velha[1][0] = pc;
			 		casa3=1;
			 	}
	 		}else if(casa2 == 9){
			 	if(velha[0][1] == ' '){
			 		velha[0][1] = pc;
			 	}else{
			 		velha[1][0] = pc;
			 		casa3=2;}
	 		}
		}
		
	if(casa == 9){
	 		if(casa2 == 1){
	 			if(velha[2][1] == ' '){
	 				velha[2][1] = pc;
	 			}else{
	 				velha[2][0] = pc;
					 casa3=8;}	
			 }else if(casa2 == 2){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 	}else{
			 		velha[0][2] = pc;
			 		casa3=6;}
			 }else if(casa2 == 3){
			 	if(velha[1][0] == ' '){
			 		velha[1][0] = pc;
			 	}else{
			 		velha[0][1] = pc;
			 		casa3=6;}
			}else if(casa2 == 4){
			 	if(velha[2][1] == ' '){
			 		velha[2][1] = pc;
			 	}else{
			 		velha[2][0] = pc;
			 		casa3=8;}
	 		}else if(casa2 == 6){
			 	if(velha[2][0] == ' '){
			 		velha[2][0] = pc;
			 	}else{
			 		velha[2][1] = pc;
			 		casa3=7;}
	 		}else if(casa2 == 8){
			 	if(velha[0][2] == ' '){
			 		velha[0][2] = pc;
			 }else{
			 		velha[1][2] = pc;
			 		casa3=3;
			 	}
	 		}else if(casa2 == 7){
			 	if(velha[0][1] == ' '){
			 		velha[0][1] = pc;
			 	}else{
			 		velha[1][0] = pc;
			 		casa3=2;}
	 		}
		}
	if(casa == 2){
	 		if(casa2 == 1){
	 			if(velha[2][0] == ' '){
	 				velha[2][0] = pc;
	 			}else{
	 				velha[1][0] = pc;
					 casa3=8;}	
			 }else if(casa2 == 2){
			 	if(velha[1][2] == ' '){
			 		velha[1][2] = pc;
			 	}else{
			 		velha[0][2] = pc;
			 		casa3=6;}
			 }else if(casa2 == 3){
			 	if(velha[1][0] == ' '){
			 		velha[1][0] = pc;
			 	}else{
			 		velha[0][1] = pc;
			 		casa3=6;}
			}else if(casa2 == 4){
			 	if(velha[2][1] == ' '){
			 		velha[2][1] = pc;
			 	}else{
			 		velha[2][0] = pc;
			 		casa3=8;}
	 		}else if(casa2 == 6){
			 	if(velha[2][0] == ' '){
			 		velha[2][0] = pc;
			 	}else{
			 		velha[2][1] = pc;
			 		casa3=7;}
	 		}else if(casa2 == 8){
			 	if(velha[0][2] == ' '){
			 		velha[0][2] = pc;
			 }else{
			 		velha[1][2] = pc;
			 		casa3=3;
			 	}
	 		}else if(casa2 == 7){
			 	if(velha[0][1] == ' '){
			 		velha[0][1] = pc;
			 	}else{
			 		velha[1][0] = pc;
			 		casa3=2;}
	 		}
		}
		else if(casa !=1 && casa !=2 && casa !=3 && casa !=7 && casa !=9 ){
		lin = rand()%3;
		col = rand()%3;
		velha[lin][col] = pc;}
	}

	if(jogada == 4){
		if(casa == 1){
			if(casa2 == 2){
				if(casa3 == 7){
					if(velha[1][2] == ' '){
						velha[1][2] = pc;
					}
					else
						velha[2][2] = pc;
				}
			}
			if(casa2 == 3){
				if(casa3 == 8){
					if(velha[1][2] == ' '){
						velha[1][2] = pc;
					}
					else
						velha[2][2] = pc;
				}
			}
			if(casa2 == 4){
				if(casa3 == 3){
					if(velha[2][1] == ' '){
						velha[2][1] = pc;
					}
					else
						velha[1][2] = pc;
				}
			}
			if(casa2 == 6){
				if(casa3 == 7){
					if(velha[0][1] == ' '){
						velha[0][1] = pc;
					}
					else
						velha[2][1] = pc;
				}
			}
			if(casa2 == 7){
				if(casa3 == 6){
					if(velha[2][1] == ' '){
						velha[2][1] = pc;
					}
					else
						velha[2][2] = pc;
				}
			}
			if(casa2 == 8){
				if(casa3 == 6){
					if(velha[2][0] == ' '){
						velha[2][0] = pc;
					}
					else
						velha[2][2] = pc;
				}
			}
			if(casa2 == 9){
				if(casa3 == 6){
					if(velha[2][0] == ' '){
						velha[2][0] = pc;
					}
					else
						velha[2][1] = pc;
				}
			}	
		}
		
		if(casa == 3){
			if(casa2 == 2){
				if(casa3 == 9){
					if(velha[1][0] == ' '){
						velha[1][0] = pc;
					}
					else
						velha[2][1] = pc;
				}
			}
			if(casa2 == 1){
				if(casa3 == 8){
					if(velha[1][2] == ' '){
						velha[1][2] = pc;
					}
					else
						velha[2][2] = pc;
				}
			}
			if(casa2 == 4){
				if(casa3 == 8){
					if(velha[2][1] == ' '){
						velha[2][1] = pc;
					}
					else
						velha[2][2] = pc;
				}
			}
			if(casa2 == 6){
				if(casa3 == 1){
					if(velha[2][1] == ' '){
						velha[2][1] = pc;
					}
					else
						velha[1][0] = pc;
				}
			}
			if(casa2 == 7){
				if(casa3 == 6){
					if(velha[0][0] == ' '){
						velha[0][0] = pc;
					}
					else
						velha[0][1] = pc;
				}
			}
			if(casa2 == 8){
				if(casa3 == 6){
					if(velha[0][0] == ' '){
						velha[0][0] = pc;
					}
					else
						velha[0][1] = pc;
				}
			}
			if(casa2 == 9){
				if(casa3 == 4){
					if(velha[0][1] == ' '){
						velha[0][1] = pc;
					}
					else
						velha[0][0] = pc;
				}
			}	
		}
		
		if(casa == 7){
			if(casa2 == 2){
				if(casa3 == 6){
					if(velha[2][2] == ' '){
						velha[2][2] = pc;
					}
					else
						velha[0][2] = pc;
				}
			}
			if(casa2 == 1){
				if(casa3 == 6){
					if(velha[2][1] == ' '){
						velha[2][1] = pc;
					}
					else
						velha[2][2] = pc;
				}
			}
			if(casa2 == 4){
				if(casa3 == 9){
					if(velha[0][1] == ' '){
						velha[0][1] = pc;
					}
					else
						velha[1][2] = pc;
				}
			}
			if(casa2 == 6){
				if(casa3 == 2){
					if(velha[2][2] == ' '){
						velha[2][2] = pc;
					}
					else
						velha[0][2] = pc;
				}
			}
			if(casa2 == 3){
				if(casa3 == 6){
					if(velha[0][0] == ' '){
						velha[0][0] = pc;
					}
					else
						velha[0][1] = pc;
				}
			}
			if(casa2 == 8){
				if(casa3 == 1){
					if(velha[1][2] == ' '){
						velha[1][2] = pc;
					}
					else
						velha[0][1] = pc;
				}
			}
			if(casa2 == 9){
				if(casa3 == 2){
					if(velha[1][2] == ' '){
						velha[1][2] = pc;
					}
					else
						velha[0][2] = pc;
				}
			}	
		}
		
	if(casa == 9){
			if(casa2 == 2){
				if(casa3 == 6){
					if(velha[2][2] == ' '){
						velha[2][2] = pc;
					}
					else
						velha[0][2] = pc;
				}
			}
			if(casa2 == 1){
				if(casa3 == 8){
					if(velha[0][2] == ' '){
						velha[0][2] = pc;
					}
					else
						velha[1][2] = pc;
				}
			}
			if(casa2 == 4){
				if(casa3 == 8){
					if(velha[0][2] == ' '){
						velha[0][2] = pc;
					}
					else
						velha[1][2] = pc;
				}
			}
			if(casa2 == 6){
				if(casa3 == 2){
					if(velha[2][2] == ' '){
						velha[2][2] = pc;
					}
					else
						velha[0][2] = pc;
				}
			}
			if(casa2 == 3){
				if(casa3 == 6){
					if(velha[0][0] == ' '){
						velha[0][0] = pc;
					}
					else
						velha[0][1] = pc;
				}
			}
			if(casa2 == 8){
				if(casa3 == 1){
					if(velha[1][2] == ' '){
						velha[1][2] = pc;
					}
					else
						velha[0][1] = pc;
				}
			}
			if(casa2 == 7){
				if(casa3 == 2){
					if(velha[1][2] == ' '){
						velha[1][2] = pc;
					}
					else
						velha[0][2] = pc;
				}
			}	
		}	
	}
} 
 
 
void jogada_computador(char jog,int nivel,int jogada){
    char pc;
    if (jog == 'X'){
        pc = 'O';
    }else{
        pc = 'X';
    }
    if (nivel == 1){
        basico(pc);
    }
    if (nivel == 2){
        intermediario(pc,jogada);
    }
    if (nivel == 3){
        avancado(pc,jogada);
    }
}
 
char criar_txt(char jog1[20],char jog2[20],char simb1,char simb2){
 FILE * ftp;
 char ch;
 if((ftp = fopen("Jogadores.txt", "a"))== NULL)
 {
 printf("O arquivo não pode ser aberto!");
 }
 if (simb1=='X')
    simb2='O';
 else if (simb1=='O');
    simb2='X';
 fprintf(ftp, "%s; %c;", jog1,simb1);
 fprintf(ftp, "%s; %c \n", jog2,simb2);
fclose(ftp);
}
 
 
int menu(char *nome1,char *nome2){
    int oponente;
    do{
        printf("Escolha como deseja jogar: \n");
        printf("1 - Jogar contra o computador\n");
        printf("2 - Jogar contra outro jogador\n");
        printf("Escolha: ");
        scanf("%d%*c",&oponente);
        printf("Insira o nome do primeiro jogador: ");
        scanf("%s",nome1);
        scanf("%*c");
        if(oponente == 1){
        	nome2 = "Computador";
		}
        else if (oponente == 2){
            printf("Insira o nome do segundo jogador: ");
            scanf("%s",nome2);
            scanf("%*c");
            return 2;
        }
    }while(oponente != 1 && oponente !=2);
    system("cls");
    if (oponente == 1){
    do{
        printf("Escolha a dificuldade: \n");
        printf("1 - Basico\n");
        printf("2 - Intermediario\n");
        printf("3 - Avancado\n");
        printf("Escolha: ");
        scanf("%d%*c",&dificuldade);
    }while(dificuldade != 1 && dificuldade != 2 && dificuldade != 3 );
    system("cls");
    return 1;
}
}
 
 
 
void inicializa_velha(){
    int i,j;
    for (i=0;i<3;i++){
        for(j=0;j<3;j++){
            velha[i][j] = ' ';
        }
    }  
}
 
int jogada_usuario(int lin,int col,char jog){
    int i,j;
   
    if(velha[lin-1][col-1] == 'X' || velha[lin-1][col-1] == 'O'){
        return 2;
    }else if(lin > 3 || col >3 || lin < 1 || col < 1 ){
        return 1;
    }
    else{
    velha[lin-1][col-1] = jog;
    return 0;
    }  
}
 
 
void escolha_simb(char *jog1, char *jog2){
   
    char fsymb;
    do  {
    printf("Escolha o simbolo: X ou O\n");
    scanf("%c%*c",&fsymb);
    fsymb=toupper(fsymb);
    } while (fsymb!='X' && fsymb!='O');
    if (fsymb=='X'){
        *jog1='X';
        *jog2='O';
           
    }   else if (fsymb=='O'){
        *jog1='O';
        *jog2='X';
    }
       
   
}
 
 int verifica_pc(char pc){
   
    if (velha[0][0]==pc && velha[0][1]==pc && velha[0][2] == pc)
        return 1;
 
    else if (velha[1][0]==pc && velha[1][1]==pc && velha[1][2] == pc)
        return 1;
 
    else if (velha[2][0]==pc && velha[2][1]==pc && velha[2][2] == pc)
        return 1;
 
    else if (velha[0][0]==pc && velha[1][0]==pc && velha[2][0] == pc)
        return 1;
 
    else if (velha[0][1]==pc && velha[1][1]==pc && velha[2][1] == pc)
        return 1;
 
    else if (velha[0][2]==pc && velha[1][2]==pc && velha[2][2] == pc)
        return 1;
 
    else if (velha[0][0]==pc && velha[1][1]==pc && velha[2][2] == pc)
        return 1;
 
    else if (velha[0][2]==pc && velha[1][1]==pc && velha[2][0] == pc)       
        return 1;
 
    else {
        return 0;
    }    
 }
 
int verifica_ganhador(char jog){
   
    if (velha[0][0]==jog && velha[0][1]==jog && velha[0][2] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
    else if (velha[1][0]==jog && velha[1][1]==jog && velha[1][2] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
    else if (velha[2][0]==jog && velha[2][1]==jog && velha[2][2] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
    else if (velha[0][0]==jog && velha[1][0]==jog && velha[2][0] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
    else if (velha[0][1]==jog && velha[1][1]==jog && velha[2][1] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
 
    else if (velha[0][2]==jog && velha[1][2]==jog && velha[2][2] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
    else if (velha[0][0]==jog && velha[1][1]==jog && velha[2][2] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
    else if (velha[0][2]==jog && velha[1][1]==jog && velha[2][0] == jog){
			if (jog=='X'){
				x.resultado='X';
			}
			else{
				x.resultado='O';
			}	
        return 1;
}
    else {
        return 0;
    }
       
 }
void main(){
    char nomearq[]="Partida.bin";
    char nome1[20],nome2[20];
    int lin,col,i,j,ganhador=0,validar,oponente,jogada=1,casas,ganhadorpc,jogar;
    char jog,jog1,jog2,pc;
for(jogar = 1;jogar<2;){
    oponente = menu(nome1,nome2);
    inicializa_velha();
    escolha_simb(&jog1,&jog2);
    jog = jog1;
   	pc = jog2;
    do{
        printf("Escolha uma linha: ");
        scanf("%d",&lin);
        printf("Escolha uma coluna: ");
        scanf("%d",&col);
        validar = jogada_usuario(lin,col,jog);
        if(oponente == 1 && validar == 0){
            jogada_computador(jog,dificuldade,jogada);
            jogada++;  
        }
        system("cls");
        if(validar == 1){
            printf("Posicao informada e invalida!!\n");
        }
        if(validar == 2){
            printf("Posicao informada ja preenchida!!\n");
        }
        ganhador = verifica_ganhador(jog);
        ganhadorpc = verifica_pc(pc);
        if(ganhador == 0){
            for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    if(velha[i][j] == 'X'||velha[i][j] == 'O'){
                        casas++;
                    }  
                }
            }
        }
        if(casas == 29){
            ganhador = 3;
            x.resultado='V';
        }  
        if(oponente == 2 && validar == 0){
            if (jog == 'X'){
                jog = 'O';
            }
            else{
                jog = 'X';
            }
        }
       
        printf("   1   2   3   \n");
   printf(" 1 %c | %c | %c \n",velha[0][0],velha[0][1],velha[0][2]);
   printf("  ---|---|--- \n ");
   printf("2 %c | %c | %c \n",velha[1][0],velha[1][1],velha[1][2]);
   printf("  ---|---|--- \n ");
   printf("3 %c | %c | %c \n",velha[2][0],velha[2][1],velha[2][2]);
 
    }while (ganhador != 1 && ganhador != 3 && ganhadorpc != 1);
        for (i=0;i<3;i++){
            for(j=0;j<3;j++){
            x.JogVelha[i][j]=velha[i][j];
        }
}   
criar_bin(nomearq, x);
if(ganhadorpc == 1){
	printf("O Computador Ganhou!!\n");
}else if(ganhador == 3){
	printf("Vishhh deu velha!!\n");
}else{
	printf("O Jogador Ganhou\n");
}
printf("Deseja jogar novamente: \n");
printf("1 - Sim\n");
printf("2 - Nao\n");
++x.partida;
scanf("%d",&jogar);
system("cls");

}

abrir_bin(nomearq, x);
criar_txt(nome1,nome2,jog1,jog2);

pesquisa(nomearq,x,nome1,nome2,jog1,jog2);
system("pause");
}



