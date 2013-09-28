#ifndef IMPACCPOINT_H
#define IMPACCPOINT_H

#include <QDialog>
#include <QCheckBox>
#include <QListWidget>

namespace Ui {
    class ImpAccPoint;
}

class ImpAccPoint : public QDialog
{
    Q_OBJECT

public:
    explicit ImpAccPoint(QWidget *parent = 0);
    ~ImpAccPoint();

    QListWidget *accListWidget;
    QString accPointsTxt;
    void setAccPointCheckBox(QString curAccPoints,QString allAccPoints);
private:
    Ui::ImpAccPoint *ui;

private slots:
    void setAccPoints(QListWidgetItem * item);
};

#endif // IMPACCPOINT_H
