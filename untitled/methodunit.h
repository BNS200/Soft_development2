#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "unit.h"
#include <vector>
#include <string>
#include <memory>

class MethodUnit : public Unit {
public:
    explicit MethodUnit(const std::string& name, const std::string& returnType, Flags flags);

    void add(const std::shared_ptr<Unit>& unit, Flags = 0) override;

    std::string compile(unsigned int level = 0) const override;

    virtual ~MethodUnit() = default;

    virtual std::string compileModifiers() const = 0;
    virtual std::string compileSignature() const = 0;

    Flags getFlags() const;
    std::string getReturnType() const;
    std::string getName() const;

private:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

#endif
