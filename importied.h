#ifndef IMPORTIED_H
#define IMPORTIED_H

#include "ui_importied.h"
#include "typeDef.h"
#include "../xmlhelplib/xmlhelplib.h"
#include "impdelegate.h"

namespace Ui {
    class ImportIED;
}

class ImportIED : public QDialog
{
    Q_OBJECT

public:
     ImportIED(QWidget *parent = 0);
    ~ImportIED();

     void parseFile(QString path);
    QList<Pointdef*> allPointList;

private:
    Ui::ImportIED *ui;
    XMLHelpLib xmlhelplib;
    QDomNode dataTypeTemplates;
    QList<QDomNode> subNetList;
    ImpDelegate *impDelegate;

    QList<IED*> listIED(QString path);
    QList<QDomNode> getLdByIed(QDomNode iedNode);
    QList<Pointdef*> getCtlPoints(QList<QDomNode> lnList);
    QList<QDomNode> getDsByLd(QDomNode ldNode);
    QString getCtlCDC(QString doName,QString lnType);
    QString getFCDADesc(QDomElement fcda,QDomElement LdNode);
    QString getCDC(QDomElement fcda,QDomElement LdNode);
    QList<QString> getAccPoints(QDomNode iedNode);
    void impIED(IED* ied);
    LdNode* getLN(QDomNode lnNode);
    QList<QDomNode> getPointByDs(QDomNode dsNode);
    QDomElement getPointLN(QDomElement fcda,QHash<QString,QDomNode> lnHash);
    Pointdef* getPoint(QDomElement pointEle,QDomElement pointLN);

private slots:
    void insertIED();

};

#endif // IMPORTIED_H
