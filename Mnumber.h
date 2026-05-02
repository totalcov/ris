#pragma once
#include "MObject.h"

class Mnumber: public MObject {
    public:
    std::string oprint() const;
    ~Mnumber();
};

