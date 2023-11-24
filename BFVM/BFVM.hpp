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
#include <functional>
using namespace std;
namespace fs = std::filesystem;

namespace BF
{

class BFVM
{
private:
    string codeline;
    vector<char> varline;
    size_t codepointer = 0;
    size_t varpointer = 0;
    stack<size_t> cyclestack;

    void archasm(char input)
    {
        switch (input)
        {
        case '>':
            varpointer++;
            break;
        case '<':
            varpointer--;
            break;
        case '+':
            varline[varpointer]++;
            break;
        case '-':
            varline[varpointer]--;
            break;
        case '.':
            cout.put(varline[varpointer]);
            break;
        case ',':
            cin.get(varline[varpointer]);
            break;
        case '[':
            if(varline[varpointer] != 0)
            {
                cyclestack.push(codepointer);
            }
            else
            {
                codepointer++;
                for(size_t inner = 0;inner != 0 || codeline[codepointer] != ']';codepointer++)
                {
                    if(codeline[codepointer] == '[')
                    inner++;
                    else if(codeline[codepointer] == ']')
                    inner--;
                }
            }
            break;
        case ']':
            codepointer = cyclestack.top() - 1;
            cyclestack.pop();
            break;
        default:
            break;
        }
    }

    void runtimecoder()
    {
        switch (runtimecode)
        {
        case 0:
            break;
        case 1:
            return runtimecoder();
        case 2:
            runtimecode++;
            return runtimecoder();
        default:
            return runtimecoder();
        }
    }

public:
    int runtimecode = 0;

    BFVM(string code, size_t varsize = 1024)
    {
        codeline = code;
        varline.resize(varsize);
    }
    
    int runner()
    {
        for(;codepointer < codeline.size();codepointer++)
        {
            runtimecoder();
            archasm(codeline[codepointer]);
        }
        return 0;
    }

};                    

class BFPPVM
{
private:
    string codeline;
    vector<char> varline;
    size_t codepointer = 0;
    size_t varpointer = 0;
    stack<size_t> cyclestack;
    size_t arch = 1;
    void (BF::BFPPVM::*archasm)(char);

    void archasm00(char input)
    {
        switch (input)
        {
        case '>':
            varpointer++;
            break;
        case '<':
            varpointer--;
            break;
        case '+':
            varline[varpointer]++;
            break;
        case '-':
            varline[varpointer]--;
            break;
        case '.':
            cout.put(varline[varpointer]);
            break;
        case ',':
            cin.get(varline[varpointer]);
            break;
        case '[':
            if(varline[varpointer] != 0)
            {
                cyclestack.push(codepointer);
            }
            else
            {
                codepointer++;
                for(size_t inner = 0;inner != 0 || codeline[codepointer] != ']';codepointer++)
                {
                    if(codeline[codepointer] == '[')
                    inner++;
                    else if(codeline[codepointer] == ']')
                    inner--;
                }
            }
            break;
        case ']':
            codepointer = cyclestack.top() - 1;
            cyclestack.pop();
            break;
        default:
            break;
        }
    }
    
    void archasm01(char input)
    {
        switch (input)
        {
        case '>':
            varpointer++;
            break;
        case '<':
            varpointer--;
            break;
        case '+':
            varline[varpointer]++;
            break;
        case '-':
            varline[varpointer]--;
            break;
        case '.':
            cout.put(varline[varpointer]);
            break;
        case ',':
            cin.get(varline[varpointer]);
            break;
        case '{':
            codepointer -= varline[varpointer];
            break;
        case '}':
            codepointer += varline[varpointer];
        case '[':
            if(varline[varpointer] != 0)
            {
                cyclestack.push(codepointer);
            }
            else
            {
                codepointer++;
                for(size_t inner = 0;inner != 0 || codeline[codepointer] != ']';codepointer++)
                {
                    if(codeline[codepointer] == '[')
                    inner++;
                    else if(codeline[codepointer] == ']')
                    inner--;
                }
            }
            break;
        case ']':
            codepointer = cyclestack.top() - 1;
            cyclestack.pop();
            break;
        default:
            break;
        }
    }

    void runtimecoder()
    {
        switch (runtimecode)
        {
        case 0:
            break;
        case 1:
            return runtimecoder();
        case 2:
            runtimecode++;
            return runtimecoder();
        default:
            return runtimecoder();
        }
    }

public:
    int runtimecode = 0;

    BFPPVM(string code, size_t varsize = 1024,size_t archno = 1)
    {
        codeline = code;
        varline.resize(varsize);
        arch = archno;
    }

    void stopvm()
    {
        
    }

    int runner()
    {
        archasm = &BF::BFPPVM::archasm01;
        switch (arch)
        {
        case 0:
            archasm = &BF::BFPPVM::archasm00;
            break;
        case 1:
            archasm = &BF::BFPPVM::archasm01;
            break;
        default:
            break;
        }
        for(;codepointer < codeline.size();codepointer++)
        {
            runtimecoder();
            (this->*archasm)(codeline[codepointer]);
        }
        return 0;
    }

};

}