#include "DocumentFactory.h"
#include "TxtDocument.h"
#include "PDFDocument.h"
#include "HtmlDocument.h"

shared_ptr<Document> DocumentFactory::createDocument(std::string name)
{
    if (name == "txt")
    {
        return std::make_shared<TxtDocument>();
    }
    if (name == "pdf")
    {
        return std::make_shared<PDFDocument>();
    }
    if (name == "html")
    {
        return std::make_shared<HtmlDocument>();
    }
}