#ifndef TXTWRITER_H
#define TXTWRITER_H


#include <iostream>
#include "WriteManager.h"


class TxtWriter : public WriteManager{
    private:
        string txtData;
    public:
        TxtWriter();
        void newFile(const string&) override;
        bool loadFromFile(const string&) override;
        bool saveToFile(const string&) override;
        string getTxtData() const;
        void setTxtData(const string& txtData); 
};


#endif