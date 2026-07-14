/*
 * Super Trunfo de Países - Interatividade (Nível Aventureiro)
 *
 * Continuação da aula de comparação de cartas. Cartas pré-cadastradas,
 * menu interativo com switch para escolha do atributo e lógica de
 * comparação com if-else aninhados.
 *
 * Autor: Super Trunfo Cards
 */

#include <stdio.h>

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
     * Cartas pré-cadastradas (cadastro feito no desafio anterior).
     * Cada carta representa um país com seus atributos numéricos.
     */
    char nomePais1[] = "Brasil";
    int populacao1 = 214000000;
    float area1 = 8515767.0f;
    float pib1 = 1920.0f;
    int pontosTuristicos1 = 100;

    char nomePais2[] = "Argentina";
    int populacao2 = 45000000;
    float area2 = 2780400.0f;
    float pib2 = 450.0f;
    int pontosTuristicos2 = 80;

    /* Densidade demográfica calculada no desafio anterior */
    float densidadeDemografica1;
    float densidadeDemografica2;

    int opcao;
    float valorCarta1;
    float valorCarta2;
    const char *nomeAtributo;
    int atributoValido = 1;

    densidadeDemografica1 = (float)populacao1 / area1;
    densidadeDemografica2 = (float)populacao2 / area2;

    printf("=== Super Trunfo de Paises ===\n\n");

    printf("Cartas cadastradas:\n");
    printf("  Carta 1: %s\n", nomePais1);
    printf("  Carta 2: %s\n\n", nomePais2);

    /* Menu interativo para escolha do atributo de comparacao */
    printf("=== Menu de Comparacao ===\n");
    printf("1 - Populacao\n");
    printf("2 - Area\n");
    printf("3 - PIB\n");
    printf("4 - Numero de pontos turisticos\n");
    printf("5 - Densidade demografica\n");
    printf("\nEscolha o atributo para comparar: ");
    scanf("%d", &opcao);

    /*
     * switch seleciona o atributo e prepara os valores para comparacao
     */
    switch (opcao) {
    case 1:
        nomeAtributo = "Populacao";
        valorCarta1 = (float)populacao1;
        valorCarta2 = (float)populacao2;
        break;
    case 2:
        nomeAtributo = "Area";
        valorCarta1 = area1;
        valorCarta2 = area2;
        break;
    case 3:
        nomeAtributo = "PIB";
        valorCarta1 = pib1;
        valorCarta2 = pib2;
        break;
    case 4:
        nomeAtributo = "Numero de pontos turisticos";
        valorCarta1 = (float)pontosTuristicos1;
        valorCarta2 = (float)pontosTuristicos2;
        break;
    case 5:
        nomeAtributo = "Densidade demografica";
        valorCarta1 = densidadeDemografica1;
        valorCarta2 = densidadeDemografica2;
        break;
    default:
        printf("\nOpcao invalida! Escolha um numero de 1 a 5.\n");
        atributoValido = 0;
        break;
    }

    if (atributoValido) {
        printf("\n=== Resultado da Comparacao ===\n");
        printf("Atributo: %s\n\n", nomeAtributo);

        /* Exibe os valores do atributo para cada pais */
        if (opcao == 1 || opcao == 4) {
            printf("%s: ", nomePais1);
            imprimirInteiroFormatado((int)valorCarta1);
            printf("\n");
            printf("%s: ", nomePais2);
            imprimirInteiroFormatado((int)valorCarta2);
            printf("\n");
        } else {
            printf("%s: %.2f\n", nomePais1, valorCarta1);
            printf("%s: %.2f\n", nomePais2, valorCarta2);
        }

        printf("\nResultado: ");

        /*
         * Comparacao com if-else aninhados
         * Densidade demografica: menor valor vence
         * Demais atributos: maior valor vence
         */
        if (opcao == 5) {
            if (valorCarta1 < valorCarta2) {
                printf("%s venceu!\n", nomePais1);
            } else {
                if (valorCarta1 > valorCarta2) {
                    printf("%s venceu!\n", nomePais2);
                } else {
                    printf("Empate!\n");
                }
            }
        } else {
            if (valorCarta1 > valorCarta2) {
                printf("%s venceu!\n", nomePais1);
            } else {
                if (valorCarta1 < valorCarta2) {
                    printf("%s venceu!\n", nomePais2);
                } else {
                    printf("Empate!\n");
                }
            }
        }
    }

    return 0;
}
