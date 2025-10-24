#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

struct Placar {
    int vitorias_humano;
    int vitorias_maquina;
    int empates;
};

struct Placar placar = {0, 0, 0};

char tabuleiro[3][3];

const char JOGADOR_HUMANO = 'X';
const char JOGADOR_MAQUINA = 'O';
const char VAZIO = '-';

void limparTela();
void mostrarTabuleiro();
void mostrarPlacar();
void iniciarJogo();
void jogadaHumano();
void jogadaMaquina();
int verificarVencedor(char jogador);

int main() {
    srand(time(NULL));

    int opcao;
    int sair = 0; 

    do {
        limparTela();
        printf("========================\n");
        printf("    JOGO DA VELHA\n");
        printf("========================\n");
        printf("1. Iniciar Jogo\n");
        printf("2. Mostrar Placar\n");
        printf("3. Sair\n");
        printf("\nEscolha uma opcao: ");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                iniciarJogo();
                break;
            case 2:
                mostrarPlacar();
                break;
            case 3:
                printf("Tem certeza que deseja sair? (S/N): ");
                char confirm;
                scanf(" %c", &confirm); 

                if (toupper(confirm) == 'S') {
                    sair = 1;
                }
                break;
            default:
                printf("\nOpcao invalida! Pressione 1 e Enter para tentar novamente: ");
                int temp;
                scanf("%d", &temp); 
                break;
        }

    } while (sair == 0);

    printf("\nObrigado por jogar!\n");
    return 0; 
}

void limparTela() {
    system("cls");
}

void mostrarTabuleiro() {
    printf("\n  Mapa (1-9):     Tabuleiro Atual:\n");
    printf("     1 | 2 | 3          %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("    ---+---+---        ---+---+---\n");
    printf("     4 | 5 | 6          %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("    ---+---+---        ---+---+---\n");
    printf("     7 | 8 | 9          %c | %c | %c \n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

void mostrarPlacar() {
    limparTela();
    printf("========================\n");
    printf("         PLACAR\n");
    printf("========================\n");
    printf("Humano (X): %d vitorias\n", placar.vitorias_humano);
    printf("Maquina (O): %d vitorias\n", placar.vitorias_maquina);
    printf("Empates:    %d\n", placar.empates);
    printf("========================\n");
    
    printf("\nPressione 1 e Enter para voltar ao menu: ");
    int temp;
    scanf("%d", &temp); 
}

void iniciarJogo() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = VAZIO;
        }
    }

    int turno = rand() % 2; 
    int vencedor = 0; 
    
    printf("Sorteio: ");
    if (turno == 0) {
        printf("Voce (X) comeca!\n");
    } else {
        printf("Maquina (O) comeca!\n");
    }
    
    printf("Pressione 1 e Enter para comecar: ");
    int temp;
    scanf("%d", &temp);

    for (int jogada = 0; jogada < 9; jogada++) {
        limparTela();
        mostrarTabuleiro();

        if (turno == 0) {
            jogadaHumano();
            if (verificarVencedor(JOGADOR_HUMANO)) {
                placar.vitorias_humano++; 
                vencedor = 1;
                break; 
            }
            turno = 1; 
        } else {
            jogadaMaquina();
            if (verificarVencedor(JOGADOR_MAQUINA)) {
                placar.vitorias_maquina++; 
                vencedor = 1;
                break; 
            }
            turno = 0; 
        }
    }

    limparTela();
    mostrarTabuleiro();
    
    if (vencedor == 1) {
        if (turno == 0) { 
            printf("\n*** PARABENS! Voce (X) venceu! ***\n");
        } else {
            printf("\n*** QUE PENA! A Maquina (O) venceu! ***\n");
        }
    } else {
        printf("\n*** DEU VELHA! O jogo empatou! ***\n");
        placar.empates++; 
    }

    printf("\nPressione 1 e Enter para voltar ao menu: ");
    scanf("%d", &temp); 
}

void jogadaHumano() {
    int pos, i, j;
    
    do {
        printf("Sua vez (X). Digite a posicao (1-9): ");
        scanf("%d", &pos);

        i = (pos - 1) / 3; 
        j = (pos - 1) % 3; 

        if (pos < 1 || pos > 9) {
            printf("Posicao invalida. Tente de 1 a 9.\n");
        } else if (tabuleiro[i][j] != VAZIO) {
            printf("Posicao ja ocupada. Tente outra.\n");
        }
    } while (pos < 1 || pos > 9 || tabuleiro[i][j] != VAZIO);

    tabuleiro[i][j] = JOGADOR_HUMANO;
}

void jogadaMaquina() {
    int pos, i, j;
    
    printf("Vez da Maquina (O)... ");

    do {
        pos = (rand() % 9) + 1; 
        i = (pos - 1) / 3;
        j = (pos - 1) % 3;
        
    } while (tabuleiro[i][j] != VAZIO);

    tabuleiro[i][j] = JOGADOR_MAQUINA;
    printf("Maquina jogou na %d.\n", pos);
    
    for(long k=0; k < 99999999; k++); 
}

int verificarVencedor(char jogador) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] == jogador && tabuleiro[i][1] == jogador && tabuleiro[i][2] == jogador) {
            return 1;
        }
    }

    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] == jogador && tabuleiro[1][j] == jogador && tabuleiro[2][j] == jogador) {
            return 1;
        }
    }

    if (tabuleiro[0][0] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][2] == jogador) {
        return 1;
    }
    if (tabuleiro[0][2] == jogador && tabuleiro[1][1] == jogador && tabuleiro[2][0] == jogador) {
        return 1;
    }

    return 0; 
}
