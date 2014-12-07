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
        char* readChunk(int32_t from, int32_t to);
        
    protected:
        
    private:
        std::string fileName;
        std::ifstream* inputFileStream;
        void initInputFileStream();
    };
}

#endif // FILEHANDLER_H
