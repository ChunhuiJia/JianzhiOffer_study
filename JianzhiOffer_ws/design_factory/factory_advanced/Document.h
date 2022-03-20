#ifndef PROJECT_DOCUMENT_H
#define PROJECT_DOCUMENT_H

#include <memory>
#include "boost/make_shared.hpp"
#include "map"

using namespace std;

class Document
{
public:
    virtual ~Document(){};
    virtual void print() = 0;
};

#endif