#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdlib.h>
#include <string>
#include <fstream>
#include "LinePointerList.h"

namespace tysort
{
    class FileHandler
    {
    public:
        FileHandler(std::string fileName);
        virtual ~FileHandler();
        char* readChunk(size_t start, size_t size);
        char* readUntilCharFound(size_t start, char seek);
        LinePointerList* appendCharToMemoryBlock(char* block, size_t start, char delimiter, size_t blockSize);
        size_t fileSize();
        bool isFileOK();
        long getLastSeekPos();
        long getMaxSeekPos();
        
    protected:
        
    private:
        std::string fileName;
        std::ifstream* inputFileStream;
        long lastSeekPos;
        long maxSeekPos;
        void initInputFileStream();
    };
}

#endif // FILEHANDLER_H
