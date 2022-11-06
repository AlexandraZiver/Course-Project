#ifndef DATA_H
#define DATA_H

#include <QMainWindow>
#include <registration.h>

QT_BEGIN_NAMESPACE
namespace Ui { class Data; }
QT_END_NAMESPACE

class Data : public QMainWindow
{
    Q_OBJECT

public:
    Data(QWidget *parent = nullptr);
    ~Data();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Data *ui;
    Registration * registration;
};
#endif // DATA_H
