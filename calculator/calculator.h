
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE

class calculator : public QMainWindow
{
    Q_OBJECT

private slots:
    void spacebar();//пробел

    void math();//Для решения поставленной задачи

    void clicked();//Меню, выбор действия

    void point();//для точки

   void cleanC();//Отчистка

   void cleanAC();//отчистка

   void digit_num();//Ввод

private:
    Ui::calculator *ui;
public:

    calculator(QWidget *parent = nullptr);
    ~calculator();

};

#endif

