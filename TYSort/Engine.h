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
            void playground();
        
        protected:
        private:
            Param* param;
            FileHandler* fileHandler;
            char* pool;
            void initFileHandler();
            void checkFile();
            void createPool();
            void fillPool();
    };
}

#endif // ENGINE_H
