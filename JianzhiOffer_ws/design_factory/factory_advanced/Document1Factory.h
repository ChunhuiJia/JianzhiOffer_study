#ifndef PROJECT_DOCUMENT1FACTORY_H
#define PROJECT_DOCUMENT1FACTORY_H

#include "Document.h"
#include "boost/function.hpp"
#include <cstring>

class Document1Factory
{
public:
    shared_ptr<Document> create(std::string name);
    void addCreator(std::string name, boost::function<shared_ptr<Document>()> function);
private:
    std::map<std::string, boost::function<shared_ptr<Document>()>> _creatorMap;
};

#endif