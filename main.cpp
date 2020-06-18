#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <Qt5harts>


class linearReg {
    public:
     void printData(std::vector< std::vector<int> > data){
        for(int x = 0; x < data.size(); x++) {
            for (int y = 0; y < data[0].size(); y++) {
                std::cout << data[x][y] << " ";
            }
            std::cout << "\n";
        };
    }
};



int main() {
    std::ifstream infile;
    std::string line, item;
    std::vector< std::vector<int> > data;
    std::vector<int> row;
    int num;
    linearReg lr;
    char *ptr = NULL;
    infile.open("data.csv");
    if(infile.is_open()){
        std::cout << "File Open \n";
        while (std::getline(infile,line)){
            if (!infile.good()) break;
            std::stringstream strs(line);
            while(std::getline(strs, item, '|')){
                num = std::strtol(item.c_str(),&ptr, 10);
                row.push_back(num);
            };
            data.push_back(row);
            row.clear();
        };
    };
    lr.printData(data);
    return 0;
};