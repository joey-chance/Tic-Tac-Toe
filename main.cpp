#include <iostream>

void fill(char* board, int position, char mark) {
    if (board[position-1] != 'X' || board[position-1] != 'O') {
        board[position-1] = mark;
    }
}

bool isDone(char* board) {
    return ((board[0] == board[1] && board[1] == board[2]) ||
            (board[3] == board[4] && board[4] == board[5]) ||
            (board[6] == board[7] && board[7] == board[8]) ||
            (board[0] == board[3] && board[3] == board[6]) ||
            (board[1] == board[4] && board[4] == board[7]) ||
            (board[2] == board[5] && board[5] == board[8]) ||
            (board[0] == board[4] && board[4] == board[8]) ||
            (board[2] == board[4] && board[4] == board[6]));
}

void printBoard(char* board) {
    std::cout << '\n';
    std::cout << "     |     |   \n";
    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << '\n';
    std::cout << "     |     |     \n";
    std::cout << "-----------------\n";
    std::cout << "     |     |   \n";
    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << '\n';
    std::cout << "     |     |     \n";
    std::cout << "-----------------\n";
    std::cout << "     |     |   \n";
    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |   \n\n";
}
int main() {
    char mark = 'X';
    int pos;
    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printBoard(board);
    for (int i = 0; i < 9; i++) {
        std::cout << "Player " << mark << ", choose cell: \n";
        std::cin >> pos;
        while (board[pos-1] == 'X' || board[pos-1] == 'O' || pos < 1 || pos > 9) {
            std::cout << "Cell is invalid. Please choose another cell: \n";
            std::cin >> pos;
        }

        fill(board, pos, mark);
        if (isDone(board)) {
            printBoard(board);
            std::cout << "Player " << mark << " won!\n";
            return 0;
        }
        printBoard(board);
        mark = (mark=='X') ? 'O' : 'X';
    }
}