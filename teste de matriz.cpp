#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int vida = 3;
void Inicio();
void Perdeu();
void Tutorial();
void Fase1();
void Fase2();
void Fase3();


int main() {
    int escolha = 0;
    system("cls");
    Inicio();
    cout << "Bem Vindo ao Jogo explorador!" << endl;
    cout << "[1] --> Jogar\n[2] --> Tutorial\n[3] --> Sair\nEScolha: ";
    cin >> escolha;
    switch(escolha) {
        case 1:
            vida = 3;
            Fase1();
            if(vida == 0){
                return main(); // Apos finalizar o loop e a vida estiver em 0, volta ao menu principal.
            }
            Fase2();
            if(vida == 0){
            	return main();
			}
			Fase3();
			if(vida == 0){
				return main();
			}
			system("cls");
			cout << "/tParabens! Voce venceu o jogo!";
			system("pause");
			return main();
            break;

        case 2:
            Tutorial();
            return main();
            break;

        case 3:
            return 0;
            break;
        default:
        	return main();
       	break;
    }
}
void Perdeu() {
    system("cls");
    cout << "Voce acertou um espinho! Restam " << vida - 1 << " chances para voce!";
    cout << "\nRetornando em 5...";
    Sleep(800);
    cout << "\nRetornando em 4...";
    Sleep(800);
    cout << "\nRetornando em 3...";
    Sleep(800);
    cout << "\nRetornando em 2...";
    Sleep(800);
    cout << "\nRetornando em 1...";
    Sleep(800);
    vida -=1;
}

void Inicio() {
    cout << "Vamos comecar!\n";
}

void Tutorial() {
    int lixo = 0;
    system ("cls");
    cout << "O jogo eh do estilo aventura/puzzle onde o objetivo eh o jogador conseguir passar de tres fases.\nEm cada fase o jogador deve se movimentar para pegar uma chave para abrir a porta fechada.\n";
    cout << "O jogador possui os seguintes comando:\n --> W: O jogador movimenta uma unidade para cima\n --> A: O jogador movimenta uma unidade para esquerda\n --> S: O jogador movimenta uma unidade para baixo\n";
    cout << " --> D: O jogador movimenta uma unidade para direita\n --> I: O jogador interage com o objeto que ele esta em cima\n";
    system("pause");
    system("cls");
    cout << "&: Simbolo que representa o jogador\n*: Simbolo que representa uma parede\n@: Simbolo que representa a chave para abrir a porta para finalizar a fase, a porta abre no momento que o jogador interage com a chave.";
    cout <<	"\nD: Simbolo que representa a porta fechada\n=: Simbolo que representa a porta aberta quando o jogador interagiu com a chave\nO: Simbolo que representa um botao que o usuario pode interagir, o jogador deve ficar em cima dele para poder interagir.";
    cout <<"\n#: Simbolo que representa um espinho. A fase eh reiniciada quando o jogador toca no espinho, caso a fase seja reiniciada tres vezes, o jogo volta para o menu principal\n";
    cout << ">: Simbolo que representa um teletransporte. O teletransporte sempre deve vir em par, quando o jogador toca em um ele eh transportado para o outro e vice-versa\n";
    system("pause");
    main();
}


