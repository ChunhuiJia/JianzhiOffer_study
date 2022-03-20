#ifndef PROJECT_TXTDOCUMENT_H
#define PROJECT_TXTDOCUMENT_H
#include "Document.h"
#include <iostream>

class TxtDocument : public Document
{
public:
    void print() override;
};

#endif