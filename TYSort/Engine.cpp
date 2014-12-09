#include "Engine.h"
#include "Util.h"

tysort::Engine::Engine(Param* param)
{
    this->param = param;
    
    this->initFileHandler();
}

tysort::Engine::~Engine()
{
    //dtor
}

void tysort::Engine::process()
{
    size_t fileSize = this->fileHandler->fileSize();
    
    if(fileSize < 1)
    {
        printf("WARNING! The input file is empty!\n");
        
        return;
    }
    
    Engine::playground();
}

void tysort::Engine::initFileHandler()
{
    this->fileHandler = new FileHandler(this->param->fileName);
}

char** tysort::Engine::grabFileContent(size_t offset, size_t length)
{
    char* text = this->fileHandler->readChunk(offset, 15);
    
    printf("Read Size: %ld\n", strlen(text));
    
    char** split = new char*[1];
    
    return split;
}

void tysort::Engine::playground()
{
    const char* testString = "Halo, saya Yoppy Yunhasnawa. Saya suaminya Rina Dewi Astuti. Saya mahasiswa di Chang Gung University. Saya sangat menyayangi orang tua dan adik-adik saya. Saya bersyukur kepada Allah SWT atas karunia-Nya kepada saya selama ini dan hingga nanti.";
    
    /*
    char* chunk = Util::charArrayChunk(3, 4, testString);
    
    puts(chunk);
    */
    
    Util::charArraySplit('.', testString);
}
