#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "classunit.h"
#include "methodunit.h"
#include "printoperatorunit.h"

std::string generateProgram() {
    return 0;
}
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::string program = generateProgram();
    qDebug() << QString::fromStdString(program);
    std::cout << program << std::endl;

    return a.exec();
}
