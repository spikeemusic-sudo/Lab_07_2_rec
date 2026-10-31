#define UNIT_TESTING
#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_07_2_rec/Lab_07_2_rec.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72rec
{
    TEST_CLASS(UnitTest72rec)
    {
    public:

        TEST_METHOD(TestSearchMaxMainDiagRec)
        {
            // Arrange: підготовка даних
            int n = 4;
            int** a = new int* [n];

            // Створюємо тестову матрицю 4х4
            // Елементи головної діагоналі: -5, 12, 0, 7. 
            a[0] = new int[n] { -5, 2, 3, 4 };
            a[1] = new int[n] {  1, 12, 5, 6 };
            a[2] = new int[n] { 22, 8, 0, 10 }; // 22 не на діагоналі, ігнорується
            a[3] = new int[n] { 99, 11, 14, 7 }; // 99 не на діагоналі, ігнорується

            // Максимальний серед (-5, 12, 0, 7) дорівнює 12.
            int expected_max = 12;

            // Act: виконання рекурсивної функції (починаємо перевірку з індексу i = 0)
            int actual_max = SearchMaxMainDiag(a, n, 0);

            // Assert: перевірка результату
            Assert::AreEqual(expected_max, actual_max);

            // Очищення пам'яті
            for (int i = 0; i < n; i++) {
                delete[] a[i];
            }
            delete[] a;
        }
    };
}