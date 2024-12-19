#include "lib.h"  // Підключаємо заголовочний файл, де оголошені функції
#include <check.h> // Підключаємо бібліотеку для тестування

// Тестуємо функцію countVowels
START_TEST(test_countVowels) {
    char test_string1[] = "Hello, World!";  // Очікуємо 3 голосні (e, o, o)
    char test_string2[] = "AEIOUaeiou";     // Очікуємо 10 голосних (всі голосні)
    char test_string3[] = "bcdfg";          // Очікуємо 0 голосних

    // Перевіряємо кількість голосних в кожному рядку
    ck_assert_int_eq(countVowels(test_string1), 3);
    ck_assert_int_eq(countVowels(test_string2), 10);
    ck_assert_int_eq(countVowels(test_string3), 0);
}
END_TEST

// Функція для створення тестового набору
Suite *create_suite(void) {
    Suite *s = suite_create("VowelCounter");  // Створюємо новий тестовий набір
    TCase *tc_core = tcase_create("Core");   // Створюємо основний блок тестів

    // Додаємо тест до блоку
    tcase_add_test(tc_core, test_countVowels);
    
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


