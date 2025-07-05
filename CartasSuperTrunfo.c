#include <stdio.h>

typedef struct {
    char estado;
    char codigo[4];
    char nome[50];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões
    int pontosTuristicos;
    float densidade;
    float pibPerCapita;
    float superPoder;
} Carta;

void cadastrarCarta(Carta *c) {
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &c->estado);

    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", c->codigo);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", c->nome);

    printf("Digite a população da cidade: ");
    scanf("%lu", &c->populacao);

    printf("Digite a área da cidade (em km²): ");
    scanf("%f", &c->area);

    printf("Digite o PIB da cidade (em bilhões de reais): ");
    scanf("%f", &c->pib);

    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &c->pontosTuristicos);

    // Cálculos
    c->densidade = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000.0) / c->populacao;
    c->superPoder = c->populacao + c->area + c->pib + c->pontosTuristicos + c->pibPerCapita + (1 / c->densidade);
}

void exibirCarta(Carta c, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", c.estado);
    printf("Código: %s\n", c.codigo);
    printf("Nome da Cidade: %s\n", c.nome);
    printf("População: %lu\n", c.populacao);
    printf("Área: %.2f km²\n", c.area);
    printf("PIB: %.2f bilhões de reais\n", c.pib);
    printf("Número de Pontos Turísticos: %d\n", c.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", c.densidade);
    printf("PIB per capita: R$ %.2f\n", c.pibPerCapita);
    printf("Super Poder: %.2f\n", c.superPoder);
}

void compararCartas(Carta c1, Carta c2) {
    printf("\n=== Comparação ===\n");
    printf("População: %d\n", (c1.populacao > c2.populacao));
    printf("Área: %d\n", (c1.area > c2.area));
    printf("PIB: %d\n", (c1.pib > c2.pib));
    printf("Pontos Turísticos: %d\n", (c1.pontosTuristicos > c2.pontosTuristicos));
    printf("Densidade Populacional (menor vence): %d\n", (c1.densidade < c2.densidade));
    printf("PIB per capita: %d\n", (c1.pibPerCapita > c2.pibPerCapita));
    printf("Super Poder: %d\n", (c1.superPoder > c2.superPoder));
}

int main() {
    Carta carta1, carta2;

    printf("Cadastro da Carta 1:\n");
    cadastrarCarta(&carta1);

    printf("\nCadastro da Carta 2:\n");
    cadastrarCarta(&carta2);

    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    compararCartas(carta1, carta2);

    return 0;
}
