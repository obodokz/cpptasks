#include <iostream>
#include <string>

using namespace std;

// ������� ��� ���������� ����� ������� ������
string encryptCaesarCipher(string word, int shift) {
    string encryptedWord = ""; // �������������� �����

    // �������� �� ������� ������� � �����
    for (char& ch : word) {
        // ���������, �������� �� ������ ������
        if (isalpha(ch)) {
            // ���������� ������� ������ ��� 'A' ��� 'a' � ����������� �� �������� �������
            char base = isupper(ch) ? 'A' : 'a';
            // ��������� ����� ������ � ������ ������
            char shifted = static_cast<char>((ch - base + shift) % 26 + base);
            encryptedWord += shifted; // ��������� ����� ������ � ��������������� �����
        }
        else {
            // ���� ������ �� �������� ������, ��������� ��� ��� ����
            encryptedWord += ch;
        }
    }

    return encryptedWord;
}

int main() {
    int shift;
    string word;

    // ���� �����-������
    cout << "������� ����-����� (����� ����� �� 1 �� 25): ";
    cin >> shift;

    // ���� ����� ��� ����������
    cout << "������� ����� ��� ����������: ";
    cin.ignore(); // ������� ����� ����� ����� �����
    getline(cin, word);

    // ���������� ����� � ����� ����������
    string encryptedWord = encryptCaesarCipher(word, shift);
    cout << "�������������� �����: " << encryptedWord << endl;

    return 0;
}
