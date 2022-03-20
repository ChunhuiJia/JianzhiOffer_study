#ifndef PROJECT_TEMPLATEFACTORY_H
#define PROJECT_TEMPLATEFACTORY_H

#include "boost/function.hpp"
template <class Base, class Id>
struct TemplateFactory
{
    TemplateFactory(){};
    shared_ptr<Base> create(Id id)
    {
        return _creatorMap[id]();
    }

    void addCreator(Id id, boost::function<shared_ptr<Base>()> function)
    {
        _creatorMap.insert({id, function});
    }

private:
    std::map<Id, boost::function<shared_ptr<Base>()>> _creatorMap;
};

#endif