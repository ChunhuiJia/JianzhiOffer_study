#include "DocumentFactory.h"
#include "Document1Factory.h"
#include "TxtDocument.h"
#include "PDFDocument.h"
#include "HtmlDocument.h"
#include "TemplateFactory.h"

int main(){
    DocumentFactory factory;
    auto doc = factory.createDocument("txt");
    doc->print();
    factory.createDocument("pdf")->print();
    factory.createDocument("html")->print();

    Document1Factory document1Factory;
    document1Factory.addCreator("txt",[](){return shared_ptr<Document>(new TxtDocument);});
    document1Factory.addCreator("pdf",[](){return shared_ptr<Document>(new PDFDocument);});
    document1Factory.addCreator("html",[](){return shared_ptr<Document>(new HtmlDocument);});
    document1Factory.create("txt")->print();
    document1Factory.create("pdf")->print();
    document1Factory.create("html")->print();

    typedef TemplateFactory<Document, std::string> Document2Factory;
    Document2Factory document2Factory;
    document2Factory.addCreator("txt",[](){return shared_ptr<Document>(new TxtDocument);});
    document2Factory.addCreator("pdf",[](){return shared_ptr<Document>(new PDFDocument);});
    document2Factory.addCreator("html",[](){return shared_ptr<Document>(new HtmlDocument);});
    document2Factory.create("txt")->print();
    document2Factory.create("pdf")->print();
    document2Factory.create("html")->print();
}