#include "calculator.h"

#include <QApplication>

#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calculator w;
    w.show();

    QLabel label("Привет, используй пробел после кажого знака и цифры, чтобы не было ошибок!");

    label.show();

    return a.exec();
}
