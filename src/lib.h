#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_LEN 100  /**< Максимальна довжина рядка */

/**
 * @brief Функція для підрахунку кількості голосних букв у рядку.
 *
 * @param text Рядок, для якого проводиться підрахунок.
 * @return Кількість голосних букв.
 */
int countVowels(const char *text);

/**
 * @brief Функція для обробки вхідних даних з командного рядка.
 * Якщо дані не передані, генерується випадковий рядок.
 *
 * @param argc Кількість аргументів командного рядка.
 * @param argv Масив аргументів командного рядка.
 * @param text Рядок для обробки.
 */
void processInput(int argc, char *argv[], char *text);

#endif

