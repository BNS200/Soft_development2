#include "csharp_printoperatorunit.h"

CSharpPrintOperatorUnit::CSharpPrintOperatorUnit(const std::string& text)
    : PrintOperatorUnit(text)
{}

std::string CSharpPrintOperatorUnit::getPrintSyntax() const
{
    return "Console.WriteLine(\"" + getText() + "\");";
}
