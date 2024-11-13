#include <iostream>
#include <fstream>

int main() {
    std::ofstream outputFile("example.txt");

    if (!outputFile.is_open()) {
        std::cerr << "Error opening the file for writing!" << std::endl;
        return 1;
    }

    // Writing data to the file
    outputFile << "Hello, World!" << std::endl;

    // Check the state flags
    if (outputFile.bad()) {
        std::cerr << "Error writing to the file (bad flag)!" << std::endl;
    }
    if (outputFile.fail()) {
        std::cerr << "Format error or write error (fail flag)!" << std::endl;
    }
    if (outputFile.eof()) {
        std::cerr << "End of file reached (eof flag)!" << std::endl;
    }
    if (outputFile.good()) {
        std::cout << "All state flags are good." << std::endl;
    }

    // Clear the state flags
    outputFile.clear();

    // Reading data from the file
    std::ifstream inputFile("example.txt");

    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file for reading!" << std::endl;
        return 1;
    }

    std::string content;
    inputFile >> content;

    // Check the state flags after reading
    if (inputFile.bad()) {
        std::cerr << "Error reading from the file (bad flag)!" << std::endl;
    }
    if (inputFile.fail()) {
        std::cerr << "Format error or read error (fail flag)!" << std::endl;
    }
    if (inputFile.eof()) {
        std::cerr << "End of file reached (eof flag)!" << std::endl;
    }
    if (inputFile.good()) {
        std::cout << "All state flags are good." << std::endl;
    }

    return 0;
}