void Fase1() {
    char x[25][25];
    int i, j;
    int cx = 12, cy = 12;
    int a = 0;
    char chave = '@';
    char porta = 'D';
    char botao = ' ';
    while (a == 0) 
	{
        for(i = 0; i < 25; i++) 
		{
            for(j = 0; j < 25; j++) 
			{
                if( i == 0 || i == 24 || j == 0 || j == 24) 
				{
                    x[i][j] = '*';
                } 
				else 
				
				{
                    x[i][j] = ' ';
                }
            }
        }

        for(i=0; i < 10; i++) 
		{
            x[i][12] = '*';
        }
        for(i=0; i < 25; i++) 
		{
            x[10][i] = '*';
        }
        for(i=0; i < 25; i++) 
		{
            x[18][i] = '*';
        }
        x[7][22] = botao;
		x[10][6] = porta;
        x[18][12] = '=';
        x[22][12] = chave;
        x[1][23] = '|';
        x[13][2] = '#', x[13][22] = '#';
        x[5][5] = '>', x[5][22] = '>';
        x[cx][cy] = '&';
        system("cls");

        for(i = 0; i < 25; i++) 
		{
            cout << "\t\t\t";
            for(j = 0; j < 25; j++) 
			{
                cout << x[i][j] << " ";
            }
            cout << "\n";
        }


        switch(getch()) 
		{
        	case 'w':
            case 'W':
            case 72:
               	if(x[cx-1][cy] == '#')
                {
                	Perdeu();
                    if(vida > 0) 
					{
                        return Fase1();
                    } 
					else 
					{
                        a = 1;
                    }
				}
			    if(x[cx-1][cy] == ' ' || x[cx-1][cy] == '=' || x[cx-1][cy] == '@'|| x[cx-1][cy] == '>' || x[cx-1][cy] == 'O' || x[cx-1][cy] == '|') 
				{
                    cx-=1;
                }
                break;

            case 'a':
            case 'A':
            case 75:
               	if(x[cx][cy-1] == '#')
				{
					Perdeu();
                    if(vida > 0) 
					{
                        return Fase1();
                    } 
					else 
					{
                        a = 1;
                    }
				}
			    if(x[cx][cy-1] == ' ' || x[cx][cy-1] == '=' || x[cx][cy-1] == '@' || x[cx][cy-1] == '>' || x[cx][cy-1] == 'O' || x[cx][cy-1] == '|' ) 
				{
                    cy-=1;
                }
                break;

            case 's':
            case 'S':
            case 80:
			    if(x[cx+1][cy] == '#') // Verificação de espinho a frente
                {
                	Perdeu(); //Função para mostrar que perdeu.
                    if(vida > 0) 
					{
                        return Fase1(); //Caso sua vida for maior que zero, joga a fase 1 de novo.
                    } 
					else 
					{
                        a = 1; //Finaliza o loop do jogo e prossegue.
                    }
				}
			    if(x[cx+1][cy] == ' ' || x[cx+1][cy] == '=' || x[cx+1][cy] == '@' || x[cx+1][cy] == '>' || x[cx+1][cy] == 'O' || x[cx+1][cy] == '|') 
				{
                    cx+=1; //Movimentação basica e com todas as permissões por quais pode se movimentar
                }
                break;

            case 'd':
            case 'D':
            case 77:
				if(x[cx][cy+1] == '#') 
				{
					Perdeu();
                    if(vida > 0) 
					{
                        return Fase1();
                    } 
					else 
					{
                        a = 1;
                    }
                }
				if(x[cx][cy+1] == ' ' || x[cx][cy+1] == '=' || x[cx][cy+1] == '@' || x[cx][cy+1] == '>' || x[cx][cy+1] == 'O' || x[cx][cy+1] == '|') 
				{
                    cy+=1;
                }
                
                break;

            case 'i':
            case 'I':
                
				if(x[cx][cy] == x[22][12]) //Chave sendo coletada e porta abrindo
				{
                    chave = ' ';
                    porta = '=';
                }
			    
				if(x[cx][cy] == x[5][5])//Teleporte para o outro lado da parede
                {
                	cx = 5, cy = 22;
				}
				else
				{
					if(x[cx][cy] == x[5][22]) //Teleporte de volta pro lugar de origem
					{
						cx = 5, cy = 5;
					}
				}
				if(x[cx][cy] == x[1][23])
				{
					a = 1;
				}
				if(x[cx][cy] == x[7][22]) //Interação com o botão secreto para ter vida infinita
				{
					vida = 999;
				}
            break;
            
            case 189://Carcater ¢ para tornar o botao visivel
            	botao = 'O'; 
            break;
        }
        
    }
}

