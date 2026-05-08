#include "java_methodunit.h"

JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags)
    : MethodUnit(name, returnType, flags){}

std::string JavaMethodUnit::compileModifiers() const
{
    std::string result;
    if (getFlags() & STATIC) {
        result += "static ";
    }
    if (getFlags() & FINAL) {
        result += "final ";
    }
    if (getFlags() & ABSTRACT) {
        result += "abstract ";
    }
    if (getFlags() & NATIVE) {
        result += "native ";
    }
    if (getFlags() & STRICTFP) {
        result += "strictfp ";
    }

    return result;
}

std::string JavaMethodUnit::compileSignature() const
{
    return getReturnType() + " " + getName() + "()";
}

std::string JavaMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);
    result += compileModifiers();
    result += compileSignature();

    if (getFlags() & ABSTRACT) {
        result += ";\n";
    } else {
        result += " {\n";
        for (const auto& b : getBody()) {
            result += b->compile(level + 1);
        }
        result += generateShift(level) + "}\n";
    }
    return result;
}
