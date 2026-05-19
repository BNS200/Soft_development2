# Soft_development2

## 1. Постановка задачи

### 1.1 Цель работы
Разработать расширяемую систему для генерации кода на разных языках программирования (C++, C#, Java), используя паттерн "Абстрактная фабрика".

### 1.2 Исходные данные
Имеется реализация генератора кода на C++, включающая классы:
- `Unit` - базовый абстрактный класс
- `ClassUnit` - генерация классов
- `MethodUnit` - генерация методов
- `PrintOperatorUnit` - генерация операторов печати

## 2. Предлагаемое решение

### 2.1 Общая архитектура

В основе разработанного решения лежит архитектура генерации кода, построенная с использованием патернов и принципов проектирования, что обеспечивает расширяемость системы и поддержку различных языков.

**Принципы проектирования**

- **Open/Closed** – базовые классы открыты для расширения, но закрыты для модификации. Существующий код не меняется при добавлении поддержки нового языка.
- **Dependency Inversion** – код зависит от абстракций, а не от конкретных реализаций. Это позволяет легко подменять одну реализацию другой без изменения клиентского кода.

**Паттерны проектирования**

- **Абстрактная фабрика** – паттерн используется для создания семейств взаимосвязанных объектов (класс, метод, оператор печати) для каждого языка программирования.

### 2.2 Паттерн абстрактная фабрика
**Паттерн используется тогда, когда:**
- Система должна оставаться независимой как от процесса создания новых
объектов, так и от типов порождаемых объектов.
- Необходимо создавать группы или семейства взаимосвязанных объектов,
исключая возможность одновременного использования объектов из разных
семейств в одном контексте.

### 2.3 Структура классов

#### Базовый класс Unit

**Назначение:** абстрактный базовый класс для всех синтаксических единиц кода.

**Основные методы:**
- `add()` – виртуальный метод для добавления вложенных элементов 
- `compile()` – чисто виртуальный метод для генерации кода, обязательный для реализации в наследниках
- `generateShift()` – метод для создания строки отступов (два пробела на уровень вложенности)

---

#### Абстрактный класс ClassUnit

**Назначение:** сущность для представления класса в любом языке программирования.
**Основные методы:**
- `getAccessModifiers()` – чисто виртуальный метод, возвращающий список модификаторов доступа для конкретного языка
- `add()` – добавление элемента (метода) в соответствующую секцию класса. Индекс секции определяется переданным флагом
- `compile()` – генерация кода класса

**Поля класса:**
- `m_name` – имя класса
- `m_fields` – вектор векторов, где каждый внутренний вектор хранит элементы (методы) одной секции доступа

---

#### Абстрактный класс MethodUnit

**Назначение:** сущность для представления метода в любом языке программирования.

**Основные методы:**
- `compileModifiers()` – чисто виртуальный метод, генерирующий строку модификаторов метода 
- `compileSignature()` – чисто виртуальный метод, генерирующий сигнатуру метода (тип возвращаемого значения, имя, параметры)
- `add()` – добавление оператора в тело метода
- `compile()` – шаблонный метод, определяющий общую структуру генерации метода: отступы, модификаторы, сигнатуру, тело в фигурных скобках

**Поля класса:**
- `m_name` – имя метода
- `m_returnType` – тип возвращаемого значения
- `m_flags` – битовая маска модификаторов
- `m_body` – вектор, хранящий операторы тела метода

---

#### Абстрактный класс PrintOperatorUnit

**Назначение:** сущность для представления оператора печати в любом языке программирования.

**Основные методы:**
- `getPrintSyntax()` – чисто виртуальный метод, возвращающий синтаксис оператора печати для конкретного языка 
- `compile()` – финальный метод, единый для всех языков: отступ + синтаксис печати + перевод строки

**Поля класса:**
- `m_text` – текст, выводимый на печать

---

#### Абстрактная фабрика CodeFactory

**Назначение:** интерфейс для создания семейств связанных объектов.

**Основные методы:**
- `createClass()` – создание объекта класса
- `createMethod()` – создание объекта метода
- `createPrintOperator()` – создание объекта оператора печати

Все методы возвращают умные указатели на абстрактные базовые классы (`ClassUnit`, `MethodUnit`, `PrintOperatorUnit`), что обеспечивает независимость клиентского кода от конкретных реализаций.

---

#### Конкретные фабрики

**CppFactory** – фабрика для создания C++ объектов. Создает экземпляры классов `CppClassUnit`, `CppMethodUnit`, `CppPrintOperatorUnit`.

**CSharpFactory** – фабрика для создания C# объектов. Создает экземпляры классов `CSharpClassUnit`, `CSharpMethodUnit`, `CSharpPrintOperatorUnit`.

**JavaFactory** – фабрика для создания Java объектов. Создает экземпляры классов `JavaClassUnit`, `JavaMethodUnit`, `JavaPrintOperatorUnit`.

---

#### Конкретные классы для C++

**CppClassUnit**

Реализация класса для C++. Поддерживает три модификатора доступа: `public`, `protected`, `private`. Метод `getAccessModifiers()` возвращает соответствующий вектор строк.

**CppMethodUnit**

Реализация метода для C++. Поддерживает модификаторы: `static`, `const`, `virtual`. Модификаторы могут комбинироваться через побитовое ИЛИ.

**CppPrintOperatorUnit**

Реализация оператора печати для C++.

---

#### Конкретные классы для C#

**CSharpClassUnit**

Реализация класса для C#. Поддерживает семь модификаторов доступа: `private`, `private protected`, `file`, `protected`, `internal`, `protected internal`, `public`. Также поддерживает модификаторы класса: `public`, `internal`, `abstract`, `sealed`, `static`, `partial`.

**CSharpMethodUnit**

Реализация метода для C#. Поддерживает модификаторы: `static`, `virtual`, `abstract`, `sealed`, `override`, `new`.

**CSharpPrintOperatorUnit**

Реализация оператора печати для C#.

---

#### Конкретные классы для Java

**JavaClassUnit**

Реализация класса для Java. Поддерживает четыре уровня доступа: `public`, `protected`, `private`. Также поддерживает модификаторы класса: `public`, `abstract`, `final`.

**JavaMethodUnit**

Реализация метода для Java. Поддерживает модификаторы: `static`, `final`, `abstract`, `native`, `strictfp`. Для абстрактных методов тело не генерируется – вместо него ставится точка с запятой.

**JavaPrintOperatorUnit**

Реализация оператора печати для Java.

---
### 2.4 UML диаграмма
https://app.diagrams.net/#G12QhGn-Jpa18bUZUv7fqqazJbKnjRQhR5#%7B%22pageId%22%3A%22dDzy2u72NRlW93BvClvD%22%7D
## 3. Инструкция пользователя

### 3.1 Сборка программы

**Требования для сборки:**
- Qt: версия 5 или 6 
- CMake: версия 3.1 или выше
- Компилятор: с поддержкой C++17

**Инструкция по сборке (macOS/Linux):**
- Настройка проекта: `cmake -B build -S .`
- Компиляция проекта: `cmake --build build`
- Запуск программы: `./build/project_name`

### 3.2 Пример работы программы

**Пример: Генерация C++ кода**

```cpp
#include <iostream>
#include <memory>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"
#include "cppfactory.h"
#include "csharpfactory.h"
#include "javafactory.h"



int main() {
    // Создаем фабрику для C++
    auto factory = std::make_shared<CppFactory>();
    
    // Создаем класс с именем MyClass
    auto myClass = factory->createClassUnit("MyClass");
    
    // Создаем публичный метод
    auto method1 = factory->createMethodUnit("test1", "void", 0);
    
    // Создаем приватный статический метод
    auto method2 = factory->createMethodUnit("test2", "void", CppMethodUnit::STATIC);
    
    // Создаем метод с телом
    auto method3 = factory->createMethodUnit("test3", "void", 0);
    auto print = factory->createPrintOperatorUnit("Hello, World!\\n");
    method3->add(print);
    
    // Добавляем методы в класс с разными модификаторами доступа
    myClass->add(method1, CppClassUnit::PUBLIC);   
    myClass->add(method2, CppClassUnit::PRIVATE);  
    myClass->add(method3, CppClassUnit::PUBLIC);  
    
    std::cout << myClass->compile(0);
    
    return 0;
}
```
**Вывод программы:**
```cpp
class MyClass {
  public:
    void test1() {
    }
    void test3() {
      std::cout << "Hello, World!\n"<< std::endl;
    }

  private:
    static void test2() {
    }

};
```
## 4. Тестирование

### 4.1 Генерация C++ кода
```cpp

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
```
**Вывод программы:**
```cpp
class FullCppClass {
  public:
    static void staticMethod() {
    }
    virtual void virtualMethod() {
    }
  protected:
    void constMethod() const {
    }
    virtual void virtualConstMethod() const {
    }
  private:
    static void methodWithBody() {
      std::cout << "Hola!"<< std::endl;
    }
};
```
### 4.2 Генерация C# кода
```cpp
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
```
**Вывод программы:**
```csharp
public abstract class FullCSharpClass {
  private void privateMethod() {
  }
  private protected void privateProtectedMethod() {
  }
  file void fileMethod() {
  }
  protected void protectedMethod() {
  }
  protected internal void protectedInternalMethod() {
  }
  public void publicMethod() {
  }
  public static void staticMethod() {
  }
  public virtual void virtualMethod() {
  }
  public abstract void abstractMethod();
  public sealed override void sealedMethod() {
  }
  public override void overrideMethod() {
  }
  public static void methodWithBody() {
    Console.WriteLine("Hola!");
  }
  void internalMethod() {
  }
}
```
### 4.3 Генерация Java кода
```cpp
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

```
**Вывод программы:**
```java
public abstract class FullJavaClass {
  public final void finalMethod() {
  }
  public abstract void abstractMethod();
  public native void nativeMethod();
  public static final void staticFinalMethod() {
  }
  public static void publicStaticMethod() {
  }
  public static void methodWithBody() {
    System.out.println("Hola!");
  }
  protected void protectedMethod() {
  }
  private static void privateMethod() {
  }
  void publicMethod() {
  }
  static void staticMethod() {
  }
}
```
