#include "csharp_classunit.h"

CSharpClassUnit::CSharpClassUnit(const std::string& name)
    : ClassUnit(name, 7), m_classModifier(INTERNAL_CLASS) {}


void CSharpClassUnit::setClassModifier(Flags someModifier){
    m_classModifier = someModifier;
}

void CSharpClassUnit::addClassModifier(Flags someModifier){
    m_classModifier |= someModifier;
}

const std::string CSharpClassUnit::getClassModifier() const {
    std::string result;

    if (m_classModifier & PUBLIC_CLASS) {
        result += "public ";
    } else if (m_classModifier & INTERNAL_CLASS) {
        result += "internal ";
    }
    if (m_classModifier & ABSTRACT_CLASS) {
        result += "abstract ";
    }
    if (m_classModifier & SEALED_CLASS) {
        result += "sealed ";
    }
    if (m_classModifier & STATIC_CLASS) {
        result += "static ";
    }
    if (m_classModifier & PARTIAL_CLASS) {
        result += "partial ";
    }

    return result;
}

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
    std::string result = generateShift(level) + getClassModifier() + "class " + getName() + "\n";
    result += generateShift(level) + "{\n";

    const auto& modifiers = getAccessModifiers();

    for (size_t i = 0; i < getFields().size(); ++i) {
        for (const auto& f : getFields()[i]) {
            if (i < modifiers.size() && !modifiers[i].empty()) {
                result += generateShift(level + 1) + modifiers[i];
            }
            result += f->compile(level + 1);
        }
    }
    return result += generateShift(level) + "}\n";
}
