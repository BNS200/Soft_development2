#ifndef CPP_PRINTOPERATORUNIT_H
#define CPP_PRINTOPERATORUNIT_H
#include "printoperatorunit.h"

class CppPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CppPrintOperatorUnit(const std::string& text);
    std::string getPrintSyntax() const override;
};

#endif // CPP_PRINTOPERATORUNIT_H
