#ifndef CPPFACTORY_H
#define CPPFACTORY_H
#include "abstractfactory.h"
#include "cpp_classunit.h"
#include "cpp_methodunit.h"
#include "cpp_printoperatorunit.h"


class CppFactory : public AbstractFactory
{
public:
    virtual ~CppFactory() = default;

    std::shared_ptr<ClassUnit> createClassUnit(const std::string& name) override;
    std::shared_ptr<MethodUnit> createMethodUnit(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> createPrintOperatorUnit(const std::string& text) override;


};

#endif // CPPFACTORY_H
