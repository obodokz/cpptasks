#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

// Константы для определения соседних клеток в 4 направлениях: вверх, вниз, влево, вправо
const vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

// Функция для поиска пути в лабиринте методом BFS
bool bfs(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
    int rows = maze.size();
    int cols = maze[0].size();

    queue<pair<int, int>> q;
    q.push(start);
    maze[start.first][start.second] = 1; // Помечаем начальную точку как посещённую

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        // Если достигли конечной точки, завершаем поиск
        if (current == end) {
            return true;
        }

        // Просматриваем соседние клетки
        for (auto dir : directions) {
            int nx = current.first + dir.first;
            int ny = current.second + dir.second;

            // Проверяем, что соседняя клетка находится в пределах лабиринта и не посещена
            if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && maze[nx][ny] == 0) {
                q.push({ nx, ny });
                maze[nx][ny] = 1; // Помечаем клетку как посещённую
            }
        }
    }

    return false; // Если не найдено пути
}

int main() {
    vector<vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1}
    };

    pair<int, int> start = { 0, 0 };
    pair<int, int> end = { 4, 4 };

    if (bfs(maze, start, end)) {
        cout << "Путь найден!\n";
    }
    else {
        cout << "Путь не найден.\n";
    }

    return 0;
}
