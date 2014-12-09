//
//  Util.h
//  TYSort
//
//  Created by Yoppy Yunhasnawa on 12/10/14.
//  Copyright (c) 2014 Yoppy Yunhasnawa. All rights reserved.
//

#ifndef __TYSort__Util__
#define __TYSort__Util__

#include <stdio.h>

namespace tysort
{
    class Util
    {
    public:
        static char* charArrayReplace(char search, char replace, const char* subject);
        static size_t charArrayElementCount(char search, const char* subject);
        static char** charArraySplit(char delimiter, const char* subject);
        static char* charArrayChunk(size_t start, size_t length, const char* subject);
    };
}

#endif /* defined(__TYSort__Util__) */
