#include <iostream>
#include <string>

using namespace std;

// Функция для шифрования слова методом Цезаря
string encryptCaesarCipher(string word, int shift) {
    string encryptedWord = ""; // Закодированное слово

    // Проходим по каждому символу в слове
    for (char& ch : word) {
        // Проверяем, является ли символ буквой
        if (isalpha(ch)) {
            // Определяем базовый индекс для 'A' или 'a' в зависимости от регистра символа
            char base = isupper(ch) ? 'A' : 'a';
            // Вычисляем новый символ с учётом сдвига
            char shifted = static_cast<char>((ch - base + shift) % 26 + base);
            encryptedWord += shifted; // Добавляем новый символ к закодированному слову
        }
        else {
            // Если символ не является буквой, добавляем его как есть
            encryptedWord += ch;
        }
    }

    return encryptedWord;
}

int main() {
    int shift;
    string word;

    // Ввод ключа-сдвига
    cout << "Введите ключ-сдвиг (целое число от 1 до 25): ";
    cin >> shift;

    // Ввод слова для шифрования
    cout << "Введите слово для шифрования: ";
    cin.ignore(); // Очищаем буфер после ввода числа
    getline(cin, word);

    // Шифрование слова и вывод результата
    string encryptedWord = encryptCaesarCipher(word, shift);
    cout << "Закодированное слово: " << encryptedWord << endl;

    return 0;
}