void Fase2()
{
	char x[50][50];
    int i, j;
    int cx = 24, cy = 24;
    int dcx = 0;
    int a = 0;
    char chave1 = '@';
    char chave2 = '@';
    char chave3 = '@';
    char chave4 = '@';
    char porta1 = 'D';
    char porta2 = 'D';
    char porta3 = 'D';
    char porta4 = 'D';
    char botao = ' ';
    int retorno1 = 0, retorno2 = 0, retorno3 = 0, retorno4 = 0;
    while (a == 0) 
	{
       if(cx != 0)
  	  {
    	dcx = cx;
      }
	    for(i = 0; i < 50; i++) 
		{
            for(j = 0; j < 50; j++) 
			{
                if( i == 0 || i == 49 || j == 0 || j == 49) 
				{
                    x[i][j] = '*';
                } 
				else 
				{
                    x[i][j] = ' ';
                }
            }
        }
        for(i = 19; i < 30; i++) 
		{
            for(j = 19; j < 30; j++) 
			{
                if( i == 19 || i == 29 || j == 19 || j == 29) 
				{
                    x[i][j] = '*';
                } 
				else 
				{
                    x[i][j] = '@';
                }
            }
        }
        for(i = 4; i < 19; i++)
        {
        	x[i][23] = '#';
        	x[i][25] = '#';
		}
		for(i = 30; i <= 45; i++)
		{
			x[i][23] = '#';
        	x[i][25] = '#';
		}
		for(i = 30; i <= 45; i++)
		{
			x[23][i] = '#';
        	x[25][i] = '#';
		}
		for(i = 4; i < 19; i++)
        {
        	x[23][i] = '#';
        	x[25][i] = '#';
		}
		for(i = 1; i < 24;  i++)
		{
			x[i][4] = '*';
			x[i][45] = '*';
			x[4][i] = '*';
			x[45][i] = '*';
		}
		for(i = 25; i < 50;  i++)
		{
			x[i][4] = '*';
			x[i][45] = '*';
			x[4][i] = '*';
			x[45][i] = '*';
		}
        	
		
        x[28][20] = chave1,  x[20][20] = chave2, x[20][28] = chave3, x[28][28] = chave4;
        x[19][24] = porta1, x[29][24] = porta2,  x[24][19] = porta3, x[24][29] = porta4;
        x[21][25] = '=', x[27][23] = '=', x[21][23] = '=', x[27][25] = '=';
        x[25][20] = '#', x[25][21] = '#', x[25][22] = '#', x[25][23] = '#';
        x[26][23] = '#', x[28][23] = '#', x[23][20] = '#', x[23][21] = '#';
        x[23][22] = '#', x[23][23] = '#', x[22][23] = '#', x[20][23] = '#';
        x[20][25] = '#', x[22][25] = '#', x[23][25] = '#', x[28][25] = '#';
        x[23][26] = '#', x[23][27] = '#', x[23][28] = '#', x[26][25] = '#';
        x[25][25] = '#', x[25][26] = '#', x[25][27] = '#', x[25][28] = '#';
        x[2][2] = '>', x[2][47] ='>', x[47][2] = '>', x[47][47] = '>';
        x[1][1] = '|', x[1][48] = '|', x[48][1] = '|', x[48][48] = '|';
        x[2][36] = '>', x[36][47] = '>', x[12][2] = '>', x[47][12] = '>';
        x[24][24] = 'O';
        x[3][2] = botao;
        x[cx][cy] = '&';
        system("cls");
        
		for(i = 0; i < 50; i++) 
		{
            cout << "\t\t\t";
            for(j = 0; j < 50; j++) 
			{
                cout <<	x[i][j] << " ";
                
            }
            cout << "\n";
        }
        cout << cx << cy;
		switch(getch())
		{
			case 'w':
            case 'W':
            case 72:
               	if(x[cx-1][cy] == '#')
                {
                	Perdeu();
                    if(vida > 0) 
					{
                        return Fase2();
                    } 
					else 
					{
                        a = 1;
                    }
				}
			    if(x[cx-1][cy] == ' ' || x[cx-1][cy] == '=' || x[cx-1][cy] == '@'|| x[cx-1][cy] == '>' || x[cx-1][cy] == 'O' || x[cx-1][cy] == '|') 
				{
                    cx-=1;
                }
                break;

            case 'a':
            case 'A':
            case 75:
               	if(x[cx][cy-1] == '#')
				{
					Perdeu();
                    if(vida > 0) 
					{
                        return Fase2();
                    } 
					else 
					{
                        a = 1;
                    }
				}
			    if(x[cx][cy-1] == ' ' || x[cx][cy-1] == '=' || x[cx][cy-1] == '@' || x[cx][cy-1] == '>' || x[cx][cy-1] == 'O' || x[cx][cy-1] == '|' ) 
				{
                    cy-=1;
                }
                break;

            case 's':
            case 'S':
            case 80:
			    if(x[cx+1][cy] == '#') // Verificação de espinho a frente
                {
                	Perdeu(); //Função para mostrar que perdeu.
                    if(vida > 0) 
					{
                        return Fase2(); //Caso sua vida for maior que zero, joga a fase 1 de novo.
                    } 
					else 
					{
                        a = 1; //Finaliza o loop do jogo e prossegue.
                    }
				}
			    if(x[cx+1][cy] == ' ' || x[cx+1][cy] == '=' || x[cx+1][cy] == '@' || x[cx+1][cy] == '>' || x[cx+1][cy] == 'O' || x[cx+1][cy] == '|') 
				{
                    cx+=1; //Movimentação basica e com todas as permissões por quais pode se movimentar
                }
                break;

            case 'd':
            case 'D':
            case 77:
				if(x[cx][cy+1] == '#') 
				{
					Perdeu();
                    if(vida > 0) 
					{
                        return Fase2();
                    } 
					else 
					{
                        a = 1;
                    }
                }
				if(x[cx][cy+1] == ' ' || x[cx][cy+1] == '=' || x[cx][cy+1] == '@' || x[cx][cy+1] == '>' || x[cx][cy+1] == 'O' || x[cx][cy+1] == '|') 
				{
                    cy+=1;
                }
                
                break;

            case 'i':
            case 'I':
				if(cx == 28 && cy == 20) //Chave1 sendo coletada e porta1 abrindo
				{
                    chave1 = ' ';
                    porta1 = '=';
                }
                if(cx == 20 && cy == 20) //Chave2 sendo coletada e porta2 abrindo
				{
                    chave2 = ' ';
                    porta2 = '=';
                }
                if(cx == 20 && cy == 28) //Chave3 sendo coletada e porta3 abrindo
				{
                    chave3 = ' ';
                    porta3 = '=';
                }
                if(cx == 28 && cy == 28) //Chave3 sendo coletada e porta3 abrindo
				{
                    chave4 = ' ';
                    porta4 = '=';
                }
				
				
				if((cx == 47 && cy == 12) || (cx == 2 && cy == 2))//Teleporte para a saida correta.
                {
                	if(retorno1 == 0)
                	{
                		cx = 2, cy = 2;
                		retorno1 =  1;
					}
					else
					{
						cx = 47, cy = 12;
						retorno1 = 0;
					}
				}
				
				
				if((cx == 36 && cy == 47) || (cx == 47 && cy ==2))//Teleporte para outro lado.
                {
                	if(retorno2 == 0)
                	{
                		cx = 47, cy = 2;
                		retorno2 = 1;
					}
					else
					{
						cx = 36, cy = 47;
						retorno2 = 0;
					}
				}
				
				
				if((cx == 12 && cy == 2) || (cx == 2 && cy == 47))
				{
					if(retorno3 == 0)
					{
						cx = 2, cy = 47;
						retorno3 = 1;
					}
					else
					{
						cx = 12, cy = 2;
						retorno3 = 0;
					}
				}
				
				
				if((cx == 2 && cy == 36) || (cx == 47 && cy == 47))
				{
					if(retorno4 == 0)
					{
						cx = 47, cy = 47;
						retorno4 = 1;
					}
					else
					{
						cx = 2, cy = 36;
						retorno4 = 0;
					}
				}
			
				
				if(cx == 1 && cy == 1)
				{
					a = 1;
				}
				if(cx == 24 && cy == 24) //Revela dica para a saída correta
				{
					botao = '^';
				}
            	
			break;
            
		}	
	}
}

