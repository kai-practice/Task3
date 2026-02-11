#include <iostream>
#include <vector>
#include <cmath>
#include "../../format.h"
#include "../Modules.h"

// -----------------------------
//   ДОПОМІЖНІ ФУНКЦІЇ
// -----------------------------

long findMinAll(const std::vector<long>& a, int n)
{
    long mn = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] < mn) mn = a[i];
    return mn;
}

long findMaxAll(const std::vector<long>& a, int n)
{
    long mx = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > mx) mx = a[i];
    return mx;
}

long findMinOdd(const std::vector<long>& a, int n)
{
    long mn = a[0]; // a1, a3, a5...
    for (int i = 0; i < n; i += 2)
        if (a[i] < mn) mn = a[i];
    return mn;
}

long findMaxEven(const std::vector<long>& a, int n)
{
    long mx = (n > 1 ? a[1] : a[0]); // a2, a4, a6...
    for (int i = 1; i < n; i += 2)
        if (a[i] > mx) mx = a[i];
    return mx;
}


// -----------------------------
//   ОСНОВНИЙ МОДУЛЬ
// -----------------------------
static void module_init()
{
    setupEnv();

    int n;
    std::cout << "Введіть n (кількість елементів): ";
    std::cin >> n;

    std::vector<long> a(n);

    std::cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; i++)
    {
        std::cout << "a[" << i+1 << "] = ";
        std::cin >> a[i];
    }

    // -----------------------------
    //   ВЕРСІЯ З ЦИКЛОМ FOR
    // -----------------------------
    long min_all = findMinAll(a, n);
    long max_all = findMaxAll(a, n);
    long min_odd = findMinOdd(a, n);
    long max_even = findMaxEven(a, n);

    std::cout << "\n--- FOR ---\n";
    std::cout << "min(a1..an) = " << min_all << "\n";
    std::cout << "max(a1..an) = " << max_all << "\n";
    std::cout << "min(a1, a3, ...) = " << min_odd << "\n";
    std::cout << "max(a2, a4, ...) = " << max_even << "\n";
    std::cout << "min(a1, a3, ...) + max(a2, a4, ...) = "
              << (min_odd + max_even) << "\n";


    // -----------------------------
    //   ВЕРСІЯ З ЦИКЛОМ WHILE
    // -----------------------------
    long min_all_w = a[0];
    long max_all_w = a[0];
    long min_odd_w = a[0];
    long max_even_w = (n > 1 ? a[1] : a[0]);

    int i = 0;

    // min і max усіх елементів
    while (i < n)
    {
        if (a[i] < min_all_w) min_all_w = a[i];
        if (a[i] > max_all_w) max_all_w = a[i];
        i++;
    }

    // min серед непарних індексів
    i = 0;
    while (i < n)
    {
        if (i % 2 == 0 && a[i] < min_odd_w)
            min_odd_w = a[i];
        i++;
    }

    // max серед парних індексів
    i = 1;
    while (i < n)
    {
        if (a[i] > max_even_w)
            max_even_w = a[i];
        i += 2;
    }

    std::cout << "\n--- WHILE ---\n";
    std::cout << "min(a1..an) = " << min_all_w << "\n";
    std::cout << "max(a1..an) = " << max_all_w << "\n";
    std::cout << "min(a1, a3, ...) = " << min_odd_w << "\n";
    std::cout << "max(a2, a4, ...) = " << max_even_w << "\n";
    std::cout << "min(a1, a3, ...) + max(a2, a4, ...) = "
              << (min_odd_w + max_even_w) << "\n";
}

static Module module(
    module_init,
    "Завдання 5: прості min/max (for/while)"
);
