#include <iostream>
#include <getopt.h>
#include "Param.h"
#include "Engine.h"

using namespace std;
using namespace tysort;

int main(int argc, char* argv[])
{
    Param* param = new Param();

    char c;

    while((c = getopt(argc, argv, "rncm:o:")) != -1)
    {
        cout << "OPT -> " << c << endl;

        switch (c)
        {
        case 'r' :
            param->isReverse = true;
            break;
        case 'n' :
            param->isSortedAsInteger = true;
            break;
        case 'c' :
            param->isCaseInsensitive = true;
            break;
        case 'm' :
            param->setMemorySize(optarg);
            break;
        case 'o' :
            param->setFileName(optarg);
            break;
        default:
            break;
        }
    }

    param->showOnScreen();

    Engine* engine = new Engine(param);

    engine->process();

    delete engine;
    delete param;

    return 0;
}
