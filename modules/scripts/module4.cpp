#include <iostream>
#include <vector>
#include <cmath>
#include "../../format.h"
#include "../Modules.h"

static bool is_square(int x) {
	if (x < 0) return false;
	int r = static_cast<int>(std::sqrt(x));
	return r*r == x;
}

static void module_init()
{
	setupEnv();
	int n;
	std::cout << "Введите количество элементов: ";
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	// for
	int evens_f = 0, squares_f = 0, odd_sq_f = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] % 2 == 0) ++evens_f;
		if (is_square(a[i])) {
			++squares_f;
			int r = static_cast<int>(std::sqrt(a[i]));
			if (r % 2 != 0) ++odd_sq_f;
		}
	}
	std::cout << "For -> Парные: " << evens_f << ", Полные квадраты: " << squares_f << ", Квадраты непарных оснований: " << odd_sq_f << '\n';

	// while
	int evens_w = 0, squares_w = 0, odd_sq_w = 0;
	int i = 0;
	while (i < n) {
		if (a[i] % 2 == 0) ++evens_w;
		if (is_square(a[i])) {
			++squares_w;
			int r = static_cast<int>(std::sqrt(a[i]));
			if (r % 2 != 0) ++odd_sq_w;
		}
		++i;
	}
	std::cout << "While -> Парные: " << evens_w << ", Полные квадраты: " << squares_w << ", Квадраты непарных оснований: " << odd_sq_w << '\n';
}

static Module module(
	module_init,
	"Анализ массива: парные, полные квадраты, квадраты непарных (for/while)"
);
