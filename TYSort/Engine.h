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
    };
}

#endif // ENGINE_H
