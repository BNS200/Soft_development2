#ifndef JAVAFACTORY_H
#define JAVAFACTORY_H
#include "abstractfactory.h"
#include "java_classunit.h"
#include "java_methodunit.h"
#include "java_printoperatorunit.h"



class JavaFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, size_t fieldsSize) override;
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override;
};

#endif // JAVAFACTORY_H
