#include "lib.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

/**
 * @brief Функція для підрахунку кількості голосних букв у рядку.
 * 
 * @param text Рядок для перевірки.
 * @return Кількість голосних букв.
 */
int countVowels(const char *text) {
    int vowel_count = 0;

    // Перевіряємо кожен символ рядка на голосну букву
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == 'a' || text[i] == 'e' || text[i] == 'i' || text[i] == 'o' || text[i] == 'u' ||
            text[i] == 'A' || text[i] == 'E' || text[i] == 'I' || text[i] == 'O' || text[i] == 'U') {
            vowel_count++;  // Збільшуємо лічильник голосних
        }
    }
    
    return vowel_count;  // Повертаємо кількість голосних
}

/**
 * @brief Функція для обробки вхідних даних з командного рядка.
 * Якщо дані не передані, генерується випадковий рядок.
 * 
 * @param argc Кількість аргументів.
 * @param argv Масив аргументів.
 * @param text Рядок для зберігання результату.
 */
void processInput(int argc, char *argv[], char *text) {
    // Якщо аргументи командного рядка передані
    if (argc > 1) {
        int i = 0;
        // Копіюємо символи з argv[1] в text
        while (argv[1][i] != '\0' && i < MAX_LEN - 1) {
            text[i] = argv[1][i];
            i++;
        }
        text[i] = '\0';  // Завершуємо рядок нульовим символом
    } else {
        // Якщо аргументи не передані, генеруємо випадковий рядок
        const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        srand((unsigned int)time(NULL));
        
        for (int i = 0; i < MAX_LEN - 1; i++) {
            text[i] = charset[rand() % (int)(sizeof(charset) - 1)];
        }
        text[MAX_LEN - 1] = '\0';  // Завершуємо рядок
    }
}

