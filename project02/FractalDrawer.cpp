// FractalDrawer.cpp
// --------- includes ---------
#include <iostream>
#include <string>
#include <deque>
#include <vector>
#include "Fractal.h"
#include "boost/filesystem.hpp"
// --------- constants ---------
#define FILE_PATH 1 /** The argument number that the files path should be located at */
#define INPUT_COUNT 2 /** Number of input (-1) that the user should provide */
#define USAGE "Usage: FractalDrawer <file path>" /** USAGE error message. */
#define INVALID_INPUT "Invalid input" /** Invalid input error message */
#define COMMA ','
#define COLUMNS 1
#define SPACE ' '

using namespace boost::filesystem;

/**
 * This method verifies the user input and return false if the program should exit (failure)
 * and true otherwise. (this method also prints the error if ones occur)
 * @param argc Number of arguments that the user provided (the first argument is
 * the name of the running file ("FractalDrawer.cpp")
 * @param argv Arguments "string" array.
 * @return false if the program should fail, true otherwise.
 */
bool checkValidity(int argc, char* argv[])
{
    if (argc != INPUT_COUNT) // Incorrect number of arguments
    {
        std::cerr << USAGE << std::endl;
        return false;
    }
    if (!exists(argv[FILE_PATH]))
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    return true;
}

/**
 * Checks if the file has a legal input, if it will return false.
 * The function also prints the error if one occures.
 * @param line A line from the given file.
 * @return false if the line is illegal, true otherwise.
 */
bool validLine(const std::string& line)
{
    int counter = 0;
    std::string strNum;
    for(char ch : line) // iterating char by char to search for illegal ones.
    {
        if(ch == COMMA)
        {
            counter++;
        }
        if(ch == SPACE)
        {
            std::cerr << INVALID_INPUT << std::endl;
            return false;
        }
    }
    if(counter != COLUMNS)
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    return true;
}

//bool addToVec(const std::string& line, std::vector<Fractal&> fracVec)
//{
//    std::string newStr;
//    int fracNum = 0, height = 0;
//    for(char ch : line) // iterating char by char to search for illegal ones.
//    {
//        if(ch == COMMA)
//        {
//            try
//            {
//                fracNum = stoi(newStr);
//            }
//            catch (...)
//            {
//                std::cerr << INVALID_INPUT << std::endl;
//                return false;
//            }
//            newStr = "";
//        }
//        else
//        {
//            newStr += ch;
//        }
//    }
//    try
//    {
//        height = stoi(newStr);
//    }
//    catch (...)
//    {
//        std::cerr << INVALID_INPUT << std::endl;
//        return false;
//    }
//    Fractal& frac = Fractal::Create(fracNum, height);
//    //fracVec.push_back(frac);
//    return true;
//}

/**
 * Main function. here I load the file and check if its a valid one,
 * then I print all the fractals.
 * @param argc Number of arguments (including the files name)
 * @param argv Array of all the arguments as char*.
 * @return 0 on successful run 1 on failure.
 */
int main(int argc, char* argv[])
{
    if(!checkValidity(argc, argv)) // validity check
    {
        return EXIT_FAILURE;
    }
    // open the file and start loading the data...
    //std::vector<Fractal&> fracVec;
    ifstream inFile(argv[FILE_PATH]);
    std::string line;
    std::deque<std::string> lst;
    while (std::getline(inFile, line))
    {
        if(!validLine(line))
        {
            return EXIT_FAILURE;
        }
        lst.push_front(line); // load line by line
    }
    // ------------------------------
//    for(const std::string& str: lst)
//    {
//        if(addToVec(str, fracVec))
//        {
//            return EXIT_FAILURE;
//        }
//    }
//    for(Fractal* frac: fracVec)
//    {
//        frac->draw();
//    }
    Fractal& frac = Fractal::Create(1, 3);
    frac.draw();
    return 0;
}
