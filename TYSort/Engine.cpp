#include "Engine.h"
#include "Util.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>

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
    
    //this->fileHandler->readUntilCharFound(0, '\n');
}
