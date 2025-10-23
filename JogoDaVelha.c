#include <stdio.h>
#include <stdlib.h>

char tabuleiro[3][3];
vitorias_humano = 0; vitorias_maquina = 0; empates = 0;

void inicializarTabuleiro(){
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = '-';    
}

void imprimirTabuleiro(){
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++)
            printf(" %c ", tabuleiro[i][j]);
        printf("\n");
    }
    printf("\n");
}

void mostrar_menu(){
    printf("=======================================\n");
    printf("        JOGO DA VELHA EM C\n");
    printf("=======================================\n");
    printf("1. Iniciar Jogo\n");
    printf("2. Placar\n");
    printf("3. Sair\n");
    printf("---------------------------------------\n");
}

void iniciar_jogo(){
    printf("\n[ O Jogo vai começar!\n");
}

void mostrar_placar(){
    printf("\n[ Placar ]\n");
    printf("Vitórias do Humano (X): %d\n", vitorias_humano);
    printf("Vitórias da Máquina (O): %d\n", vitorias_maquina);
    printf("Empates: %d\n", empates);
    printf("\n");
}

int main() {
    printf("Jogo da Velha\n");
   int opção;

    While (1) {
        mostrar_menu ();
        printf("escolha uma opção: ");
        if (scanf("%d", &opção) != 1) {
            printf("Opção inválida. Tente novamente! ");
            while (getchar() != '\n');
            continue;
        }
        switch (opção) (
            case 1:
                iniciar_jogo(); 
                break;
            case 2:
                mostrar_placar(); 
                break;
            case 3: 
                printf("\nTem certeza que deseja sair? (1 para Sim / 0 para Não): ");
                int confirmacao;
                scanf("%d", &confirmacao);
                if (confirmacao == 1) {
                    printf("Programa finalizado. Até mais!\n"); 
                    return 0;
                }
                break;
            default:
                printf("\nOpção inválida. Por favor, escolha 1, 2 ou 3.\n\n");
                break;
    }
    return 0;
}
