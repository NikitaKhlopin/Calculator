
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calc; }
QT_END_NAMESPACE

class calc : public QMainWindow
{
    Q_OBJECT
private slots:

    void cleanC();//Отчистка
    void cleanAC();//отчистка
    void digit_num();//Ввод
    void spacebar();//пробел
    void math();//Для решения поставленной задачи
    void clicked();//Меню, выбор действия
    void point();//для точки

private:

    Ui::calc *ui;
    bool Point = false, OperationVVod = true, Otvet = false,  VvodSpacebar = false;


public:

    calc(QWidget *parent = nullptr);

    ~calc();

};

#endif

