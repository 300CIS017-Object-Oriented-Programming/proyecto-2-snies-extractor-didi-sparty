#ifndef FILEMANAGER_H
#define FILEMANAGER_H
#include <string>
using namespace std;

class FileManager{
    public:
        FileManager();
        virtual void newFile(const string&) = 0;
        virtual bool loadFromFile(const string&) = 0;
        virtual bool saveToFile(const string&) = 0;

};

#endif