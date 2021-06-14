#include "zip_file.h"

int main()
{
    std::string myFile = "myFile.txt";

    Zip a(myFile);
    a.readFromFile();
    a.encoding();
    a.writeToFile();
    //a.decoding();
}