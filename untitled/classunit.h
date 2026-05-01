#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "unit.h"
#include <vector>
#include <string>
#include <memory>

class ClassUnit : public Unit {
public:

    // static const std::vector<std::string> ACCESS_MODIFIERS;
    virtual const std::vector<std::string> getAccessModifiers() const;
    virtual size_t getModifiersCount() const;
public:
    explicit ClassUnit(const std::string& name);
    void add(const std::shared_ptr<Unit>& unit, Flags flags) override final;
    std::string compile(unsigned int level = 0) const override final;
private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif
