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
    badWords.insert(std::to_string(3), "yoav");
    badWords.insert(std::to_string(2), "jacob");
    badWords.insert(std::to_string(1), "levy");
    HashMap<std::string, std::string> badWords2(0.25,0.5);
    badWords2.insert(std::to_string(3), "yoav");
    badWords2.insert(std::to_string(2), "jacob");
    badWords2.insert(std::to_string(1), "levy");
//    typename HashMap<std::string, std::string>::iterator k;
//    k = badWords.begin();
//    std::cout << (*k).second << std::endl;
//    ++k;
//    std::cout << (*k).second << std::endl;
//    ++k;
//    std::cout << (*k).second << std::endl;
    //for (auto i = badWords.begin(); i != badWords.end(); i++)
    for (auto item : badWords)
    {
        std::cout << item.second << std::endl;
    }
    std::cout << "------------" << std::endl;
    std::cout << (badWords == badWords2) << std::endl;
}