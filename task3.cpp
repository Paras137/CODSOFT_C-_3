#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
const char EMPTY = ' ';
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';

void printBoard(const vector<char>& board) {
    cout << "\n";
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << board[i * SIZE + j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << "\n";
        if (i < SIZE - 1) cout << "---------\n";
    }
    cout << "\n";
}

bool checkWin(const vector<char>& board, char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < SIZE; ++i) {
        if (board[i * SIZE] == player && board[i * SIZE + 1] == player && board[i * SIZE + 2] == player) return true;
        if (board[i] == player && board[i + SIZE] == player && board[i + 2 * SIZE] == player) return true;
    }
    if (board[0] == player && board[4] == player && board[8] == player) return true;
    if (board[2] == player && board[4] == player && board[6] == player) return true;

    return false;
}

bool checkDraw(const vector<char>& board) {
    for (char cell : board) {
        if (cell == EMPTY) return false;
    }
    return true;
}

bool isMoveValid(const vector<char>& board, int move) {
    return move >= 0 && move < SIZE * SIZE && board[move] == EMPTY;
}

void playGame() {
    vector<char> board(SIZE * SIZE, EMPTY);
    char currentPlayer = PLAYER_X;
    int move;
    bool gameOngoing = true;

    while (gameOngoing) {
        printBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;
        move--;  // Convert to 0-based index

        if (!isMoveValid(board, move)) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[move] = currentPlayer;

        if (checkWin(board, currentPlayer)) {
            printBoard(board);
            cout << "Player " << currentPlayer << " wins!\n";
            gameOngoing = false;
        } else if (checkDraw(board)) {
            printBoard(board);
            cout << "It's a draw!\n";
            gameOngoing = false;
        } else {
            currentPlayer = (currentPlayer == PLAYER_X) ? PLAYER_O : PLAYER_X;
        }
    }

    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        playGame();
    }
}

int main() {
    cout << "Welcome to Tic-Tac-Toe!\n";
    playGame();
    return 0;
}
