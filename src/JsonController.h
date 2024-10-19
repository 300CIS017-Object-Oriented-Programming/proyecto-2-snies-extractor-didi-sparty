#ifndef JSONCONTROLLER_H
#define JSONCONTROLLER_H

#include <iostream>
#include "json.hpp"
#include <string>

using json = nlohmann::json;
using namespace std;

class JsonController {
    private:
        json jsonData;
    public:
        JsonController();
        void newJson(const string&);
        bool loadFromFile(const string&);
        bool saveToFile(const string&);
        json getJson() const;
        void setJson(const json&);


};




#endif JSONCONTROLLER_H
