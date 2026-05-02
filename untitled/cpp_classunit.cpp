#include "cpp_classunit.h"

CppClassUnit::CppClassUnit(const std::string& name, size_t fieldsSize) : ClassUnit(name, fieldsSize){}

const std::vector<std::string> ClassUnit::getAccessModifiers() const {
    std::vector<std::string> modifiers = {"public", "protected", "private"};
    return modifiers;
}
