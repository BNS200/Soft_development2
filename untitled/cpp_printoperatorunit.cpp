#include "cpp_printoperatorunit.h"

CppPrintOperatorUnit::CppPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text){}


std::string CppPrintOperatorUnit::getPrintSyntax() const {
    return "std::cout << \"" + getText() + "\"<< std::endl;";
}
