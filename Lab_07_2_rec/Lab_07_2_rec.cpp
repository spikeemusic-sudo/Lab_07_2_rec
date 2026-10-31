// Lab_07_2_rec.cpp
// Фащевський Богдан
// Лабораторна робота № 7.2
// Варіант 28
// Опрацювання багатовимірних масивів ітераційним і рекурсивним способами

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <Windows.h>

using namespace std;

// === Прототипи рекурсивних функцій ===

// Формування матриці
void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo);
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo);

// Виведення матриці
void PrintRow(int** a, const int rowNo, const int n, int colNo);
void PrintRows(int** a, const int n, int rowNo);

// Пошук максимального елемента на головній діагоналі
int SearchMaxMainDiag(int** a, const int n, int i);


#ifndef UNIT_TESTING
int main() {
    // Налаштування кодування для коректного відображення української мови
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    srand((unsigned)time(NULL));

    int n;
    cout << "Введіть розмір квадратної матриці n: ";
    cin >> n;

    // Діапазон значень елементів
    int Low = -20;
    int High = 20;

    // Створення динамічної матриці (n x n)
    int** a = new int* [n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
    }

    // Рекурсивне формування та виведення матриці
    CreateRows(a, n, Low, High, 0);
    cout << "Згенерована матриця:" << endl;
    PrintRows(a, n, 0);

    // Рекурсивний пошук (починаємо з індексу i = 0)
    int maxDiag = SearchMaxMainDiag(a, n, 0);
    cout << "Максимальний елемент головної діагоналі: " << maxDiag << endl;

    // Звільнення пам'яті (ітераційно, для безпеки управління ресурсами)
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[] a;

    return 0;
}
#endif

// === Реалізація рекурсивних функцій ===

// Заповнення одного рядка
void CreateRow(int** a, const int rowNo, const int n, const int Low, const int High, int colNo) {
    a[rowNo][colNo] = Low + rand() % (High - Low + 1);
    if (colNo < n - 1) {
        CreateRow(a, rowNo, n, Low, High, colNo + 1);
    }
}

// Перебір рядків для заповнення
void CreateRows(int** a, const int n, const int Low, const int High, int rowNo) {
    CreateRow(a, rowNo, n, Low, High, 0);
    if (rowNo < n - 1) {
        CreateRows(a, n, Low, High, rowNo + 1);
    }
}

// Виведення одного рядка
void PrintRow(int** a, const int rowNo, const int n, int colNo) {
    cout << setw(5) << a[rowNo][colNo];
    if (colNo < n - 1) {
        PrintRow(a, rowNo, n, colNo + 1);
    }
    else {
        cout << endl;
    }
}

// Перебір рядків для виведення
void PrintRows(int** a, const int n, int rowNo) {
    if (rowNo == 0) cout << endl;
    PrintRow(a, rowNo, n, 0);
    if (rowNo < n - 1) {
        PrintRows(a, n, rowNo + 1);
    }
    else {
        cout << endl;
    }
}

// Функція рекурсивного пошуку максимального елемента на головній діагоналі
int SearchMaxMainDiag(int** a, const int n, int i) {
    // Змінна i - поточний індекс елемента на головній діагоналі (одночасно і рядок, і стовпець).
    // Змінна n - загальна розмірність квадратної матриці.

    // Базовий випадок: якщо досягнуто останнього елемента діагоналі (правий нижній кут)
    if (i == n - 1) {
        return a[i][i];
    }

    // Змінна restMax зберігає результат рекурсивного виклику: 
    // максимальний елемент серед решти елементів діагоналі.
    int restMax = SearchMaxMainDiag(a, n, i + 1);

    // Порівнюємо поточний елемент з максимальним серед наступних
    if (a[i][i] > restMax) {
        return a[i][i];
    }
    else {
        return restMax;
    }
}