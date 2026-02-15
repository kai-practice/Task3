#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "../../format.h"
#include "../Modules.h"

void byFor(const std::vector<double>& a, int n) {
    double min_all = DBL_MAX;
    double max_abs = -1.0;

    double max_even_pos = -DBL_MAX;
    double min_odd_pos = DBL_MAX;
    double min_even_pos = DBL_MAX;
    double max_odd_pos = -DBL_MAX;
    double max_pow2 = -DBL_MAX;


    for (int i = 0; i < n; i++) {
        double val = a[i];
        int real_index = i + 1;

        if (val < min_all) min_all = val;

        if (std::abs(val) > max_abs) max_abs = std::abs(val);

        if (real_index % 2 == 0) {
            if (val > max_even_pos) max_even_pos = val; // в)
            if (val < min_even_pos) min_even_pos = val; // для ґ)
        } else {
            if (val < min_odd_pos) min_odd_pos = val;   // г)
            if (val > max_odd_pos) max_odd_pos = val;   // для ґ)
        }
    }


    for (int k = 1; k <= n; k *= 2) {
        if (a[k-1] > max_pow2) {
            max_pow2 = a[k-1];
        }
    }
    std::cout << "\n--- Результати (FOR) ---\n";
    std::cout << "а) min(a1...an): " << min_all << std::endl;
    std::cout << "б) max(|a1|...|an|): " << max_abs << std::endl;

    if (n >= 2) {
        std::cout << "в) max(a2, a4...): " << max_even_pos << std::endl;
        std::cout << "ґ) min(a2, a4...) + max(a1, a3...): " << (min_even_pos + max_odd_pos) << std::endl;
    } else {
        std::cout << "в) та ґ) Неможливо обчислити (n < 2)" << std::endl;
    }

    std::cout << "г) min(a1, a3...): " << min_odd_pos << std::endl;
    std::cout << "д) max(a1, a2, a4, a8...): " << max_pow2 << std::endl;
}

void byWhile(const std::vector<double>& a, int n) {
    double min_all = DBL_MAX;
    double max_abs = -1.0;
    double max_even_pos = -DBL_MAX;
    double min_odd_pos = DBL_MAX;
    double min_even_pos = DBL_MAX;
    double max_odd_pos = -DBL_MAX;
    double max_pow2 = -DBL_MAX;

    int i = 0;
    while (i < n) {
        double val = a[i];
        int real_index = i + 1;


        if (val < min_all) min_all = val;

        if (std::abs(val) > max_abs) max_abs = std::abs(val);


        if (real_index % 2 == 0) {
            if (val > max_even_pos) max_even_pos = val;
            if (val < min_even_pos) min_even_pos = val;
        } else {
            if (val < min_odd_pos) min_odd_pos = val;
            if (val > max_odd_pos) max_odd_pos = val;
        }
        i++;
    }


    int k = 1;
    while (k <= n) {
        if (a[k-1] > max_pow2) {
            max_pow2 = a[k-1];
        }
        k *= 2;
    }
    std::cout << "\n--- Результати (WHILE) ---\n";

    std::cout << "а) min(a1...an): " << min_all << std::endl;
    std::cout << "б) max(|a1|...|an|): " << max_abs << std::endl;

    if (n >= 2) {
        std::cout << "в) max(a2, a4...): " << max_even_pos << std::endl;
        std::cout << "ґ) min(a2, a4...) + max(a1, a3...): " << (min_even_pos + max_odd_pos) << std::endl;
    } else {
        std::cout << "в) та ґ) Неможливо обчислити (недостатньо чисел)" << std::endl;
    }

    std::cout << "г) min(a1, a3...): " << min_odd_pos << std::endl;
    std::cout << "д) max(a1, a2, a4, a8...): " << max_pow2 << std::endl;
}

static void module_init()
{
    setupEnv();
    int n;
    std::cout << "Введіть кількість чисел (n): ";
    std::cin >> n;


    std::vector<double> a(n);
    std::cout << "Введіть " << n << " дійсних чисел: " << std::endl;
    for (int i = 0; i < n; i++) {
		std::cout << "n["<<i<<"]:";
        std::cin >> a[i];
    }
    byFor(a, n);
    byWhile(a, n);
}

static Module module(
    module_init,
    "Завдання 5: Задано натуральне число n і дійсні числа а1, а2,…, аn. Написати програми знаходження Min(3 варіанта) та Max(3 варіанта)"
);