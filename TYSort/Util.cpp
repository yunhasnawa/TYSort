//
//  Util.cpp
//  TYSort
//
//  Created by Yoppy Yunhasnawa on 12/10/14.
//  Copyright (c) 2014 Yoppy Yunhasnawa. All rights reserved.
//

#include <iostream>
#include "Util.h"

char* tysort::Util::charArrayReplace(char search, char replace, const char *subject)
{
    size_t length = strlen(subject);
    
    char* copy = new char[length];
    
    for(size_t i = 0; i < length; i++)
    {
        char c = subject[i];
        
        if(c == search)
        {
            c = replace;
        }
        
        copy[i] = c;
    }
    
    return copy;
}

size_t tysort::Util::charArrayElementCount(char search, const char *subject)
{
    size_t length = strlen(subject);
    
    size_t count = 0;
    
    for(size_t i = 0; i < length; i++)
    {
        char c = subject[i];
        
        if(c == search)
        {
            count++;
        }
    }
    
    return count;
}

char** tysort::Util::charArraySplit(char delimiter, const char* subject)
{
    size_t count = Util::charArrayElementCount(delimiter, subject);
    
    size_t splitsLength = count + 1;
    
    size_t subjectLength = strlen(subject);
    
    char** splits = new char*[splitsLength];
    
    size_t index = 0; // index of splits
    
    size_t startingPoint = 0; // Index of last found same char
    
    for(size_t i = 0; i < subjectLength; i++)
    {
        char c = subject[i];
        
        if(c == delimiter)
        {
            size_t newLength = (i + 1) - startingPoint; // lenght of newly formed split element
            
            char* element = Util::charArrayChunk(startingPoint, newLength, subject);
            
            puts(element);
            
            splits[index] = element;
            
            index++;
            
            startingPoint = (i + 1);
        }
    }
    
    return splits;
}

char* tysort::Util::charArrayChunk(size_t start, size_t length, const char* subject)
{
    size_t count = 0;
    
    char* chunk = new char[length];
    
    size_t pos = start;
    
    while (count < length)
    {
        chunk[count] = subject[pos];
        
        count++;
        pos++;
    }
    
    return chunk;
}