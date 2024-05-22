#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class fileReader {
private:
    std::vector<std::string> data; 
    std::ifstream file; 

public:
    std::vector<std::string> getData() {
        return data;
    }
    fileReader(const std::string& filename) {
        file.open(filename); 
        if (!file.is_open()) {
            std::cerr << "Failed to open the file." << std::endl;
        }
        else {
            std::string line;
            while (std::getline(file, line)) {
                data.push_back(line); 
            }
        }
    }

    ~fileReader() { 
        if (file.is_open()) {
            file.close();
        }
    }
};