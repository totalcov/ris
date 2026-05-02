#pragma once
#include <string>

class MObject{
  private:
    MObject *pNext;
    MObject *pPrev; 

    static MObject *pFirst;
    static MObject *pLast;

    public:
    MObject();

    virtual ~MObject(); 

    virtual std::string oprint() const;

    static void printAll();
};