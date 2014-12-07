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
    
    this->fileHandler->readChunk(0, 3);
}
