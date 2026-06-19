#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.
// Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1
    
    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0

int main() {
    //Declaração das variáveis
    //Criação do tabuleiro
    char letras_colunas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numero_linhas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[10][10] = {0};

    //Posicionamento dos navios
    int navio_horizontal[3] = {3, 3, 3};
    int linha_horizontal = 3;
    int coluna_horizontal = 3;
    int navio_vertical[3] = {3, 3, 3};
    int linha_vertical = 6;
    int coluna_vertical = 4;

    printf("*********************\n");
    printf("*** BATALHA NAVAL ***\n");
    printf("*********************\n");
    printf("\n\n");

    // Tabuleiro
    /* TABULEIRO DO JOGO
    linha   -> identificação das colunas (A-J)
    coluna  -> identificação das linhas (1-10)
    tabuleiro -> matriz 10x10 inicializada com água */

    //Exibição do Tabuleiro Inicial
    //Nesse momento todas as posições contêm água (0)
    printf("* TABULEIRO BATALHA NAVAL *\n\n");
    
    printf("    ");
    for(int i = 0; i < 10; i++){
        printf("%c  ", letras_colunas[i]);  //imprime as letras no topo
        }
    
    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%2d ", numero_linhas[i]);
        
        for(int j = 0; j < 10; j++){
            printf("%2d ", tabuleiro[i][j]);  //imprime a numeração nas colunas
            }
        printf("\n");
        }
        
     //Posicionando os navios
    /* CONFIGURAÇÃO DOS NAVIOS
    Cada navio possui tamanho 3.
    O valor 3 representa uma posição ocupada.*/

    //Posicionamento horizontal
    // O navio ocupa três posições consecutivas na mesma linha
    if(coluna_horizontal + 3 <= 10) { // Verifica se o navio permanece dentro dos limites
        for(int i = 0; i < 3; i++) {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
        }
    }

    //Posicionamento vertical
    // O navio ocupa três posições consecutivas na mesma coluna
    if(linha_vertical + 3 <= 10) { // Verifica se o navio permanece dentro dos limites
        for(int i = 0; i < 3; i++) {
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
        }
    } 

    //Exibição do tabuleiro final
    //Mostra o tabuleiro após o posicionamento dos navios
    printf("\nTABULEIRO COM NAVIOS\n\n");

    printf("   ");
    for(int i = 0; i < 10; i++) {
        printf("%c ", letras_colunas[i]);
    }

    printf("\n");

    for(int i = 0; i < 10; i++){
        printf("%2d ", numero_linhas[i]);

        for(int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
