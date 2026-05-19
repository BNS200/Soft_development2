#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "unit.h"
#include <vector>
#include <string>
#include <memory>

class ClassUnit : public Unit {
public:

    virtual const std::vector<std::string> getAccessModifiers() const = 0;

    explicit ClassUnit(const std::string& name, size_t fieldsSize);

    void add(const std::shared_ptr<Unit>& unit, Flags flags) override final;

    std::string compile(unsigned int level = 0) const override;

    const std::string& getName() const;

    const std::vector<std::vector<std::shared_ptr<Unit>>>& getFields() const;

private:
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};

#endif
