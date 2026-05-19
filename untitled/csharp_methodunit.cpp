#include "csharp_methodunit.h"

CSharpMethodUnit::CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : MethodUnit(name, returnType, flags) {}

std::string CSharpMethodUnit::compileModifiers() const
{
    std::string result;
    if (getFlags() & STATIC) {
        result += "static ";
    }
    if (getFlags() & VIRTUAL) {
        result += "virtual ";
    }
    if (getFlags() & ABSTRACT) {
        result += "abstract ";
    }
    if (getFlags() & SEALED) {
        result += "sealed ";
    }
    if (getFlags() & OVERRIDE) {
        result += "override ";
    }
    if (getFlags() & NEW) {
        result += "new ";
    }
    return result;
}

std::string CSharpMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);
    result += compileModifiers();
    result += compileSignature();
    if (getFlags() & ABSTRACT) {
        result += ";\n";
    } else {
        result += " {\n";
        for (const auto& b : getBody()) {
            result += b->compile(level + 2);
        }
        result += generateShift(level + 1) + "}\n";
    }
    return result;
}



std::string CSharpMethodUnit::compileSignature() const
{
    return getReturnType() + " " + getName() + "()";
}
