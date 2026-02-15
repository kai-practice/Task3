#include <iostream>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
    setupEnv();

    int n;
    std::cout << "Введіть n (сума цифр): ";
    std::cin >> n;

    if (n < 1 || n > 27) {
        std::cout << "Для трицифрового числа сума цифр має бути від 1 до 27.\n";
        std::cout << "Кількість: 0\n";
        return;
    }

    int count_for = 0;
    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k <= 9; k++) {
                if (i + j + k == n) {
                    count_for++;
                }
            }
        }
    }

    int count_while = 0;
    int i = 1;
    while (i <= 9) {
        int j = 0;
        while (j <= 9) {
            int k = 0;
            while (k <= 9) {
                if (i + j + k == n) {
                    count_while++;
                }
                k++;
            }
            j++;
        }
        i++;
    }

    std::cout << "\n--- Результати ---" << "\n";
    std::cout << "Кількість (через for): " << count_for << "\n";
    std::cout << "Кількість (через while): " << count_while << "\n";
}

static Module module(
    module_init,
    "Завдання 2: Написати програму визначення кількості тризначних натуральних чисел, сума цифр яких дорівнює n (n ≥ 1)."
);