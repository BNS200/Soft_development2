#include "cpp_classunit.h"

CppClassUnit::CppClassUnit(const std::string& name) : ClassUnit(name, 3){}

const std::vector<std::string> CppClassUnit::getAccessModifiers() const {
    std::vector<std::string> modifiers = {"public", "protected", "private"};
    return modifiers;
}
