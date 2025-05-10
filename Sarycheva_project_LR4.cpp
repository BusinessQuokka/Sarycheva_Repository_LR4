#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Прототипы функций, пустые реализации
int findNthDigitRightToLeft(int k, int n);
int findNthDigitLeftToRight(int k, int n);

int main() {
  int choice;

  do {
    cout << "\nМеню:" << endl;
    cout << "1. Ввести натуральное число K" << endl;
    cout << "2. Ввести цифру N" << endl;
    cout << "3. Найти N-ю цифру целого положительного числа К при нумерации цифр справа налево" << endl;
    cout << "4. Найти N-ю цифру целого положительного числа К при нумерации цифр слева направо" << endl;
    cout << "0. Выход" << endl;
    cout << "Выберите пункт меню: ";
    cin >> choice;

    switch (choice) {
      case 1:
        cout << "Выбрано: Ввести натуральное число K. (Функция пока не реализована)" << endl;
        // TODO: Добавить код для ввода числа K
        break;
      case 2:
        cout << "Выбрано: Ввести цифру N. (Функция пока не реализована)" << endl;
        // TODO: Добавить код для ввода цифры N
        break;
      case 3: {
        int k, n;
        cout << "Введите натуральное число K: ";
        cin >> k;
        cout << "Введите цифру N: ";
        cin >> n;
        int result = findNthDigitRightToLeft(k, n);
        cout << "N-я цифра (справа налево): " << result << endl;
        break;
      }
      case 4: {
        int k, n;
        cout << "Введите натуральное число K: ";
        cin >> k;
        cout << "Введите цифру N: ";
        cin >> n;
        int result = findNthDigitLeftToRight(k, n);
        cout << "N-я цифра (слева направо): " << result << endl;
        break;
      }
      case 0:
        cout << "Выход из программы." << endl;
        break;
      default:
        cout << "Неверный выбор. Пожалуйста, выберите пункт меню от 0 до 4." << endl;
    }
  } while (choice != 0);

  return 0;
}

// Функция для нахождения N-й цифры справа налево
int findNthDigitRightToLeft(int k, int n) {
  string numStr = to_string(k);
  if (n > numStr.length()) {
    return -1;
  }
  return numStr[numStr.length() - n] - '0'; 
}

// Функция для нахождения N-й цифры слева направо
int findNthDigitLeftToRight(int k, int n) {
  string numStr = to_string(k);
  if (n > numStr.length()) {
    return -1;
  }
  return numStr[n - 1] - '0'; 
}