void Fase3()
{
	char x[75][75];
    int i, j;
    int cx = 38, cy = 38;
    int a = 0;
    char chave1 = '@';
    char porta1 = 'D';
    char chave2 = '@';
    char porta2 = 'D';
    int retorno = 0;
    char exit[5]; 
    	 exit[0] = '*',  exit[1] = '*',  exit[2] = '*', exit[3] = '*', exit[4] = '*';
    while (a == 0)
    {
    	for(i = 0; i < 75; i++) 
		{
            for(j = 0; j < 75; j++) 
			{
                if( i == 0 || i == 74 || j == 0 || j == 74) 
				{
                    x[i][j] = '*';
                } 
				else 
				{
                    x[i][j] = ' ';
                }
            }
        }
        for(i = 0; i < 65; i++)
        {
        	x[39][i] = '*';
        	x[37][i] = '*';
		}
		for(i = 70; i < 75; i++)
        {
        	x[i][31] = '*';
        	x[i][37] = '*';
		}
		for(i = 30; i < 37; i++)
		{
			x[i][12] = '*';
			x[i][15] = '*';
		}
		for(i = 12; i < 16; i++)
		{
			x[30][i] = '*';
		}
		for(i = 15; i < 37; i++)
		{
			x[i][37] = '*';
			x[i][39] = '*';
		}
		for(i = 31; i < 46; i++)
		{
			x[15][i] = '*';
			x[5][i] = '*';
		}
		for(i = 6; i < 15; i++)
		{
			x[i][31] = '*';
			x[i][45] = '*';
		}
		for(i = 34; i < 37; i++)
		{
			x[i][64] = '*';
		}
		for(i = 40; i < 44; i++)
		{
			x[i][64] = '*';
		}
		for(i = 64; i < 75; i++)
		{
			x[33][i] = '*';
			x[44][i] = '*';
		}
		
		x[70][32] = exit[0], x[70][33] = exit[1], x[70][34] = exit[2], x[70][35] = exit[3], x[70][36] = exit[4];
		x[38][2] = 'O', x[37][38] = porta1, x[38][69] = '>', x[72][34] = '>';
		x[71][32] = '|';
		x[37][13] = '=', x[37][14] = '=', x[15][38] = '=', x[38][64] = '=';
		x[10][38] = chave2, x[38][39] = porta2;
		x[36][13] = '#', x[34][14] = '#', x[32][13] = '#', x[31][13] = chave1;
		x[cx][cy] = '&';
		system("cls");
        
        for(i = 0; i < 75; i++) 
		{
            cout << "\t\t\t";
            for(j = 0; j < 75; j++) 
			{
                cout <<	x[i][j] << " ";
                
            }
            cout << "\n";
        }
        cout << cx << cy << retorno;
        switch(getch())
		{
			case 'w':
            case 'W':
            case 72:
               	if(x[cx-1][cy] == '#')
                {
                	Perdeu();
                    if(vida > 0) 
					{
                        return Fase3();
                    } 
					else 
					{
                        a = 1;
                    }
				}
			    if(x[cx-1][cy] == ' ' || x[cx-1][cy] == '=' || x[cx-1][cy] == '@'|| x[cx-1][cy] == '>' || x[cx-1][cy] == 'O' || x[cx-1][cy] == '|') 
				{
                    cx-=1;
                }
                break;

            case 'a':
            case 'A':
            case 75:
               	if(x[cx][cy-1] == '#')
				{
					Perdeu();
                    if(vida > 0) 
					{
                        return Fase3();
                    } 
					else 
					{
                        a = 1;
                    }
				}
			    if(x[cx][cy-1] == ' ' || x[cx][cy-1] == '=' || x[cx][cy-1] == '@' || x[cx][cy-1] == '>' || x[cx][cy-1] == 'O' || x[cx][cy-1] == '|' ) 
				{
                    cy-=1;
                }
                break;

            case 's':
            case 'S':
            case 80:
			    if(x[cx+1][cy] == '#') // Verificação de espinho a frente
                {
                	Perdeu(); //Função para mostrar que perdeu.
                    if(vida > 0) 
					{
                        return Fase3(); //Caso sua vida for maior que zero, joga a fase 1 de novo.
                    } 
					else 
					{
                        a = 1; //Finaliza o loop do jogo e prossegue.
                    }
				}
			    if(x[cx+1][cy] == ' ' || x[cx+1][cy] == '=' || x[cx+1][cy] == '@' || x[cx+1][cy] == '>' || x[cx+1][cy] == 'O' || x[cx+1][cy] == '|') 
				{
                    cx+=1; //Movimentação basica e com todas as permissões por quais pode se movimentar
                }
                break;

            case 'd':
            case 'D':
            case 77:
				if(x[cx][cy+1] == '#') 
				{
					Perdeu();
                    if(vida > 0) 
					{
                        return Fase3();
                    } 
					else 
					{
                        a = 1;
                    }
                }
				if(x[cx][cy+1] == ' ' || x[cx][cy+1] == '=' || x[cx][cy+1] == '@' || x[cx][cy+1] == '>' || x[cx][cy+1] == 'O' || x[cx][cy+1] == '|') 
				{
                    cy+=1;
                }
                
                break;

            case 'i':
            case 'I':
                
				if(cx == 31 && cy == 13) //Chave sendo coletada e porta abrindo
				{
                    chave1 = ' ';
                    porta1 = '=';
                }
			    if(cx == 10 && cy == 38) //Chave sendo coletada e porta abrindo
				{
                    chave2 = ' ';
                    porta2 = '=';
                }
				if((cx == 72 && cy == 34) || (cx == 38 && cy == 69))//Teleporte para a saida.
                {
                	if(retorno == 0)
                	{
                		cx = 72, cy = 34;
                		retorno = 1;
					}
					else
					{
						cx = 38, cy = 69;
						retorno = 0;
					}
				}
				
				if(cx == 71 & cy == 32)
				{
					a = 1;
				}
				if(cx == 38 && cy == 2) //Interação com o botão secreto para ter vida infinita
				{
					exit[0] = 'S', exit[1] = 'A', exit[2] = 'I', exit[3] = 'D', exit[4] = 'A';
				}
            break;
		}
	}
}
