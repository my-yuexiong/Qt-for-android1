#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QSize *my_size,QWidget *parent)
    : QWidget(parent)
    , self_size(my_size) ,ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setFixedSize(self_size->width(),self_size->height());
    srand(time(0));
    target_num = rand() % 1000;
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    if(ui->input_num->text().isEmpty())
    {
        QMessageBox::information(this,"警告","请输入内容！！");
    }
    else
    {
        QString str_getnum = ui->input_num->text();
        bool ok;
        guess_num = str_getnum.toInt(&ok);


        if(guess_num == target_num)
        {
            QMessageBox::information(this,"提示","恭喜你猜对了！！");
        }
        else if(guess_num < target_num)
        {
            QMessageBox::information(this,"提示","猜小了，但您还有机会");
        }
        else if(guess_num > target_num)
        {
            QMessageBox::information(this,"提示","猜大了，但您还有机会");
        }
    }
}

