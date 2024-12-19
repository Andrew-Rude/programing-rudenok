
#include "lib.h"

int main() {
    // Приклад масивів
    int mas1[] = {1, 7, 4, 8, 3};
    int mas2[] = {6, 6, 9, 9};
    int *result;
    int resultSize;
    
    int N = sizeof(mas1) / sizeof(mas1[0]);
    int M = sizeof(mas2) / sizeof(mas2[0]);

    // Викликаємо функцію для об'єднання масивів
    mergeArrays(mas1, N, mas2, M, &result, &resultSize);
    
    // Для перевірки результату (можна подивитись значення в відлагоднику)
    for (int i = 0; i < resultSize; i++) {
        // result[i] дивитись у відлагоднику
    }

    // Звільняємо пам'ять
    free(result);
    return 0;
}

