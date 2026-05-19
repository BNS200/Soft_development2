
#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "cppfactory.h"
#include "csharpfactory.h"
#include "javafactory.h"

void testCppAllModifiers() {
    auto factory = std::make_shared<CppFactory>();
    auto myClass = factory->createClassUnit("FullCppClass");

    auto methodStatic = factory->createMethodUnit("staticMethod", "void", CppMethodUnit::STATIC);
    auto methodVirtual = factory->createMethodUnit("virtualMethod", "void", CppMethodUnit::VIRTUAL);
    auto methodConst = factory->createMethodUnit("constMethod", "void", CppMethodUnit::CONST);
    auto methodVirtualConst = factory->createMethodUnit("virtualConstMethod", "void", CppMethodUnit::VIRTUAL | CppMethodUnit::CONST);
    auto methodWithBody = factory->createMethodUnit("methodWithBody", "void", CppMethodUnit::STATIC);
    auto print = factory->createPrintOperatorUnit("Hola!");
    methodWithBody->add(print);

    myClass->add(methodStatic, CppClassUnit::PUBLIC);
    myClass->add(methodVirtual, CppClassUnit::PUBLIC);
    myClass->add(methodConst, CppClassUnit::PROTECTED);
    myClass->add(methodVirtualConst, CppClassUnit::PROTECTED);
    myClass->add(methodWithBody, CppClassUnit::PRIVATE);

    std::string result = myClass->compile(0);
    std::cout << result << std::endl;
}

void testCSharpAllModifiers() {
    auto factory = std::make_shared<CSharpFactory>();
    auto myClass = factory->createClassUnit("FullCSharpClass");

    auto csharpClass = std::dynamic_pointer_cast<CSharpClassUnit>(myClass);
    csharpClass->setClassModifier(CSharpClassUnit::PUBLIC_CLASS);
    csharpClass->addClassModifier(CSharpClassUnit::ABSTRACT_CLASS);


    auto methodPrivate = factory->createMethodUnit("privateMethod", "void", 0);
    auto methodPrivateProtected = factory->createMethodUnit("privateProtectedMethod", "void", 0);
    auto methodFile = factory->createMethodUnit("fileMethod", "void", 0);
    auto methodProtected = factory->createMethodUnit("protectedMethod", "void", 0);
    auto methodInternal = factory->createMethodUnit("internalMethod", "void", 0);
    auto methodProtectedInternal = factory->createMethodUnit("protectedInternalMethod", "void", 0);
    auto methodPublic = factory->createMethodUnit("publicMethod", "void", 0);

    auto methodStatic = factory->createMethodUnit("staticMethod", "void", CSharpMethodUnit::STATIC);
    auto methodVirtual = factory->createMethodUnit("virtualMethod", "void", CSharpMethodUnit::VIRTUAL);
    auto methodAbstract = factory->createMethodUnit("abstractMethod", "void", CSharpMethodUnit::ABSTRACT);
    auto methodSealed = factory->createMethodUnit("sealedMethod", "void", CSharpMethodUnit::SEALED | CSharpMethodUnit::OVERRIDE);
    auto methodOverride = factory->createMethodUnit("overrideMethod", "void", CSharpMethodUnit::OVERRIDE);


    auto methodWithBody = factory->createMethodUnit("methodWithBody", "void", CSharpMethodUnit::STATIC);
    auto print = factory->createPrintOperatorUnit("Hola!");
    methodWithBody->add(print);

    myClass->add(methodPrivate, CSharpClassUnit::PRIVATE);
    myClass->add(methodPrivateProtected, CSharpClassUnit::PRIVATE_PROTECTED);
    myClass->add(methodFile, CSharpClassUnit::FILE);
    myClass->add(methodProtected, CSharpClassUnit::PROTECTED);
    myClass->add(methodInternal, CSharpClassUnit::PACKAGE_PRIVATE);
    myClass->add(methodProtectedInternal, CSharpClassUnit::PROTECTED_INTERNAL);
    myClass->add(methodPublic, CSharpClassUnit::PUBLIC);

    myClass->add(methodStatic, CSharpClassUnit::PUBLIC);
    myClass->add(methodVirtual, CSharpClassUnit::PUBLIC);
    myClass->add(methodAbstract, CSharpClassUnit::PUBLIC);
    myClass->add(methodSealed, CSharpClassUnit::PUBLIC);
    myClass->add(methodOverride, CSharpClassUnit::PUBLIC);
    myClass->add(methodWithBody, CSharpClassUnit::PUBLIC);

    std::string result = myClass->compile(0);
    std::cout << result << std::endl;
}

void testJavaAllModifiers() {
    auto factory = std::make_shared<JavaFactory>();
    auto myClass = factory->createClassUnit("FullJavaClass");

    auto javaClass = std::dynamic_pointer_cast<JavaClassUnit>(myClass);
    javaClass->setClassModifier(JavaClassUnit::PUBLIC_CLASS);
    javaClass->addClassModifier(JavaClassUnit::ABSTRACT_CLASS);

    auto methodPublic = factory->createMethodUnit("publicMethod", "void", 0);
    auto methodProtected = factory->createMethodUnit("protectedMethod", "void", 0);
    auto methodPrivate = factory->createMethodUnit("privateMethod", "void", JavaMethodUnit::STATIC);

    auto methodStatic = factory->createMethodUnit("staticMethod", "void", JavaMethodUnit::STATIC);
    auto methodFinal = factory->createMethodUnit("finalMethod", "void", JavaMethodUnit::FINAL);
    auto methodAbstract = factory->createMethodUnit("abstractMethod", "void", JavaMethodUnit::ABSTRACT);
    auto methodNative = factory->createMethodUnit("nativeMethod", "void", JavaMethodUnit::NATIVE);

    auto methodStaticFinal = factory->createMethodUnit("staticFinalMethod", "void", JavaMethodUnit::STATIC | JavaMethodUnit::FINAL);
    auto methodPublicStatic = factory->createMethodUnit("publicStaticMethod", "void", JavaMethodUnit::STATIC);


    auto methodWithBody = factory->createMethodUnit("methodWithBody", "void", JavaMethodUnit::STATIC);
    auto print = factory->createPrintOperatorUnit("Hola!");
    methodWithBody->add(print);

    myClass->add(methodPublic, JavaClassUnit::PACKAGE_PRIVATE);
    myClass->add(methodProtected, JavaClassUnit::PROTECTED);
    myClass->add(methodPrivate, JavaClassUnit::PRIVATE);
    myClass->add(methodStatic, JavaClassUnit::PACKAGE_PRIVATE);
    myClass->add(methodFinal, JavaClassUnit::PUBLIC);
    myClass->add(methodAbstract, JavaClassUnit::PUBLIC);
    myClass->add(methodNative, JavaClassUnit::PUBLIC);
    myClass->add(methodStaticFinal, JavaClassUnit::PUBLIC);
    myClass->add(methodPublicStatic, JavaClassUnit::PUBLIC);
    myClass->add(methodWithBody, JavaClassUnit::PUBLIC);

    std::string result = myClass->compile(0);
    std::cout << result << std::endl;
}

int main() {
    testCppAllModifiers();
    testCSharpAllModifiers();
    testJavaAllModifiers();
    return 0;
}
