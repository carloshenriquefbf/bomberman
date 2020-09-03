#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define LIN 13
#define COL 13

typedef struct{
        int tipo;
        char nome;
}estrutura;

void fimprimir(estrutura mapa[][13]);

void fcriarmapa(estrutura mapa[][13]);

void fjogar(estrutura mapa[][13], int quantMonstro, int cpos, int lpos, int quantBomba);

void fmonstro(estrutura mapa[][13],int i, int j);							

void fbomba(estrutura mapa[][13],int lbomba, int cbomba, int lpos, int cpos, int quantMonstro);

void fcarta(estrutura mapa[][13],int lbomba,int cbomba,int lpos,int cpos,int range, int quantMonstro);

int main(){
	
int i,j; 																		//contadores
int input,input2; 																//input do usuário para os switchs
int quantParede,quantMonstro,quantCarta,posCarta[LIN][COL],quantBomba; 					//quantidade de paredes, monstros e cartas e posicao das cartas
int t,lpos=1,cpos=1; 																			//random
char l,letra;
int coluna, linha;	          
char nome[100],c;                                                        
estrutura mapa[LIN][COL];

FILE* arquivo;
FILE* modo3;
do{

printf("\n1. Jogar\n2. DEBUG\n3. Vencedores\n4. Desenvolvedores\n5. Sair\n");	//menu inicial
scanf("%d",&input);
system("cls");

fcriarmapa(mapa);

srand(time(NULL));		

switch(input){
case 1: 																		
	//Jogar
	t=rand()%5;																	//escolha aleatoria dos 5 mapas iniciais 	
	switch(t){
    	case 0:
             arquivo=fopen("Resources\\MAPA1.txt","r");             
             break;   
		case 1:
			 arquivo=fopen("Resources\\MAPA2.txt","r");
			 break;
		case 2:
			 arquivo=fopen("Resources\\MAPA3.txt","r");
			 break;                         
		case 3:
			 arquivo=fopen("Resources\\MAPA4.txt","r");        
			 break;
		case 4:
			 arquivo=fopen("Resources\\MAPA5.txt","r");
			 break; 
    }  
    
    mapa[lpos][cpos].nome='p';
    mapa[lpos][cpos].tipo=1;
    
    mapa[1][2].nome=' ';
    mapa[1][2].tipo=7;
    
    mapa[2][1].nome=' ';
    mapa[2][1].tipo=7;
    
    
    
    if(arquivo==NULL)
    {
                     perror("error");
                     
    }
    
    
    while(fscanf(arquivo,"%c%d",&l,&coluna)!=EOF) {                                //parede indestrutivel
                                                  
                                                                 
         letra='a';
         for(i=0;i<13;i++)
         {
              if(letra==l)
              {
                          linha=i;
                          break;
                          }
              else{
                   letra++;
                   }
                   }
         mapa[linha][coluna].tipo=9;
         mapa[linha][coluna].nome='#';          
                   }   
                   
        fclose(arquivo);                                                                                                                                                                                           
                                                      
    printf("\nEscolha a dificuldade:\n1. Facil\n2. Normal\n3. Dificil\n");			//escolha da dificuldade
	scanf("%d",&input2);
	system("cls");
	switch(input2){
	
    case 1:																			//atribuicao da posicao das paredes, dos monstros e das cartas dependendo da dificuldade
         quantParede=0;
         quantMonstro=0;
         quantCarta=0;
		//modo facil com menos inimigos
		do{
            i=rand()%13;
            j=rand()%13;
               
            	if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2)
            	{
            		mapa[i][j].nome='*';
            		mapa[i][j].tipo=2;          		
            		quantParede++;
        		}
                                         
        }while(quantParede<16);
               
        do{
            i=rand()%13;
            j=rand()%13;
               
             	if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
             	{
                    mapa[i][j].nome='m';
                    mapa[i][j].tipo=3;
                	quantMonstro++;
                }
      	}while(quantMonstro<4);
		 
      		
        do{
               i=rand()%13;
               j=rand()%13;
               
              if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                    mapa[i][j].nome='*';
                    mapa[i][j].tipo=4;
                    quantCarta++;
             	}
      	}while(quantCarta<2); 
		  
		quantBomba=10;                                                                                                                          
		break;
	case 2:
         quantParede=0;
         quantMonstro=0;
         quantCarta=0;
		//modo normal com quantidade normal de  inimigos
			do{
               i=rand()%13;
               j=rand()%13;
               
               if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2)
               	{
                	mapa[i][j].nome='*';
                	mapa[i][j].tipo=2;
                    quantParede++;
            	}    
            }while(quantParede<22);
               
            do{
               i=rand()%13;
               j=rand()%13;
               
              if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                  	mapa[i][j].nome='m';
                  	mapa[i][j].tipo=3;                  	
                  	quantMonstro++;
            	}
         	}while(quantMonstro<6);
         	
            do{
               i=rand()%13;
               j=rand()%13;
               
                      if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  {
                mapa[i][j].nome='*';
                mapa[i][j].tipo=4;
            	quantCarta++;
              }
         	}while(quantCarta<3);     
			 
			 quantBomba=15;
			 			                                                  
		break;
		
	case 3:
         quantParede=0;
         quantMonstro=0;
         quantCarta=0;
		//modo dificil com mais inimigos
			do{
               i=rand()%13;
               j=rand()%13;
               
                 if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2)
               	{
                	mapa[i][j].nome='*';
                	mapa[i][j].tipo=2;
                	quantParede++;
				}                                      
            }while(quantParede<26);
              
            do{
               i=rand()%13;
               j=rand()%13;
               
                 if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                	mapa[i][j].nome='m';
                	mapa[i][j].tipo=3;
                	quantMonstro++;
                }
        	}while(quantMonstro<8);
        	
            do{
               i=rand()%13;
               j=rand()%13;
               
                      if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                mapa[i][j].nome='*';
                mapa[i][j].tipo=4;
                quantCarta++;
               	}
            }while(quantCarta<4);  
			
			
			quantBomba=20;                                          
                            
                                                                   
		break;
	default:
		printf("\nOpcao invalida.\n");
		return 0;
		break;
    }
    
 fjogar(mapa,quantMonstro,lpos,cpos,quantBomba);    
              //movimento do mapa
 	break;
	
