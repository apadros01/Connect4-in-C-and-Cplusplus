#include "minimax.h"
#include "4enratlla.h"


int main(){


    Node *arrel=(Node *)malloc(sizeof(Node));
    arrel->n_fills=N;
    arrel->fills=malloc(arrel->n_fills*sizeof(Node *));
    arrel->profunditat=0;
    inicialitzaTauler(arrel->tauler);
    int comptadortirades=0;
    int comptadortirades2=0;
    int comptadortirades3=0;
    printf(" \t \tBON DIA! \n Si vols jugar un 1 vs 1, prem a! \n Si vols jugar contra l'ordinador, prem b!\n Prem qualsevol altra tecla per sortir:\n ");
    char operacio;
    fflush(stdin);
    operacio=getchar();
    
    
    switch(operacio){
        case 'b': //aquest és el cas on jugues contra l'ordinador
    
            printf("\nAmb quin nivell de dificultat vols jugar?:\n Aquestes són totes les opcions:\n 2 - Principiant \n 3 - Fàcil  \n 4 - Normal \n 5 - Avançat \n 6 - Difícil \n 7 - Molt difícil\n ");
            int dificultat,introduit=0;
            char c[10];
            while(introduit==0){
                introduit=1;
                scanf("%s",c);
                dificultat=c[0]-48;
                if(8<=dificultat || dificultat<=1  || c[1]!='\0'){
                    introduit=0;
                    puts("Això no és una opció vàlida, torna-hi:\n");
                    fflush(stdin);
                    }
                }
                
            char quicomenca;
            fflush(stdin);
            printf("\n Si vols començar tu, prem la tecla x. \nSi vols que comenci l'ordinador, prem la tecla o \n");
            scanf("%s",&quicomenca);
            
            switch(quicomenca){
                case 'x': //aquest és el cas on comença tirant l'humà.
            imprimirTauler2(arrel->tauler);
            while(guanyador(arrel->tauler,ORD)==15){
                printf("\n");
                tirar(arrel->tauler,HUMA);
                comptadortirades++;
                if(comptadortirades==64){
                    printf("EMPAT\n\n");
                    break;
                }
                imprimirTauler2(arrel->tauler);
                if(guanyador(arrel->tauler,HUMA)==14){
                    imprimirTauler2(arrel->tauler);                    
                    printf(verd"VICTORIA DE L'HUMA \u263A \u263A \u263A \u263A \n\n"negre);
                    break;
                }
                printf("\n Tirada de l'ordinador:\n\n");
                creaArbreRecursiu(arrel,1,dificultat);
                int tiradabuenax=tiradaBona(arrel,dificultat);
                aplicarTirada(arrel->tauler,tiradabuenax,ORD);
                comptadortirades++;
                imprimirTauler2(arrel->tauler);
                printf(" \nLa màquina ha tirat a la columna %i \n Portem %d tirades\n",tiradabuenax+1,comptadortirades);                
                guanyador(arrel->tauler,ORD);
                esborraArbre(arrel);
                if(comptadortirades==64){
                    printf("EMPAT\n");
                    break;
                }
            }
            if(guanyador(arrel->tauler,ORD)==14){
                
                printf(vermell"\n\n#     # #######     #####  #     #    #    #     # #     #    #    #######\n#     # #          #     # #     #   # #   ##    #  #   #    # #      #    \n#     # #          #       #     #  #   #  # #   #   # #    #   #     #    \n####### #####      #  #### #     # #     # #  #  #    #    #     #    #    \n#     # #          #     # #     # ####### #   # #    #    #######    #    \n#     # #          #     # #     # #     # #    ##    #    #     #    #    \n#     # #######     #####   #####  #     # #     #    #    #     #    #    \n\n"negre);
                
            }
            break;//aquest break talla quan el case de quan comença l'humà.
            
                case 'o': //aquest és el cas on comença tirant l'ordinador
                    while(guanyador(arrel->tauler,HUMA)==15){
                        printf("\n Tirada de l'ordinador:\n\n");
                        creaArbreRecursiu(arrel,1,dificultat);
                        int tiradabuenao=tiradaBona(arrel,dificultat);
                        aplicarTirada(arrel->tauler,tiradabuenao,ORD);
                        comptadortirades3++;
                        imprimirTauler2(arrel->tauler);
                        printf(" \nLa màquina ha tirat a la columna %i \n Portem %d tirades\n",tiradabuenao+1,comptadortirades3);                        
                        if(guanyador(arrel->tauler,ORD)==14){
                            printf(vermell"\n\n#     # #######     #####  #     #    #    #     # #     #    #    #######\n#     # #          #     # #     #   # #   ##    #  #   #    # #      #    \n#     # #          #       #     #  #   #  # #   #   # #    #   #     #    \n####### #####      #  #### #     # #     # #  #  #    #    #     #    #    \n#     # #          #     # #     # ####### #   # #    #    #######    #    \n#     # #          #     # #     # #     # #    ##    #    #     #    #    \n#     # #######     #####   #####  #     # #     #    #    #     #    #    \n\n"negre);
                            break;
                        }
                        esborraArbre(arrel);
                        if(comptadortirades3==64){
                            printf("EMPAT\n");
                            break;
                        }
                        printf("\n");
                        tirar(arrel->tauler,HUMA);
                        imprimirTauler2(arrel->tauler);
                        guanyador(arrel->tauler,HUMA);
                        comptadortirades3++;
                        if(comptadortirades3==64){
                            printf("EMPAT\n");
                            break;
                        }
                    }
                if(guanyador(arrel->tauler,HUMA)==14){
                    imprimirTauler2(arrel->tauler);
                    printf(verd"VICTORIA DE L'HUMÀ \u263A \u263A \u263A\n\n"negre);
                }
                    break; //AQUEST és el break de quan comença l'ordinador
            
                default:
                    puts("Aquesta opció no existeix\n");
                    break; //aquest és el que tanca el default
        }            //això tanca el switch de l'ordre dels torns
            break; //aquest és el case del 'b'
            
        case 'a': //aquest és el cas quan jugues un 1 contra 1 contra un altre humà
            imprimirTauler2(arrel->tauler);
            printf("Comença X \n");
            while(comptadortirades2<=63){
                tirar(arrel->tauler,HUMA);
                comptadortirades2++;
                imprimirTauler2(arrel->tauler);
                if(guanyador(arrel->tauler,HUMA)==14){
                    printf(verd"Ha guanyat la X\n"negre);
                    break;
                }
                tirar(arrel->tauler,ORD);
                comptadortirades2++;
                imprimirTauler2(arrel->tauler);
                if(guanyador(arrel->tauler,ORD)==14){
                    printf(vermell"Ha guanyat la O \n"negre);
                    break;
                }
            }
        if(comptadortirades2==64){
            puts("EMPAT\n");
        }
            break;
        
        default:
            puts("ADÉU\n");
        break;
    }
     return 0;
}

