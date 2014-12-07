#include "FileHandler.h"

tysort::FileHandler::FileHandler(std::string fileName)
{
    this->fileName = fileName;
    
    this->initInputFileStream();
}

void tysort::FileHandler::initInputFileStream()
{
    this->inputFileStream = new std::ifstream(this->fileName, std::ifstream::binary);
}

char* tysort::FileHandler::readChunk(int32_t from, int32_t to)
{
    int32_t length = (to - from) + 1;
    
    char* text = new char[length];
    
    if(this->inputFileStream != nullptr)
    {
        printf("Reading file from offset %d, to %d\n", from, to);
    }
    
    return text;
}

tysort::FileHandler::~FileHandler()
{
    //dtor
    delete this->inputFileStream;
}
