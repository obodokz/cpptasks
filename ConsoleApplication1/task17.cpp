#include <iostream>
#include <vector>

using namespace std;

const int N = 8; // ������ ��������� ����� (8x8)

// ������� ��� ������ �����
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

// ������� ��� ��������, ��������� �� ���������� ����� � ������� (row, col)
bool isSafe(const vector<vector<int>>& board, int row, int col) {
    // ��������� ��������� �����
    for (int i = 0; i < row; ++i) {
        if (board[i][col] == 1) {
            return false;
        }
    }

    // ��������� ����� ��������� �����
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // ��������� ������ ��������� �����
    for (int i = row, j = col; i >= 0 && j < N; --i, ++j) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// ����������� ������� ��� ���������� ������
bool placeQueens(vector<vector<int>>& board, int row) {
    // ������� ������: ���� ��� ����� ���������
    if (row == N) {
        // �������� ��������� ������������
        printBoard(board);
        return true;
    }

    bool res = false;
    // ������� ���������� ����� � ������� ���� � ������ �������
    for (int col = 0; col < N; ++col) {
        if (isSafe(board, row, col)) {
            // ��������� �����
            board[row][col] = 1;

            // ���������� ��������� ��������� ������
            res = placeQueens(board, row + 1) || res;

            // ���� ���������� ���� ������ �� �������, �������� ���������� �������� �����
            board[row][col] = 0;
        }
    }

    return res;
}

int main() {
    // ������ ��������� ����� NxN � �������������� �
    vector<vector<int>> board(N, vector<int>(N, 0));

    // �������� ������� ��� ���������� ������, ������� � ������� ���� (row = 0)
    placeQueens(board, 0);

    return 0;
}
