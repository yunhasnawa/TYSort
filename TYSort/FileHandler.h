#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdlib.h>
#include <string>
#include <fstream>

namespace tysort
{
    class FileHandler
    {
    public:
        FileHandler(std::string fileName);
        virtual ~FileHandler();
        char* readChunk(size_t start, size_t size);
        char* readUntilCharFound(size_t start, char seek);
        size_t fileSize();
        bool isFileOK();
        
    protected:
        
    private:
        std::string fileName;
        std::ifstream* inputFileStream;
        void initInputFileStream();
    };
}

#endif // FILEHANDLER_H
