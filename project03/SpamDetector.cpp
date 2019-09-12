#include <iostream>
#include <string>
#include "HashMap.hpp"

int main()
{
    HashMap<std::string, std::string> badWords(0.25,0.5);
    std::cout << badWords.size() << std::endl;
    badWords.insert(std::to_string(1), "yoav");
    badWords.insert(std::to_string(2), "jacob");
    badWords.insert(std::to_string(3), "levy");
    badWords.insert(std::to_string(34), "lasdasdy");
    badWords.insert(std::to_string(31234), "lasdasdasdy");
    badWords.insert(std::to_string(34114), "lasdasdy");
    badWords.insert(std::to_string(341), "lasdasdy");
    std::cout << badWords.capacity() << std::endl;
    badWords.insert(std::to_string(31233333), "lasdasdy");
    badWords.insert(std::to_string(311233333333), "lasdasdy");
    badWords.erase(std::to_string(341));
    badWords.erase(std::to_string(3));
    badWords.erase(std::to_string(2));
    std::cout << badWords.capacity() << std::endl;
}