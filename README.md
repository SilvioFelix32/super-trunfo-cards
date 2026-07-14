# Super Trunfo de Países

Projeto do jogo **Super Trunfo de Países**, desenvolvido em C. O repositório contém as três versões do desafio — inciante, intermediário e mestre — cada uma em sua pasta.

## Sobre o projeto

Cada carta representa uma cidade e contém os seguintes atributos:

| Campo | Tipo | Descrição |
|-------|------|-----------|
| Estado | `char` | Letra de **A** a **H** |
| Código da Carta | `char[]` | Estado + número de 01 a 04 (ex.: `A01`, `B03`) |
| Nome da Cidade | `char[]` | Nome da cidade |
| População | `int` | Número de habitantes |
| Área | `float` | Área em km² |
| PIB | `float` | Produto Interno Bruto em bilhões de reais |
| Pontos Turísticos | `int` | Quantidade de pontos turísticos |

O programa lê os dados pelo teclado, armazena em variáveis e exibe as duas cartas de forma organizada na tela.

## Requisitos

- Compilador **GCC** (ou compatível com C11)
- Terminal para entrada e saída de dados

## Como executar

### 1. Compilar

Escolha o nível desejado e compile a partir da pasta correspondente:

```bash
# Nível inciante
gcc -Wall -Wextra -std=c11 -o super_trufo nivel-inciante/main.c

# Nível intermediário
gcc -Wall -Wextra -std=c11 -o super_trufo nivel-intermediario/main.c

# Nível mestre
gcc -Wall -Wextra -std=c11 -o super_trufo nivel-mestre/main.c
```

Também é possível compilar a partir da raiz com `main.c` (equivalente ao nível mestre).

### 2. Executar

```bash
./super_trufo
```

O programa solicitará os dados de cada carta. Informe os valores e pressione **Enter** após cada campo.

### Exemplo de entrada

**Carta 1**

```
Estado: A
Código: A01
Cidade: São Paulo
População: 12325000
Área: 1521.11
PIB: 699.28
Pontos turísticos: 50
```

**Carta 2**

```
Estado: B
Código: B02
Cidade: Rio de Janeiro
População: 6748000
Área: 1200.25
PIB: 300.50
Pontos turísticos: 30
```

## Estrutura do projeto

```
super-trunfo-cards/
├── nivel-inciante/
│   └── main.c          # Nível 1 — cadastro e exibição de duas cartas
├── nivel-intermediario/
│   └── main.c          # Nível 2 — densidade populacional e PIB per capita
├── nivel-mestre/
│   └── main.c          # Nível 3 — Super Poder e comparação entre cartas
├── main.c              # Cópia do nível mestre (entrada na raiz)
├── assets/             # Imagens e capturas de tela
└── README.md
```

| Pasta | Nível | Funcionalidades |
|-------|-------|-----------------|
| `nivel-inciante/` | Inciante | Leitura e exibição dos dados de duas cartas |
| `nivel-intermediario/` | Intermediário | + Densidade populacional e PIB per capita |
| `nivel-mestre/` | Mestre | + Super Poder e comparação atributo a atributo |

## Demonstração

Salve o print do terminal em `assets/terminal.png` (ou ajuste o caminho abaixo) e descomente a linha da imagem.

![Execução do programa no terminal](assets/terminal.png)

## Níveis implementados

Todos os três níveis do desafio estão disponíveis, cada um em sua pasta:

- **Inciante** — leitura, armazenamento e exibição (`scanf`, variáveis, `printf`)
- **Intermediário** — cálculo de densidade populacional e PIB per capita (`float`, operadores aritméticos)
- **Mestre** — Super Poder, comparação entre cartas e `unsigned long int` para população
