#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int prioridade;
    int tempo;
    char nome[51];
} Prato;

void trocar(Prato* a, Prato* b) {
    Prato temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Prato* pratos, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (pratos[j].prioridade < pratos[j + 1].prioridade ||
               (pratos[j].prioridade == pratos[j + 1].prioridade && pratos[j].tempo > pratos[j + 1].tempo)) {
                trocar(&pratos[j], &pratos[j + 1]);
            }
        }
    }
}

int particionar(Prato* pratos, int low, int high) {
    Prato pivo = pratos[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (pratos[j].prioridade > pivo.prioridade ||
           (pratos[j].prioridade == pivo.prioridade && pratos[j].tempo < pivo.tempo)) {
            i++;
            trocar(&pratos[i], &pratos[j]);
        }
    }
    trocar(&pratos[i + 1], &pratos[high]);
    return i + 1;
}

void quickSort(Prato* pratos, int low, int high) {
    if (low < high) {
        int pi = particionar(pratos, low, high);
        quickSort(pratos, low, pi - 1);
        quickSort(pratos, pi + 1, high);
    }
}

int carregarCSV(const char* nomeArquivo, Prato* pratos) {
    FILE* file = fopen(nomeArquivo, "r");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        return 0;
    }

    char buffer[200];
    fgets(buffer, sizeof(buffer), file);

    int count = 0;
    while (fscanf(file, "%d,%d,%50[^\n]\n", &pratos[count].prioridade, &pratos[count].tempo, pratos[count].nome) == 3) {
        count++;
        if (count >= 10000) break;
    }

    fclose(file);
    return count;
}

int main() {
    Prato pratos[10000];
    int n;

    const char* nomeArquivo = "restaurante_pratos.csv";
    n = carregarCSV(nomeArquivo, pratos);
    if (n == 0) {
        return 1;
    }

    clock_t start = clock();
    bubbleSort(pratos, n);
    clock_t end = clock();
    double bubbleSortTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nResultado Bubble Sort (10 primeiros pratos):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("Prioridade: %d, Tempo: %d, Nome: %s\n", pratos[i].prioridade, pratos[i].tempo, pratos[i].nome);
    }
    printf("Tempo de execução do Bubble Sort: %.6f segundos\n", bubbleSortTime);

    n = carregarCSV(nomeArquivo, pratos);

    start = clock();
    quickSort(pratos, 0, n - 1);
    end = clock();
    double quickSortTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("\nResultado Quicksort (10 primeiros pratos):\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("Prioridade: %d, Tempo: %d, Nome: %s\n", pratos[i].prioridade, pratos[i].tempo, pratos[i].nome);
    }
    printf("Tempo de execução do Quicksort: %.6f segundos\n", quickSortTime);

    return 0;
}
