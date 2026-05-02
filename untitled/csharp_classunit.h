#ifndef CSHARP_CLASSUNIT_H
#define CSHARP_CLASSUNIT_H
#include "classunit.h"

class CSharpClassUnit : public ClassUnit
{
public:
    explicit CSharpClassUnit(const std::string& name, size_t fieldSize, std::string classModifier);
    virtual ~CSharpClassUnit() = default;

    enum AccessModifier {
        PRIVATE,
        PRIVATE_PROTECTED,
        FILE,
        PROTECTED,
        INTERNAL,
        PROTECTED_INTERNAL,
        PUBLIC
    };

    const std::vector<std::string> getAccessModifiers() const override;
    std::string compile(unsigned int level) const override;

private:
    std::string m_classModifier;
};

#endif // CSHARP_CLASSUNIT_H
