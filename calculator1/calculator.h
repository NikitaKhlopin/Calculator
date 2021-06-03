
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class calculator; }
QT_END_NAMESPACE
struct Symbols{
    QString fill = " ";
    QChar plus = '+'; QString add_plus = fill + plus;
    QChar minus = '-'; QString add_minus = fill + minus;
    QChar umnozh = '*'; QString umnozh_add = fill + umnozh;
    QChar delenie = '/'; QString delenie_add = fill + delenie;
    QChar stepen = '^'; QString stepen_add = fill + stepen;
};

class calculator : public QMainWindow
{
    Q_OBJECT

private slots:
    void spacebar();//пробел

    void math();//Для решения поставленной задачи

    QString drop_symbol(QString text); //удалить лишний символ

    void dv_block(QString&); //заменить блок символов

    void clicked();//Меню, выбор действия

    void point();//для точки

   void cleanC();//Отчистка

   void change(QString&, QChar, QString);//заменить символы

   void cleanAC();//отчистка

   void digit_num();//Ввод

private:
    Ui::calculator *ui;
    QString filler = " ";
public:

    calculator(QWidget *parent = nullptr);
    ~calculator();

};

#endif

