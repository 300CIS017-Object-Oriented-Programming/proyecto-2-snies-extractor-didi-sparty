#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <sstream>
#include <list>
#include <algorithm>
#include "../Settings.h"

using namespace std;

class WriteManager{
    public:
        WriteManager();
        ~WriteManager();
        virtual void newFile(const string&) = 0;
        virtual bool loadFromFile(const string&) = 0;
        virtual bool saveToFile(const string&) = 0;
};

#endif