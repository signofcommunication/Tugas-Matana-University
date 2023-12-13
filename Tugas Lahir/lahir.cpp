#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open the file
    std::ifstream inputFile("datalahir.txt");

    // Check if the file is open
    if (!inputFile.is_open()) {
        std::cerr << "Error opening the file!" << std::endl;
        return 1; // Return an error code
    }

    // Read data from the file
    std::string line;
    while (std::getline(inputFile, line)) {
        // Process each line as needed
        std::cout << line << std::endl;
    }

    // Close the file
    inputFile.close();

    return 0; // Return success
}

