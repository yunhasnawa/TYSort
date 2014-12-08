#include "Engine.h"

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

}

void tysort::Engine::initFileHandler()
{
    this->fileHandler = new FileHandler(this->param->fileName);
    
    size_t fileSize = this->fileHandler->fileSize();
    
    printf("File Size: %ld\n", fileSize);
    
    char* text = this->fileHandler->readChunk(5, 15);
    
    printf("Read Size: %ld\n", strlen(text));
}
