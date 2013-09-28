#include "impaccpoint.h"
#include "ui_impaccpoint.h"

ImpAccPoint::ImpAccPoint(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImpAccPoint)
{
    ui->setupUi(this);
    accListWidget = qFindChild<QListWidget*>(this, "listWidget");
    accPointsTxt = "";

    connect(accListWidget,SIGNAL(itemChanged(QListWidgetItem*)),this,SLOT(setAccPoints(QListWidgetItem*)));
}


void ImpAccPoint::setAccPointCheckBox(QString curAccPoints,QString allAccPoints)
{
    accListWidget->clear();

    QStringList curAccList = curAccPoints.split("->");

    QStringList accList = allAccPoints.split("->");
    foreach (QString accPoint, accList)
    {
        QListWidgetItem *accItem = new QListWidgetItem(accPoint);
        if(curAccList.indexOf(accPoint) != -1 )
        {
            accItem->setCheckState(Qt::Checked);
        }
        else
        {
            accItem->setCheckState(Qt::Unchecked);
        }
        accListWidget->addItem(accItem);
    }

    this->accPointsTxt = curAccPoints;
}


void ImpAccPoint::setAccPoints(QListWidgetItem* item)
{
    QString curAccPoint = item->text();

    if(item->checkState() == Qt::Checked)
    {
        if(accPointsTxt == "")
        {
            accPointsTxt.append(curAccPoint);
        }
        else
        {
            accPointsTxt.append("->").append(curAccPoint);
        }

    }
    else
    {
        QStringList accLists = accPointsTxt.split("->");
        QString replaceStr = "";
        if(accLists.indexOf(curAccPoint) == 0)
        {
            replaceStr = curAccPoint;
        }
        else
        {
            replaceStr = QString("->").append(curAccPoint);
        }
        accPointsTxt = accPointsTxt.replace(replaceStr,"");
    }
}


ImpAccPoint::~ImpAccPoint()
{
    delete ui;
}
