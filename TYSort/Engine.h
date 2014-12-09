#ifndef ENGINE_H
#define ENGINE_H

#include "Param.h"
#include "FileHandler.h"

namespace tysort
{
    class Engine
    {
        public:
            Engine(Param* param);
            virtual ~Engine();
            void process();
        protected:
        private:
            Param* param;
            FileHandler* fileHandler;
            void initFileHandler();
            char** grabFileContent(size_t offset, size_t length);
            void playground();
    };
}

#endif // ENGINE_H