case 2:			//debug
t=rand()%3;																	//escolha aleatoria dos 3 mapas iniciais 	
		switch(t){
    	case 0:
             arquivo=fopen("Resources\\MAPA1.txt","r");             
             break;   
		case 1:
			 arquivo=fopen("Resources\\MAPA2.txt","r");
			 break;
		case 2:
			 arquivo=fopen("Resources\\MAPA3.txt","r");
			 break;                         
		case 3:
			 arquivo=fopen("Resources\\MAPA4.txt","r");        
			 break;
		case 4:
			 arquivo=fopen("Resources\\MAPA5.txt","r");
			 break; 
    }
    
    mapa[lpos][cpos].nome='p';
    mapa[lpos][cpos].tipo=1;
    
    mapa[1][2].nome=' ';
    mapa[1][2].tipo=7;
    
    mapa[2][1].nome=' ';
    mapa[2][1].tipo=7;
    
    
    
    if(arquivo==NULL)
    {
                     perror("error");
                     
    }
    
    while(fscanf(arquivo,"%c%d",&l,&coluna)!=EOF) {                                //parede indestrutivel
                                                  
                                                                 
         letra='a';
         for(i=0;i<13;i++)
         {
              if(letra==l)
              {
                          linha=i;
                          break;
                          }
              else{
                   letra++;
                   }
                   }
         mapa[linha][coluna].tipo=9;
         mapa[linha][coluna].nome='#';          
                   }   
                   
                                                                                                                                                                                                   
                                                      
    printf("\nEscolha a dificuldade:\n1. Facil\n2. Normal\n3. Dificil\n");			//escolha da dificuldade
	scanf("%d",&input2);
	system("cls");
	switch(input2){
	
    case 1:																			//atribuicao da posicao das paredes, dos monstros e das cartas dependendo da dificuldade
         quantParede=0;
         quantMonstro=0;
         quantCarta=0;
		//modo facil com menos inimigos
		do{
            i=rand()%13;
            j=rand()%13;
               
            	if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2)
            	{
            		mapa[i][j].nome='*';
            		mapa[i][j].tipo=2;          		
            		quantParede++;
        		}
                                         
        }while(quantParede<18);
               
        do{
            i=rand()%13;
            j=rand()%13;
               
             	if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
             	{
                    mapa[i][j].nome='m';
                    mapa[i][j].tipo=3;
                	quantMonstro++;
                }
      	}while(quantMonstro<4); 
      		
        do{
               i=rand()%13;
               j=rand()%13;
               
              if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                    mapa[i][j].nome='c';
                    mapa[i][j].tipo=4;
                    quantCarta++;
             	}
      	}while(quantCarta<2); 
		  
		quantBomba=10;                                                                                                                          
		break;
	case 2:
         quantParede=0;
         quantMonstro=0;
         quantCarta=0;
		//modo normal com quantidade normal de  inimigos
			do{
               i=rand()%13;
               j=rand()%13;
               
               if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2)
               	{
                	mapa[i][j].nome='*';
                	mapa[i][j].tipo=2;
                    quantParede++;
            	}    
            }while(quantParede<22);
               
            do{
               i=rand()%13;
               j=rand()%13;
               
              if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                  	mapa[i][j].nome='m';
                  	mapa[i][j].tipo=3;                  	
                  	quantMonstro++;
            	}
         	}while(quantMonstro<6);
         	
            do{
               i=rand()%13;
               j=rand()%13;
               
                      if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  {
                mapa[i][j].nome='c';
                mapa[i][j].tipo=4;
            	quantCarta++;
              }
         	}while(quantCarta<3);     
			 
			 quantBomba=15;
			 			                                                  
		break;
		
	case 3:
         quantParede=0;
         quantMonstro=0;
         quantCarta=0;
		//modo dificil com mais inimigos
			do{
               i=rand()%13;
               j=rand()%13;
               
                 if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2)
               	{
                	mapa[i][j].nome='*';
                	mapa[i][j].tipo=2;
                	quantParede++;
				}                                      
            }while(quantParede<26);
              
            do{
               i=rand()%13;
               j=rand()%13;
               
                 if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                	mapa[i][j].nome='m';
                	mapa[i][j].tipo=3;
                	quantMonstro++;
                }
        	}while(quantMonstro<8);
        	
            do{
               i=rand()%13;
               j=rand()%13;
               
                      if(mapa[i][j].tipo!=1 && mapa[i][j].tipo!=7 && mapa[i][j].tipo!=9 && mapa[i][j].tipo!=2 && mapa[i][j].tipo!=3)
			  	{
                mapa[i][j].nome='c';
                mapa[i][j].tipo=4;
                quantCarta++;
               	}
            }while(quantCarta<4);  			
			
			quantBomba=20;                                  
                            
                                                                   
		break;
	default:
		printf("\nOpcao invalida.\n");
		return 0;
		break;
    }    
 fjogar(mapa,quantMonstro,lpos,cpos,quantBomba);    
	break;	 
