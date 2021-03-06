#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include "Engine.h"
#include "Util.h"
#include "LinePointerList.h"

tysort::Engine::Engine(Param* param)
{
    this->param = param;
    
    this->totalReadCharacters = 0;
    
    this->savedPoolCount = 0;
    
    this->initFileHandler();
    
    this->initFileWriter();
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
    
    long maxSeekPos = this->fileHandler->getMaxSeekPos();
    
    while (this->totalReadCharacters <= maxSeekPos)
    {
        LinePointerList* lpl = this->fillPool();
        
        this->sortPool(lpl);
        
        this->savePool(lpl);
        
        this->clearPool();
    }
    
    this->playground();
}

void tysort::Engine::initFileHandler()
{
    this->fileHandler = new FileHandler(this->param->inputFileName);
}

void tysort::Engine::initFileWriter()
{
    this->fileWriter = new FileWriter(this->param->fileName);
}

void tysort::Engine::checkFile()
{
    bool isOK = this->fileHandler->isFileOK();
    
    if(!isOK)
    {
        printf("ERROR! File canot be opened! Please check whether the file exists or not.\n");
        
        exit(1);
    }
}

void tysort::Engine::createPool()
{
    size_t memorySize = this->param->memorySize;
    
    this->pool = (char*) malloc(memorySize);
}

tysort::LinePointerList* tysort::Engine::fillPool()
{
    size_t start = this->totalReadCharacters;
    
    printf("----------------%zu--of--%zu--------------\n", start, this->fileHandler->getMaxSeekPos());
    
    LinePointerList* lpl = this->fileHandler->appendCharToMemoryBlock(this->pool, start, '\n', this->param->memorySize);
    
    this->totalReadCharacters += lpl->totalCharacterCount();
    
    return lpl;
}

void tysort::Engine::clearPool()
{
    delete this->pool;
    
    this->createPool();
}

void tysort::Engine::sortPool(tysort::LinePointerList *lpl)
{
    char** lines = lpl->firstLinePointer;
    size_t lineCount = lpl->lineCount;
    
    Engine::quickSort(lines, lineCount);
    
    //lpl->print();
}

void tysort::Engine::savePool(tysort::LinePointerList *lpl)
{
    std::string fileName = std::to_string((long) this->savedPoolCount);
    
    fileName = "pool_" + fileName + ".tyspart";
    
    this->fileWriter->writeToFile(fileName, lpl);
    
    this->savedPoolCount++;
}

void tysort::Engine::quickSort(char** lines, size_t lineCount)
{
    if(lineCount < 2)
        return;
    
    char* pivot = lines[(lineCount/2)];
    
    char** left = lines;
    char** right = lines + (lineCount - 1);
    
    while (left <= right)
    {
        if(strcmp(*left, pivot) < 0)
        {
            left++;
        }
        else if(strcmp(*right, pivot) > 0)
        {
            right--;
        }
        else
        {
            // Swap
            char* temp = *left;
            *left = *right;
            *right = temp;
            
            left++;
            right--;
        }
    }
    Engine::quickSort(lines, (right - lines + 1));
    Engine::quickSort(left, (lines + lineCount - left));
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
    
    //printf("\n===============\n");
    
    //LinePointerList* lpl = this->fileHandler->appendCharToMemoryBlock(this->pool, 0, '\n', this->param->memorySize);
    
    //char** ptr = lpl->firstLinePointer;
    
    /*
    char* line = *ptr;
    
    size_t lineCount = 0;
    
    while(lineCount < lpl->lineCount)
    {
        printf("%zu) %s\n",lineCount, line);
        
        lineCount++;
        
        ptr += sizeof(char**);
        
        line = *ptr;
    }
    */
    /*
    for(size_t i = 0; i < lpl->lineCount; i++)
    {
        char* line = ptr[i];

        printf("%zu) %s\n",i, line);
    }*/
    
    /*
    this->sort(lpl);
    
    int tesInts[10] = {1, 4, 5, 2, 3, 6, 9, 8, 7, 0};
    
    Engine::quickSort(tesInts, 10);
    
    for(int i = 0; i < 10; i++)
    {
        std::cout << tesInts[i];
    }
    */
    
    /*
    char** lines = lpl->firstLinePointer;
    size_t lineCount = lpl->lineCount;
    
    Engine::quickSort(lines, lineCount);
    
    for(size_t i = 0; i < lineCount; i++)
    {
        char* line = lines[i];
        
        printf("%zu) %s\n", i + 1, line);
    }
    */
}

void tysort::Engine::quickSort(int *a, size_t n)
{
    if(n < 2)
        return;
    int p = a[n / 2];
    int *l = a;
    int *r = a + n - 1;
    while (l <= r)
    {
        if (*l < p)
        {
            l++;
        }
        else if (*r > p)
        {
            r--;
        }
        else
        {
            int t = *l;
            *l = *r;
            *r = t;
            l++;
            r--;
        }
    }
    Engine::quickSort(a, r - a + 1);
    Engine::quickSort(l, a + n - l);
}