#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H

#include "unit.h"
#include <string>

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit(const std::string& text);
    std::string compile(unsigned int level) const override final;
    virtual std::string getPrintSyntax() const = 0;
    std::string getText() const;
private:
    std::string m_text;
};

#endif
