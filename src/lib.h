#ifndef LIB_H //перевірка чи був раніше визначений іменований макрос
#define LIB_H //визначаємо макрос

#include <stdlib.h>

// Функція для об'єднання масивів по черзі (по два елементи з кожного масиву)
void mergeArrays(int *mas1, int N, int *mas2, int M, int **result, int *resultSize);

#endif // Закриваємо блок перевірки

