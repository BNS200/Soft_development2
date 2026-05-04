#include "java_printoperatorunit.h"

JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string& text)
    : PrintOperatorUnit(text)
{}

std::string JavaPrintOperatorUnit::getPrintSyntax() const
{
    return "System.out.println(\"" + getText() + "\");";
}