void inicialitzaTauler(char tauler[N][N]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            tauler[i][j]=BUIDA;
        }
    }
}


void imprimirTauler2(char tauler[N][N]){
    int i,j;
    printf("\n");
    for(i=0;i<N;i++){
        printf(" ");     
        printf("\t\t%d |",i+1);
        for(j=0;j<N;j++){
            printf(" ");
            if(tauler[i][j]==HUMA){
            printf(verd"%c"negre,tauler[i][j]);
            }
            if(tauler[i][j]==ORD){
            printf(vermell"%c"negre,tauler[i][j]);
            }
            if(tauler[i][j]==BUIDA){
            printf("%c",tauler[i][j]);
            }
            printf(" |");
        }
        printf(" ");       
        printf("\n");
    }
    printf("\t\t");
    printf("    ");
    for(j=0;j<N;j++){
        printf("%d   ",j+1);
    }
  printf("\n");
}





 void copiaTauler(char desti[N][N], char origen[N][N]){ //això només copia el tauler per moure'l entre nodes.
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            desti[i][j]=origen[i][j];
            }
    }
 }
 
 
 int determinaFills(char tauler[N][N]){ //això, donada una situació de la partida, determina el nombre de possibles tirades del següent jugador.
    int col,PosiblesColumnes;
    PosiblesColumnes=0;
    for(col=0;col<N;col++){
        if(tauler[0][col]==BUIDA){
            PosiblesColumnes++;
        }
    }
    return PosiblesColumnes;
 }
 
 int determinaColumna(char tauler[N][N], int numFill){ //això serveix per comprovar a quina columna es pot tirar, donat el numFill
   int j,aux;
   aux=-1;
   for(j=0;j<N;j++){
      if(tauler[0][j]==BUIDA){//és a dir, la columna no està plena
            aux++;
            if(aux==numFill){
                return j;
            }      
        }
    }
    return -1;
    //en teoria aquí no hauria d'arribar mai, però ho poso perquè no salti un warning.
 }
 
 int determinaFila(char tauler[N][N],int columna){ //això serveix per determinar quina és la fila més baixa on tirar
    int i,aux;
    aux=-1;
    for(i=N-1;i>=0;i--){ 
        if(tauler[i][columna]==BUIDA){
            aux=i;
            break;
        }
    }
   return aux;
}
 
 void aplicarTirada(char tauler[N][N], int numFill, char jugador){ //això, donat el numFill, canvia el BUIDA de més abaix per la tirada del jugador que correspongui.
    int fila;
    fila=determinaFila(tauler,numFill);
    tauler[fila][numFill]=jugador;
 }

 
 int guanyadorFiles(char tauler[N][N], char torn){//aquesta funció té el propòsit de comptar si hi ha 4 X seguides en una fila per detectar que algú ha guanyat.
    int files, columnes;
    for(files=0;files<N;files++){
        for(columnes=0;columnes<=N-4;columnes++){ //faig que columnes vagi fins N-4 perquè no es pot fotre 4 seguides començant per la antepenultima.
            if(tauler[files][columnes]==torn && tauler[files][columnes+1]==torn && tauler[files][columnes+2]==torn && tauler[files][columnes+3]==torn ){
                return 4;
            }
        }
    }
    return 0; //això és per si no n'hi ha 4 de seguides
 }    

 int guanyadorColumnes(char tauler[N][N], char torn){
    int files, columnes;
    for(columnes=0;columnes<N;columnes++){
        for(files=0;files<=N-4;files++){
            if(tauler[files][columnes]==torn && tauler[files+1][columnes]==torn && tauler[files+2][columnes]==torn && tauler[files+3][columnes]==torn ){
                return 4;
            }
        }
    }
     return 0; //això és per si no n'hi ha 4 de seguides
}


