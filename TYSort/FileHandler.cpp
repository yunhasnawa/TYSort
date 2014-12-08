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

char* tysort::FileHandler::readChunk(size_t start, size_t size)
{
    size_t fileSize = this->fileSize();
    
    if((start + size) > fileSize)
        size = (fileSize - start);
    
    char* text = new char[size];
    
    if(this->inputFileStream != nullptr)
    {
        printf("Reading file from offset %ld, with size %ld\n", start, size);
        
        this->inputFileStream->seekg(start);
        
        this->inputFileStream->read(text, size);
        
        // Jangan ditutup kalo masi dipake
        //this->inputFileStream->close();
    }
    
    printf("The obtained content: \n>>%s<<\n", text);
    
    return text;
}

size_t tysort::FileHandler::fileSize()
{
    this->inputFileStream->seekg(0, this->inputFileStream->end);

    size_t size = this->inputFileStream->tellg();
    
    return size;
}

tysort::FileHandler::~FileHandler()
{
    //dtor
    this->inputFileStream->close();
    
    delete this->inputFileStream;
}
