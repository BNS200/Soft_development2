#include "java_classunit.h"

JavaClassUnit::JavaClassUnit(const std::string& name, size_t sizeFields)
    : ClassUnit(name, sizeFields), m_classModifier(ClassModifier::PUBLIC_CLASS){}

void JavaClassUnit::setClassModifier(Flags someClassModifier){
    m_classModifier = someClassModifier;
}

void JavaClassUnit::addClassModifier(Flags someClassModifier){
    m_classModifier |= someClassModifier;
}

const std::vector<std::string> JavaClassUnit::getAccessModifiers() const {
    std::vector<std::string> modifiers;
    modifiers = {"public", "protected", "private", ""};
    return modifiers;
}

const std::string JavaClassUnit::getClassModifier() const {
    std::string result;

    if (m_classModifier & PUBLIC_CLASS){
        result += "public ";
    }

    if (m_classModifier & ABSTRACT_CLASS){
        result += "abstract ";
    }

    if (m_classModifier & FINAL_CLASS){
        result += "final ";
    }

    return result;
}

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + getClassModifier() + " " + getName() + "\n";

    const auto& modifiers = getAccessModifiers();
    for (int i = 0; i < getFields().size (); i++){
        for (const auto& f : getFields()[i]){
            if (i < modifiers.size() && !modifiers[i].empty()){
                result += generateShift(level + 1) + modifiers[i] + " ";
            } else if (i == DEFAULT) {
                result += generateShift(level + 1);
            }
            result += f->compile(level + 1);
        }
    }
    return result += generateShift(level) + "}\n";
 }

