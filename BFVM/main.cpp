#include "BFVM.hpp"

void runbf(string path,size_t varsize=1024)
{
    if (fs::exists(path))
    {
        ifstream bfin(path);
        stringstream codein;
        codein<<bfin.rdbuf();
        BF::BFVM vm(codein.str(),varsize);
        vm.runner();
    }
    else
    {
        cout<<"BF file "<<path<<" not found"<<endl;
    }
}

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout<<"Error command. Please use 'help' to get help"<<endl;
        return 1;
    }

    string argv1 = argv[1];

    if (argv1 == "bf")
    {
        
        if(argc >= 4)
        {
            runbf(argv[2],stoull(argv[3]));
        }
        else
        {
            runbf(argv[2]);
        }
    }
    return 0;
}