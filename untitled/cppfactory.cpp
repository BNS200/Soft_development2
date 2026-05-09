#include "cppfactory.h"

// CppFactory::CppFactory() {}

std::shared_ptr<ClassUnit> CppFactory::createClassUnit(const std::string& name, size_t fieldsSize){
    return std::shared_ptr<CppClassUnit>(new CppClassUnit(name, fieldsSize));
}

std::shared_ptr<MethodUnit> CppFactory::createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags){
    return std::make_shared<CppMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CppFactory::createPrintOperatorUnit(const std::string& text){
    return std::make_shared<CppPrintOperatorUnit>(text);
}
