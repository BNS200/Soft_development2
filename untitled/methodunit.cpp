#include "methodunit.h"

MethodUnit::MethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    m_name(name), m_returnType(returnType), m_flags(flags){}

void MethodUnit::add(const std::shared_ptr<Unit>& unit, Flags){
    m_body.push_back(unit);
}

std::string MethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);
    result += compileModifiers();
    result += compileSignature();
    result += " {\n";
    for(const auto& b : m_body){
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}

std::string MethodUnit::getName() const {
    return m_name;
}

std::string MethodUnit::getReturnType() const {
    return m_returnType;
}

MethodUnit::Flags MethodUnit::getFlags() const {
    return m_flags;
}
