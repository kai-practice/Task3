#include <iostream>

#include "../../format.h"
#include "../Modules.h"


static void module_init()
{
	setupEnv();

	unsigned long long x;
	std::cout << "Введіть x\n(мінус ігнорується)\nx:";
	std::cin >> x;
	std::cout << "таблиця:\n";

	unsigned long long
		x2 = x * x,
		x3 = x2 * x,
		x4 = x2 * x2,
		x6 = x3 * x3,
		x8 = x4 * x2,
		x9 = x3 * x6,
		x12 = x4 * x3,
		x15 = x12 * x3,
		x16 = x8 * x8,
		x24 = x16 * x8,
		x28 = x24 * x4,
		x32 = x16 * x16,
		x64 = x32 * x32;

	std::cout << "x^4 = " << x4 << '\n';
	std::cout << "x^6 = " << x6 << '\n';
	std::cout << "x^9 = " << x9 << '\n';
	std::cout << "x^15 = " << x15 << '\n';
	std::cout << "x^28 = " << x28 << '\n';
	std::cout << "x^64 = " << x64 << '\n';
}

static Module module(
	module_init,
	"(39) Дано дійсне число x. Користуючись тільки операцією множення, отримати:\n а) x4 за дві операції; б) x6 за три операції; в) x9 за чотири операції; г) x15 за п'ять операцій; \nґ) x28 за шість операцій; д) x64 за шість операцій."
);
//test