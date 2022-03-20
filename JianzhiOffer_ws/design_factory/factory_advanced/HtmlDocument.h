#ifndef PROJECT_HTMLDOCUMENT_H
#define PROJECT_HTMLDOCUMENT_H
#include "Document.h"
#include <iostream>


class HtmlDocument : public Document
{
public:
    void print() override;
};

#endif