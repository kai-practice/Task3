#include <iostream>
#include "modules/modules.h"
#include "format.h"

void pause(std::string message)
{
	std::cout << message;
	std::cin.ignore();
	std::cin.get();
}

int main()
{
    setupEnv();

    auto& modules = getModules();

    std::cout << "меню(треба вписати номер програми)\n\n---------\n\n";

    for (size_t i = 0; i < modules.size(); ++i)
    {
        std::cout << '{' << i + 1 << '}' << " -- "
                  << modules[i].description << "\n\n";
    }
    std::cout << "програма:";
    int choice;
    std::cin >> choice;

    if (choice > 0 && choice <= (int)modules.size())
    {
    	std::cout << "запуск..." << modules[choice - 1].description << "\n...\n";
    	try {
    		modules[choice - 1].func();
    	} catch (_exception) {
    		return 0;
    	}
    }
	pause( "\nНатисніть Enter для виходу...");
    std::cout << "програма виконана. повернення в меню.";
	main();
}