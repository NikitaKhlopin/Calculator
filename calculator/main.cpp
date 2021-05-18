#include "calc.h"
#include <QApplication>
#include<QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    calc w;
    w.show();

    QLabel label("Привет, используй пробел после кажого знака и цифры, чтобы не было ошибок!");
    label.show();
    return a.exec();
}
