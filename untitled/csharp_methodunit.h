#ifndef CSHARP_METHODUNIT_H
#define CSHARP_METHODUNIT_H
#include "methodunit.h"

class CSharpMethodUnit : public MethodUnit
{
public:
    enum Modifier {
        STATIC = 1,
        VIRTUAL = 1 << 1,
        ABSTRACT = 1 << 2,
        SEALED = 1 << 3,
        OVERRIDE = 1 << 4,
        NEW = 1 << 5
    };

    explicit CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    virtual ~CSharpMethodUnit() = default;

    virtual std::string compileModifiers() const = 0;
    virtual std::string compileSignature() const = 0;



};

#endif // CSHARP_METHODUNIT_H
