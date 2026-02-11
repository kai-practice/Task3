#include <iostream>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
	setupEnv();
	int n;
	std::cout << "Введите n (сумма цифр >= 1): ";
	std::cin >> n;

	int count_for = 0;
	for (int a = 1; a <= 9; ++a)
		for (int b = 0; b <= 9; ++b)
			for (int c = 0; c <= 9; ++c)
				if (a + b + c == n) ++count_for;
	std::cout << "Количество (for) = " << count_for << '\n';

	int count_while = 0;
	int a = 1;
	while (a <= 9) {
		int b = 0;
		while (b <= 9) {
			int c = 0;
			while (c <= 9) {
				if (a + b + c == n) ++count_while;
				++c;
			}
			++b;
		}
		++a;
	}
	std::cout << "Количество (while) = " << count_while << '\n';
}

static Module module(
	module_init,
	"Количество трицифровых чисел с суммой цифр = n (for/while)"
);
