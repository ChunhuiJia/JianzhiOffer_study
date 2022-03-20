#ifndef PROJECT_DOCUMENTFACTORY_H
#define PROJECT_DOCUMENTFACTORY_H

#include "Document.h"
#include <cstring>

class DocumentFactory
{
public:
    shared_ptr<Document> createDocument(std::string name);
};

#endif
