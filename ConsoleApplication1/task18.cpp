#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 4; // ���������� ������ � ������

// ������� ��� ���������� ��������� �����-�����
void stableMarriage(const vector<vector<int>>& menPreferences, const vector<vector<int>>& womenPreferences) {
    vector<int> currentPartner(N, -1); // ������� ������ ��� ������ �������
    vector<int> nextProposal(N, 0); // ��������� �������, ������� ������ ������� ����� ����������

    queue<int> freeMen; // ������� ��������� ������
    for (int i = 0; i < N; ++i) {
        freeMen.push(i);
    }

    while (!freeMen.empty()) {
        int m = freeMen.front();
        freeMen.pop();

        // ����������� ��������� ������� �� ������ ������������ ������� m
        int w = menPreferences[m][nextProposal[m]];
        nextProposal[m]++;

        // ������� w ������������� ����������� �� ������� m
        if (currentPartner[w] == -1) {
            // ������� w ���� ��������
            currentPartner[w] = m;
        }
        else {
            // ������� w ��� ������, ����� �������� ������ m � currentPartner[w]
            int m1 = currentPartner[w];
            if (find(womenPreferences[w].begin(), womenPreferences[w].end(), m) < find(womenPreferences[w].begin(), womenPreferences[w].end(), m1)) {
                // ������� m ���������������� �������� ������� m1 ��� ������� w
                currentPartner[w] = m;
                freeMen.push(m1); // ������� m1 ���������� ���������
            }
            else {
                // ������� w ��������� �������� �������� ������� m1
                freeMen.push(m); // ������� m ������� ���������
            }
        }
    }

    // ����� ��� ���������� ������
    cout << "���������� �����:\n";
    for (int i = 0; i < N; ++i) {
        cout << "������� " << i << " � ������� " << currentPartner[i] << endl;
    }
}

int main() {
    // ������ ������������ ������ � ������ (������� �� 0 �� N-1)
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

    // ����� ������� ��� ���������� ���������� ������
    stableMarriage(menPreferences, womenPreferences);

    return 0;
}
