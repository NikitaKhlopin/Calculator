#include "calculator.h"

#include "ui_calculator.h"

#include <stack>

#include <math.h>

#include <QMessageBox>

    bool P = false,
    O1 = true,
    Ot = false,
    VS = false;

using namespace std;
calculator::calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calculator)
{
    ui->setupUi(this);
    connect(ui->pb0,SIGNAL(clicked()),
            this,SLOT(digit_num()));//0
    connect(ui->pb1,SIGNAL(clicked()),
            this,SLOT(digit_num()));//1
    connect(ui->pb2,SIGNAL(clicked()),
            this,SLOT(digit_num()));//2
    connect(ui->pb3,SIGNAL(clicked()),
            this,SLOT(digit_num()));//3
    connect(ui->pb4,SIGNAL(clicked()),
            this,SLOT(digit_num()));//4
    connect(ui->pb5,SIGNAL(clicked()),
            this,SLOT(digit_num()));//5
    connect(ui->pb6,SIGNAL(clicked()),
            this,SLOT(digit_num()));//6
    connect(ui->pb7,SIGNAL(clicked()),
            this,SLOT(digit_num()));//7
    connect(ui->pb8,SIGNAL(clicked()),
            this,SLOT(digit_num()));//8
    connect(ui->pb9,SIGNAL(clicked()),
            this,SLOT(digit_num()));//9
    connect(ui->spaceb,SIGNAL(clicked()),
            this,SLOT(spacebar())); //space

    connect(ui->plus,SIGNAL(clicked()),
            this,SLOT(math()));//+
    connect(ui->minus,SIGNAL(clicked()),
            this,SLOT(math()));//-
    connect(ui->div,SIGNAL(clicked()),
            this,SLOT(math()));
    connect(ui->mult,SIGNAL(clicked()),
            this,SLOT(math()));
    connect(ui->deg,SIGNAL(clicked()),
            this,SLOT(math()));

    connect(ui->equally,SIGNAL(clicked()),
            this,SLOT(clicked()));

    connect(ui->point,SIGNAL(clicked()),
            this,SLOT(point()));//точка

    connect(ui->clearC,SIGNAL(clicked()),
            this,SLOT(cleanC()));//отчиска1

    connect(ui->clearAC,SIGNAL(clicked()),
            this,SLOT(cleanAC()));//отчиска2
}
calculator::~calculator()
{
    delete ui;
}

void calculator :: point()
{ //Для точки
    if(!Ot && !P)
    {
    QPushButton* button = (QPushButton*)sender();

    QString s = ui->result_show->text() + button->text();

    ui->result_show->setText(s);    P = true;
    }
}

void calculator :: spacebar()
{ //Пробел

    if(!Ot && !VS)
    {
    QString text = ui->result_show->text() + filler;

    ui->result_show->setText(text);

   VS = true;    P = false;
    }
}

Symbols symb;

void calculator::change(QString &text, QChar first, QString sec){
    int index = 0;
    QString new_s = "";
    while (index != text.size()){
        if (text[index] == first)
            new_s += sec;
        else
            new_s += text[index];
        index++;
    }
    text = new_s;
}

void calculator :: cleanAC()
{ //Отчистка
    if(!Ot)

    {
   QString text = ui->result_show->text();

        if(text.size() != 0){

            text = drop_symbol(text);

    ui->result_show->setText(text);

    if(O1)    {      O1 = false;   }

    else if(VS)   {       VS = false;    }

    else if(P)      P = false;   }
   }
}

void calculator :: digit_num(){ //Ввод

    if(!Ot)
    {
    QPushButton* button = (QPushButton*)sender();
    QString digits = ui->result_show->text() + button->text();
    ui->result_show->setText(digits);
    O1 = false;VS = false;
    }
}

QString calculator::drop_symbol(QString text){
    QString temp = "";
    for (int i = 0; i < text.size()-1; i++)
        temp += text[i];
    return temp;
}

void calculator::clicked()
{ //Меню, выбор действия

    QString output = ui->result_show->text();
    if(output != "")

        if(!Ot && O1)
        {
    stack<QString> qwerty;

    if(!VS){
        dv_block(output);
     }

    QStringList mylist = output.split(filler);
    int razm = mylist.size();

    for (int i = 0; i < razm; i++)
    {
        QString temp = mylist.front();
        mylist.pop_front();

        bool nr;

        temp.toDouble(&nr);
        if (nr){

            qwerty.push(temp);
        }

        else
        {

            QString ab1, ab2;
            switch(temp.toStdString().back())
            {

            case '/':
                ab1 = qwerty.top();
                qwerty.pop();
                ab2 = qwerty.top();
                qwerty.pop();

                if(ab1.toDouble() == 0)
                {

                    QMessageBox::critical(this,"ОШИБКА!!!404!!!","На ноль делить нельзя!!!"); Ot = true;return;
                }
                qwerty.push(QString::number(ab2.toDouble()/ab1.toDouble()));
                break;

            case '+':
                ab1 = qwerty.top();
                qwerty.pop();
                ab2 = qwerty.top();
                qwerty.pop();
                qwerty.push(QString::number(ab2.toDouble()+ab1.toDouble()));
                break;

            case '-':
                ab1 = qwerty.top();
                qwerty.pop();
                ab2 = qwerty.top();
                qwerty.pop();
                qwerty.push(QString::number(ab2.toDouble()-ab1.toDouble()));
                break;

            case '*':
                ab1 = qwerty.top();
                qwerty.pop();
                ab2 = qwerty.top();
                qwerty.pop();
                qwerty.push(QString::number(ab2.toDouble()*ab1.toDouble()));
                break;


            case '^':
                ab1 = qwerty.top();
                qwerty.pop();
                ab2 = qwerty.top();
                qwerty.pop();
                qwerty.push(QString::number(pow(ab2.toDouble(),ab1.toDouble())));
                break;
            }
        }
    }

    ui->result_show->setText(qwerty.top());Ot = true;
        }
}



void calculator:: cleanC()
{ //ОТчистка
    ui->result_show->setText("");
    P = false;Ot = false;O1 = true;VS = false;
}

void calculator::dv_block(QString& output){
    change(output, symb.plus, symb.add_plus);
    change(output, symb.minus, symb.add_minus);
    change(output, symb.umnozh, symb.umnozh_add);
    change(output, symb.delenie, symb.delenie_add);
    change(output, symb.stepen, symb.stepen_add);
}

void calculator :: math()
{ //Для решения поставленной задачи
    if(!Ot)
    {
    QPushButton* button = (QPushButton*)sender(); QString text = ui->result_show->text() + button->text(); ui->result_show->setText(text); O1 = true;
    }
}


