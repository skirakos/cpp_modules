#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
    if (argc == 4) {
        std::ifstream inputFile(argv[1]);
        std::string name = ".replace";
        std::ofstream newFile(argv[1] + name);
        std::string line;

        if (!inputFile) {
            std::cerr << "Error opening the file!" << std::endl;
            return 1;
        }

        std::ofstream replaceFile(argv[1] + name);
        while (std::getline(inputFile, line)) {
			size_t index = line.find(argv[2]);
            while (index != std::string::npos) {
				line.erase(index, strlen(argv[2]));
				line.insert(index, argv[3]);
				index += std::string(argv[3]).length();
				index = line.find(argv[2], index);
			}
			replaceFile << line << std::endl;
        }
        replaceFile.close();
        inputFile.close();
    } else {
        std::cout << "Input error." << std::endl;
    }
}
