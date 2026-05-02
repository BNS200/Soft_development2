#include "csharp_classunit.h"

CSharpClassUnit::CSharpClassUnit(const std::string& name, size_t fieldSize, std::string classModifier)
    : ClassUnit(name, fieldSize), m_classModifier(classModifier) {}

const std::vector<std::string> CSharpClassUnit::getAccessModifiers() const{
    std::vector<std::string> modifiers = {
        "private",
        "private protected",
        "file",
        "protected",
        "internal",
        "protected internal",
        "public"
    };
    return modifiers;
}

std::string CSharpClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + m_classModifier + " class " + getName() + "\n";
    result += generateShift(level) + "{\n";

    const auto& modifiers = getAccessModifiers();

    for (size_t i = 0; i < getFields().size(); ++i) {
        for (const auto& f : getFields()[i]) {
            if (i < modifiers.size() && !modifiers[i].empty()) {
                result += generateShift(level + 1) + modifiers[i] + " ";
            }
            result += f->compile(level + 1);
        }
    }

    result += generateShift(level) + "}\n";
    return result;
}
