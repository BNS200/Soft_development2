#include "csharpfactory.h"

std::shared_ptr<ClassUnit> CSharpFactory::createClassUnit(const std::string& name, size_t fieldsSize){
    return std::make_shared<CSharpClassUnit>(name, fieldsSize);
}

std::shared_ptr<MethodUnit> CSharpFactory::createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags){
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CSharpFactory::createPrintOperatorUnit(const std::string& text){
    return std::make_shared<CSharpPrintOperatorUnit>(text);
}
