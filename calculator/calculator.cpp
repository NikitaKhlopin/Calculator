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
    if(Ot == false && P == false)
    {
    QPushButton* button = (QPushButton*)sender();

    QString s = ui->result_show->text() + button->text();

    ui->result_show->setText(s);    P = true;
    }
}

void calculator :: spacebar()
{ //Пробел

    if(Ot == false && VS == false)
    {
    QString s = ui->result_show->text() + " ";

    ui->result_show->setText(s);

   VS = true;    P = false;
    }
}


void calculator :: cleanAC()
{ //Отчистка
    if(Ot == false)

    {
   QString s = ui->result_show->text();

        if(s.size() != 0){

            s.chop(1);

    ui->result_show->setText(s);

    if(O1 == true)    {      O1 = false;   }

    else if(VS == true)   {       VS = false;    }

    else if(P == true)      P = false;   }
   }
}

void calculator :: digit_num(){ //Ввод

    if(Ot == false)
    {
    QPushButton* button = (QPushButton*)sender();
    QString s = ui->result_show->text() + button->text();
    ui->result_show->setText(s);
    O1 = false;VS = false;
    }
}
void calculator::clicked()
{ //Меню, выбор действия

    QString r = ui->result_show->text();
    if(!r.isEmpty())

        if(Ot == false && O1 == true)
        {
    stack<QString> qwerty;

    if(VS == false){
    r.replace("+", " +"); r.replace("-", " -"); r.replace("*", " *"); r.replace("/", " /"); r.replace("^", " ^"); }

    auto sl = r.split(" ");
    int n = sl.size();

    for (int i = 0; i < n; i++)
    {
        auto t = sl.front();
        sl.pop_front();

        bool nr;

        t.toDouble(&nr);
        if (nr){

            qwerty.push(t);
        }

        else
        {

            QString ab1, ab2;

            switch(t.toStdString().back())
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
                ab1 = tmp.top();
                tmp.pop();
                ab2 = tmp.top();
                tmp.pop();
                tmp.push(QString::number(ab2.toDouble()*ab1.toDouble()));
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


void calculator :: math()
{ //Для решения поставленной задачи
    if(Ot == false)
    {
    QPushButton* button = (QPushButton*)sender(); QString s = ui->result_show->text() + button->text(); ui->result_show->setText(s); O1 = true;
    }
}


