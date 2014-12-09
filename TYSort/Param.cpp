#include <stdlib.h>
#include <stdio.h>
#include "Param.h"
#include "Constants.h"

tysort::Param::Param()
{
    this->isCaseInsensitive = false;
    this->isReverse = false;
    this->isSortedAsInteger = false;
    this->memorySize = 100;
    this->fileName = Constant::kDefaultInputFileName;
}

tysort::Param::~Param()
{
    //dtor
}

void tysort::Param::setMemorySize(char* argSize)
{
    int sizeInt = atoi(argSize);

    this->memorySize = sizeInt;
}

void tysort::Param::setFileName(char* argName)
{
    std::string nameString(argName);

    this->fileName = nameString;
}

void tysort::Param::showOnScreen()
{
    printf("\n============================\n");
    printf("Reverse Result   : %d\n", this->isReverse);
    printf("Sort as Integer  : %d\n", this->isSortedAsInteger);
    printf("Case Insensitive : %d\n", this->isCaseInsensitive);
    printf("Memory size      : %d\n", this->memorySize);
    printf("File Name        : %s\n", this->fileName.c_str());
}
