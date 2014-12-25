//
//  PointerStorage.cpp
//  TYSort
//
//  Created by Yoppy Yunhasnawa on 12/25/14.
//  Copyright (c) 2014 Yoppy Yunhasnawa. All rights reserved.
//

#include "LinePointerList.h"
#include <iostream>

tysort::LinePointerList::LinePointerList(char **firstLinePointer, size_t lineCount)
{
    this->firstLinePointer = firstLinePointer;
    this->lineCount = lineCount;
}

tysort::LinePointerList::~LinePointerList()
{
    delete this->firstLinePointer;
}

size_t tysort::LinePointerList::totalCharacterCount()
{
    char** lines = this->firstLinePointer;
    size_t numberOfLines = this->lineCount;
    
    size_t totalCharacterCount = 0;
    
    for(size_t i = 0; i < numberOfLines; i++)
    {
        char* line = lines[i];
        
        size_t lineLength = strlen(line) + 1;
        
        totalCharacterCount += lineLength;
    }
    
    return totalCharacterCount;
}

void tysort::LinePointerList::print(bool fixOrder)
{
    char** lines = this->firstLinePointer;
    size_t numberOfLines = this->lineCount;
    
    if(!fixOrder)
    {
        for(size_t i = 0; i < numberOfLines; i++)
        {
            char* line = lines[i];
            
            size_t lineLength = strlen(line) + 1;
            
            printf("%zu) %s (%zu)\n", i + 1, line, lineLength);
        }
    }
    else
    {
        for(long i = (numberOfLines - 1); i > -1; i--)
        {
            char* line = lines[i];
            
            size_t lineLength = strlen(line) + 1;
            
            printf("%zu) %s (%zu)\n", i + 1, line, lineLength);
        }
    }
}