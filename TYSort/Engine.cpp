#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Engine.h"
#include "Util.h"
#include "LinePointerList.h"

tysort::Engine::Engine(Param* param)
{
    this->param = param;
    
    this->initFileHandler();
}

tysort::Engine::~Engine()
{
    //dtor
    
    free(this->pool);
}

void tysort::Engine::process()
{
    this->checkFile();
    this->createPool();
    this->fillPool();
    
    this->playground();
}

void tysort::Engine::initFileHandler()
{
    this->fileHandler = new FileHandler(this->param->fileName);
}

void tysort::Engine::checkFile()
{
    bool isOK = this->fileHandler->isFileOK();
    
    if(!isOK)
    {
        printf("ERROR! File canot be opened! Please check wheter the file exists.\n");
        
        exit(1);
    }
}

void tysort::Engine::createPool()
{
    size_t memorySize = this->param->memorySize;
    
    this->pool = (char*) malloc(memorySize);
}

void tysort::Engine::fillPool()
{
    //size_t startPos = 0;
    
    //while (strlen(this->pool) < this->param->memorySize)
    //{
        //char* text = this->fileHandler->readUntilCharFound(startPos, '\n');
        
        //strcat(this->pool, text);
        
        //startPos = strlen(this->pool);
        
        //printf("%s\n%zd\n--\n", this->pool, strlen(this->pool));
    //}
}

// TEST FIELD //

void tysort::Engine::playground()
{
    //const char* testString = "Halo, saya Yoppy Yunhasnawa. Saya suaminya Rina Dewi Astuti. Saya mahasiswa di Chang Gung University. Saya sangat menyayangi orang tua dan adik-adik saya. Saya bersyukur kepada Allah SWT atas karunia-Nya kepada saya selama ini dan hingga nanti.";
    
    /*
    char* chunk = Util::charArrayChunk(3, 4, testString);
    
    puts(chunk);
    */
    
    //Util::charArraySplit('.', testString);
    
    //size_t fileSize = this->fileHandler->fileSize();
    
    //printf("File size: %zu\n", fileSize);
    /*
    size_t read = 0;
    
    int readCount = 0;
    
    while (readCount < 2)
    {
        printf("Read: %zu\n", read);
        
        char* text = this->fileHandler->readUntilCharFound(read, '\n');
        
        size_t textSize = strlen(text);
        
        printf("Text Size: %zu\n", textSize);
        
        read += textSize;
        
        printf("Text: %s\n", text);
        
        readCount++;
    }
     */
    
    printf("===============");
    
    LinePointerList* lpl = this->fileHandler->appendCharToMemoryBlock(this->pool, 0, '\n', this->param->memorySize);
    
    char** ptr = lpl->firstLinePointer;
    
    char* line = *ptr;
    
    size_t lineCount = 0;
    
    while(lineCount < lpl->lineCount)
    {
        printf("TES: %s\n", line);
        
        lineCount++;
        
        ptr += sizeof(char**);
        
        line = *ptr;
    }
}
