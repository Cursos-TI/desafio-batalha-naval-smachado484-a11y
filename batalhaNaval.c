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

//Dimensões do tabuleiro principal
#define linhas 10
#define colunas 10

int main() {
    //Declaração das variáveis
    //Criação do tabuleiro
    char letras_colunas[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int numero_linhas[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int tabuleiro[linhas][colunas] = {0};

    //Posicionamento dos navios
    int navio_horizontal[3] = {3, 3, 3}, linha_horizontal = 5, coluna_horizontal = 4;
    int navio_vertical[3] = {3, 3, 3}, linha_vertical = 6, coluna_vertical = 9;
    int navio_diagonal1 [3] = {3, 3, 3}, linha_diagonal1 = 0, coluna_diagonal1 = 1;
    int navio_diagonal2 [3] = {3, 3, 3}, linha_diagonal2= 0, coluna_diagonal2 = 7;

    //Habilidades especiais
    int cone[5][5] = {0};
    int cruz[5][5] = {0};
    int octaedro[5][5] = {0}; 
    int opcao, origem_linha, origem_coluna;

    
    printf("**********************************\n");
    printf("*** BEM VINDO AO BATALHA NAVAL ***\n");
    printf("**********************************\n");
    printf("\n");
    printf("Prepare sua estratégia!\n");
    printf("O oceano está vazio e o tabuleiro está sendo organizado.\n");
    printf("Primeiramente, vamos conhecer nosso tabuleiro e algumas informações iniciais.\n\n");

    printf("Legenda:\n");
    printf("0 - Agua\n");
    printf("3 - Navio\n");
    printf("5 - Área afetada por habilidade especial\n\n");
    
   // Tabuleiro
   /* TABULEIRO DO JOGO
   letras_colunas -> identificação das colunas (A-J)
   numero_linhas  -> identificação das linhas (1-10)
   tabuleiro      -> matriz 10x10 inicializada com água (0)
   */

    //Exibição do Tabuleiro Inicial
    //Nesse momento todas as posições contêm água (0)
    printf("*** TABULEIRO BATALHA NAVAL ***\n\n");
    
    printf("    ");
    for(int i = 0; i < colunas; i++){
        printf("%c  ", letras_colunas[i]);  //imprime as letras no topo
        }
    
    printf("\n");

    for(int i = 0; i < linhas; i++){
        printf("%2d ", numero_linhas[i]);
        
        for(int j = 0; j < colunas; j++){
            printf("%2d ", tabuleiro[i][j]);  //imprime a numeração nas colunas
            }
        printf("\n");
        }
        
    //Posicionando os navios
    /* CONFIGURAÇÃO DOS NAVIOS
    Cada navio possui tamanho 3.
    O valor 3 representa uma posição ocupada.*/

    printf("\n*** Hora de posicionar os navios no tabuleiro: ***\n");

    printf("Pressione ENTER para visualizar o tabuleiro...\n");
    getchar();

    //Posicionamento horizontal
    // O navio ocupa três posições consecutivas na mesma linha
    if(coluna_horizontal + 2 < colunas)
    {
        int livre = 1;

        for(int i = 0; i < 3; i++)
        {
            if(tabuleiro[linha_horizontal][coluna_horizontal + i] != 0)
            {
                livre = 0;
            } 

        }

        if(livre)
        {
            for(int i = 0; i < 3; i++)
            {
            tabuleiro[linha_horizontal][coluna_horizontal + i] = navio_horizontal[i];
            }
            } else {
                printf("Erro: sobreposição de navios.\n"); 
            }
        } else {
        printf("Erro: navio fora dos limites do tabuleiro.\n");
        }

    //Posicionamento vertical
    // O navio ocupa três posições consecutivas na mesma coluna
    
    if(linha_vertical + 2 < linhas)
    {
        int livre = 1;

        for(int i = 0; i < 3; i++)
            {
                if(tabuleiro[linha_vertical + i][coluna_vertical] != 0)
                {
            livre = 0;
              } 
            }

        if(livre)
        {
            for(int i = 0; i < 3; i++)
            {
            tabuleiro[linha_vertical + i][coluna_vertical] = navio_vertical[i];
             }
        } else {
            printf("Erro: sobreposição de navios.\n"); 
        }
        } else {
            printf("Erro: navio fora dos limites do tabuleiro.\n");
    }

    //Posicionamento diagonal crescente
    // O navio ocupa três posições consecutivas na diagonal

    if(linha_diagonal1 + 2 < linhas && coluna_diagonal1 + 2 < colunas)
    {
        int livre = 1;

        for(int i = 0; i < 3; i++)
        {
            if(tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] != 0)
            {
                livre = 0;
            }
        }

        if(livre)
        {
            for(int i = 0; i < 3; i++)
            {
                tabuleiro[linha_diagonal1 + i][coluna_diagonal1 + i] = navio_diagonal1[i];
            }
        } else {
            printf("Erro: sobreposição de navios.\n"); 
        }
        } else {
           printf("Erro: navio fora dos limites do tabuleiro.\n"); 
    }

    //Posicionamento diagonal decrescente
    // O navio ocupa três posições consecutivas na diagonal

    if(linha_diagonal2 + 2 < linhas && coluna_diagonal2 - 2 >= 0)
    {
        int livre = 1;

        for(int i = 0; i < 3; i++)
        {
            if(tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] != 0)
            {
                livre = 0;
            }
        }

        if(livre)
        {
            for(int i = 0; i < 3; i++)
            {
                tabuleiro[linha_diagonal2 + i][coluna_diagonal2 - i] = navio_diagonal2[i];
            }
        } else {
            printf("Erro: sobreposição de navios.\n"); 
        }
        } else {
            printf("Erro: navio fora dos limites do tabuleiro.\n");
    }

    //Exibição do tabuleiro final
    //Mostra o tabuleiro após o posicionamento dos navios
    printf("\n*** TABULEIRO COM NAVIOS ***\n\n");

    printf("   ");
    for(int i = 0; i < colunas; i++) {
        printf("%c ", letras_colunas[i]);
    }

    printf("\n");

    for(int i = 0; i < linhas; i++){
        printf("%2d ", numero_linhas[i]);

        for(int j = 0; j < colunas; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    printf("Agora você pode escolher entre três opções de habilidade especial para usar no jogo.\n");
    printf("1. Cone \n");
    printf("2. Cruz \n");
    printf("3. Octaedro\n");
    printf("Qual você quer usar?  \n");
    scanf("%d", &opcao);
    printf("\n");

    switch(opcao) {
        case 1:
        //Habilidade especial
        /* HABILIDADE CONE
        Cria uma matriz 5x5.
        Valor 1 representa a área afetada.
        Valor 0 representa área não afetada.
        */
        printf("\n*** Ataque em Cone: ***\n"); 

        for(int i = 0; i < 5; i++)
{
    for(int j = 0; j < 5; j++)
    {
        if(i >= 1 && i <= 3 && j >= 3 - i && j <= 1 + i)
        {
            cone[i][j] = 1;
        }
    }
}

        // Sobrepõe a matriz da habilidade Cone ao tabuleiro 
        /* SOBREPOSIÇÃO DA HABILIDADE
        A matriz da habilidade é centralizada na posição
        informada pelo usuário e copiada para o tabuleiro.
        As posições afetadas recebem o valor 5.
        */

        printf("*** Vamos lançar o ataque no tabuleiro? ***\n");

        for(int i = 0; i < linhas; i++)
            {
                printf("Para linha %d digite %d\n", i + 1, i);
            }

        // Solicita a linha de origem até que o usuário informe um valor válido. 
        do
            {
                printf("Digite a linha de origem da habilidade (0 a 9): ");
                scanf("%d", &origem_linha);
            }
        while(origem_linha < 0 || origem_linha >= linhas); 

        for(int i = 0; i < colunas; i++)
            {   
                printf("Para coluna %c digite %d\n", letras_colunas[i], i);
            } 

        // Solicita a coluna de origem até que o usuário informe um valor válido. 
        do
            {
                printf("Digite a coluna de origem da habilidade (0 a 9): ");
                scanf("%d", &origem_coluna);
            }
        while(origem_coluna < 0 || origem_coluna >= colunas); 

        for(int i = 0; i < 5; i++)
            {       
                for(int j = 0; j < 5; j++)
                    {
                        if(cone[i][j] == 1)
                            {
                            // Calcula a posição correspondente da habilidade dentro do tabuleiro, centralizando a matriz 5x5
                            // no ponto de origem informado pelo usuário. 
                                int linha = origem_linha - 2 + i;
                                int coluna = origem_coluna - 2 + j;

                            // Verifica se a posição calculada permanece dentro dos limites do tabuleiro. 
                                if(linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
                                     {
                                        tabuleiro[linha][coluna] = 5;
                            }
                    }
             }
        }
            printf("\n"); 

            // Exibe o estado atual do tabuleiro após a aplicação da habilidade escolhida.
 
            printf("\nTABULEIRO COM A HABILIDADE\n\n");

            printf("   ");

            for(int i = 0; i < colunas; i++)
                printf("%c ", letras_colunas[i]);
                printf("\n");

            for(int i = 0; i < linhas; i++)
                {
                    printf("%2d ", numero_linhas[i]);

                 for(int j = 0; j < colunas; j++)
                    {
                        printf("%2d ", tabuleiro[i][j]);
                    }

                    printf("\n");
                }
        break;

        case 2:
        /* HABILIDADE CRUZ
        Cria uma matriz 5x5.
        Valor 1 representa a área afetada.
        Valor 0 representa área não afetada.
        O formato final é em cruz de 5 pontos na vertical e cinco pontos na horizontal.
        */ 
        printf("\n*** Ataque em Cruz: ***\n"); 

        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(i == 2 || j == 2)
                    {
                        cruz[i][j] = 1;
                    }
            }       
        }
        printf("\n"); 

        // Sobrepõe a matriz da habilidade Cruz ao tabuleiro 
        printf("*** Vamos lançar o ataque no tabuleiro? ***\n");

        for(int i = 0; i < linhas; i++)
            {
                printf("Para linha %d digite %d\n", i + 1, i);
            }

        // Solicita a linha de origem até que o usuário informe um valor válido. 
        do
            {
                printf("Digite a linha de origem da habilidade (0 a 9): ");
                scanf("%d", &origem_linha);
            }
        while(origem_linha < 0 || origem_linha >= linhas); 

        for(int i = 0; i < colunas; i++)
            {
                printf("Para coluna %c digite %d\n", letras_colunas[i], i);
            } 

        // Solicita a coluna de origem até que o usuário informe um valor válido. 
        do
            {
                printf("Digite a coluna de origem da habilidade (0 a 9): ");
                scanf("%d", &origem_coluna);
            }
        while(origem_coluna < 0 || origem_coluna >= colunas); 

        for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                    {
                        if(cruz[i][j] == 1)
                            {
                                // Calcula a posição correspondente da habilidade dentro do tabuleiro, centralizando a matriz 5x5
                                // no ponto de origem informado pelo usuário. 
                                int linha = origem_linha - 2 + i;
                                int coluna = origem_coluna - 2 + j;

                                // Verifica se a posição calculada permanece dentro dos limites do tabuleiro. 
                                if(linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
                                    {
                                        tabuleiro[linha][coluna] = 5;
                                    }
                            }
                    }
            }
            printf("\n"); 

        //Exibe o estado atual do tabuleiro após a aplicação da habilidade escolhida.
        printf("\nTABULEIRO COM A HABILIDADE\n\n");

        printf("   ");
        for(int i = 0; i < colunas; i++)
            printf("%c ", letras_colunas[i]);
            printf("\n");

        for(int i = 0; i < linhas; i++)
            {
                printf("%2d ", numero_linhas[i]);

                for(int j = 0; j < colunas; j++)
                {
                    printf("%2d ", tabuleiro[i][j]);
                }

                printf("\n");
            }
        break;  

        case 3:
        /* HABILIDADE OCTAEDRO
        Cria uma matriz 5x5.
        Valor 1 representa a área afetada.
        Valor 0 representa área não afetada.
        A área afetada fica em formato de 3 pontos verticais e 3 pontos horizontais.
        */
        printf("\n*** Ataque em Octaedro: ***\n"); 

        for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++)
                    {
                        if((i == 2 && j >= 1 && j <= 3) || (j == 2 && i >= 1 && i <= 3)) 
                            {
                                octaedro[i][j] = 1;
                            }
                    }
            }

        printf("\n"); 

        // Sobrepõe a matriz da habilidade Octaedro ao tabuleiro 
        printf("*** Vamos lançar o ataque no tabuleiro? ***\n");

        for(int i = 0; i < linhas; i++)
            {
                printf("Para linha %d digite %d\n", i + 1, i);
            }

        // Solicita a linha de origem até que o usuário informe um valor válido. 
        do
            {
                printf("Digite a linha de origem da habilidade (0 a 9): ");
                scanf("%d", &origem_linha);
            }
        while(origem_linha < 0 || origem_linha >= linhas); 

        for(int i = 0; i < colunas; i++)
            {
                printf("Para coluna %c digite %d\n", letras_colunas[i], i);
            } 

        // Solicita a coluna de origem até que o usuário informe um valor válido. 
        do
            {
                printf("Digite a coluna de origem da habilidade (0 a 9): ");
                scanf("%d", &origem_coluna);
            }
        while(origem_coluna < 0 || origem_coluna >= colunas); 

        for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < 5; j++) 
                    {
                        if(octaedro[i][j] == 1)
                            {
                                // Calcula a posição correspondente da habilidade dentro do tabuleiro, centralizando a matriz 5x5
                                // no ponto de origem informado pelo usuário. 
                                int linha = origem_linha - 2 + i;
                                int coluna = origem_coluna - 2 + j;

                                // Verifica se a posição calculada permanece dentro dos limites do tabuleiro. 
                                if(linha >= 0 && linha < linhas && coluna >= 0 && coluna < colunas)
                                    {
                                        tabuleiro[linha][coluna] = 5;
                                    }
                            }
                    }
            }
        printf("\n"); 

        /*
        Exibe o estado atual do tabuleiro após a aplicação
        da habilidade escolhida.
        */ 
        printf("\nTABULEIRO COM A HABILIDADE\n\n");

        printf("   ");

        for(int i = 0; i < colunas; i++)
            printf("%c ", letras_colunas[i]);

            printf("\n");

        for(int i = 0; i < linhas; i++)
        {
            printf("%2d ", numero_linhas[i]);

            for(int j = 0; j < colunas; j++)
                {
                    printf("%2d ", tabuleiro[i][j]);
                }

            printf("\n");
        }
        break;

        default:
        printf("\n");
        printf("Opção inválida. Execute o programa novamente para escolher uma habilidade.\n");
        break;
    }

    printf("\n");
    printf("*****************************************\n");
    printf("*** Partida encerrada! Até a próxima! ***\n");
    printf("*****************************************\n");

    return 0;
}
