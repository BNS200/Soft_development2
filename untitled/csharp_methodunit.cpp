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
    return result;
}

std::string CSharpMethodUnit::compileSignature() const
{
    return getReturnType() + " " + getName() + "()";
}
