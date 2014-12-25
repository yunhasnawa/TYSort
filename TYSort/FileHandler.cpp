#include "FileHandler.h"
#include <iostream>

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
    // If you want to return a string containing
    // one character, you have to allocate at least two characters.
    // The first one contains the character you want to return.
    // The second one contains the null character - '\0'
    char* text = new char[2];
    
    if(this->inputFileStream != nullptr)
    {
        bool goOn = true;
        
        size_t seekPos = start;
        
        while (goOn)
        {
            this->inputFileStream->seekg(seekPos);
            
            // No need to allocate memory form the heap.
            char buffer[2];
            
            this->inputFileStream->read(buffer, 1);
            
            if( buffer[0] != seek )
            {
                buffer[1] = '\0';
                strcat(text, buffer);
                
                seekPos++;
            }
            else
            {
                goOn = false;
            }
        }
    }
    
    return text;
}

tysort::LinePointerList* tysort::FileHandler::appendCharToMemoryBlock(char* block, size_t start, char delimiter, size_t blockSize)
{
    if(this->inputFileStream == nullptr)
        return nullptr;
    
    bool goOn = true;
    
    size_t seekPos = start;
    
    size_t lastBlockIndex = (blockSize - 1);
    
    size_t pointerSize = sizeof(char**);
    
    char* linePointer = block; // Pointing first memory block
    //char** linePointerStorage = (char**) ((&block) + blockSize); <-- This is not working. I don't know
    
    char** linePointerStorage = (char**) (block + (blockSize - 1));
    
    linePointerStorage += (blockSize - 1);// Pointer ke akhir blok memori
    
    size_t lineLength = 0;
    
    size_t lineCount = 0;
    
    while (goOn)
    {
        this->inputFileStream->seekg(seekPos);
        
        char buffer;
        
        this->inputFileStream->read(&buffer, 1);
        
        char append = buffer == delimiter ? '\0' : buffer;
        
        block[seekPos] = append;
        
        lineLength++;
        
        if(append == '\0')
        {
            *linePointerStorage = linePointer; // Store current line pointer
            
            printf("-> %s\n", *linePointerStorage);
            
            linePointer += lineLength; // pluss null character
            
            // Shift back because current storage already filed
            lastBlockIndex -= pointerSize;
            linePointerStorage -= pointerSize;
            
            lineLength = 0; // Reset line length for next iteration

            lineCount++; // Record total number of lines
        }
        
        if((lastBlockIndex - seekPos) <= pointerSize)
            goOn = false;
        else
            seekPos++;
    }
    
    linePointerStorage += pointerSize; // Adjust one step because last iteration shift back
    
    LinePointerList* lpl = new LinePointerList(linePointerStorage, lineCount);
    
    return lpl;
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
