#ifndef ENGINE_H
#define ENGINE_H

#include "Param.h"
#include "FileHandler.h"
#include "LinePointerList.h"

namespace tysort
{
    class Engine
    {
    public:
        Engine(Param* param);
        virtual ~Engine();
        void process();
        void playground();
        
    protected:
    private:
        Param* param;
        FileHandler* fileHandler;
        char* pool;
        size_t totalReadCharacters;
        void initFileHandler();
        void checkFile();
        void createPool();
        LinePointerList* fillPool();
        void clearPool();
        void sort(LinePointerList* lpl);
        static void quickSort(int* a, size_t n);
        static void quickSort(char** lines, size_t lineCount);
    };
}

#endif // ENGINE_H
