
void copiaTauler(char desti[N][N], char origen[N][N]);
int determinaFills(char tauler[N][N]);
int determinaColumna(char tauler[N][N], int numFill);
void aplicarTirada(char tauler[N][N], int numFill,char jugador);
void imprimirTauler2(char tauler[N][N]);
void inicialitzaTauler(char tauler[N][N]); 
int determinaFila(char tauler[N][N],int columna);
int guanyadorFiles(char tauler[N][N], char torn);
int guanyadorColumnes(char tauler[N][N], char torn);
int guanyadorDiagonals(char tauler[N][N],char torn);
void tirar(char tauler[N][N], char torn);
int guanyador(char tauler[N][N], char torn);
int ColumnaPlena(char tauler[N][N], int col);

double heuristica(Node *arrel, int profund);

int tiradaBona(Node *arrel, int dificultat);