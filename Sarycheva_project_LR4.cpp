#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Прототипы функций
int findNthDigitRightToLeft(int k, int n);
int findNthDigitLeftToRight(int k, int n);
int enterNumberK();
int enterNumberN();

// Глобальные переменные для хранения K и N
int K = 0;
int N = 0;

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
        K = enterNumberK();
        break;
      case 2:
        N = enterNumberN();
        break;
      case 3: {
        if (K == 0 || N == 0) {
          cout << "Сначала введите K и N (пункты 1 и 2)." << endl;
          break;
        }
        int result = findNthDigitRightToLeft(K, N);
        cout << "N-я цифра (справа налево): " << result << endl;
        break;
      }
      case 4: {
        if (K == 0 || N == 0) {
          cout << "Сначала введите K и N (пункты 1 и 2)." << endl;
          break;
        }
        int result = findNthDigitLeftToRight(K, N);
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

// Функция для ввода натурального числа K
int enterNumberK() {
  int k;
  cout << "Введите натуральное число K: ";
  cin >> k;
  // Можно добавить проверку на натуральность числа (k > 0)
  if (k <= 0) {
    cout << "Некорректный ввод. K должно быть натуральным числом." << endl;
    return 0; // Возвращаем 0, чтобы обозначить ошибку. Можно использовать другое значение, например -1.
  }
  return k;
}

// Функция для ввода цифры N
int enterNumberN() {
  int n;
  cout << "Введите цифру N: ";
  cin >> n;
  // Можно добавить проверку на то, что n - целое положительное число
  if (n <= 0) {
    cout << "Некорректный ввод. N должно быть натуральным числом." << endl;
    return 0; // Возвращаем 0, чтобы обозначить ошибку. Можно использовать другое значение, например -1.
  }
  return n;
}


// Функция для нахождения N-й цифры справа налево
int findNthDigitRightToLeft(int k, int n) {
  string numStr = to_string(k);
  if (n > numStr.length()) {
    return -1;
  }
  return numStr[numStr.length() - n] - '0'; // Convert char to int
}

// Функция для нахождения N-й цифры слева направо
int findNthDigitLeftToRight(int k, int n) {
  string numStr = to_string(k);
  if (n > numStr.length()) {
    return -1;
  }
  return numStr[n - 1] - '0'; // Convert char to int
}