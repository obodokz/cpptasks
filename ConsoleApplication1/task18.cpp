#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 4; // Количество мужчин и женщин

// Функция для выполнения алгоритма Гейла-Шепли
void stableMarriage(const vector<vector<int>>& menPreferences, const vector<vector<int>>& womenPreferences) {
    vector<int> currentPartner(N, -1); // Текущий партнёр для каждой женщины
    vector<int> nextProposal(N, 0); // Следующая женщина, которой каждый мужчина будет предлагать

    queue<int> freeMen; // Очередь свободных мужчин
    for (int i = 0; i < N; ++i) {
        freeMen.push(i);
    }

    while (!freeMen.empty()) {
        int m = freeMen.front();
        freeMen.pop();

        // Предложение следующей женщине из списка предпочтений мужчины m
        int w = menPreferences[m][nextProposal[m]];
        nextProposal[m]++;

        // Женщина w рассматривает предложение от мужчины m
        if (currentPartner[w] == -1) {
            // Женщина w была свободна
            currentPartner[w] = m;
        }
        else {
            // Женщина w уже занята, нужно сравнить мужчин m и currentPartner[w]
            int m1 = currentPartner[w];
            if (find(womenPreferences[w].begin(), womenPreferences[w].end(), m) < find(womenPreferences[w].begin(), womenPreferences[w].end(), m1)) {
                // Мужчина m предпочтительнее текущего партнёра m1 для женщины w
                currentPartner[w] = m;
                freeMen.push(m1); // Мужчина m1 становится свободным
            }
            else {
                // Женщина w предпочла оставить текущего партнёра m1
                freeMen.push(m); // Мужчина m остаётся свободным
            }
        }
    }

    // Вывод пар стабильных браков
    cout << "Стабильные браки:\n";
    for (int i = 0; i < N; ++i) {
        cout << "Женщина " << i << " и Мужчина " << currentPartner[i] << endl;
    }
}

int main() {
    // Пример предпочтений мужчин и женщин (индексы от 0 до N-1)
    vector<vector<int>> menPreferences = {
        {1, 0, 2, 3},
        {3, 1, 0, 2},
        {0, 1, 3, 2},
        {1, 2, 3, 0}
    };

    vector<vector<int>> womenPreferences = {
        {2, 0, 1, 3},
        {1, 2, 3, 0},
        {0, 3, 2, 1},
        {3, 0, 1, 2}
    };

    // Вызов функции для нахождения стабильных браков
    stableMarriage(menPreferences, womenPreferences);

    return 0;
}
