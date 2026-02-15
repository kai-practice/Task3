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
		std::cout << "Потрібно мінімум 3\n";
		return;
	}

	std::vector<long> arr(n);
	std::cout << "Введіть цілі числа:\n";
	for (int i = 0; i < n; i++) {
		std::cout << "n["<<i<<"]:";
		std::cin >> arr[i];
	}

	int count1 = 0;
	for (int i = 1; i < n - 1; i++) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
			count1++;
		}
	}

	int count2 = 0;
	int j = 1;
	while (j < n - 1) {
		if (arr[j] > arr[j - 1] && arr[j] > arr[j + 1]) {
			count2++;
		}
		j++;
	}

	std::cout << "\n--- Результати ---" << "\n";
	std::cout << "\nРезультат (через for): " << count1 << "\n";
	std::cout << "Результат (через while): " << count2 << "\n";
}

static Module module(
	module_init,
	"Завдання 3: Дано n цілих чисел. Створити програму, що визначає, яка кількість з них більша за своїх \"сусідів\", тобто за попереднє та наступне числа."
);