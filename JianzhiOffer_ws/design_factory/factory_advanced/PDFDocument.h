#ifndef PROJECT_PDFDOCUMENT_H
#define PROJECT_PDFDOCUMENT_H
#include "Document.h"
#include <iostream>

class PDFDocument : public Document
{
public:
    void print() override;
};

#endif