#include "calc.h"
#include "ui_calc.h"
#include <stack>
#include <math.h>
#include <QMessageBox>


using namespace std;
calc::calc(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::calc)
{
    ui->setupUi(this);

    connect(ui->spaceb,SIGNAL(clicked()),this,SLOT(spacebar())); //Связи между кнопками и функциями

    connect(ui->plus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->minus,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->div,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->mult,SIGNAL(clicked()),this,SLOT(math()));
    connect(ui->deg,SIGNAL(clicked()),this,SLOT(math()));

    connect(ui->equally,SIGNAL(clicked()),this,SLOT(clicked()));

    connect(ui->point,SIGNAL(clicked()),this,SLOT(point()));

    connect(ui->clearC,SIGNAL(clicked()),this,SLOT(cleanC()));

    connect(ui->clearAC,SIGNAL(clicked()),this,SLOT(cleanAC()));

    connect(ui->pb0,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb1,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb2,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb3,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb4,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb5,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb6,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb7,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb8,SIGNAL(clicked()),this,SLOT(digit_num()));
    connect(ui->pb9,SIGNAL(clicked()),this,SLOT(digit_num()));
}
calc::~calc(){
    delete ui;
}

void calc :: spacebar(){ //Пробел

    if(Otvet == false && VvodSpacebar == false){
    QString s = ui->result_show->text() + " ";
    ui->result_show->setText(s);
   VvodSpacebar = true;
    Point = false;
    }
}

void calc :: point(){ //Для точки
    if(Otvet == false && Point == false){
    QPushButton* button = (QPushButton*)sender();
    QString s = ui->result_show->text() + button->text();
    ui->result_show->setText(s);
    Point = true;
    }
}

void calc :: cleanAC(){ //Отчистка
    if(Otvet == false)
    {
   QString s = ui->result_show->text();

        if(s.size() != 0){
    s.chop(1);
    ui->result_show->setText(s);

    if(OperationVVod == true) {
        OperationVVod = false;
    }

    else if(VvodSpacebar == true){
       VvodSpacebar = false;
    }

    else if(Point == true)
        Point = false;
    }
    }
}

void calc:: cleanC(){ //ОТчистка
    ui->result_show->setText("");
    Point = false;
 Otvet = false;
    OperationVVod = true;
    VvodSpacebar = false;
}

void calc :: digit_num(){ //Ввод

    if(Otvet == false)
    {
    QPushButton* button = (QPushButton*)sender();
    QString s = ui->result_show->text() + button->text();
    ui->result_show->setText(s);
    OperationVVod = false;
    VvodSpacebar = false;
    }
}


void calc :: math(){ //Для решения поставленной задачи
    if(Otvet == false)
    {
    QPushButton* button = (QPushButton*)sender();
    QString s = ui->result_show->text() + button->text();
    ui->result_show->setText(s);
    OperationVVod = true;
    }
}

void calc::clicked(){ //Меню, выбор действия

    QString r = ui->result_show->text();
    if(!r.isEmpty())

        if(Otvet == false && OperationVVod == true){
    stack<QString> tmp;

    if(VvodSpacebar == false){
    r.replace("+", " +"); r.replace("-", " -"); r.replace("*", " *"); r.replace("/", " /"); r.replace("^", " ^"); }

    auto sl = r.split(" ");
    int n = sl.size();

    for (int i = 0; i < n; i++){
        auto t = sl.front();
        sl.pop_front();
        bool is_number;
        t.toDouble(&is_number);
        if (is_number){
            tmp.push(t);
        }

        else {

            QString a1, a2;

            switch(t.toStdString().back()){

            case '/':
                a1 = tmp.top();
                tmp.pop();
                a2 = tmp.top();
                tmp.pop();

                if(a1.toDouble() == 0) {

                    QMessageBox::critical(this,"ОШИБКА!!!404!!!","На ноль делить нельзя!!!");
                    Otvet = true;
                    return;
                }
                tmp.push(QString::number(a2.toDouble()/a1.toDouble()));
                break;

            case '+':
                a1 = tmp.top();

               tmp.pop();
                a2 = tmp.top();

                tmp.pop();
                tmp.push(QString::number(a2.toDouble()+a1.toDouble()));
                break;

            case '-':
                a1 = tmp.top();
                tmp.pop();
                a2 = tmp.top();
                tmp.pop();
                tmp.push(QString::number(a2.toDouble()-a1.toDouble()));
                break;

            case '*':
                a1 = tmp.top();
                tmp.pop();
                a2 = tmp.top();
                tmp.pop();
                tmp.push(QString::number(a2.toDouble()*a1.toDouble()));
                break;


            case '^':
                a1 = tmp.top();
                tmp.pop();
                a2 = tmp.top();
                tmp.pop();
                tmp.push(QString::number(pow(a2.toDouble(),a1.toDouble())));
                break;
            }
        }
    }

    ui->result_show->setText(tmp.top()); Otvet = true;
        }
}


