//
//  PointerStorage.h
//  TYSort
//
//  Created by Yoppy Yunhasnawa on 12/25/14.
//  Copyright (c) 2014 Yoppy Yunhasnawa. All rights reserved.
//

#ifndef __TYSort__PointerStorage__
#define __TYSort__PointerStorage__

#include <stdio.h>

namespace tysort
{
    struct LinePointerList
    {
    public:
        char** firstLinePointer;
        size_t lineCount;
        LinePointerList(char** firstLinePointer, size_t lineCount);
        virtual ~LinePointerList();
    };
}

#endif /* defined(__TYSort__PointerStorage__) */
