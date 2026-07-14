/*
 * Super Trunfo de Países - Nível Inciante
 *
 * Programa para cadastrar e exibir os dados de duas cartas do jogo.
 * Cada carta representa uma cidade com informações como população, área,
 * PIB e pontos turísticos.
 *
 * Autor: Super Trunfo Cards
 */

#include <stdio.h>

int main(void)
{
    /*
     * Variáveis da Carta 1
     * Cada campo corresponde a um atributo da carta conforme o enunciado.
     */
    char estado1;                  /* Letra de 'A' a 'H' que identifica o estado */
    char codigo1[4];               /* Código no formato letra + dois dígitos (ex: A01) */
    char nomeCidade1[100];         /* Nome completo da cidade */
    int populacao1;                /* Número de habitantes */
    float area1;                   /* Área em quilômetros quadrados */
    float pib1;                    /* Produto Interno Bruto em bilhões de reais */
    int pontosTuristicos1;         /* Quantidade de pontos turísticos */

    /*
     * Variáveis da Carta 2
     * Mesma estrutura da Carta 1, armazenando os dados da segunda carta.
     */
    char estado2;
    char codigo2[4];
    char nomeCidade2[100];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;

    /* Mensagem de boas-vindas e instruções gerais para o usuário */
    printf("=== Super Trunfo de Paises - Cadastro de Cartas ===\n");
    printf("Voce cadastrara duas cartas com dados de cidades.\n\n");

    /*
     * Leitura dos dados da Carta 1
     * scanf le cada valor do teclado e armazena na variavel correspondente.
     */
    printf("--- Carta 1 ---\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &estado1);

    printf("Digite o codigo da carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade1);

    printf("Digite a populacao (habitantes): ");
    scanf("%d", &populacao1);

    printf("Digite a area em km2: ");
    scanf("%f", &area1);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    printf("\n");

    /*
     * Leitura dos dados da Carta 2
     * Repete o mesmo processo de entrada para a segunda carta.
     */
    printf("--- Carta 2 ---\n");
    printf("Digite o estado (letra de A a H): ");
    scanf(" %c", &estado2);

    printf("Digite o codigo da carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", nomeCidade2);

    printf("Digite a populacao (habitantes): ");
    scanf("%d", &populacao2);

    printf("Digite a area em km2: ");
    scanf("%f", &area2);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    printf("\n");

    /*
     * Exibicao dos dados cadastrados
     * Cada informacao e impressa em uma linha separada, com descricao clara.
     */
    printf("=== Cartas Cadastradas ===\n\n");

    printf("Carta 1:\n");
    printf("Estado: %c\n", estado1);
    printf("Codigo: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", nomeCidade1);
    printf("Populacao: %d\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);

    printf("\n");

    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %d\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);

    return 0;
}
