#include <iostream>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard() {
    std::cout << "Kółko i Krzyżyk\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j];
            if (j < 2) std::cout << " | ";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "--|---|--" << std::endl;
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentMarker;
        return true;
    }
    return false;
}

int winner() {
    for (int i = 0; i < 3; i++) {
        // Weryfikacja wierszy
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;
        // Weryfikacja kolumn
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
    }
    // Weryfikacja przekątnych
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

    return 0;
}

void swapPlayerAndMarker() {
    if (currentMarker == 'X') currentMarker = 'O';
    else currentMarker = 'X';

    if (currentPlayer == 1) currentPlayer = 2;
    else currentPlayer = 1;
}

int main() {
    currentMarker = 'X';
    currentPlayer = 1;
    int playerWon;

    drawBoard();

    for (int i = 0; i < 9; i++) {
        int slot;
        std::cout << "Gracz " << currentPlayer << ", wybierz pole: ";
        std::cin >> slot;

        if (slot < 1 || slot > 9) {
            std::cout << "Błędne pole! Spróbuj jeszcze raz.\n";
            i--;
            continue;
        }

        if (!placeMarker(slot)) {
            std::cout << "To pole jest już zajęte! Spróbuj jeszcze raz.\n";
            i--;
            continue;
        }

        drawBoard();

        playerWon = winner();

        if (playerWon == 1) {
            std::cout << "Gracz 1 wygrywa!" << std::endl;
            break;
        } else if (playerWon == 2) {
            std::cout << "Gracz 2 wygrywa!" << std::endl;
            break;
        }

        swapPlayerAndMarker();
    }

    if (playerWon == 0) {
        std::cout << "Remis!" << std::endl;
    }

    return 0;
}