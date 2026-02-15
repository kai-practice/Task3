#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
    setupEnv();

    int n;
    std::cout << "Введіть n: ";
    std::cin >> n;

    if (n < 1) {
        std::cout << "Помилка. n має бути більше 0\n";
        return;
    }

    std::vector<double> a(n);

    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "a[" << i+1 << "] = ";
        std::cin >> a[i];
    }

    double min_all = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min_all) min_all = a[i];
    }

    double max_abs = std::abs(a[0]);
    for (int i = 1; i < n; i++) {
        if (std::abs(a[i]) > max_abs) max_abs = std::abs(a[i]);
    }

    double max_even_idx = (n > 1) ? a[1] : -1e9;
    if (n > 1) {
        for (int i = 1; i < n; i += 2) {
            if (a[i] > max_even_idx) max_even_idx = a[i];
        }
    }

    double min_odd_idx = a[0];
    for (int i = 0; i < n; i += 2) {
        if (a[i] < min_odd_idx) min_odd_idx = a[i];
    }

    double min_even_pos = (n > 1) ? a[1] : 0;
    if (n > 1) {
        for (int i = 1; i < n; i += 2) {
            if (a[i] < min_even_pos) min_even_pos = a[i];
        }
    }

    double max_odd_pos = a[0];
    for (int i = 0; i < n; i += 2) {
        if (a[i] > max_odd_pos) max_odd_pos = a[i];
    }

    double sum_res = min_even_pos + max_odd_pos;

    double max_pow2 = a[0];
    for (int k = 1; k <= n; k *= 2) {
        int index = k - 1;
        if (a[index] > max_pow2) max_pow2 = a[index];
    }

    std::cout << "\n--- Результати ---\n";
    std::cout << "а)" << min_all << '\n';
    std::cout << "б)" << max_abs << '\n';

    if (n > 1)
        std::cout << "в)" << max_even_idx << '\n';
    else
        std::cout << "в) Неможливо (мало елементів)\n";

    std::cout << "г)" << min_odd_idx << '\n';

    if (n > 1)
        std::cout << "ґ)" << sum_res << '\n';
    else
        std::cout << "ґ) Неможливо порахувати повністю\n";

    std::cout << "д)" << max_pow2 << '\n';ё
}

static Module module(
    module_init,
    "Завдання 5: Точна версія (double)"
);