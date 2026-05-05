#ifndef JAVA_CLASSUNIT_H
#define JAVA_CLASSUNIT_H
#include "classunit.h"

class JavaClassUnit : public ClassUnit
{
public:
    enum AccessModifier {
        PUBLIC = 0,
        PROTECTED = 1,
        PRIVATE = 2,
        DEFAULT = 3
    };
    enum ClassModifier {
        NONE = 0,
        PUBLIC_CLASS = 1,
        ABSTRACT_CLASS = 1 << 1,
        FINAL_CLASS = 1 << 2
    };

    explicit JavaClassUnit(const std::string& name, size_t fieldsSize);
    virtual ~JavaClassUnit() = default;

    const std::vector<std::string> getAccessModifiers() const override;
    const std::string getClassModifier() const;
    std::string compile(unsigned int level) const override;


    void setClassModifier(Flags someClassModifier);
    void addClassModifier(Flags someClassModifier);

private:
    Flags m_classModifier;

};

#endif // JAVA_CLASSUNIT_H
