//
// Created by Crafter on 26.01.2026.
//

#include "format.h"

#include <clocale>
#include <cstdlib>

void setupEnv()
{
    system("chcp 65001 > nul"); // UTF-8 windows
    std::setlocale(LC_ALL, "");
}

