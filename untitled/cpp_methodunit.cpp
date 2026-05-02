#include "cpp_methodunit.h"

CppMethodUnit::CppMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : MethodUnit(name, returnType, flags){}

std::string CppMethodUnit::compileModifiers() const {
    std::string result;
    if (getFlags() & STATIC) {
        result += "static ";
    }
    if (getFlags() & VIRTUAL) {
        result += "virtual ";
    }
    return result;
}

std::string CppMethodUnit::compileSignature() const {
    std::string result = getReturnType() + " " + getName() + "()";
    if (getFlags() & CONST) {
        result += " const";
    }
    return result;
}
