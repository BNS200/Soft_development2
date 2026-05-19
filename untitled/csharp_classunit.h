#ifndef CSHARP_CLASSUNIT_H
#define CSHARP_CLASSUNIT_H
#include "classunit.h"

class CSharpClassUnit : public ClassUnit
{
public:
    explicit CSharpClassUnit(const std::string& name);
    virtual ~CSharpClassUnit() = default;

    enum AccessModifier {
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        PROTECTED,
        INTERNAL,
        PROTECTED_INTERNAL,
        PUBLIC,
        PACKAGE_PRIVATE
    };

    enum ClassModifier {
        NONE = 0,
        PUBLIC_CLASS = 1,
        INTERNAL_CLASS = 1 << 1,
        ABSTRACT_CLASS = 1 << 2,
        SEALED_CLASS = 1 << 3,
        STATIC_CLASS = 1 << 4,
        PARTIAL_CLASS = 1 << 5

    };

    const std::vector<std::string> getAccessModifiers() const override;
    std::string compile(unsigned int level) const override;
    const std::string getClassModifier() const;


    void setClassModifier(Flags someClassModifier);
    void addClassModifier(Flags someClassModifier);

private:
    Flags m_classModifier;
};

#endif // CSHARP_CLASSUNIT_H
