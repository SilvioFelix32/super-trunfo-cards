/*
 * Super Trunfo de Países - Comparando Cartas
 *
 * Aula focada na lógica de comparação entre duas cartas já cadastradas.
 * Calcula densidade populacional e PIB per capita, compara um atributo
 * escolhido no código e exibe a carta vencedora usando if e if-else.
 *
 * Autor: Super Trunfo Cards
 */

#include <stdio.h>

/*
 * Atributo usado na comparação (altere aqui para testar outros atributos):
 * 1 = População
 * 2 = Área
 * 3 = PIB
 * 4 = Densidade Populacional
 * 5 = PIB per capita
 */
#define ATRIBUTO_COMPARACAO 1

/* Imprime inteiros com separador de milhar no padrão brasileiro (ex: 12.300.000) */
static void imprimirInteiroFormatado(int valor)
{
    if (valor >= 1000000) {
        printf("%d.", valor / 1000000);
        printf("%03d.", (valor / 1000) % 1000);
        printf("%03d", valor % 1000);
    } else if (valor >= 1000) {
        printf("%d.", valor / 1000);
        printf("%03d", valor % 1000);
    } else {
        printf("%d", valor);
    }
}

int main(void)
{
    /*
     * Cartas pré-definidas no código (simplificação do desafio).
     * Estrutura reaproveitada do cadastro desenvolvido nas aulas anteriores.
     */
    char estado1[] = "SP";
    char codigo1[] = "A01";
    char nomeCidade1[] = "São Paulo";
    int populacao1 = 12300000;
    float area1 = 1521.11f;
    float pib1 = 699.28f;
    int pontosTuristicos1 = 50;

    char estado2[] = "RJ";
    char codigo2[] = "B02";
    char nomeCidade2[] = "Rio de Janeiro";
    int populacao2 = 6000000;
    float area2 = 1200.25f;
    float pib2 = 300.50f;
    int pontosTuristicos2 = 30;

    /* Atributos calculados */
    float densidadePopulacional1;
    float densidadePopulacional2;
    float pibPerCapita1;
    float pibPerCapita2;

    /* Valores do atributo escolhido para exibição e comparação */
    float valorCarta1;
    float valorCarta2;
    const char *nomeAtributo;

    /* Cálculos conforme o enunciado */
    densidadePopulacional1 = (float)populacao1 / area1;
    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita1 = pib1 / (float)populacao1;
    pibPerCapita2 = pib2 / (float)populacao2;

    /*
     * Exibição dos dados cadastrados e calculados
     */
    printf("=== Super Trunfo de Paises - Cartas Cadastradas ===\n\n");

    printf("Carta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: ");
    imprimirInteiroFormatado(populacao1);
    printf("\n");
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.6f\n", pibPerCapita1);

    printf("\n");

    printf("Carta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: ");
    imprimirInteiroFormatado(populacao2);
    printf("\n");
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.6f\n", pibPerCapita2);

    /*
     * Seleção do atributo para comparação (definida no código via ATRIBUTO_COMPARACAO)
     */
    if (ATRIBUTO_COMPARACAO == 1) {
        nomeAtributo = "Populacao";
        valorCarta1 = (float)populacao1;
        valorCarta2 = (float)populacao2;
    } else if (ATRIBUTO_COMPARACAO == 2) {
        nomeAtributo = "Area";
        valorCarta1 = area1;
        valorCarta2 = area2;
    } else if (ATRIBUTO_COMPARACAO == 3) {
        nomeAtributo = "PIB";
        valorCarta1 = pib1;
        valorCarta2 = pib2;
    } else if (ATRIBUTO_COMPARACAO == 4) {
        nomeAtributo = "Densidade Populacional";
        valorCarta1 = densidadePopulacional1;
        valorCarta2 = densidadePopulacional2;
    } else {
        nomeAtributo = "PIB per Capita";
        valorCarta1 = pibPerCapita1;
        valorCarta2 = pibPerCapita2;
    }

    /*
     * Comparação e exibição do resultado
     * Maior valor vence, exceto para Densidade Populacional (menor vence).
     */
    printf("\nComparacao de cartas (Atributo: %s):\n\n", nomeAtributo);

    if (ATRIBUTO_COMPARACAO == 1) {
        printf("Carta 1 - %s (%s): ", nomeCidade1, estado1);
        imprimirInteiroFormatado(populacao1);
        printf("\n");
        printf("Carta 2 - %s (%s): ", nomeCidade2, estado2);
        imprimirInteiroFormatado(populacao2);
        printf("\n");
    } else {
        printf("Carta 1 - %s (%s): %.2f\n", nomeCidade1, estado1, valorCarta1);
        printf("Carta 2 - %s (%s): %.2f\n", nomeCidade2, estado2, valorCarta2);
    }

    printf("\nResultado: ");

    if (ATRIBUTO_COMPARACAO == 4) {
        /* Densidade: menor valor vence */
        if (valorCarta1 < valorCarta2) {
            printf("Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (valorCarta1 > valorCarta2) {
            printf("Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Empate!\n");
        }
    } else {
        /* Demais atributos: maior valor vence */
        if (valorCarta1 > valorCarta2) {
            printf("Carta 1 (%s) venceu!\n", nomeCidade1);
        } else if (valorCarta1 < valorCarta2) {
            printf("Carta 2 (%s) venceu!\n", nomeCidade2);
        } else {
            printf("Empate!\n");
        }
    }

    return 0;
}
