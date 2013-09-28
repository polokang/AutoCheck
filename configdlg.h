#ifndef CONFIGDLG_H
#define CONFIGDLG_H

#include <QDialog>
#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>
#include <qaxselect.h>

#include "ui_configdlg.h"
#include "excelengine.h"
#include "importied.h"

namespace Ui {
    class ConfigDlg;
}

class ConfigDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ConfigDlg(QWidget *parent = 0);
    ~ConfigDlg();

    QList<Pointdef*> confList_yx;
    QList<Pointdef*> confList_yc;
    QList<Pointdef*> confList_yk;
private:
    Ui::ConfigDlg *ui;
    QString xmlFile;
    QString excelPath;

    int curIndex_YX;
    int curIndex_YC;
    int curIndex_YK;

public slots:
    void impICD();
    void impExcel();
    void dymicICDTab(int);
    void dymicEXCTab(int);
    void dymicPoint(QTableWidgetItem* item);
    void setConfList();
};

#endif // CONFIGDLG_H
