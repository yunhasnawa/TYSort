//
//  FileWriter.h
//  TYSort
//
//  Created by Yoppy Yunhasnawa on 12/26/14.
//  Copyright (c) 2014 Yoppy Yunhasnawa. All rights reserved.
//

#ifndef __TYSort__FileWriter__
#define __TYSort__FileWriter__

#include <stdio.h>
#include <fstream>
#include "LinePointerList.h"

namespace tysort
{
    class FileWriter
    {
    public:
        FileWriter(std::string outputFileName);
        virtual ~FileWriter();
        void writeToFile(std::string fileName, LinePointerList* lpl);
        
    private:
        std::ofstream* outputFileStream;
        std::string outputFileName;
        std::string outputFolder;
        void initOutputFileStream();
        void checkOutputFolder();
    };
}

#endif /* defined(__TYSort__FileWriter__) */
