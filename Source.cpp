#include "Header.h"
#include <iostream>
#include <fstream>
#include <sstream>


Computer::Computer() : model(""), processor(""), ram(0), hdd(0), price(0.0) {}


Computer::~Computer() {}

void Computer::display() const {
    std::cout << "Model: " << model << ", Processor: " << processor
        << ", RAM: " << ram << " GB, HDD: " << hdd
        << " GB, Price: " << price << " RUB\n";
}


Computer Computer::inputFromKeyboard() {
    Computer comp;
    std::string input;

    std::cout << "Enter model: ";
    std::getline(std::cin, input);
    comp.setModel(input);

    std::cout << "Enter processor: ";
    std::getline(std::cin, input);
    comp.setProcessor(input);

    std::cout << "Enter RAM (GB): ";
    std::getline(std::cin, input);
    comp.setRAM(std::stoi(input));

    std::cout << "Enter HDD (GB): ";
    std::getline(std::cin, input);
    comp.setHDD(std::stoi(input));

    std::cout << "Enter price (RUB): ";
    std::getline(std::cin, input);
    comp.setPrice(std::stod(input));

    return comp;
}


bool Computer::hasProcessor(const std::string& targetProcessor) const {
    return processor == targetProcessor;
}

bool Computer::hasRAMGreaterThan(int minRAM) const {
    return ram > minRAM;
}

bool Computer::hasPriceLessThan(double maxPrice) const {
    return price < maxPrice;
}


bool validateString(const std::string& str) {
    return !str.empty();
}

bool validateNumber(int num) {
    return num > 0;
}

bool validatePrice(double price) {
    return price > 0;
}


void loadDataFromFile(const std::string& filename, std::vector<Computer>& computers) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file!\n";
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string model, processor;
        int ram, hdd;
        double price;

        if (iss >> model >> processor >> ram >> hdd >> price) {
            Computer comp;
            comp.setModel(model);
            comp.setProcessor(processor);
            comp.setRAM(ram);
            comp.setHDD(hdd);
            comp.setPrice(price);
            computers.push_back(comp);
        }
    }
    file.close();
}

void addComputerToVector(std::vector<Computer>& computers, const Computer& comp) {
    computers.push_back(comp);
}

void displayAllComputers(const std::vector<Computer>& computers) {
    for (const auto& comp : computers) {
        comp.display();
    }
}

void displayComputersByProcessor(const std::vector<Computer>& computers, const std::string& processor) {
    for (const auto& comp : computers) {
        if (comp.hasProcessor(processor)) {
            comp.display();
        }
    }
}

void displayComputersByRAM(const std::vector<Computer>& computers, int minRAM) {
    for (const auto& comp : computers) {
        if (comp.hasRAMGreaterThan(minRAM)) {
            comp.display();
        }
    }
}


void displayComputersByPrice(const std::vector<Computer>& computers, double maxPrice) {
    for (const auto& comp : computers) {
        if (comp.hasPriceLessThan(maxPrice)) {
            comp.display();
        }
    }
}