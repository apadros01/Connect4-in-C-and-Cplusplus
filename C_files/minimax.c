#include "minimax.h"
#include "4enratlla.h"

void crea1Nivell(Node *pare, int profunditat, int dificultat){
    int i;
    pare->n_fills=determinaFills(pare->tauler);
    for(i=0;i<pare->n_fills;i++){
        pare->fills[i]=creaNode(pare,i,profunditat,dificultat);
    }
}

void creaArbreRecursiu(Node *arrel,int profunditat, int dificultat){ //això serveix per crear l'arbre amb varios nivells de profunditat
    int i;
    crea1Nivell(arrel,profunditat,dificultat);
    for(i=0;i<arrel->n_fills;i++){
        if(arrel->fills[i]->n_fills>0){
            creaArbreRecursiu(arrel->fills[i],profunditat+1,dificultat);
        }
    }
}

Node *creaNode(Node *pare, int numFill, int profund, int dificultat){
    char jugador;
    if(profund % 2 == 0){
        jugador=HUMA;
    }
    else{
        jugador=ORD;
    }
    Node *p=(Node*)malloc(sizeof(Node)); 
    p->profunditat=profund;
    copiaTauler(p->tauler,pare->tauler);
    aplicarTirada(p->tauler,determinaColumna(p->tauler,numFill),jugador);
if(profund<dificultat && guanyador(p->tauler,jugador)==15 ){ //mentre no estigui al màxim de profunditat o CAP HA GUANYAT
    
        p->n_fills=determinaFills(p->tauler);
        p->fills=malloc(p->n_fills*sizeof(Node*));                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
    }
    else{
        p->n_fills=0; 
        p->fills=NULL;
        p->valor=heuristica(p,profund);
    }	
    return p;
}

void esborraArbre(Node *arrel){
    int i;
    for(i=0;i<arrel->n_fills;i++){
        esborraArbre(arrel->fills[i]);
        free(arrel->fills[i]);
    }
}

void minim(Node *arrel){ 
    int i;
    double valorminim=10000099;
    if(arrel->n_fills>0){
        for(i=0;i<arrel->n_fills;i++){
            if(arrel->fills[i]->valor<valorminim){
                valorminim=arrel->fills[i]->valor;
            }
        }
    arrel->valor=valorminim;
    }
}

void maxim(Node *arrel){ //això envia el valor màxim un nivell cap adalt
    int i;
    double valormax=-10000099;
    if(arrel->n_fills>0){
        for(i=0;i<arrel->n_fills;i++){
            if(arrel->fills[i]->valor>valormax){
                valormax=arrel->fills[i]->valor;
            }
        }
    arrel->valor=valormax;
    }    
}


void minimax(Node *arrel, int dificultat){
    int i;
    if(arrel->profunditat<dificultat-1){
        for(i=0;i<arrel->n_fills;i++){
            minimax(arrel->fills[i], dificultat);
            if(arrel->profunditat%2==0){
                minim(arrel->fills[i]);
            }
            else{
                maxim(arrel->fills[i]);
            }
        }
    }
}