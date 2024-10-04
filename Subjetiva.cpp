#include <iostream>

int main() {
    char reserva[10][6] = {
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' '}
    };

    int fileira = -1, acento = -1;
    char poltrona = ' ';
    char tipoPassagem = ' ';
    char novaReserva = ' ';

    while (true) {
        // Solicitar o tipo de passagem
        do {
            printf("\nDigite o tipo de passagem (E - Economico, X - Executivo): ");
            scanf(" %c", &tipoPassagem);
            tipoPassagem = toupper(tipoPassagem);
            if (tipoPassagem != 'E' && tipoPassagem != 'X') {
                printf("\nTipo de passagem invalido. Tente novamente.");
            }
        } while (tipoPassagem != 'E' && tipoPassagem != 'X');

        // Solicitar entrada de fileira
        do {
            printf("\nDigite a fileira (1-10): ");
            scanf("%d", &fileira);
            if (fileira < 1 || fileira > 10) {
                printf("\nFileira invalida. Tente novamente.");
            }
        } while (fileira < 1 || fileira > 10);

        // Solicitar entrada de poltrona
        bool assentoValido = false;
        do {
            printf("\nDigite a poltrona [A][B][C][D][E][F]: ");
            scanf(" %c", &poltrona);
            poltrona = toupper(poltrona);
            switch (poltrona) {
                case 'A': acento = 0; break;
                case 'B': acento = 1; break;
                case 'C': acento = 2; break;
                case 'D': acento = 3; break;
                case 'E': acento = 4; break;
                case 'F': acento = 5; break;
                default:
                    printf("\nPoltrona invalida. Tente novamente.");
                    continue;
            }

            // Verificar se é uma passagem econômica e se está tentando reservar assento na janela
            if (tipoPassagem == 'E' && (poltrona == 'A' || poltrona == 'F')) {
                printf("\nPoltronas A e F sao exclusivas para classe Executiva. Escolha outra poltrona.");
            } else {
                assentoValido = true;
            }

            // Se for passagem executiva, recomendar assentos A e F
            if (tipoPassagem == 'X' && poltrona != 'A' && poltrona != 'F') {
                printf("\nRecomendamos as poltronas A e F para a classe Executiva.");
            }

        } while (!assentoValido);

        // Verificar se o assento já está reservado
        if (reserva[fileira - 1][acento] == 'x') {
            printf("\nEsse assento ja esta reservado. Por favor, escolha outro.");
            continue;  // Recomeçar o loop se o assento já estiver reservado
        } else {
            reserva[fileira - 1][acento] = 'x';  // Reservar o assento
        }

        // Exibir o mapa de assentos
        printf("\n\t\t[A] [B] [C]\t[D] [E] [F]\n");
        for (int x = 0; x < 10; x++) {
            if (x != 9)
                printf("\n\t0%d\t", x + 1);
            else
                printf("\n\t%d\t", x + 1);

            for (int y = 0; y < 6; y++) {
                printf("[%c] ", reserva[x][y]);
                if (y == 2) {
                    printf("\t");
                }
            }
        }
        printf("\n");

        // Perguntar se deseja realizar outra reserva
        do {
            printf("\nDeseja realizar outra reserva? (S/N): ");
            scanf(" %c", &novaReserva);
            novaReserva = toupper(novaReserva);
            if (novaReserva != 'S' && novaReserva != 'N') {
                printf("\nOpção invalida. Tente novamente.");
            }
        } while (novaReserva != 'S' && novaReserva != 'N');

        // Encerrar o loop se a resposta for 'N'
        if (novaReserva == 'N') {
            printf("\nEncerrando o sistema de reservas...\n");
            break;
        }
    }

    return 0;
}
