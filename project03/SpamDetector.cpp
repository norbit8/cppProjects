// SpamDetector.cpp
// --------- includes ---------
#include <iostream>
#include <string>
#include <fstream>
#include "HashMap.hpp"

// --------- constants ---------
static const int INPUT_COUNT = 4; /** Number of input (-1) that the user should provide */
static const char *const USAGE =
        "Usage: SpamDetector <database path> <message path> <threshold>"; /** USAGE ERROR */
static const int DATA_ARG = 1; /** The argument number of the DataBase path file */
static const int MESSAGE_ARG = 2; /** The argument number of the Message path file */
static const int THRESHOLD_ARG = 3; /** The argument number of the Message path file */
static const char *const INVALID_INPUT = "Invalid input"; /** Invalid input error message */
static const char *const SPAM = "SPAM"; /** When spam email is detecteted */
static const char *const NOT_SPAM = "NOT_SPAM"; /** When an email is not a spam */
// -----------------------------

/**
 * This method verifies the user input and return false if the program should exit (failure)
 * and true otherwise. (this method also prints the error if ones occur)
 * @param argc Number of arguments that the user provided (the first argument is
 * the name of the running file ("SpamDetector.cpp")
 * @param argv Arguments "string" array.
 * @return false if the program should fail, true otherwise.
 */
bool checkValidity(int argc , char *argv[]) noexcept
{
    if (argc != INPUT_COUNT) // Incorrect number of arguments
    {
        std::cerr << USAGE << std::endl;
        return false;
    }
    std::string data , message;
    std::string threshold;
    std::ifstream inFile(argv[DATA_ARG]);
    if (inFile.fail())
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    return true;
}

bool isSpam(std::string &dataPath , std::string &string1 , std::string &string2)
{
    return false;
}

/**
 * The main function scans
 * @param argc number of arguments.
 * @param argv Array of chars of all the arguments (first place is the program name).
 * @return EXIT_SUCCESS if the given input is a SPAM or NOT SPAM, EXIT_FAILURE if something is
 * wrong.
 */
int main(int argc , char *argv[])
{
    if (!checkValidity(argc , argv)) // validity check can't throw
    {
        return EXIT_FAILURE;
    }
    std::string dataPath = argv[DATA_ARG];
    std::string messagePath = argv[MESSAGE_ARG];
    std::string threshold = argv[THRESHOLD_ARG];
    try
    {
        if (isSpam(dataPath , messagePath , threshold)) // isSpam can throw
        {
            std::cout << SPAM << std::endl;
        }
        else
        {
            std::cout << NOT_SPAM << std::endl;
        }
    }
    catch (...)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}