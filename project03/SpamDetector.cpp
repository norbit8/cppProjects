#include <iostream>
#include <string>
#include "HashMap.hpp"

int main()
{
    HashMap<std::string, std::string> badWords;
    std::cout << badWords.size() << std::endl;
    badWords.insert(std::to_string(1), "yoav");
    badWords.insert(std::to_string(2), "jacob");
    badWords.insert(std::to_string(3), "levy");
    badWords.erase(std::to_string(2));
    std::cout << badWords.containsKey("2") << std::endl;
}