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

bool tysort::FileHandler::isFileOK()
{
    return this->inputFileStream->is_open();
}

char* tysort::FileHandler::readChunk(size_t start, size_t size)
{
    size_t fileSize = this->fileSize();
    
    if((long)fileSize < 0) return nullptr;
    
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
    
    printf("The obtained content: \n------------------------\n%s\n------------------------\n", text);
    
    return text;
}

char* tysort::FileHandler::readUntilCharFound(size_t start, char seek)
{
    char* text = new char;
    
    if(this->inputFileStream != nullptr)
    {
        bool goOn = true;
        
        size_t seekPos = start;
        
        while (goOn)
        {
            this->inputFileStream->seekg(seekPos);
            
            char* buffer = new char;
            
            this->inputFileStream->read(buffer, 1);
            
            if(strcmp(buffer, &seek) != 0)
            {
                strcat(text, buffer);
                
                seekPos++;
            }
            else
            {
                goOn = false;
            }
        }
    }
    
    printf("%s\n", text);
    
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
