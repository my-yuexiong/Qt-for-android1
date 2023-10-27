#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <ctime>
#include <cstdlib>
#include <QString>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    int guess_num;
    int target_num;
    QSize *self_size;


public:
    Widget(QSize *my_size,QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
