#ifndef __ZIP_FILE__
#define __ZIP_FILE__
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>



class Zip
{
public:
    using VecStr = std::vector<std::string>;
    Zip() = default;
    Zip(const std::string& path);
    Zip(const Zip& obj) = delete;
    ~Zip() = default;
public:
    void encoding();
    void decoding();

    void readFromFile();
    void writeToFile();
    std::ofstream getZipFile() const;
    std::ofstream unZipFile() const;
    

private:
    std::ifstream _fileIn;
    std::ofstream _fileOut;
    std::string _path;
    std::string doc;
    std::vector<int> output_code;
};




#endif /* ZIP FILE */
