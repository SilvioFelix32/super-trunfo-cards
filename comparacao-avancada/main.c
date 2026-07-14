/*
 * Super Trunfo de Países - Comparação Avançada (Nível Mestre)
 *
 * Desafio final da trilha interativa: escolha de dois atributos distintos
 * via menus dinâmicos (switch), comparação individual, soma dos valores
 * e determinação do vencedor com operador ternário e if-else aninhados.
 *
 * Autor: Super Trunfo Cards
 */

#include <stdio.h>

/* Retorna o nome do atributo conforme o código numérico (1 a 5) */
static const char *nomeDoAtributo(int atributo)
{
    switch (atributo) {
    case 1: return "Populacao";
    case 2: return "Area";
    case 3: return "PIB";
    case 4: return "Numero de pontos turisticos";
    case 5: return "Densidade demografica";
    default: return "Desconhecido";
    }
}

/*
 * Exibe menu dinâmico: o atributo já escolhido (excluir != 0)
 * não aparece como opção disponível.
 */
static void exibirMenuAtributos(int excluir)
{
    const char *titulo = excluir == 0
        ? "=== Escolha o primeiro atributo ==="
        : "=== Escolha o segundo atributo ===";

    printf("%s\n", titulo);

    if (excluir != 1) {
        printf("1 - Populacao\n");
    }
    if (excluir != 2) {
        printf("2 - Area\n");
    }
    if (excluir != 3) {
        printf("3 - PIB\n");
    }
    if (excluir != 4) {
        printf("4 - Numero de pontos turisticos\n");
    }
    if (excluir != 5) {
        printf("5 - Densidade demografica\n");
    }
}

/* Valida se a opção é um atributo válido e diferente do já escolhido */
static int atributoValido(int opcao, int excluir)
{
    if (opcao < 1 || opcao > 5) {
        return 0;
    }
    if (excluir != 0 && opcao == excluir) {
        return 0;
    }
    return 1;
}

/* Obtém o valor numérico do atributo para a carta indicada (1 ou 2) */
static float valorDoAtributo(
    int atributo,
    int carta,
    int populacao1, int populacao2,
    float area1, float area2,
    float pib1, float pib2,
    int pontos1, int pontos2,
    float densidade1, float densidade2)
{
    switch (atributo) {
    case 1:
        return carta == 1 ? (float)populacao1 : (float)populacao2;
    case 2:
        return carta == 1 ? area1 : area2;
    case 3:
        return carta == 1 ? pib1 : pib2;
    case 4:
        return carta == 1 ? (float)pontos1 : (float)pontos2;
    case 5:
        return carta == 1 ? densidade1 : densidade2;
    default:
        return 0.0f;
    }
}

/* Imprime inteiros com separador de milhar (ex: 214.000.000) */
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

static void exibirValorAtributo(int atributo, float valor)
{
    if (atributo == 1 || atributo == 4) {
        imprimirInteiroFormatado((int)valor);
    } else {
        printf("%.2f", valor);
    }
}

/*
 * Compara um atributo entre as cartas.
 * Retorna 1 se carta 1 vence, 2 se carta 2 vence, 0 se empate.
 */
static int compararAtributo(int atributo, float valor1, float valor2)
{
    if (atributo == 5) {
        return valor1 < valor2 ? 1 : (valor1 > valor2 ? 2 : 0);
    }
    return valor1 > valor2 ? 1 : (valor1 < valor2 ? 2 : 0);
}

