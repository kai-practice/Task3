#include <iostream>
#include <vector>
#include "../../format.h"
#include "../Modules.h"

static void module_init()
{
	setupEnv();

	int n;
	std::cout << "Введіть n: ";
	std::cin >> n;

	if (n < 3) {
		std::cout << "Кількість: 0\n";
		return;
	}

	std::vector<long> a(n);
	std::cout << "Введіть цілі числа:\n";
	for (int i = 0; i < n; i++) {
		std::cout << "n["<<i<<"]:";
		std::cin >> a[i];
	}

	int count_for = 0;
	for (int i = 1; i < n - 1; i++) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
			count_for++;
		}
	}

	int count_while = 0;
	int j = 1;
	while (j < n - 1) {
		if (a[j] > a[j - 1] && a[j] > a[j + 1]) {
			count_while++;
		}
		j++;
	}
	std::cout << "\n--- Результати ---" << "\n";
	std::cout << "\nРезультат (через for): " << count_for << "\n";
	std::cout << "Результат (через while): " << count_while << "\n";
}

static Module module(
	module_init,
	"Завдання 3: Дано n цілих чисел. Створити програму, що визначає, яка кількість з них більша за своїх \"сусідів\", тобто за попереднє та наступне числа."
);