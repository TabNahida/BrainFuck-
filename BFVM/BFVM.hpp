#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <stack>
#include <thread>
#include <chrono>
using namespace std;

namespace BF
{

class varblock
{
private:
    list<char[1024]> varlist;
    size_t front = 0;
    size_t end = 1023;
public:
    bool add_(size_t pos)
    {
        if (pos > front && pos < end)
        {
            auto it = varlist.begin();
            
        }
        else
        {

        }
    }

    bool sub_(size_t pos)
    {

    }
};

class BFVM
{
private:
    string codeline;
    varblock varline;
    size_t codepointer = 0;
    size_t varpointer = 0;
    stack<size_t> cyclestack;
public:
    BFVM(string code)
    {
        codeline = code;
    }
};

}