int main(void)
{
    /* Cartas pré-cadastradas dos desafios anteriores */
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

    float densidadeDemografica1;
    float densidadeDemografica2;

    int opcao1;
    int opcao2;
    float valor1Atributo1;
    float valor2Atributo1;
    float valor1Atributo2;
    float valor2Atributo2;
    float somaCarta1;
    float somaCarta2;
    int vencedorAtributo1;
    int vencedorAtributo2;
    int vencedorRodada;

    densidadeDemografica1 = (float)populacao1 / area1;
    densidadeDemografica2 = (float)populacao2 / area2;

    printf("=== Super Trunfo de Paises - Comparacao Avancada ===\n\n");
    printf("Cartas cadastradas:\n");
    printf("  Carta 1: %s\n", nomePais1);
    printf("  Carta 2: %s\n\n", nomePais2);

    /* Primeira escolha de atributo */
    exibirMenuAtributos(0);
    printf("\nOpcao: ");
    scanf("%d", &opcao1);

    if (!atributoValido(opcao1, 0)) {
        printf("\nOpcao invalida! Escolha um numero de 1 a 5.\n");
        return 1;
    }

    /* Segunda escolha com menu dinâmico (sem o primeiro atributo) */
    printf("\n");
    exibirMenuAtributos(opcao1);
    printf("\nOpcao: ");
    scanf("%d", &opcao2);

    if (!atributoValido(opcao2, opcao1)) {
        if (opcao2 == opcao1) {
            printf("\nErro: voce nao pode escolher o mesmo atributo duas vezes.\n");
        } else {
            printf("\nOpcao invalida! Escolha um atributo disponivel no menu.\n");
        }
        return 1;
    }

    /* Valores de cada atributo por carta */
    valor1Atributo1 = valorDoAtributo(
        opcao1, 1, populacao1, populacao2, area1, area2, pib1, pib2,
        pontosTuristicos1, pontosTuristicos2,
        densidadeDemografica1, densidadeDemografica2);
    valor2Atributo1 = valorDoAtributo(
        opcao1, 2, populacao1, populacao2, area1, area2, pib1, pib2,
        pontosTuristicos1, pontosTuristicos2,
        densidadeDemografica1, densidadeDemografica2);
    valor1Atributo2 = valorDoAtributo(
        opcao2, 1, populacao1, populacao2, area1, area2, pib1, pib2,
        pontosTuristicos1, pontosTuristicos2,
        densidadeDemografica1, densidadeDemografica2);
    valor2Atributo2 = valorDoAtributo(
        opcao2, 2, populacao1, populacao2, area1, area2, pib1, pib2,
        pontosTuristicos1, pontosTuristicos2,
        densidadeDemografica1, densidadeDemografica2);

    /* Comparação individual de cada atributo */
    vencedorAtributo1 = compararAtributo(opcao1, valor1Atributo1, valor2Atributo1);
    vencedorAtributo2 = compararAtributo(opcao2, valor1Atributo2, valor2Atributo2);

    /* Soma dos valores dos atributos escolhidos */
    somaCarta1 = valor1Atributo1 + valor1Atributo2;
    somaCarta2 = valor2Atributo1 + valor2Atributo2;

    vencedorRodada = somaCarta1 > somaCarta2 ? 1 : (somaCarta1 < somaCarta2 ? 2 : 0);

    /* Exibição organizada do resultado */
    printf("\n=== Resultado da Comparacao ===\n\n");
    printf("Paises: %s x %s\n", nomePais1, nomePais2);
    printf("Atributos: %s e %s\n\n", nomeDoAtributo(opcao1), nomeDoAtributo(opcao2));

    printf("--- %s ---\n", nomeDoAtributo(opcao1));
    printf("%s: ", nomePais1);
    exibirValorAtributo(opcao1, valor1Atributo1);
    printf("\n");
    printf("%s: ", nomePais2);
    exibirValorAtributo(opcao1, valor2Atributo1);
    printf("\n");
    printf("Vencedor do atributo: %s\n\n",
           vencedorAtributo1 == 0 ? "Empate!"
           : (vencedorAtributo1 == 1 ? nomePais1 : nomePais2));

    printf("--- %s ---\n", nomeDoAtributo(opcao2));
    printf("%s: ", nomePais1);
    exibirValorAtributo(opcao2, valor1Atributo2);
    printf("\n");
    printf("%s: ", nomePais2);
    exibirValorAtributo(opcao2, valor2Atributo2);
    printf("\n");
    printf("Vencedor do atributo: %s\n\n",
           vencedorAtributo2 == 0 ? "Empate!"
           : (vencedorAtributo2 == 1 ? nomePais1 : nomePais2));

    printf("--- Soma dos atributos ---\n");
    printf("%s: %.2f\n", nomePais1, somaCarta1);
    printf("%s: %.2f\n\n", nomePais2, somaCarta2);

    printf("Resultado final: ");
    if (vencedorRodada == 0) {
        printf("Empate!\n");
    } else {
        if (vencedorRodada == 1) {
            printf("%s venceu a rodada!\n", nomePais1);
        } else {
            printf("%s venceu a rodada!\n", nomePais2);
        }
    }

    return 0;
}
