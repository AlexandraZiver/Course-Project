#ifndef RECORD_H
#define RECORD_H

#include <QDialog>
#include <QString>
#include <QJsonValue>
#include <QJsonObject>
#include <QJsonDocument >
#include <QJsonArray>
#include <QFile>

namespace Ui {
class record;
}

class record : public QDialog
{
    Q_OBJECT

public:
    explicit record(QWidget *parent = nullptr);
    ~record();

private slots:
    void on_back_clicked();

    void on_show_json_clicked();

private:
    Ui::record *ui;
};

#endif // RECORD_H
