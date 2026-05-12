#include "javafactory.h"

std::shared_ptr<ClassUnit> JavaFactory::createClassUnit(const std::string& name){
    return std::make_shared<JavaClassUnit>(name);
}

std::shared_ptr<MethodUnit> JavaFactory::createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags){
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> JavaFactory::createPrintOperatorUnit(const std::string& text){
    return std::make_shared<JavaPrintOperatorUnit>(text);
}
