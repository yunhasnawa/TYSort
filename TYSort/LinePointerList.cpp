//
//  PointerStorage.cpp
//  TYSort
//
//  Created by Yoppy Yunhasnawa on 12/25/14.
//  Copyright (c) 2014 Yoppy Yunhasnawa. All rights reserved.
//

#include "LinePointerList.h"

tysort::LinePointerList::LinePointerList(char **firstLinePointer, size_t lineCount)
{
    this->firstLinePointer = firstLinePointer;
    this->lineCount = lineCount;
}

tysort::LinePointerList::~LinePointerList()
{
    delete this->firstLinePointer;
}