#ifndef ENGINE_H
#define ENGINE_H

#include "Param.h"

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
    };
}

#endif // ENGINE_H
