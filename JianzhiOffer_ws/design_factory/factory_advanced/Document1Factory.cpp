#include "Document1Factory.h"

shared_ptr<Document> Document1Factory::create(std::string name)
{
    return _creatorMap[name]();
}
void Document1Factory::addCreator(std::string name, boost::function<shared_ptr<Document>()> function)
{
    _creatorMap.insert({name, function});
}