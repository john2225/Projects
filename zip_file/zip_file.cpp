#include "zip_file.h"
using VecStr = std::vector<std::string>;

Zip::Zip(const std::string &path) : _path(path)
{
}

void Zip::readFromFile()
{
    std::string line;
    _fileIn.open(_path);
    if (!_fileIn.is_open())
    {
        std::cerr << "Can't open the file" << std::endl;
    }
    else
    {
        while (getline(_fileIn, line))
        {
            doc += line;
        }
    }
    _fileIn.close();
}
void Zip::encoding()
{
    //std::cout << "Encoding" << std::endl;
    std::unordered_map<std::string, int> table;
    for (int i = 0; i <= 255; ++i)
    {
        std::string ch = "";
        ch += char(i);
        table[ch] = i;
    }
    std::string p = "";
    std::string c = "";
    p += doc[0];
    int code = 256;

    for (int i = 0; i < doc.size(); ++i)
    {
    
        if (i != doc.size() - 1)
        {
            c += doc[i + 1];
        }
        if (table.find(p + c) != table.end())
        {
            p = p + c;
        }
        else
        {
            output_code.push_back(table[p]);
            table[p + c] = code;
            ++code;
            p = c;
        }
        c = "";
    }
  
    output_code.push_back(table[p]);
}

void Zip::decoding()
{
    std::unordered_map<int, std::string> table;
    for (int i = 0; i <= 255; ++i)
    {
        std::string ch = "";
        ch += char(i);
        table[i] = ch;
    }
    int old = output_code[0];
    int n;
    std::string s = table[old];
    std::string c = "";
    c += s[0];
    int count = 256;
    std::cout << s;
    for (int i = 0; i < output_code.size(); ++i)
    {
        n = output_code[i + 1];
        if (table.find(n) == table.end())
        {
            s = table[old];
            s = s + c;
        }
        else
        {
            s = table[n];
        }
        c = "";
        c += s[0];
        table[count] = table[old] + c;
        ++count;
        old = n;
        std::cout << s;
    }
}
void Zip::writeToFile()
{
    _path = "encoded_file.txt";
    _fileOut.open(_path);
    if(!_fileOut.is_open())
    {
        std::cerr << "can't create the file!" << std::endl;
    }
    else
    {
        for(int i = 0; i < output_code.size(); ++i)
        {
            _fileOut << output_code[i];
        }
    }

}