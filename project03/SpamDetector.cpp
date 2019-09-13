// SpamDetector.cpp
#include <iostream>
#include <string>
#include "HashMap.hpp"

int main()
{
//    using bucket = vector<std::pair<std::string , std::string>>;
//    vector<bucket> emptyTable(1);
//    emptyTable[0].push_back(std::pair<std::string,std::string>());
//    for(auto i = emptyTable.begin(); i < emptyTable.end(); i++)
//    {
//        for (auto j = i->begin(); j < i->end(); ++j)
//        {
//            std::cout << (" "==j->second) << std::endl;
//        }
//    }
    HashMap<std::string, std::string> badWords(0.25,0.5);
    std::cout << badWords.size() << std::endl;
    badWords.insert(std::to_string(3), "yoav");
    badWords.insert(std::to_string(2), "jacob");
    badWords.insert(std::to_string(1), "levy");
//    typename HashMap<std::string, std::string>::iterator k;
//    k = badWords.begin();
//    std::cout << (*k).second << std::endl;
//    ++k;
//    std::cout << (*k).second << std::endl;
//    ++k;
//    std::cout << (*k).second << std::endl;
    for (auto i = badWords.begin(); i != badWords.end(); i++)
    {
        std::cout << (*i).second << std::endl;
    }
}