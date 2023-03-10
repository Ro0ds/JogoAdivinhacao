#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#define NIVEL_FACIL 20
#define NIVEL_MEDIO 15
#define NIVEL_DIFICIL 6

int main() {
    setlocale(LC_ALL, "Portuguese_Brasil");

    printf("                                                               \n\n");
    printf("              P /_\\ P                                           \n");
    printf("            /_\\_|_|_/_\\                                        \n");
    printf("         n_n | ||. .|| | n_n                    Bem-vindo ao     \n");
    printf("         |_|_|nnnn nnnn|_|_|                Jogo de Adivinhacao! \n");
    printf("        |\" \" | |_| |\" \" |                                    \n");
    printf("        |_____| ' _ ' |_____|                                    \n");
    printf("             \\__|_|__/                                          \n");
    printf("                                                               \n\n");


    //compilar e gerar o .exe
    //gcc .\adivinhacao.c -o adivinhacao.exe

    int nivel;
    int totaldetentativas;
    int chute;
    int chuteanterior;
    int ganhou = 0;
    int pontos = 1000;
    int acertou;
    int valormaximo;

    /*
    gerando número secreto randomico a partir do tempo (segundos)
    após gerar o número, pegar o resto da divisão com 100 para diminui-lo 
    Usuario ira definir qual o valor maximo dos numeros aleatorios
    */

    printf("Defina o valor maximo do numero que tera que adivinhar: ");
    scanf("%d", &valormaximo);
    
    int segundos = time(0);
    srand(segundos);
    int numerogrande = rand();
    int numerosecreto = numerogrande % valormaximo;

    printf("\nQual o nivel de dificuldade?\n");
    printf("(1) Facil | (2) Medio | (3) Dificil\n");
    printf("Escolha: ");
    scanf("%d", &nivel);

    switch(nivel){
        case 1:
            totaldetentativas = NIVEL_FACIL;
            break;
        case 2:
            totaldetentativas = NIVEL_MEDIO;
            break;
        default:
            totaldetentativas = NIVEL_DIFICIL;
            break;
    }

    for(int i = 1; i <= totaldetentativas; i++){
        printf("\nQual e o seu chute? ");
        scanf("%d", &chute);

        if(chute == chuteanterior){
            printf("Este numero ja foi jogado, tente novamente");
            i--;
            continue;
        }

        chuteanterior = chute;

        if(chute < 0){
            printf("Voce nao pode chutar numeros negativos\n");
            i--;
            continue;
        }

        printf("Tentativa %d", i);

        acertou = chute == numerosecreto;
        int maior = chute > numerosecreto;

        if(acertou) {
            printf("\nNumero de tentativas %d\n", i);
            break;
        } 
        else if(maior) {
                printf("\nSeu chute foi maior do que o numero secreto\n");
            }
            else {
                printf("\nSeu chute foi menor do que o numero secreto\n");
            }
        double pontosperdidos = abs(chute - numerosecreto) / (double)2;
        pontos = pontos - pontosperdidos;
    }
    printf("\nVoce fez %.2f pontos\n", pontos);
    
    if(acertou){
        printf(" OOOOOOOOOOO \n");
        printf(" OOOOOOOOOOOOOOOOOOO \n");
        printf(" OOOOOO OOOOOOOOO OOOOOO \n");
        printf(" OOOOOO OOOOO OOOOOO \n");
        printf(" OOOOOOOO # OOOOO # OOOOOOOO \n");
        printf(" OOOOOOOOOO OOOOOOO OOOOOOOOOO \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n");
        printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO \n");
        printf("OOOO OOOOOOOOOOOOOOOOOOOOOOOOO OOOO \n");
        printf(" OOOO OOOOOOOOOOOOOOOOOOOOOOO OOOO \n");
        printf(" OOOO OOOOOOOOOOOOOOOOOOOO OOOO \n");
        printf(" OOOOO OOOOOOOOOOOOOOO OOOO \n");
        printf(" OOOOOO OOOOOOOOO OOOOOO \n");
        printf(" OOOOOO OOOOOO \n");
        printf(" OOOOOOOOOOOO \n");
        printf("\nParabens! Voce acertou!\n");
        printf("Voce fez %.2f pontos. Ate a proxima!\n\n", pontos);
    }
    else{
        printf(" \\|/ ____ \\|/ \n");
        printf(" @~/ ,. \\~@ \n");
        printf(" /_( \\__/ )_\\ \n");
        printf(" \\__U_/ \n");
        printf("\nVoce perdeu! Tente novamente!\n\n");
        printf("O numero secreto era %d", numerosecreto);
    }
}