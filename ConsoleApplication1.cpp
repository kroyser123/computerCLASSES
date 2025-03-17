#include "header.h"
#include <map>
#include <functional>
#include <iostream>

int main() {
    std::vector<Computer> computers;
    const std::string filename = "computers.txt";


    loadDataFromFile(filename, computers);


    std::map<int, std::function<void()>> menu = {
        {1, [&]() { displayAllComputers(computers); }},
        {2, [&]() {
            std::string processor;
            std::cout << "Enter processor: ";
            std::getline(std::cin, processor);
            displayComputersByProcessor(computers, processor);
        }},
        {3, [&]() {
            int minRAM;
            std::cout << "Enter minimum RAM: ";
            std::cin >> minRAM;
            std::cin.ignore();
            displayComputersByRAM(computers, minRAM);
        }},
        {4, [&]() {
            double maxPrice;
            std::cout << "Enter maximum price: ";
            std::cin >> maxPrice;
            std::cin.ignore();
            displayComputersByPrice(computers, maxPrice);
        }},
        {5, [&]() {
            Computer comp = Computer::inputFromKeyboard();
            addComputerToVector(computers, comp);
        }},
        {6, []() { std::cout << "Exiting...\n"; exit(0); }}
    };

    while (true) {
        std::cout << "\nMenu:\n"
            << "1. Display all computers\n"
            << "2. Display computers by processor\n"
            << "3. Display computers by RAM\n"
            << "4. Display computers by price\n"
            << "5. Add a new computer\n"
            << "6. Exit\n"
            << "Choose an option: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore();

        if (menu.find(choice) != menu.end()) {
            menu[choice]();
        }
        else {
            std::cout << "Invalid choice!\n";
        }
    }

    return 0;
}