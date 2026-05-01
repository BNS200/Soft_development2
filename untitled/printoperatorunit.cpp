#include "printoperatorunit.h"

PrintOperatorUnit::PrintOperatorUnit(const std::string& text) : m_text(text){}

std::string PrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + getPrintSyntax() + "\n";
}

std::string PrintOperatorUnit::getText() const {
    return m_text;
}
