#include <iostream>
#include <map>
#include <string>
#include <fstream>

typedef std::map<std::string, int> StringIntMap;
void cwords(std::istream &in, StringIntMap &words)
{
    std::string text;
    while (in >> text)
    {
        ++words[text];
    }
}

int main(int argc, char **argv)
{
    std::ifstream in("dict.txt");
    StringIntMap wmap;
    cwords(in, wmap);

    for (StringIntMap::iterator it = wmap.begin(); it != wmap.end(); ++it)
    {
        std::cout << it->first << " sebanyak : " << it->second << std::endl;
    }
}