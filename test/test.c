#include "lib.h"  // Підключаємо заголовочний файл, де оголошені функції
#include <check.h> // Підключаємо бібліотеку для тестування

// Тестуємо функцію mergeArrays
START_TEST(test_mergeArrays) {
    // Вхідні масиви
    int mas1[] = {1, 7, 4, 8, 3};  // Масив 1
    int mas2[] = {6, 6, 9, 9};      // Масив 2

    // Розміри масивів
    int N = sizeof(mas1) / sizeof(mas1[0]);
    int M = sizeof(mas2) / sizeof(mas2[0]);

    // Результуючий масив та його розмір
    int *result = NULL;
    int resultSize = 0;

    // Викликаємо функцію для злиття масивів
    mergeArrays(mas1, N, mas2, M, &result, &resultSize);

    // Очікуваний результат
    int expected[] = {6, 6, 1, 7, 9, 9, 4, 8, 3};  // Очікуємо таке злиття: 2 елементи з mas2, потім 2 елементи з mas1

    // Перевіряємо, чи співпадають елементи результатного масиву з очікуваними
    for (int i = 0; i < resultSize; i++) {
        ck_assert_int_eq(result[i], expected[i]);
    }

    // Звільняємо пам'ять
    free(result);
}
END_TEST

// Функція для створення тестового набору
Suite *create_suite(void) {
    Suite *s = suite_create("MergeArrays");  // Створюємо новий тестовий набір
    TCase *tc_core = tcase_create("Core");   // Створюємо основний блок тестів

    // Додаємо тест до блоку
    tcase_add_test(tc_core, test_mergeArrays);
    
    // Додаємо блок тестів до набору
    suite_add_tcase(s, tc_core);

    return s;  // Повертаємо набір тестів
}

// Основна функція для запуску тестів
int main(void) {
    int number_failed;  // Лічильник неуспішних тестів
    Suite *s = create_suite();  // Створюємо тестовий набір
    SRunner *sr = srunner_create(s);  // Створюємо запуск тестів

    // Запускаємо всі тести з детальним виведенням
    srunner_run_all(sr, CK_VERBOSE);
    
    // Отримуємо кількість неуспішних тестів
    number_failed = srunner_ntests_failed(sr);
    
    // Очищаємо ресурси після виконання тестів
    srunner_free(sr);

    // Повертаємо успіх або помилку в залежності від результатів тестів
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