case 3:  	
	 //vencedores = por meio de arquivos 
	 modo3=fopen("Resources\\vencedores.txt","r");
	 
	 if(modo3==NULL){
	 	printf("ERRO AO ABRIR O ARQUIVO");
	 }
	 else{
	 	while(fscanf(modo3,"%c",&c)!=EOF)	{
	 	printf("%c",c);	
	 	}
	 	fclose(modo3);
	 }
	 
	 break;

case 4: 
    system("cls");
	printf("\nDesenvolvedor: Carlos Henrique \n");	 	
	break;
	
case 5:
	printf("\nObrigado por jogar o nosso jogo!\n");
	break;
		
default:
	printf("\nOpcao invalida.\n");	
	break;
}
}while(input!=5);
system("PAUSE");
return 0;
}

void fimprimir(estrutura mapa[][13], int quantBomba,int quantMonstro){
      int i,j;
      printf("\t\t\t\t\t\tBOMBERMAN\n\n\n\n\n");
      for(i=0;i<13;i++)                                                                  //FUNÇAO DE IMPRIMIR
    {
    	for(j=0;j<13;j++)
            {
                
                    printf(" %c",mapa[i][j].nome);
				
            }printf("\n");
    }
    printf("Jogador = [p]\nParede Indestrutivel = [#]\nParede Destrutivel = [*]\nMonstro = [m]: %i restantes.",quantMonstro);
    printf("\n\n            [C] = Cima\n[E] = Esquerda   \t[D] = Direita\n            [B] = Baixo\n\n\n[R] = Bomba: %i",quantBomba);
    
};

