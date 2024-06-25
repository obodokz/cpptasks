#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // Размер шахматной доски (8x8)

// Функция для печати доски
void printBoard(const vector<vector<int>>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i][j] == 1) {
                cout << "Q ";
            }
            else {
                cout << ". ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// Функция для проверки, безопасно ли разместить ферзя в позиции (row, col)
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // Проверяем вертикали вверх
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // Проверяем левую диагональ вверх
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Проверяем правую диагональ вверх
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Рекурсивная функция для размещения ферзей
bool placeQueens(vector<vector<int>>& board, int row) {
    // Базовый случай: если все ферзи размещены
    if (row == N) {
        // Печатаем найденную конфигурацию
        printBoard(board);
        return true;
    }

    bool res = false;
    // Пробуем разместить ферзя в текущем ряду в каждой колонке
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            // Размещаем ферзя
            board[row][col] = 1;

            // Рекурсивно размещаем остальных ферзей
            res = placeQueens(board, row + 1) || res;

            // Если размещение всех ферзей не удалось, отменяем размещение текущего ферзя
            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    // Создаём шахматную доску NxN и инициализируем её
    vector<vector<int>> board(N, vector<int>(N, 0));

    // Вызываем функцию для размещения ферзей, начиная с первого ряда (row = 0)
    placeQueens(board, 0);

    return 0;
}
