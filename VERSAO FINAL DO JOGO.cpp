#include<iostream>
#include<stdlib.h>
#include<cstdlib>
#include<ctime>
#include<locale.h>
using namespace std;
int main()
{
    setlocale(LC_ALL,"portuguese");
    int menu=0,dif=0, modjog=0;
    char nome1[50];
    char nome2[50];
    cout<<" JOGO MASTERMIND "<<endl<<endl;
    cout<< " Qual o seu nome?"<<endl;
    cin.getline(nome1,49);

inicio:
    system(" cls");
    menu=0;
    while(menu!=1 && menu!=2 && menu!=3)
    {
        cout<<" JOGO MASTERMIND "<<endl<<endl;
        cout<< " Seja bem vindo,"<<nome1<<"."<<endl<<endl;
        cout<<"    MENU:"<<endl<<endl;
        cout<<" Pressione 1 para jogar. "<<endl;
        cout<<" Pressione 2 para instru��es. "<<endl;
        cout<<" Pressione 3 para para sair. "<<endl;
        cin>>menu;
        system("cls");
    }
    if(menu==3)
    {
        cout<<" JOGO MASTERMIND "<<endl<<endl;
        cout<<"   At� mais "<<nome1<<", volte sempre!!"<< endl;
        return 0;
    }
    //implementar instrucoes
    if(menu==2)
    {
        cout<<" JOGO MASTERMIND "<<endl<<endl;
        cout<<" INSTRU��ES"<<endl<<endl;

        cout<< "1-resumo:" <<endl<<endl;
        cout<<" O objetivo do Mastermind � descobrir uma combina��o de numeros determi-"<<endl;
        cout<<"nado aleatoriamente pelo computador. "<<endl;
        cout<<" Em cada jogada, o jogador digita uma combina��o de numeros que sao veri-"<<endl;
        cout<<"ficados com a senha gerada e lhes sao mostrados uma quantidade de pinos"<<endl;
        cout<<"brancos e pretos  para que o jogador consiga melhorar sua tentativa."<<endl;
        cout<<" O jogo acaba quando a combina��o � descoberta ou que o n�mero limite de"<<endl;
        cout<<"jogadas � atingido."<<endl<<endl;

        cout<<"2-como jogar"<<endl<<endl;

        cout<<" O jogo conta com as op��es single player e multiplayer."<<endl;
        cout<<" A senha gerada � totalmente aleat�ria e com numeros distintos."<<endl;
        cout<<" Existem 3 niveis de dificuldades:"<<endl;
        cout<<"  Nivel 1:"<<endl;
        cout<<"A senha gerada possui 4 algarismos."<<endl;
        cout<<"O jogador deve escolher entre os numeros 1 at� 6 para compor suas tentativas."<<endl;
        cout<<"Quantidade de rodadas=10."<<endl;
        cout<<"Pontua��o m�xima de 100 pontos"<<endl;
        cout<<"  Nivel 2: "<<endl;
        cout<<"A Senha gerada possui 5 algarismos."<<endl;
        cout<<"O jogador deve escolher entre os numeros 1 at� 7 para compor suas tentativas."<<endl;
        cout<<"Quantidade de rodadas=12."<<endl;
        cout<<"Pontua��o m�xima de 120 pontos"<<endl;
        cout<<"  Nivel 3:"<<endl;
        cout<<"Senha gerada possui 6 algarismos."<<endl;
        cout<<"O jogador deve escolher entre os numeros 1 at� 8 para compor suas tentativas."<<endl;
        cout<<"Quantidade de rodadas=14."<<endl;
        cout<<"Pontua��o m�xima de 140 pontos"<<endl<<endl;
        cout<<" A cada rodada o jogador deve digitar uma senha que sera verificada com a senha "<<endl;
        cout<<"gerada e duas colunas sinalizadas com p(pinos pretos) e b(pinos brancos)s�o "<<endl;
        cout<<"atualizadas com as respectivas quantidades. "<<endl;
        cout<<" Os pinos brancos mostram numeros certo na posi��o correta, j� os pretos mostram"<<endl;
        cout<<"a ocorr�ncia de numero que pertencem a senha mas na posi��o errada"<<endl;
        cout<<" A pontua��o � dada pela quantidade de rodadas, quanto menor o numero de tentativas"<<endl;
        cout<<"maior ser� a sua pontua�ao."<<endl<<endl;


        cout<<"Divirta-se!"<<endl;
        system("pause");
        goto inicio;

    }
    if(menu==1)
    {
dificuldade:
        dif=0;
        modjog=0;

        system("cls");
        while( modjog!=1 && modjog!=2 )
        {
            cout<<" JOGO MASTERMIND "<<endl<<endl;
            cout<<" MODO DE JOGO: "<<endl<<endl;
            cout<<" Aperte 1 para o single player. "<<endl;
            cout<<" Aperte 2 para o multiplayer."<<endl;
            cin>>modjog;
            system("cls");

            if(modjog==2)
            {
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cin.ignore();
                cout<<" Qual o nome do segundo jogador ?"<<endl;
                cin.getline(nome2,49);
            }



            system("cls");
            while(dif!=1 && dif!=2 && dif!=3)
            {

                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<" SELECIONE A DIFICULDADE:"<<endl<<endl;
                cout<< " Aperte 1 para o nivel 1."<<endl;
                cout<< " Aperte 2 para o nivel 2."<<endl;
                cout<< " Aperte 3 para o nivel 3."<<endl;
                cin>>dif;
                system("cls");
            }

            cout<<" JOGO MASTERMIND "<<endl<<endl;
            cout<<"  Seu jogo est� prestes a come�ar. "<<endl;
            cout<<"  Boa sorte, "<<nome1<<"!!!"<<endl<<endl;
            system("pause");
            system("cls");
            int c=0,l=0,c2=0,pp=0,pb=0,score=0, s=0;

            if(dif==1)
            {
                c=4;//coluna
                c2=6;// colunas da matusuario
                l=10;//linhas
                pp=5;// pos�ao preto
                pb=4;// posicao branco
                score=110;
                s=6;//numero para garantir q so sejam gerados numeros ate abaixo do digitado
            }
            if(dif==2)
            {
                c=5;
                c2=7;
                l=12;
                pp=6;
                pb=5;
                score=130;
                s=7;
            }
            if(dif==3)
            {
                c=6;
                c2=8;
                l=14;
                pp=7;
                pb=6;
                score=150;
                s=8;
            }

            int matusuario[l][c2]; //matriz q recebe senha do usuario
            int r=0;//cont rodadas
            int senha[c];//matriz de senha alatoria
            int b=0,p=0;//contadores dos pinos

            int pontos=0;

            //criar a matriz a vai sr atualizada comoposta por zeros
            for(int j=0; j<l; j++)
            {
                for(int i=0; i<c2; i++)
                {
                    matusuario[j][i]=0;
                }
            }
            r=0;

//CORPO DO PROGRAMA
            //parte onde sera introduzido o algoritimo para senhas aleatorias
            int t=0;
            srand(time(0));//* faz com que o numero randomico n se repita, cada vez q inicie o programa*/
            while(t!=c) // pq t= siguinifica q sao todos diferentes 4 passagens pelo if;
            {
                t=0;
                for (int i=0; i<c; i++) /* inicializar o gerador de n�meros aleat�rios */
                {
                    senha[i]= (rand()%s)+1; // soguinifica q vai gerar numero de 1 ate 6
                }
                for (int j=0; j<c; j++ )
                {
                    for (int i=0; i<c; i++ )
                    {
                        if(senha[j]==senha[i])
                        {
                            t++;
                        }
                    }
                }
            }
//
            while(r<l && b<c)
            {

                p=0;
                b=0;
                r++;
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<" Jogador: "<<nome1<<"."<<endl;
                cout<<"   Jogadas "<<endl;
                //gambiarra para indicar os pinos
                if(dif==1)
                {
                    cout<<"         b p";
                }
                if(dif==2)
                {
                    cout<<"           b p ";
                }
                if(dif==3)
                {
                    cout<<"             b p ";
                }

                cout<<" ";
                for(int j=0; j<l; j++)
                {
                    cout<<endl<<" ";
                    for(int i=0; i<c2; i++)
                    {
                        cout<<matusuario[j][i]<<" ";
                    }
                }

                cout<<endl;
                cout<<"Rodada "<< r <<"/"<<l<<endl<<endl;
                cout<<"Escolha um numero entre 1 e "<<s<<endl;
                cout<< " DIGITE A SENHA:"<< endl;

                for (int j=0; j<c; j++)
                {
                    cin>>matusuario[r-1][j];
                    //verifica�ao para o usuario digitar um numero entre os possiveis
                    while(matusuario[r-1][j]>s || matusuario[r-1][j]<1)
                    {
                        cout<<"Numero invalido, digite outro numero para o "<<j+1 <<"� digito"<<endl;
                        cin>>matusuario[r-1][j];
                    }
                }

                system("cls");
                //encontrar os pinos certor no local certo
                for (int j=0; j<c; j++ )
                {
                    if(matusuario[r-1][j]==senha[j])
                    {
                        b++;
                    }
                }
                //encontra os pinos certos no local errado(alterei)
                //compara posicao a posi�ao e garante q sejam contados apenas os pretos com a condi�ao j!=i
                for (int j=0; j<c; j++ )
                {
                    for(int i=0; i<c; i++)
                    {

                        if(matusuario[r-1][i]==senha[j] && j!=i)
                        {
                            p++;
                        }
                    }
                }
                matusuario[r-1][pb]=b;//recebe a quantidade de pinos brancos e adc na posicao referente
                matusuario[r-1][pp]=p;//recebe a quantidade de pinos pretos e adc na posicao referente
            }
            cout<<" JOGO MASTERMIND "<<endl<<endl;
            cout<<" Jogador: "<<nome1<<"."<<endl;
            cout<<"   Jogadas "<<endl;
            //gambiarra para indicar os pinos
            if(dif==1)
            {
                cout<<"         b p";
            }
            if(dif==2)
            {
                cout<<"           b p ";
            }
            if(dif==3)
            {
                cout<<"             b p ";
            }

            cout<<" ";
            for(int j=0; j<l; j++)
            {
                cout<<endl<<" ";
                for(int i=0; i<c2; i++)
                {
                    cout<<matusuario[j][i]<<" ";

                }
            }
            cout<<endl;
            cout<<"Rodada "<< r <<"/"<<l<<endl<<endl;
            cout<<"    FIM DE JOGO"<<endl <<endl;
            system("pause");

            pontos=(score-(10*r));
// para se caso o jogador perder na ultima rodada ele nao reeba nenhuma pontuaca
            if(r==l && b!=c)
            {
                pontos=0;
            }
// PONTUACAO;
            int fim=0;
            system("cls");

            if (modjog==2)//para ir pro multiplayer
            {
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<"    FIM DE JOGO"<<endl <<endl;
                cout<<"  Pontua��o de "<< nome1<< " foi = " <<pontos<<"."<<endl<<endl;
                cout<<"  Senha correta: "<<endl;
                cout<<" ";
                for(int i=0; i<c; i++)
                {
                    cout<<senha[i]<< " " ;
                }
                cout<<endl<<endl;
                system("pause");
                system("cls");
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<"  Seu jogo est� prestes a come�ar. "<<endl;
                cout<<"  Boa sorte "<<nome2<<"!!!"<<endl<<endl;
                system("pause");
                goto multiplayer;
            }
            //single player
            cout<<" JOGO MASTERMIND "<<endl<<endl;
            cout<<"    FIM DE JOGO"<<endl <<endl;
            if(pontos>0)
            {
                cout<< "  Parab�ns, "<<nome1<< " voc� ganhou!!!"<<endl;
                cout<<"  Pontua��o = "<<pontos<<"."<<endl<<endl;

            }
            else
            {
                cout<<" Poxa, "<<nome1<< " voc� perdeu!!!"<<endl;
                cout<<"  Pontua��o = "<<pontos<<"."<<endl<<endl;

            }
            cout<<" Senha correta: "<<endl;
            cout<<" ";
            for(int i=0; i<c; i++)
            {
                cout<<senha[i]<< " " ;
            }
            cout<<endl<<endl;

            system("pause");
            system("cls");
            fim=0;
            while(fim!=1 && fim!=2)
            {
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<"    FIM DE JOGO"<<endl <<endl;
                cout<< "    Deseja jogar novamente, "<<nome1<<" ?"<<endl<<endl;
                cout<<" Pessione 1 para jogar novamente."<<endl;
                cout<<" Pressione 2 para sair do jogo."<<endl;
                cin>>fim;
            }

            if(fim==1)
            {
                goto dificuldade;
            }
            else if(fim==2)
            {
                system("cls");
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<"    FIM DE JOGO"<<endl <<endl;
                cout<<"   At� mais "<<nome1<<", volte sempre!!"<< endl;
                return 0;
            }

multiplayer:

            //copia da primeira parte apenas mudando o nome das variaveis

            system("cls");

            int cmult=0,lmult=0,c2mult=0,ppmult=0,pbmult=0,scoremult=0,smult=0;

            if(dif==1)
            {
                cmult=4;//coluna
                c2mult=6;// colunas da matusuario
                lmult=10;//linhas
                ppmult=5;// pos�ao preto
                pbmult=4;// posicao branco
                scoremult=110;
                smult=6;//para a geracao da senha
            }
            if(dif==2)
            {
                cmult=5;
                c2mult=7;
                lmult=12;
                ppmult=6;
                pbmult=5;
                scoremult=130;
                smult=7;
            }
            if(dif==3)
            {
                cmult=6;
                c2mult=8;
                lmult=14;
                ppmult=7;
                pbmult=6;
                scoremult=150;
                smult=8;
            }

            int matusuariomult[lmult][c2mult]; //matriz q recebe senha do usuario
            int rmult=0;//cont rodadas
            int senhamult[cmult];//matriz de senha alatoria
            int bmult=0,pmult=0;//contadores dos pinos
            int pontosmult=0;

            //criar a matriz a vai sr atualizada comoposta por zeros
            for(int j=0; j<lmult; j++)
            {
                for(int i=0; i<c2mult; i++)
                {
                    matusuariomult[j][i]=0;
                }
            }

//CORPO DO PROGRAMA
            //parte onde sera introduzido o algoritimo para senhas aleatorias
            int tmult=0;
            srand(time(0));//* faz com que o numero randomico n se repita, cada vez q inicie o programa*/
            while(tmult!=cmult) // pq t=c siguinifica q sao todos o nmrs diferentes
            {
                tmult=0;
                for (int i=0; i<cmult; i++) /* inicializar o gerador de n�meros aleat�rios */
                {
                    senhamult[i]= (rand()%smult)+1; // 7 soguinifica q vai gerar numero ate 6

                }

                for (int j=0; j<cmult; j++ )
                {
                    for (int i=0; i<cmult; i++ )
                    {

                        if(senhamult[j]==senhamult[i])
                        {
                            tmult++;
                        }
                    }
                }
            }

            while(rmult<lmult && bmult<cmult)
            {

                pmult=0;
                bmult=0;
                rmult++;


                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<" Jogador: "<<nome2<<"."<<endl;
                cout<<"   Jogadas "<<endl;

                //gambiarra para indicar os pinos
                if(dif==1)
                {
                    cout<<"         b p";
                }
                if(dif==2)
                {
                    cout<<"           b p ";
                }
                if(dif==3)
                {
                    cout<<"             b p ";
                }

                cout<<" ";
                for(int j=0; j<lmult; j++)
                {
                    cout<<endl<<" ";
                    for(int i=0; i<c2mult; i++)
                    {
                        cout<<matusuariomult[j][i]<<" ";
                    }
                }
                cout<<endl;
                cout<<"Rodada "<< rmult <<"/"<<lmult<<endl<<endl;
                cout<<"Escolha um numero entre 1 e "<<smult<<endl;
                cout<< " DIGITE A SENHA:"<< endl;


                for (int j=0; j<cmult; j++)
                {
                    cin>>matusuariomult[rmult-1][j];
                    while(matusuariomult[rmult-1][j]>smult || matusuariomult[rmult-1][j]<1)
                    {
                        cout<<"Numero invalido, digite outro numero para o "<<j+1 <<"� digito"<<endl;
                        cin>>matusuariomult[rmult-1][j];
                    }
                }

                system("cls");
                //encontrar os pinos certor no local certo
                for (int j=0; j<cmult; j++ )
                {
                    if(matusuariomult[rmult-1][j]==senhamult[j])
                    {
                        bmult++;
                    }
                }

                //encontra os pinos certos no local errado(alterei)
                for (int j=0; j<cmult; j++ )
                {
                    for(int i=0; i<cmult; i++)
                    {

                        if(matusuariomult[rmult-1][i]==senhamult[j] && j!=i)
                        {
                            pmult++;
                        }
                    }

                }

                matusuariomult[rmult-1][pbmult]=bmult;//recebe a quantidade de pinos brancos e adc na posicao referente
                matusuariomult[rmult-1][ppmult]=pmult;//recebe a quantidade de pinos pretos e adc na posicao referente

            }
            cout<<" JOGO MASTERMIND "<<endl<<endl;
            cout<<" Jogador: "<<nome2<<"."<<endl;
            cout<<"   Jogadas "<<endl;

            //gambiarra para indicar os pinos
            if(dif==1)
            {
                cout<<"         b p";
            }
            if(dif==2)
            {
                cout<<"           b p ";
            }
            if(dif==3)
            {
                cout<<"             b p ";
            }

            cout<<" ";
            for(int j=0; j<lmult; j++)
            {
                cout<<endl<<" ";
                for(int i=0; i<c2mult; i++)
                {
                    cout<<matusuariomult[j][i]<<" ";

                }
            }
            cout<<endl;
            cout<<"Rodada "<< rmult <<"/"<<lmult<<endl<<endl;
            cout<<"    FIM DE JOGO"<<endl <<endl;

            pontosmult=(scoremult-(10*rmult));
            // garntir q se caso o jogador perder na ultima rodada, ele nao receba nenhuma pontuaca
            if(rmult==lmult && bmult!=cmult)
            {
                pontosmult=0;
            }
            system("pause");
            system("cls");

//PONTUACAO;
            int fimmult=0;


            cout<<" JOGO MASTERMIND "<<endl<<endl;
            cout<<"    FIM DE JOGO"<<endl <<endl;
            cout<<"  Pontua��o de "<< nome2<< " foi= " <<pontosmult<<"."<<endl<<endl;
            cout<<" Senha correta: "<<endl;
            cout<<" ";
            for(int i=0; i<cmult; i++)
            {
                cout<<senhamult[i]<< " " ;
            }
            cout<<endl<<endl;
            system("pause");
            system("cls");
            cout<<" JOGO MASTERMIND "<<endl<<endl;
            cout<<"    FIM DE JOGO"<<endl <<endl;
            //comparacao das pontuacao para determinar o vencedor
            if(pontos>pontosmult )
            {
                cout<< "  Parab�ns, "<<nome1<< " voc� ganhou!!!"<<endl;
                cout<<"  Pontua��o = "<<pontos<<"."<<endl<<endl;
                cout<< "  Infelizmente, "<<nome2<< " voc� perdeu."<<endl;
                cout<<"  Pontua��o = "<<pontosmult<<"."<<endl<<endl;
            }
            if(pontos<pontosmult )
            {
                cout<< "  Parab�ns, "<<nome2<< " voc� ganhou!!!"<<endl;
                cout<<"  Pontua��o = "<<pontosmult<<"."<<endl<<endl;
                cout<< "  Infelizmente, "<<nome1<< " voc� perdeu. "<<endl;
                cout<<"  Pontua��o = "<<pontos<<"."<<endl<<endl;
            }
            if(pontos==pontosmult)
            {
                cout<<" Ocorreu um empate entre voc�s, que tal uma nova partida ?"<<endl<<endl;

            }
            system("pause");
            system("cls");
            fimmult=0;
            while(fimmult!=1 && fimmult!=2)
            {
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<"    FIM DE JOGO"<<endl <<endl;
                cout<< "    Desejam jogar novamente,"<<nome1<<" e "<<nome2<<" ?"<<endl<<endl;
                cout<<" Pessione 1 para jogar novamente."<<endl;
                cout<<" Pressione 2 para sair do jogo."<<endl;
                cin>>fimmult;
            }

            if(fimmult==1)
            {
                goto dificuldade;
            }
            else if(fimmult==2)
            {
                system("cls");
                cout<<" JOGO MASTERMIND "<<endl<<endl;
                cout<<"    FIM DE JOGO"<<endl <<endl;

                cout<<"   At� mais "<<nome1<<" e "<<nome2<<", voltem sempre!!"<< endl;
                return 0;

            }

        }
    }
}












