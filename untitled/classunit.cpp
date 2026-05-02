#include "classunit.h"

// const std::vector<std::string> ClassUnit::ACCESS_MODIFIERS = {"public", "protected", "private"};

ClassUnit::ClassUnit(const std::string& name, size_t fieldsSize) : m_name(name){
    m_fields.resize(fieldsSize);
}

void ClassUnit::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    size_t accessModifier = 0;
    if(flags < getAccessModifiers().size()){
        accessModifier = flags;
    }
    m_fields[accessModifier].push_back(unit);
}

std::string ClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n";
    for(size_t i = 0; i < getAccessModifiers().size(); ++i){
        if(m_fields[i].empty()){
            continue;
        }
        result += generateShift(level + 1) + (getAccessModifiers())[i] + ":\n";
        for(const auto& f : m_fields[i]) {
            result += f->compile(level + 2);
        }
        result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}
