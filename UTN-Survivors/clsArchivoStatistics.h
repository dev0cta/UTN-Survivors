#pragma once
#include "clsStatistics.h"
#include <string>
#include <iostream>

class ArchivoStatistics
{

public:
    ArchivoStatistics(std::string filePath);
    bool Save(Statistics statistics);
    Statistics Read();

    void addAndSaveRecentMatch(Statistics statistics);



private:
    std::string _filePath;
};

