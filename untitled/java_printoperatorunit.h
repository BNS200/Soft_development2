#ifndef JAVA_PRINTOPERATORUNIT_H
#define JAVA_PRINTOPERATORUNIT_H
#include "printoperatorunit.h"

class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit(const std::string& text);
    virtual ~JavaPrintOperatorUnit() = default;

    std::string getPrintSyntax() const override;
};

#endif // JAVA_PRINTOPERATORUNIT_H
