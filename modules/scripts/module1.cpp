#include <iostream>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
	setupEnv();
	int m, n;
	std::cout << "Введите m и n: ";
	std::cin >> m >> n;

	int product_for = 0;
	for (int i = 0; i < n; ++i) product_for += m;
	std::cout << "Product (for) = " << product_for << '\n';

	int product_while = 0;
	int i = 0;
	while (i < n) { product_while += m; ++i; }
	std::cout << "Product (while) = " << product_while << '\n';
}

static Module module(
	module_init,
	"Добуток двох чисел через додавання (for/while)"
);
