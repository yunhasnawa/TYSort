//
//  FileWriter.cpp
//  TYSort
//
//  Created by Yoppy Yunhasnawa on 12/26/14.
//  Copyright (c) 2014 Yoppy Yunhasnawa. All rights reserved.
//

#include "FileWriter.h"

tysort::FileWriter::FileWriter(std::string outputFileName)
{
    this->initOutputFileStream();
    
    this->outputFileName = outputFileName;
    
    this->checkOutputFolder();
}

tysort::FileWriter::~FileWriter()
{
    delete this->outputFileStream;
}

void tysort::FileWriter::initOutputFileStream()
{
    this->outputFileStream = new std::ofstream;
}

void tysort::FileWriter::checkOutputFolder()
{
    size_t found = this->outputFileName.find_last_of("/\\");
    
    this->outputFolder = this->outputFileName.substr(0, found);
    
    this->outputFileStream->open(this->outputFileName);
    
    this->outputFileStream->close();
}

void tysort::FileWriter::writeToFile(std::string fileName, tysort::LinePointerList *lpl)
{
    std::string filePath = this->outputFolder + "/" + fileName;
    
    printf("%s\n", filePath.c_str());
}
