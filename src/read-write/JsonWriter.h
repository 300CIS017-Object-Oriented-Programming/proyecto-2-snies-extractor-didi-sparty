#ifndef JSONWRITER_H
#define JSONWRITER_H

#include <iostream>
#include "../../include/json.hpp"
#include <string>
#include "WriteManager.h"

using json = nlohmann::json;
using namespace std;

class JsonWriter : public WriteManager{
    private:
        json jsonData;
    public:
        JsonWriter();
        void newFile(const string&) override;
        bool loadFromFile(const string&) override;
        bool saveToFile(const string&) override;
        json getJson() const;
        void setJson(const json&);


};




#endif
