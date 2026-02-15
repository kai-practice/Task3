#include <iostream>
#include "../../format.h"
#include "../Modules.h"

using namespace std;

static void module_init()
{
	setupEnv();

	int m, n;

	cout << "Введіть перше натуральне число (m): ";
	cin >> m;
	cout << "Введіть друге натуральне число (n): ";
	cin >> n;

	if (m < 1 || n < 1) {
		cout << "Помилка: Числа повинні бути натуральними (>= 1)." << endl;
		return;
	}

	long long product_for = 0;
	for (int i = 0; i < n; i++) {
		product_for += m;
	}

	long long product_while = 0;
	int count = 0;
	while (count < n) {
		product_while += m;
		count++;
	}

	std::cout << "\n--- Результати ---" << "\n";
	cout << "1. Через цикл for:   " << m << " * " << n << " = " << product_for << endl;
	cout << "2. Через цикл while: " << m << " * " << n << " = " << product_while << endl;


}

static Module module(
	module_init,
	"Завдання 1: Скласти програму для обчислення добутку двох натуральних чисел m і n, використовуючи тільки операцію додавання."
);