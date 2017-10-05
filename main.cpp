#include "qsort.hpp"
#include <fstream>
#include <list>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "qsort <path>" << std::endl;
        return -1;
    }

    std::ifstream ifile{argv[1]};
    if (!ifile) {
        std::cout << "An error has occurred while opening file: " << argv[1] << std::endl;
        return -1;
    }

    ifile.seekg(0, std::ios_base::end);
    auto size = ifile.tellg();
    if (size == -1) {
        std::cout << "An error has occurred while reading file: " << argv[1] << std::endl;
        return -1;
    }

    ifile.seekg(0, std::ios_base::beg);

    std::vector<char> v;
    v.reserve(size);

    for(std::string line; std::getline(ifile, line);) {
        v.insert(v.end(), line.cbegin(), line.cend());
    }

    qs::qsort(v.begin(), v.end());
    std::copy(v.begin(), v.end(), std::ostream_iterator<char>{std::cout});
    std::cout << std::endl;
}
