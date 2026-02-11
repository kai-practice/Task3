#include <iostream>
#include <vector>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
	setupEnv();
	int n;
	std::cout << "Введите количество элементов: ";
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	int count_for = 0;
	for (int i = 1; i < n-1; ++i)
		if (a[i] > a[i-1] && a[i] > a[i+1]) ++count_for;
	std::cout << "Количество (for) = " << count_for << '\n';

	int count_while = 0;
	int i = 1;
	while (i < n-1) {
		if (a[i] > a[i-1] && a[i] > a[i+1]) ++count_while;
		++i;
	}
	std::cout << "Количество (while) = " << count_while << '\n';
}

static Module module(
	module_init,
	"Количество элементов, больших обоих соседей (for/while)"
);
