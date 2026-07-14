/*
 * Super Trunfo de Países - Nível Mestre
 *
 * Programa para cadastrar, exibir e comparar os dados de duas cartas do jogo.
 * Calcula densidade populacional, PIB per capita e Super Poder, e determina
 * a vencedora de cada atributo entre as duas cartas.
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
    char estado1;                       /* Letra de 'A' a 'H' que identifica o estado */
    char codigo1[4];                    /* Código no formato letra + dois dígitos (ex: A01) */
    char nomeCidade1[100];              /* Nome completo da cidade */
    unsigned long int populacao1;       /* Número de habitantes */
    float area1;                        /* Área em quilômetros quadrados */
    float pib1;                         /* Produto Interno Bruto em bilhões de reais */
    int pontosTuristicos1;              /* Quantidade de pontos turísticos */
    float densidadePopulacional1;       /* Habitantes por quilômetro quadrado */
    float pibPerCapita1;                /* Riqueza média por habitante em reais */
    float superPoder1;                  /* Soma dos atributos numéricos com densidade invertida */

    /*
     * Variáveis da Carta 2
     * Mesma estrutura da Carta 1, armazenando os dados da segunda carta.
     */
    char estado2;
    char codigo2[4];
    char nomeCidade2[100];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidadePopulacional2;
    float pibPerCapita2;
    float superPoder2;

    /* Resultados das comparações: 1 se Carta 1 vence, 0 se Carta 2 vence */
    int comparacaoPopulacao;
    int comparacaoArea;
    int comparacaoPib;
    int comparacaoPontosTuristicos;
    int comparacaoDensidade;
    int comparacaoPibPerCapita;
    int comparacaoSuperPoder;

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
    scanf("%lu", &populacao1);

    printf("Digite a area em km2: ");
    scanf("%f", &area1);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib1);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos1);

    densidadePopulacional1 = (float)populacao1 / area1;
    pibPerCapita1 = (pib1 * 1000000000.0f) / (float)populacao1;
    superPoder1 = (float)populacao1 + area1 + pib1 + (float)pontosTuristicos1
                + pibPerCapita1 + (1.0f / densidadePopulacional1);

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
    scanf("%lu", &populacao2);

    printf("Digite a area em km2: ");
    scanf("%f", &area2);

    printf("Digite o PIB em bilhoes de reais: ");
    scanf("%f", &pib2);

    printf("Digite o numero de pontos turisticos: ");
    scanf("%d", &pontosTuristicos2);

    densidadePopulacional2 = (float)populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0f) / (float)populacao2;
    superPoder2 = (float)populacao2 + area2 + pib2 + (float)pontosTuristicos2
                + pibPerCapita2 + (1.0f / densidadePopulacional2);

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
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional1);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita1);

    printf("\n");

    printf("Carta 2:\n");
    printf("Estado: %c\n", estado2);
    printf("Codigo: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", nomeCidade2);
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Numero de Pontos Turisticos: %d\n", pontosTuristicos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadePopulacional2);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita2);

    /*
     * Comparacao atributo a atributo
     * Maior valor vence, exceto densidade populacional (menor vence).
     */
    comparacaoPopulacao = populacao1 > populacao2;
    comparacaoArea = area1 > area2;
    comparacaoPib = pib1 > pib2;
    comparacaoPontosTuristicos = pontosTuristicos1 > pontosTuristicos2;
    comparacaoDensidade = densidadePopulacional1 < densidadePopulacional2;
    comparacaoPibPerCapita = pibPerCapita1 > pibPerCapita2;
    comparacaoSuperPoder = superPoder1 > superPoder2;

    printf("\nComparacao de Cartas:\n\n");

    printf("Populacao: Carta %d venceu (%d)\n",
           comparacaoPopulacao ? 1 : 2, comparacaoPopulacao);
    printf("Area: Carta %d venceu (%d)\n",
           comparacaoArea ? 1 : 2, comparacaoArea);
    printf("PIB: Carta %d venceu (%d)\n",
           comparacaoPib ? 1 : 2, comparacaoPib);
    printf("Pontos Turisticos: Carta %d venceu (%d)\n",
           comparacaoPontosTuristicos ? 1 : 2, comparacaoPontosTuristicos);
    printf("Densidade Populacional: Carta %d venceu (%d)\n",
           comparacaoDensidade ? 1 : 2, comparacaoDensidade);
    printf("PIB per Capita: Carta %d venceu (%d)\n",
           comparacaoPibPerCapita ? 1 : 2, comparacaoPibPerCapita);
    printf("Super Poder: Carta %d venceu (%d)\n",
           comparacaoSuperPoder ? 1 : 2, comparacaoSuperPoder);

    return 0;
}
