#ifndef CSHARP_PRINTOPERATORUNIT_H
#define CSHARP_PRINTOPERATORUNIT_H
#include "printoperatorunit.h"

class CSharpPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperatorUnit(const std::string& text);
    virtual ~CSharpPrintOperatorUnit() = default;

    std::string getPrintSyntax() const override;
};

#endif // CSHARP_PRINTOPERATORUNIT_H
