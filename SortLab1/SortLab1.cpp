// SortLab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <cstring>
#include <stdio.h>
#include "SortLab1.h"

void z1(char* input, int len, bool fromFile = false) {
    if (!fromFile) {
        std::cout << "Введите строку (массив символов): ";
        std::cin.getline(input, 100);
        len = strlen(input); 
    }

    processString(input, len);

    std::cout << "Результат (массив символов): " << input << std::endl;
}

void z2(char* input, int len, bool fromFile = false) {
    if (!fromFile) {
        std::cout << "Введите строку (C-строка): ";
        std::cin.getline(input, 100);
        len = strlen(input);  
    }

    processString(input, len);  

    std::cout << "Результат (C-строка): " << input << std::endl;
}

void z3() {
    int method_choice;
    std::cout << "Выберите метод для работы со строкой:\n";
    std::cout << "Вариант 1: Массив символов\n";
    std::cout << "Вариант 2: C-строка\n";
    std::cout << "Введите ваш выбор (1, 2): ";
    std::cin >> method_choice;
    std::cin.ignore();

    FILE* file = fopen("z31.txt", "r");
    if (file == NULL) {
        std::cout << "Ошибка открытия файла\n";
        return;
    }

    char input[100] = { '\0' };
    fgets(input, sizeof(input), file);  
    fclose(file);

    int len = strlen(input);

    if (method_choice == 1) {
        std::cout << "Выбран метод работы с массивом символов\n";
        z1(input, len, true);
    } else if (method_choice == 2) {
        std::cout << "Выбран метод работы с C-строкой\n";
        z2(input, len, true);
    } else {
        std::cout << "Неверный выбор метода\n";
        return;
    } 

    file = fopen("z32.txt", "w");
    if (file == NULL) {
        std::cout << "Ошибка открытия файла\n";
        return;
    }

    fputs(input, file); 
    fclose(file);

    std::cout << "Обработанная строка записана в z32.txt.\n";
}

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int choice;
    std::cout << "Выберите один из вариантов для тестирования:\n";
    std::cout << "Вариант 1: Массив символов\n";
    std::cout << "Вариант 2: C-строка\n";
    std::cout << "Вариант 3: Работа с файлом\n";
    std::cout << "Введите ваш выбор (1, 2, 3): ";
    std::cin >> choice;
    std::cin.ignore();

    char input[100] = { '\0' };
    int len = 0;

    switch (choice) {
    case  1:
        z1(input, len);
        break;
    case  2:
        z2(input, len);
        break;
    case  3:
        z3();
        break;
    default:
        std::cout << "Неверный выбор!\n";
        break;
    }

    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
