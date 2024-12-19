
#include "lib.h"

/**
 * @brief Об'єднує два масиви по черзі: спочатку два елементи з mas2, потім два елементи з mas1.
 *
 * @param mas1 Вхідний масив 1.
 * @param N Розмір масиву mas1.
 * @param mas2 Вхідний масив 2.
 * @param M Розмір масиву mas2.
 * @param result Вихідний масив, куди будуть записані елементи.
 * @param resultSize Розмір результатного масиву.
 */
void mergeArrays(int *mas1, int N, int *mas2, int M, int **result, int *resultSize) {
    // Розмір результатного масиву
    *resultSize = N + M;
    
    // Виділяємо пам'ять для результатного масиву
    *result = (int*)malloc(sizeof(int) * (size_t)(*resultSize));

    int *ptr1 = mas1; // покажчик на перший масив
    int *ptr2 = mas2; // покажчик на другий масив
    int *ptrResult = *result; // покажчик на результатний масив

    // Переписуємо елементи по черзі з mas2 і mas1
    while (ptr2 < mas2 + M && ptr1 < mas1 + N) {
        *ptrResult++ = *ptr2++; // два елементи з mas2
        *ptrResult++ = *ptr2++; 
        *ptrResult++ = *ptr1++; // два елементи з mas1
        *ptrResult++ = *ptr1++;
    }

    // Якщо залишились елементи в mas2
    while (ptr2 < mas2 + M) {
        *ptrResult++ = *ptr2++;
    }

    // Якщо залишились елементи в mas1
    while (ptr1 < mas1 + N) {
        *ptrResult++ = *ptr1++;
    }
}