int guanyadorDiagonals(char tauler[N][N],char torn){ //això serveix per veure si hi ha un 4 en ralla a les diagonals
    int files,columnes;
    for(files=0;files<=N-4;files++){//aquest bucle serveix per les diagonals cap abaix i cap a la dreta
        for(columnes=0;columnes<=N-4;columnes++){
           if(tauler[files][columnes]==torn && tauler[files+1][columnes+1]==torn && tauler[files+2][columnes+2]==torn && tauler[files+3][columnes+3]==torn){
               return 4;
            } 
        }
    }
    for(files=0;files<=N-4;files++){//aquest bucle serveix per les diagonals cap abaix i cap a la dreta
        for(columnes=N-1;columnes>=3;columnes--){
            if(tauler[files][columnes]==torn && tauler[files+1][columnes-1]==torn && tauler[files+2][columnes-2]==torn && tauler[files+3][columnes-3]==torn){
                return 4;
            }
        }
    }
    return 0; //això és per si no n'hi ha 4 de seguides.
}

int guanyador(char tauler[N][N], char torn){
    if(guanyadorColumnes(tauler,torn)==4 || guanyadorDiagonals(tauler,torn)==4 || guanyadorFiles(tauler,torn)==4){
        return 14;
    }
    return 15;
}

int ColumnaPlena(char tauler[N][N], int col){
    if(tauler[0][col]==ORD || tauler[0][col]==HUMA){
        return 1;
    }
    else{
        return 0;
    }
}
 void tirar(char tauler[N][N], char torn){ //això és per tirar, suposo que serveix per la tirada de l'humà només.
    int fila,columna; //utilitzo "a" per el scanf i l'huma no es confongui pero despŕes amb "columna" l'ordinador ho entendrà.
    printf(" \n A quina columna vols tirar?: \t ");
    char c[50];
    int col,introduit=0;//TOT AQUEST WHILE SERVEIX PERQUÈ EM DEMANI EL SCANF FINS QUE FIQUI ALGUNA COSA VÀLIDA
    while(introduit==0){
        introduit=1;
        scanf("%s",c);
        col=c[0]-48;
        if(8<col || col<1 || ColumnaPlena(tauler,col-1)==1 || c[1]!='\0'){
            introduit=0;
            puts("Això no és una tirada vàlida, torna-hi:\n");
            fflush(stdin);
        }
    }
    columna=col-1; //li resto un perquè l'ordinador entengui bé la tirada.
    fila=determinaFila(tauler,columna);
    tauler[fila][columna]=torn;
}