void fcriarmapa(estrutura mapa[][13]){
     
     int i,j; 
     
     for(i=0;i<13;i++){    															//criando espacos vazios para os mapas		
   for(j=0;j<13;j++){
      mapa[i][j].nome=' ';
      mapa[i][j].tipo=0;
   }
}


for(i=0;i<LIN;i++)																//bordas 
{
    mapa[i][0].nome='#';                          				
	mapa[0][i].nome='#';
    mapa[i][12].nome='#';
    mapa[12][i].nome='#';
    mapa[i][0].tipo=9;                          				
	mapa[0][i].tipo=9;
    mapa[i][12].tipo=9;
    mapa[12][i].tipo=9;
    
}
}									
     
void fjogar (estrutura mapa[][13], int quantMonstro, int cpos, int lpos, int quantBomba){
	
	estrutura aux;
     int i,j,d,contmonst=0,con,range=0;
     int lpos2=lpos,cpos2=cpos,bomba=0,bombatrue=0,contpasso=0,lbomba=0,cbomba=0;
     char input,input2;
     char nome[20];
     int remota=0;
     int carta=0;
     FILE*modo3;
     do{
     	
     fimprimir(mapa,quantBomba,quantMonstro); 																								//FUNCAO QUE IMPRIMI O MAPA
     scanf(" %c",&input);
switch(input){
            case 'c':
              	if(bombatrue!=0 )
					{
				   	contpasso++;   											//contador de passos 
				   	}
				   
              	if(mapa[lpos-1][cpos2].tipo!=1 && mapa[lpos-1][cpos2].tipo!=9 && mapa[lpos-1][cpos2].tipo!=2 && mapa[lpos2-1][cpos].nome!='*')
				   {
                   lpos2=lpos-1;
				   }
				   
				for(i=0;i<13;i++){
					for(j=0;j<13;j++){
						if(mapa[i][j].tipo==3)
						{
				  			fmonstro(mapa,i,j);
				  		}
				  	}
				}                  
            break;
                   
            case 'e':
              		if(bombatrue!=0 )
					{
				   	contpasso++;
				   	}
				   
              	if(mapa[lpos2][cpos-1].tipo!=1 && mapa[lpos2][cpos-1].tipo!=9 && mapa[lpos2][cpos-1].tipo!=2 && mapa[lpos2][cpos-1].nome!='*')
				{
                	cpos2=cpos-1;                
               	}
               
            	for(i=0;i<13;i++){
					for(j=0;j<13;j++){
						if(mapa[i][j].tipo==3)
						{
				  			fmonstro (mapa,i,j);
				  		}
				}
			}
            break;
            
            case 'b':
              	
              		if(bombatrue!=0 )
					{
				   	contpasso++;
					}
				   
              	 	if(mapa[lpos+1][cpos2].tipo!=1 && mapa[lpos+1][cpos2].tipo!=9 && mapa[lpos+1][cpos2].tipo!=2 && mapa[lpos2+1][cpos].nome!='*')
					{
                  	lpos2=lpos+1;               
               		}
               
   					for(i=0;i<13;i++){
						for(j=0;j<13;j++){
							if(mapa[i][j].tipo==3)
							{
				  			fmonstro (mapa,i,j);
				  			}
				  		}
				  	}
            break;
            
            case 'd':
              	
              	if(bombatrue!=0 )
				   {
				   	contpasso++;
				   }
				   
              	if(mapa[lpos2][cpos+1].tipo!=1 && mapa[lpos2][cpos+1].tipo!=9 && mapa[lpos2][cpos+1].tipo!=2 && mapa[lpos2][cpos+1].nome!='*')
				{
                   cpos2=cpos+1;
               	}
               	
       			for(i=0;i<13;i++){
					for(j=0;j<13;j++){
						if(mapa[i][j].tipo==3)
						{
				  			fmonstro (mapa,i,j);
				  		}
				  	}
				}
            break;                   
                   
            case 'r':    
			
	 		if(bombatrue==0)
			{  
			 quantBomba--;
			
			if(quantBomba==0)
			  {
			  	printf("\t\t\t\t VOCE FICOU SEM BOMBAS!\n\n\n\n");
				break;
			  } 	
			      	lbomba=lpos;
			      	cbomba=cpos;
			      	bombatrue=1;
			}
	break;
}			      		 						   	  				 
		if(bombatrue!=0 && contpasso>2 && carta==0){
		
		fbomba(mapa,lbomba,cbomba,lpos,cpos,quantMonstro);
		bombatrue=0;
		contpasso=0; 		
		}
		
		else if(carta==1){
		if(bombatrue!=0 && contpasso>=3){
		fcarta(mapa,lbomba,cbomba,lpos,cpos,range,quantMonstro);
			bombatrue=0;
			contpasso=0;  
		}
}
if(mapa[lpos2][cpos2].tipo!=1 && mapa[lpos2][cpos2].tipo!=9 && mapa[lpos2][cpos2].tipo!=2 && mapa[lpos2][cpos2].tipo!=3 && mapa[lpos2][cpos2].nome!='*')
{
			
	if(mapa[lpos2][cpos2].tipo==4)
	{
	printf("\nPARABENS VOCE PEGOU UMA CARTA");	
	mapa[lpos2][cpos2].nome=' ';
	mapa[lpos2][cpos2].tipo=0;
	carta=1;
	

	d=rand()%10;
	if(d<=5)
	{
		range=2;
		printf("\nSeu alcance aumentou para DUAS casas");
	}
	else if(d>5 && d<=9)
	{
		range=3;
		printf("\nSeu alcance aumentou para TRES casas");
	}
	else if(d==10){
		range=5;
		printf("\nCARTA LENDARIA! Seu alcance aumentou para CINCO casas");
	}
}
      	aux=mapa[lpos2][cpos2];
		mapa[lpos2][cpos2]=mapa[lpos][cpos];
		mapa[lpos][cpos]= aux;
															
		lpos=lpos2;
		cpos=cpos2;
		
			if(bombatrue!=0)
      		{
      			mapa[lbomba][cbomba].tipo=5;
      			mapa[lbomba][cbomba].nome='b';      					
      		}
}
else if(mapa[lpos2][cpos2].tipo==3 )
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		break;
	}

  }while(quantMonstro>0);
 if(quantMonstro==0){
 	printf("PARABENS VOCE GANHOU O JOGO!\n DIGITE SEU NOME PARA O HALL DA FAMA:");
 	modo3=fopen("Resources\\vencedores.txt","w+");
 	if(modo3==NULL){
 		printf("ERRO AO ABRIR O ARQUIVO");
 	}
 	else{
 		modo3=fopen("vencedores.txt","a");
 		fprintf(modo3,"%s",nome);
 		fclose(modo3);
 
 	}
 }
}

