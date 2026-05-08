#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"





class AbstractFactory
{
public:
    virtual ~AbstractFactory() = default;

    virtual std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, size_t fieldsSize) = 0;
    virtual std::shared_ptr<MethodUnit> createMethodUnit(const std::string& returnType, const std::string& name, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text);
};

#endif // ABSTRACTFACTORY_H
