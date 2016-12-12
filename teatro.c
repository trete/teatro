#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
    int codSessao;
} assento;

typedef struct {
	assento reserva[LIMITE_FILA];
	int inicio, fim, total;
}filaEstatica;

typedef struct {
    int codSessao;
    char nomeSessao[40];
    char data[9];
    filaEstatica filaReservas;
    
} sessao;
typedef struct {
    sessao item[NUMERO_SESSOES];
    int prim;
    int ult;
} listaEstatica;

typedef assento teatro;

void criarListaVazia(listaEstatica *l) {
    l->prim = 0;
    l->ult  = 0;
}

int verificaListaVazia(listaEstatica l){
    return (l.prim == l.ult);
}

int verificaListaCheia(listaEstatica l) {
    return (l.ult == NUMERO_SESSOES);
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

int reservaAssento(filaEstatica *fila, assento cadeira){
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

int cancelarReserva(filaEstatica *fila, assento *cadeira){
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
    printf("\n=====================\n");
    printf("Codigo do assento: %d\n", s.codSessao);
    printf("Nome apresentacao: %s\n", s.nomeSessao);
    printf("Data da apresentacao: %s\n", s.data);
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
            exibirSessao(l.item[p]);
        }
    }
}

void exibirListaSessoes(listaEstatica l) {
    int p;
    if (verificaListaVazia(l)) {
        printf("\n A lista de sessoes esta VAZIA - EXIBIR LISTA\n");
    } else {
        p = l.prim;
        while (p < l.ult) {
            exibirSessao(l.item[p]);
            p++;
        }
        printf("\n FIM DA LISTA DE SESSOES - EXIBIR LISTA\n");
    }
}

void resetTeatro(teatro assentos[LIN][COL]) {
    int l,c;
    for(l = 0; l < LIN; l++) {
        for(c = 0; c < COL; c++) {
            if (c == 0 || c == 11 || c == 22) {
                assentos[l][c].status = CORREDOR;
            } else {
                assentos[l][c].status = VAGO;
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

void cadastrarSessao(sessao apresentacao) {
    printf("\n\t\t C A D A S T R O  ||  S E S S A O\n");
    printf("\nInsira o codigo da sessao: ");
    scanf("%d", apresentacao.codSessao);
    printf("\nInsira o nome da apresentacao: ");
    gets(apresentacao.nomeSessao);
    getchar();
    _strdate(apresentacao.data);

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
    printf("\t 5 - RESERVAR ASSENTOS - TEATRO\n");
    printf("\t 6 - CANCELAR RESERVA - TEATRO\n");
    printf("\t 7 - Sair - TEATRO\n");
}




int main() {
    teatro matrizTeatro[LIN][COL];
    sessao apresentacao;
    teatro *assento;

    listaEstatica listaSessoes;

	filaEstatica *filaReservas;
  
    //Apenas cria o teatro com os lugares previamente preenchidos com status VAGO
    resetTeatro(matrizTeatro);

    menu();

    int linha, coluna, opcao, codigo, indice;
    while (opcao != 7) {
		palco();

		exibeMatrizTeatro(matrizTeatro);
        printf("\nOPCAO: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                cadastrarSessao(apresentacao);
                break;
            case 2:

                printf("\nInsira o codigo da sessao que deseja remover: ");
                scanf("%d", &apresentacao.codSessao);
                removeElementoLista(&listaSessoes, &apresentacao);
                break;
            case 3:
                printf("\nInsira o codigo da sessao que deseja consultar:");
                scanf("%d", &codigo);
                consultarElementoLista(listaSessoes, codigo);
            case 4:
                printf("\n EXIBINDO SESSOES DO DIA \n");
                exibirListaSessoes(listaSessoes);
                break;
            case 5:
            	printf("\nInsira o codigo da sessao cujo assento sera vendido:");
				scanf("%d",&codigo);
            	printf("\nInsira a linha do assento que deseja vender:");
                scanf("%d", &linha);
                printf("\n insira a coluna do assento que deseja vender : ");
                scanf("%d",&coluna);
                matrizTeatro[linha][coluna].status = RESERVADO;
                matrizTeatro[linha][coluna].codSessao = codigo;
                matrizTeatro[linha][coluna].coluna = coluna;
                matrizTeatro[linha][coluna].linha = linha;
                matrizTeatro[linha][coluna].cod = rand()%1000;
                reservaAssento(filaReservas, matrizTeatro[linha][coluna]);
                printf("\nReserva concluida. Codigo: %d\n",matrizTeatro[linha][coluna].cod);
                break;
            case 6:
            	printf("\nInsira o codigo do assento a ser reposto a venda: ");
            	scanf("%d",&codigo);
            	linha = 0;
            	coluna = 0;
            	while(matrizTeatro[linha][coluna].cod != codigo){
            		while(matrizTeatro[linha][coluna].cod != codigo){
            			coluna++;
					}
					linha++;
				}
				*assento = matrizTeatro[linha][coluna];
				cancelarReserva(filaReservas, assento);
				printf("\nCancelamento concluido.");
                break;
            case 7:
            	printf("\nTenha um bom dia!\nFinalizando...\n");
                break;
        }
    }
    return 0;
}

