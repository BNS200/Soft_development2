#ifndef CPP_METHODUNIT_H
#define CPP_METHODUNIT_H
#include "methodunit.h"

class CppMethodUnit : public MethodUnit
{
public:
    explicit CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };
    std::string compileModifiers() const override;
    std::string compileSignature() const override;

    virtual ~CppMethodUnit() = default;
};

#endif // CPP_METHODUNIT_H
