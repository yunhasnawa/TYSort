#ifndef PARAM_H
#define PARAM_H

#include <string>

namespace tysort
{
    class Param
    {
        public:
            Param();
            virtual ~Param();
            bool isReverse;
            bool isSortedAsInteger;
            bool isCaseInsensitive;
            size_t memorySize;
            std::string fileName;
            std::string inputFileName;
            void setFileName(char* argName);
            void setMemorySize(char* argSize);
            void showOnScreen();
        protected:
        private:
    };
}

#endif // PARAM_H