void fmonstro(estrutura mapa[][13],int i, int j){
	int t;
	int controlador=0;
	estrutura aux;
			
	do{
		t=rand()%4;
		if(t==0){
		
			if(mapa[i][j+1].tipo==0)
			{
				aux=mapa[i][j+1];
                mapa[i][j+1]=mapa[i][j];
                mapa[i][j]=aux;
                controlador=1;
                break;                
		
			}
		}
		else if(t==1){
			
			if(mapa[i+1][j].tipo==0)
			{
				aux=mapa[i+1][j];
                mapa[i+1][j]=mapa[i][j];
                mapa[i][j]=aux;
                controlador=1;
                break;
			}
		}
	else if(t==2){
	

			if(mapa[i-1][j].tipo==0)
			{
				aux=mapa[i-1][j];
                mapa[i-1][j]=mapa[i][j];
                mapa[i][j]=aux;
                controlador=1;
                break;                
			
			}
		}
			
		else if(t==3){
	
		
			if(mapa[i][j-1].tipo==0)
			{
				aux=mapa[i][j-1];
                mapa[i][j-1]=mapa[i][j];
                mapa[i][j]=aux;
                controlador=1;
                break;
			}
	}
	}while(controlador==0);	
	controlador=0;
}

void fbomba(estrutura mapa[][13], int lbomba, int cbomba, int lpos,int cpos, int quantMonstro){


	if(mapa[lbomba+1][cbomba].tipo==1)
	{
	 	system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
		
	} 	
	
	if(mapa[lbomba-1][cbomba].tipo==1)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
		
	} 	
	  
	if(mapa[lbomba][cbomba-1].tipo==1)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
		
	}			
	
		if(mapa[lbomba][cbomba+1].tipo==1)
	{
	 	system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
	}  
	
		
 	if(mapa[lbomba+1][cbomba].tipo==3)
	{
	 	quantMonstro--;
	} 	
	
	if(mapa[lbomba-1][cbomba].tipo==3)
	{
		quantMonstro--;
	} 	
	  
	if(mapa[lbomba][cbomba-1].tipo==3)
	{
		quantMonstro--;
	}
		
	if(mapa[lbomba][cbomba+1].tipo==3)
	{
	 	quantMonstro--;
	}  
	
	mapa[lbomba][cbomba].tipo=0;
 	mapa[lbomba][cbomba].nome=' ';	
	
	if(mapa[lbomba+1][cbomba].tipo==4)
	{
	 	mapa[lbomba+1][cbomba].nome='c';
	} 	
	else if(mapa[lbomba+1][cbomba].tipo!=9)
	{
	 	mapa[lbomba+1][cbomba].tipo=0;
	 	mapa[lbomba+1][cbomba].nome=' ';
	} 
		
	if(mapa[lbomba-1][cbomba].tipo==4)
	{
		mapa[lbomba-1][cbomba].nome='c';
	} 	
	else if(mapa[lbomba-1][cbomba].tipo!=9)
	{
	 	mapa[lbomba-1][cbomba].tipo=0;
	 	mapa[lbomba-1][cbomba].nome=' ';
	} 	
	  
	if(mapa[lbomba][cbomba-1].tipo==4)
	{
		mapa[lbomba][cbomba-1].nome='c';
	}
									 
	else if(mapa[lbomba][cbomba-1].tipo!=9)
	{
	 	mapa[lbomba][cbomba-1].tipo=0;
	 	mapa[lbomba][cbomba-1].nome=' ';
	}                         
		
	if(mapa[lbomba][cbomba+1].tipo==4)
	{
	 	mapa[lbomba][cbomba+1].nome='c';
	}                        
	
	else if(mapa[lbomba][cbomba+1].tipo!=9)
	{
	 	mapa[lbomba][cbomba+1].tipo=0;
	 	mapa[lbomba][cbomba+1].nome=' '; 
	} 
	
}

