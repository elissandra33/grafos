codigo_c = """
#include <stdio.h>
#include <stdlib.h>

#define NUM_CIDADES 10

const char *nomesCidades[NUM_CIDADES] = {
    "Corrente", "Gilbues", "Bom Jesus", "Floriano", "Oeiras",
    "Teresina", "Campo Maior", "Piripiri", "Luis Correia", "Parnaiba"
};

typedef struct Vertice {
    int cidade;
    struct Vertice *prox;
} Vertice;

typedef struct Grafo {
    Vertice *adj[NUM_CIDADES];
} Grafo;

Grafo* criarGrafo() {
    Grafo *g = malloc(sizeof(Grafo));
    for(int i = 0; i < NUM_CIDADES; i++) {
        g->adj[i] = NULL;
    }
    return g;
}

void inserirAresta(Grafo *g, int origem, int destino) {
    Vertice *novo = malloc(sizeof(Vertice));
    novo->cidade = destino;
    novo->prox = g->adj[origem];
    g->adj[origem] = novo;
}

void imprimirCaminho(int caminho[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%s", nomesCidades[caminho[i]]);
        if (i < tamanho - 1)
            printf(" -> ");
    }
    printf("\\n");
}

void listarTodosCaminhosRec(Grafo *g, int atual, int destino, int visitado[], int caminho[], int pos) {
    visitado[atual] = 1;
    caminho[pos] = atual;
    pos++;

    if (atual == destino) {
        imprimirCaminho(caminho, pos);
    } else {
        for (Vertice *v = g->adj[atual]; v != NULL; v = v->prox) {
            if (!visitado[v->cidade]) {
                listarTodosCaminhosRec(g, v->cidade, destino, visitado, caminho, pos);
            }
        }
    }
    visitado[atual] = 0;
}

void listarTodosCaminhos(Grafo *g, int inicio, int fim) {
    int visitado[NUM_CIDADES] = {0};
    int caminho[NUM_CIDADES];
    listarTodosCaminhosRec(g, inicio, fim, visitado, caminho, 0);
}

void caminhoMaisCurto(Grafo *g, int inicio, int fim) {
    int fila[NUM_CIDADES], inicioFila = 0, fimFila = 0;
    int pai[NUM_CIDADES];
    int visitado[NUM_CIDADES] = {0};

    for (int i = 0; i < NUM_CIDADES; i++) pai[i] = -1;

    fila[fimFila++] = inicio;
    visitado[inicio] = 1;

    while (inicioFila < fimFila) {
        int atual = fila[inicioFila++];
        if (atual == fim) break;

        for (Vertice *v = g->adj[atual]; v != NULL; v = v->prox) {
            if (!visitado[v->cidade]) {
                visitado[v->cidade] = 1;
                pai[v->cidade] = atual;
                fila[fimFila++] = v->cidade;
            }
        }
    }

    int caminho[NUM_CIDADES];
    int tam = 0;
    for (int v = fim; v != -1; v = pai[v]) {
        caminho[tam++] = v;
    }

    printf("Caminho mais curto (%d cidades): ", tam);
    for (int i = tam - 1; i >= 0; i--) {
        printf("%s", nomesCidades[caminho[i]]);
        if (i > 0) printf(" -> ");
    }
    printf("\\n");
}

int maiorTamanho = 0;
int caminhoMaisLongoCaminho[NUM_CIDADES];

void buscarCaminhoMaisLongoRec(Grafo *g, int atual, int fim, int visitado[], int caminho[], int tamanho) {
    visitado[atual] = 1;
    caminho[tamanho] = atual;
    tamanho++;

    if (atual == fim) {
        if (tamanho > maiorTamanho) {
            maiorTamanho = tamanho;
            for (int i = 0; i < tamanho; i++) {
                caminhoMaisLongoCaminho[i] = caminho[i];
            }
        }
    } else {
        for (Vertice *v = g->adj[atual]; v != NULL; v = v->prox) {
            if (!visitado[v->cidade]) {
                buscarCaminhoMaisLongoRec(g, v->cidade, fim, visitado, caminho, tamanho);
            }
        }
    }

    visitado[atual] = 0;
}

void buscarCaminhoMaisLongo(Grafo *g, int inicio, int fim) {
    int visitado[NUM_CIDADES] = {0};
    int caminho[NUM_CIDADES];
    maiorTamanho = 0;
    buscarCaminhoMaisLongoRec(g, inicio, fim, visitado, caminho, 0);
}

int main() {
    Grafo *g = criarGrafo();

    inserirAresta(g, 0, 1);
    inserirAresta(g, 1, 2);
    inserirAresta(g, 2, 3);
    inserirAresta(g, 3, 4);
    inserirAresta(g, 4, 5);
    inserirAresta(g, 5, 6);
    inserirAresta(g, 6, 7);
    inserirAresta(g, 7, 8);
    inserirAresta(g, 8, 9);

    inserirAresta(g, 5, 9);
    inserirAresta(g, 2, 5);

    int caminho[NUM_CIDADES];

    printf("Todos os caminhos possíveis de Corrente até Parnaíba:\\n");
    listarTodosCaminhos(g, 0, 9);

    printf("\\n");
    caminhoMaisCurto(g, 0, 9);

    printf("\\nBuscando o caminho mais longo de Corrente até Parnaíba:\\n");
    buscarCaminhoMaisLongo(g, 0, 9);
    if (maiorTamanho > 0) {
        printf("Caminho mais longo (%d cidades): ", maiorTamanho);
        for (int i = 0; i < maiorTamanho; i++) {
            printf("%s", nomesCidades[caminhoMaisLongoCaminho[i]]);
            if (i < maiorTamanho - 1) printf(" -> ");
        }
        printf("\\n");
    } else {
        printf("Nenhum caminho longo encontrado.\\n");
    }

    for (int i = 0; i < NUM_CIDADES; i++) {
        Vertice *atual = g->adj[i];
        while (atual) {
            Vertice *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(g);

    return 0;
}
"""


