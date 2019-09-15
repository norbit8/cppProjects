// SpamDetector.cpp
// --------- includes ---------
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
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
static const char COMMA = ','; /** Comma char */
static const char SPACE = ' '; /** Space char */
static const char NEXT_LINE = '\n'; /** New Line char */
static const int COLUMNS = 1; /** The number of commas which implies that the columns are 2 */
// -----------------------------

/**
 * This funcion verifies that the number of arguments are 4 (including the name of the file)
 * @param argc number of arguments.
 * @return true if so, false otherwise.
 */
inline bool numOfArgs(int argc)
{
    return argc == INPUT_COUNT;
}

/**
 * Is legit digit verfies that the string given can be converted to a legitimate digit
 * (positive natural number).
 * @param strNum string number.
 * @return true, or false.
 */
inline bool isLegitDigit(const char *strNum)
{

    std::string strNumber = strNum; // constructing a string from char.
    for (char ch : strNumber)
    {
        if (!isdigit(ch))
        {
            return false;
        }
    }
    return true;
}

/**
 * This method verifies that the file is a legit one
 * @return true if so, false otherwise.
 */
inline bool isLegitFile(const char *strNum)
{
    std::ifstream inFile1(strNum);
    if (inFile1.fail())
    {
        std::cerr << INVALID_INPUT << std::endl;
        return false;
    }
    return true;
}

/**
 * Converts a string to a digit
 * @param strNum some string
 * @return the number.
 */
int convertToDigit(std::string & strNum)
{
    int number;
    std::stringstream ss(strNum);
    ss >> number;
    if (number <= 0 || ss.fail() || !ss.eof())
    {
        std::cerr << INVALID_INPUT << std::endl;
        throw badInputException();
    }
    return number;
}

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
    if (!numOfArgs(argc) ||
        !isLegitDigit(argv[THRESHOLD_ARG]) ||
        !isLegitFile(argv[DATA_ARG]) ||
        !isLegitFile(argv[MESSAGE_ARG]))
    {
        std::cerr << USAGE << std::endl;
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
bool lineSplitter(const std::string &line , std::string &badPhrase , int &rank)
{
    int counter = 0;
    std::string strNum;
    for (char ch : line) // iterating char by char to search for illegal ones.
    {
        if (counter == 0 && ch != COMMA) // before the comma
        {
            badPhrase += ch;
        }
        else if (ch != COMMA)
        {
            if(ch == SPACE)
            {
                return false;
            }
            strNum += ch;
        }
        else
        {
            counter++; // comma++
        }
    }
    if(badPhrase.empty())
    {
        return false;
    }
    rank = convertToDigit(strNum);
    return counter == COLUMNS;
}

/**
 * loads the data into the map.
 * @param dataPath The path to the data.
 * @param map the map.
 */
void loadData(std::string &dataPath , HashMap<std::string , double>& map)
{
    std::ifstream inFile(dataPath);
    std::string line;
    while (std::getline(inFile , line))
    {
        std::string badPhrase;
        int rank;
        if (!lineSplitter(line , badPhrase , rank))
        {
            std::cout << INVALID_INPUT << std::endl;
            throw badInputException();
        }
        map.insert(badPhrase, rank); // load line by line
    }
}

/**
 * Loads the mail to a string.
 * @param mp
 * @return
 */
std::string readMail(std::string& mp)
{
    std::ifstream inFile(mp);
    std::string email;
    std::string line;
    while (std::getline(inFile , line))
    {
        email += line;
    }
    return email;
}

/**
 * This method counts the score of the email by the rating of each phrase in the map.
 * @param map Map of forbidden strings, and their rating.
 * @param email The email.
 * @return
 */
double scoreCounter(HashMap<std::string , double>& map, std::string &email)
{
    std::replace (email.begin(), email.end(), NEXT_LINE , SPACE); // replace new line with space
    double score = 0;
    size_t pos = 0;
    for (auto const &pair : map)
    {
        pos = 0;
        pos = email.find(pair.first, pos);
        while (pos != std::string::npos)
        {
            pos += pair.first.length(); // add the length of the key to the position
            score += pair.second;
            pos = email.find(pair.first, pos);
        }
    }
    return score;
}

/**
 * This method returns true if the data is actually spam, false otherwise.
 * @param dataPath The path to the data.
 * @param messagePath The path to the message.
 * @param thresholdStr threshold in string form.
 * @return true if the message is a spam, false otherwise.
 */
bool isSpam(std::string &dataPath , std::string &messagePath , int threshold)
{
    HashMap<std::string , double> map;
    loadData(dataPath , map);                   // Load the database to the hash table.
    std::string email = readMail(messagePath); // Read the mail, and generate a string.
    double totalScore = scoreCounter(map , email); // Rates the emails score.
    return totalScore >= threshold;           // If the score is g.e. the threshold => spam
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
    try
    {   // run the spam test
        std::string dataPath = argv[DATA_ARG];
        std::string messagePath = argv[MESSAGE_ARG];
        std::string thresholdStr = argv[THRESHOLD_ARG];
        int threshold = convertToDigit(thresholdStr);
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