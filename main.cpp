#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>



int main() {
    std::ifstream infile;
    infile.open("data.csv");
    std::string line, item;
    
    std::vector<std::vector<int>> data(2);
    std::vector<int> row(2);
    if(infile.is_open()){
        while (getline(infile,line)){
            if (not!infile.good()) break;
            std::stringstream strs(line);
            while(getline(strs, item, ',')) row.push_back(std::stoi(item));
            data.push_back(row);
        };
    };
    return 0;
};