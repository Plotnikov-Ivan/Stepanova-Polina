к
#define _UE_MATH_DEFINES
#include <iostream>
#include <conio.h>
#include <cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");
    int n;
    float x;
    double accuracity;
    float e;
    double s = 0;
    double sumN = 0, sumE = 0, sumE10 = 0;

    // Ввод чисел //
    printf("Enter -1 <= X <= 1: ");
    scanf_s("%f", &x);
    printf("Enter N (N=>0): ");
    scanf_s("%d", &n);
    printf("Enter e: ");
    scanf_s("%f", &e);

    // Нахождение значения функции //
    double function = log(x + sqrt(x*x +1));
    float an = x;
    int k = 1;
    // Вычисление суммы до N //
    for (int i = 1; i < n; i++) {
        sumN += an;
        an *= -x*x*k/(k+1)*k/(k+2);
    }
    double anlast = abs(an);
    an = x;
    k = 1;

    // Вычисление двух сумм пока |an| > e для sumE и |an| > e / 10 для sumE10  //
    for (int i = 1; abs(an) > e / 10; i++) {
        if (abs(an) > e) {
            sumE += an;
        }
        sumE10 += an;
        an *= -x * x * k / (k + 1) * k / (k + 2);
    }
    accuracity = abs(function - sumN);  // Нахождение абсолютной погрешности

    // Вывод в консоль //
    printf("\n\n%s", "Task 1");
    printf("\n\n%s %f", "Function: ", function);
    printf("\n%s %f", "Row: ", sumN);
    printf("\n%s %f", "Absolute accuracy: ", accuracity);
    printf("\n%s %f", "Last element |an| of row: ", anlast);
    if (accuracity > anlast)
        printf("\n%s", "Absolute accuracy > Last element |an| of row");
    else if (accuracity < anlast)
        printf("\n%s", "Absolute accuracy < Last element |an| of row");
    else
        printf("\n%s", "Absolute accuracy = Last element |an| of row");
    printf("\n\n%s", "Task 2");
    printf("\n\n%s %f", "E =", e);
    printf("\n%s %f", "E / 10 =", (e / 10));
    printf("\n%s %f", "Sum row (an > E) = ", sumE);
    printf("\n%s %f\n", "Sum row (an > E / 10) = ", sumE10);
    system("Pause");
    return 0;
}