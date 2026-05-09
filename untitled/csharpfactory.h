#ifndef CSHARPFACTORY_H
#define CSHARPFACTORY_H
#include "abstractfactory.h"
#include "csharp_classunit.h"
#include "csharp_methodunit.h"
#include "csharp_printoperatorunit.h"



class CSharpFactory : public AbstractFactory
{
public:
    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name, size_t fieldsSize) override;
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override;
};

#endif // CSHARPFACTORY_H
