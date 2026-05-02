#ifndef CPP_CLASSUNIT_H
#define CPP_CLASSUNIT_H
#include "classunit.h"

class CppClassUnit : public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC,
        PROTECTED,
        PRIVATE,
    };

    explicit CppClassUnit(const std::string& name, size_t fieldsSize);
    virtual ~CppClassUnit() = default;
    const std::vector<std::string> getAccessModifiers() const override;

};

#endif // CPP_CLASSUNIT_H
