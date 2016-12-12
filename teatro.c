#include <stdio.h>
#include <stdlib.h>
#define LIN 18
#define COL 23
#define RESERVADO 0
#define AVENDA 1
#define VAGO 2
#define CORREDOR 88
#define NUMERO_SESSOES 10
#define LIMITE_FILA 360
typedef struct {
    int cod;
    int status;
    int linha;
    int coluna;
} assento;
typedef struct {
    int codSessao;
    char nomeSessao[40];
    char data[9];
} sessao;

typedef struct {
	assento reserva[LIMITE_FILA];
	int inicio, fim, total;
}filaEstatica;

typedef struct {
    sessao item[NUMERO_SESSOES];
    int prim;
    int ult;
} listaEstatica;

void criarListaVazia(listaEstatica *l) {
    l->prim = 0;
    l->ult  = 0;
}

void criarFilaVazia(filaEstatica *fila){
	fila->inicio = 0;
	fila->fim = 0;
	fila->total = 0;
}

verificaFilaCheia(filaEstatica fila){
	return ((fila.fim+1) % LIMITE_FILA == fila.fim);
}

int verificaFilaVazia(filaEstatica fila){
	return fila.inicio == fila.fim;
}

int reservaAssento(sessao apresentacao, filaEstatica *fila, assento cadeira){
	if(verificaFilaCheia(*fila)){
		printf("Assentos esgotados, tente outra sessão");
	} else if(cadeira.status != RESERVADO) {
		fila->reserva[fila->fim] = cadeira;
		fila->reserva[fila->fim].status = RESERVADO;
		fila->fim = (fila->fim + 1) % LIMITE_FILA;
		fila->total++;
		
	} else {
		printf("O assento especificado já foi reservado");
	}
}

int cancelarReserva(sessao apresentacao, filaEstatica *fila, assento *cadeira){
	if(verificaFilaVazia) {
		printf("Não há reservas");
	} else if(cadeira->status = RESERVADO) {
		*cadeira = fila->reserva[fila->inicio];
		fila->reserva[fila->inicio].status = AVENDA;
		fila->inicio = (fila->inicio + 1) % LIMITE_FILA;
		fila->total--;
	} else {
		printf("Esse assento não foi reservado");
	}
	
}

int verificaListaVazia(listaEstatica l){
    return (l.prim == l.ult);
}

int verificaListaCheia(listaEstatica l) {
    return (l.ult == NUMERO_SESSOES);
}

typedef assento teatro;

void insereElementoLista(listaEstatica *l, sessao apresentacao) {
    int p;
    if (verificaListaCheia(*l)) {
        printf("\nA lista de sessoes esta CHEIA - INSERE ELEMENTO LISTA");
    } else {
        p = l->prim;
        while ((p < l->ult) && (apresentacao.codSessao > l->item[p].codSessao )) {
            p++;
        }
        if (p == l->ult) {
            l->item[p] = apresentacao;
            l->ult++;
        } else if (apresentacao.codSessao != l->item[p].codSessao) {
            int i;
            for (i = l->ult; i > p; i--) {
                l->item[i] = l->item[i-1];
            }
            l->item[p] = apresentacao;
            l->ult++;
        } else {
            printf("\nElemento ja EXISTE na LISTA - INSERE ELEMENTO LISTA\n");
        }
    }
}

void removeElementoLista(listaEstatica *l, sessao *apresentacao) {
    int p, i;
    if (verificaListaVazia(*l)) {
        printf("A lista de sessoes esta VAZIA - REMOCAO NEGADA\n");
    } else {
        p = l->prim;
        while ((p < l->ult) && (apresentacao->codSessao > l->item[p].codSessao)) {
            p++;
        }
        if ((p == l->ult) || (apresentacao->codSessao != l->item[p].codSessao)) {
            printf("\n Elemento nao encontrado na LISTA - REMOVER ELEMENTO \n");
        } else {
            *apresentacao = l->item[p];
            for (i = p; i < l->ult; i++) {
                l->item[i] = l->item[i + 1];
            }
            l->ult--;
        }
    }
}

void exibirSessao(sessao s) {
    
}

void consultarElementoLista(listaEstatica l, int codigoSessao) {
    int p;
    if (verificaListaVazia(l)) {
        printf("\n Nao ha sessoes - LISTA VAZIA\n");
    } else {
        p = l.prim;
        while ((p < l.ult) && (codigoSessao > l.item[p].codSessao)) {
            p++;
        }
        if (p == l.ult || (codigoSessao != l.item[p].codSessao)) {
            printf("\nSessao nao existente na LISTA - CONSULTA ELEMENTO LISTA\n");
        } else {
            //Exibir elemento

        }
    }
}


void resetTeatro(teatro assentos[LIN][COL]) {
    int l,c;
    for(l = 0; l < LIN; l++) {
        for(c = 0; c < COL; c++) {
            if (c == 0 || c == 11 || c == 22) {
                assentos[l][c].status = CORREDOR;
            } else {
                assentos[l][c].status = RESERVADO;
            }
        }
    }
}

void exibeMatrizTeatro(teatro assentos[LIN][COL]) {
    int l, c;
    for (l = 0; l < LIN; l++) {
        for (c = 0; c < COL; c++) {
            if (c == 0) {
                printf("%d", l);
            }
            if(assentos[l][c].status == CORREDOR){
            	printf("\t");
			}
			else{
				printf("%3d", assentos[l][c].status);
			}
        }
        printf("\n");
    }
}

void palco() {
    printf("\t_____________________________________________________________________\n");
    printf("\t|                                                                    |\n");
    printf("\t|                                                                    |\n");
    printf("\t|                         P A L C O                                  |\n");
    printf("\t|                                                                    |\n");
    printf("\t|                                                                    |\n");
    printf("\t|____________________________________________________________________|\n\n");
    printf("\t  1  2  3  4  5  6  7  8  9 10   12 13 14 15 16 17 18 19 20 21\t\n");
}

void menu() {
    printf("\n\tM E N U | | T E A T R O\n");
    printf("\t 1 - Inserir Nova Sessao - TEATRO\n");
    printf("\t 2 - Remover Sessao      - TEATRO\n");
    printf("\t 3 - Consultar sessao    - TEATRO\n");
    printf("\t 4 - Exibir sessoes que vao acontecer - TEATRO\n");
    printf("\t 5 - VENDER ASSENTOS - TEATRO\n");
    printf("\t 6 - RESERVAR ASSENTOS - TEATRO\n");
    printf("\t 7 - Sair - TEATRO\n");
}
int main() {
    teatro matrizTeatro[LIN][COL];
    palco();
    resetTeatro(matrizTeatro);
    exibeMatrizTeatro(matrizTeatro);
    menu();
    return 0;
}