double heuristica(Node *arrel, int profund){  //14=guanya 15=no guanya  
    int fila, col, puntuacio=0;
    if(guanyador(arrel->tauler,ORD)==14){
        return 100000-profund; //li resto el profund per prioritzar les victòries a les tirades més properes. Si no li posés, li donaria igual guanyar-me en una tirada o en 3.
    }
    else if(guanyador(arrel->tauler,HUMA)==14){
        return -100000+profund; //això és perquè detecti que és pitjor perdre en una tirada que en 3. 
    } 

    for(fila=1;fila<N-2;fila++){ //no té sentit buscar triples i dobles desde la primera fila perquè no es pot fer res si aquesta està ocupada
        for(col=0;col<N;col++){//amb això busquem les combinacions verticals
            if(arrel->tauler[fila+1][col]==ORD && arrel->tauler[fila+2][col]==ORD){//amb això les dobles
               puntuacio=puntuacio+20./fabs(3.5-col); //aquesta divisió serveix per augmentar el valor de les tirades a columnes centrals.
            }
            else if(arrel->tauler[fila+1][col]==HUMA && arrel->tauler[fila+2][col]==HUMA){
                puntuacio=puntuacio-20./fabs(3.5-col); 
            }
                        
            if(arrel->tauler[fila][col]==ORD && arrel->tauler[fila+1][col]==ORD && arrel->tauler[fila+2][col]==ORD){ //aquest if és per les triples
                puntuacio=puntuacio+30./fabs(3.5-col);
            }
            else if(arrel->tauler[fila][col]==HUMA && arrel->tauler[fila+1][col]==HUMA && arrel->tauler[fila+2][col]==HUMA){
                puntuacio=puntuacio-30./fabs(3.5-col);
            }
            
            
            if(arrel->tauler[7][3]==ORD || arrel->tauler[7][4]==ORD){ //això és perquè comenci tirant al mig, que sempre és bona idea.
                puntuacio=puntuacio+1;
            }
        }
    }
    
    
    for(col=0;col<N-2;col++){ //aquest if pels dobles i triples horitzontals
        for(fila=0;fila<N;fila++){
           if(arrel->tauler[fila][col+1]==ORD && arrel->tauler[fila][col+2]==ORD){//amb això les dobles
               puntuacio=puntuacio+20; 
            }
            else if(arrel->tauler[fila][col+1]==HUMA && arrel->tauler[fila][col+2]==HUMA){
                puntuacio=puntuacio-20; 
            }
            
            if(arrel->tauler[fila][col]==ORD && arrel->tauler[fila][col+1]==ORD && arrel->tauler[fila][col+2]==ORD){ //aquest if és per les triples
                puntuacio=puntuacio+30;
            }
            else if(arrel->tauler[fila][col]==HUMA && arrel->tauler[fila][col]==HUMA && arrel->tauler[fila][col+2]==HUMA){
                puntuacio=puntuacio-30;
            }            
            
        }
    }
    
    for(fila=1;fila<N-2;fila++){//això és per mirar triples diagonals d'esquerra a dreta. Començo desde la segona fila perquè no té sentit mirar un triple a la primera si ja està ocupada
        for(col=1;col<N-2;col++){ //vaig fins la columna 5 (la 6 pels humans) perquè sino estariem comprovant asota columnes que no existeixen
            if(arrel->tauler[fila][col]==ORD && arrel->tauler[fila+1][col+1]==ORD && arrel->tauler[fila+2][col+2]==ORD){//això són les diagonals d'esquerra a dreta cap abaix
                puntuacio=puntuacio+30;
            }
            else if(arrel->tauler[fila][col]==HUMA && arrel->tauler[fila+1][col+1]==HUMA && arrel->tauler[fila+2][col+2]==HUMA){
             puntuacio=puntuacio-30;   
            }
        }
    }
    
    for(fila=1;fila<N-2;fila++){ //això és per mirar les triples diagonals de dreta a esquerra
        for(col=N-2;col>=2;col--){ //mateix raonament que a l'anterior bucle.
            if(arrel->tauler[fila][col]==ORD && arrel->tauler[fila-1][col-1]==ORD && arrel->tauler[fila-2][col-2]==ORD){
                puntuacio=puntuacio+30;
            }
            else if(arrel->tauler[fila][col]==HUMA && arrel->tauler[fila-1][col-1]==HUMA && arrel->tauler[fila-2][col-2]==HUMA){
                puntuacio=puntuacio-30;
            }
        }
    }
    return puntuacio;
}




int tiradaBona(Node *arrel, int dificultat){ //amb això determino el màxim dels valors de la profunditat 1.
    int i,aux;
    minimax(arrel,dificultat);
    aux=0;
    double valormax=-12000000;
    for(i=0;i<arrel->n_fills;i++){ //si n_fills=0 RIP
        if(arrel->fills[i]->valor>valormax){
            valormax=arrel->fills[i]->valor;
            aux=i;
        }
    }
    if(valormax>=99992){
        printf("Ja està, has perdut. \n ");
    }
    return determinaColumna(arrel->tauler,aux);
}
