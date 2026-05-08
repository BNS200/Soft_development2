#ifndef JAVA_METHODUNIT_H
#define JAVA_METHODUNIT_H
#include "methodunit.h"

class JavaMethodUnit : public MethodUnit
{
public:

    enum Modifier {
        STATIC = 1,
        FINAL = 1 << 1,
        ABSTRACT = 1 << 2,
        NATIVE = 1 << 3,
        STRICTFP = 1 << 4

    };

    explicit JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    virtual ~JavaMethodUnit() = default;

    std::string compileModifiers() const override;
    std::string compileSignature() const override;

    std::string compile(unsigned int level) const override;
};

#endif // JAVA_METHODUNIT_H