void fcarta(estrutura mapa[][13],int lbomba,int cbomba,int lpos,int cpos,int range, int quantMonstro){
	int i;
	
	for(i=1;i<=range;i++){

	if(mapa[lbomba+i][cbomba].tipo==4)
	{
	 	mapa[lbomba+i][cbomba].nome='c';
	} 	
	else if(mapa[lbomba+i][cbomba].tipo!=9)
	{
	 	mapa[lbomba+i][cbomba].tipo=0;
	 	mapa[lbomba+i][cbomba].nome=' ';
	} 
		
	if(mapa[lbomba-i][cbomba].tipo==4)
	{
		mapa[lbomba-i][cbomba].nome='c';
	} 	
	else if(mapa[lbomba-i][cbomba].tipo!=9)
	{
	 	mapa[lbomba-i][cbomba].tipo=0;
	 	mapa[lbomba-i][cbomba].nome=' ';
	} 	
	  
	if(mapa[lbomba][cbomba-i].tipo==4)
	{
		mapa[lbomba][cbomba-i].nome='c';
	}
	
	else if(mapa[lbomba][cbomba-i].tipo!=9)
	{
	 	mapa[lbomba][cbomba-i].tipo=0;
	 	mapa[lbomba][cbomba-i].nome=' ';
	} 
		
	if(mapa[lbomba][cbomba+i].tipo==4)
	{
	 	mapa[lbomba][cbomba+i].nome='c';
	}  
	
	else if(mapa[lbomba][cbomba+i].tipo!=9)
	{
	 	mapa[lbomba][cbomba+i].tipo=0;
	 	mapa[lbomba][cbomba+i].nome=' ';
	} 

	mapa[lbomba][cbomba].tipo=0;
 	mapa[lbomba][cbomba].nome=' ';
	 
	 if(mapa[lbomba+i][cbomba].tipo==1)
	{
		system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
		 
	} 	
	 else if(mapa[lbomba-i][cbomba].tipo==1)
	 {
	 	system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
	
	} 	
	 else if(mapa[lbomba][cbomba-i].tipo==1)
	{	system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		system("pause");
	
	 } 	
	 else if(mapa[lbomba][cbomba+i].tipo==1)
	{	system("cls");
		printf("\n\n\n\n\n\t\t\t\t\t\n\t\n\n\t\t\tGAME OVER\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	system("pause");
	}
	
	
	 	if(mapa[lbomba+i][cbomba].tipo==3)
	{
	 	quantMonstro--;
	} 	
	
	if(mapa[lbomba-i][cbomba].tipo==3)
	{
		quantMonstro--;
	} 	
	  
	if(mapa[lbomba][cbomba-i].tipo==3)
	{
		quantMonstro--;
	}
		
	if(mapa[lbomba][cbomba+i].tipo==3)
	{
	 	quantMonstro--;
	}  
}
		
}
		


