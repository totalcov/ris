#include <iostream>

#include "MObject.h"

MObject* MObject::pFirst = nullptr;
MObject* MObject::pLast = nullptr;


MObject::MObject(): pNext(nullptr), pPrev(nullptr)
{
    if (pLast)
    {
        pLast->pNext = this;
    }

    pPrev = pLast;
    pLast = this;
    pNext = nullptr;

    if (pFirst == nullptr)
    {
        pFirst = this;
    }
}

MObject::~MObject()
{
    if (pPrev)
    {
        pPrev->pNext = pNext;
    }
    else
    {
        pFirst = pNext;
    }

    if (pNext)
    {
        pNext->pPrev = pPrev;
    }
    else
    {
        pLast = pPrev;
    }
}

std::string MObject::oprint() const{
    return "I am object";
}

void MObject::printAll()
{
    MObject* now = pFirst;

    while (now != nullptr)
    {
        std::cout << now->oprint() << std::endl;
        now = now->pNext;
    }
}