#include <stdio.h>
#include<math.h>
#include <stdlib.h>
#include<time.h>
#define BUIDA '-'
#define HUMA 'X'
#define ORD 'O'
#define N 8
#define vermell "\x1b[31m"
#define verd "\x1b[32m"
#define negre "\x1b[0m"
#define clear() printf("\033[H\033[J") 

typedef struct node {
struct node **fills;
int n_fills;
char tauler[N][N];
double valor;
int profunditat;
 } Node;
 
 
void crea1Nivell(Node *pare, int nivell, int dificultat);
void creaArbreRecursiu(Node *arrel, int profunditat, int dificultat);
Node *creaNode(Node *pare, int numFill, int profund, int dificultat);
void esborraArbre(Node *arrel);
void minimax(Node *arrel, int dificultat);
void minim(Node *arrel);
void maxim(Node *arrel);