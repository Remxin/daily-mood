#ifndef FILEREADER_H
#define FILEREADER_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class fileReader {
private:
    std::vector<std::string> data;
    std::ifstream file;

public:
    // Constructor
    fileReader(const std::string& filename);

    // Destructor
    ~fileReader();

    // Getter
    std::vector<std::string> getData() const;
};

#endif // FILEREADER_H
