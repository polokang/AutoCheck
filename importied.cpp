#include "importied.h"

ImportIED::ImportIED(QWidget *parent) : QDialog(parent), ui(new Ui::ImportIED)
{
    ui->setupUi(this);

    impDelegate = new ImpDelegate;
    ui->iedTable->setItemDelegate(impDelegate);
}

void ImportIED::parseFile(QString path)
{
    QList<IED*> list = listIED(path);

    QTableWidgetItem *checkItem;
    QTableWidgetItem *nameItem;
    QTableWidgetItem *descItem;
    QTableWidgetItem *factoryItem;
    QTableWidgetItem *ipaItem;
    QTableWidgetItem *ipbItem;
    QTableWidgetItem *curAccItem;
    QTableWidgetItem *accItem;
    int iedSize = list.size();

    ui->iedTable->setColumnWidth(0,60);
    ui->iedTable->setColumnWidth(1,60);
    ui->iedTable->setColumnWidth(2,172);
    ui->iedTable->setColumnWidth(3,80);
    ui->iedTable->setColumnWidth(4,90);
    ui->iedTable->setColumnWidth(5,90);
    ui->iedTable->setColumnWidth(6,90);
    ui->iedTable->setColumnWidth(7,90);
    ui->iedTable->setColumnWidth(8,80);

    ui->iedTable->setRowCount(iedSize);

    ui->iedTable->setSelectionMode(QAbstractItemView::ExtendedSelection);

    for(int i=0;i<iedSize;i++)
    {
        IED* ied = list.at(i);

        checkItem = new QTableWidgetItem(QString::number(i+1));
        checkItem->setCheckState(Qt::Checked);
        ui->iedTable->setItem(i,0,checkItem);

        nameItem = new QTableWidgetItem(ied->name);
        nameItem->setFlags(Qt::NoItemFlags);
        nameItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter );
        nameItem->setData(Qt::UserRole,ied->comtradePath);
        ui->iedTable->setItem(i,1,nameItem);

        descItem = new QTableWidgetItem(ied->desc);
        descItem->setFlags(Qt::NoItemFlags);
        descItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter );
        ui->iedTable->setItem(i,2,descItem);

        factoryItem = new QTableWidgetItem(ied->factory);
        factoryItem->setFlags(Qt::NoItemFlags);
        factoryItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter );
        ui->iedTable->setItem(i,3,factoryItem);

        ipaItem = new QTableWidgetItem(ied->ipa);
        ipaItem->setFlags(Qt::NoItemFlags);
        ipaItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter );
        ui->iedTable->setItem(i,4,ipaItem);

        ipbItem = new QTableWidgetItem(ied->ipb);
        ipbItem->setFlags(Qt::NoItemFlags);
        ipbItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter );
        ui->iedTable->setItem(i,5,ipbItem);

        QString defaultAcc = "";
        QString accPoionts = "";
        for(int accNum=0;accNum<ied->accPoints.size();accNum++)
        {
            QString acc = ied->accPoints.at(accNum);

            if(accNum == 0)
            {
                accPoionts = acc;
                defaultAcc = acc;
            }
            else
            {
                accPoionts.append("->").append(acc);
            }

            if(acc.startsWith("S",Qt::CaseInsensitive))
            {
                defaultAcc = acc;
            }
        }

        curAccItem = new QTableWidgetItem(defaultAcc);
        curAccItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter );
        curAccItem->setData(Qt::UserRole,accPoionts);
        ui->iedTable->setItem(i,6,curAccItem);

        accItem = new QTableWidgetItem(accPoionts);
        accItem->setTextAlignment(Qt::AlignHCenter | Qt::AlignVCenter );
        accItem->setFlags(Qt::NoItemFlags);
        ui->iedTable->setItem(i,7,accItem);
    }

    ui->iedTable->setVisible(true);
    ui->submitBtn->setVisible(true);
    ui->cancelBtn->setVisible(true);

    connect(ui->submitBtn,SIGNAL(clicked()),this,SLOT(insertIED()));
    connect(ui->cancelBtn,SIGNAL(clicked()),this,SLOT(close()));
}


QList<IED*> ImportIED::listIED(QString path)
{
    QList<IED*> iedList;
    xmlhelplib.document.clear();
    xmlhelplib.loadXML(path);

    QList<QDomNode> iedNodeList = xmlhelplib.selectNodesList("SCL/IED");
    QList<QDomNode> subNetList = xmlhelplib.selectNodesList("SCL/Communication/SubNetwork");

    QDomElement iedEle;
    QList<QDomNode> conNodeList;
    QDomNode conNode;
    QList<QDomNode> addrNodeList;
    QDomNode addrNode;
    QDomElement addrEle;

    QString ipA = "";
    QString ipB = "";
    QString iedName;

    int iedSize = iedNodeList.size();

    for(int i=0;i<iedSize;i++)
    {
        iedEle = iedNodeList.at(i).toElement();
        IED *ied = new IED;
        QList<QString> accList = getAccPoints(iedEle);
        iedName = iedEle.attribute("name");
        ied->accPoints = accList;
        ied->name = iedName;
        ied->comtradePath = path;
        for(int j=0;j<subNetList.size();j++)
        {
            conNodeList = xmlhelplib.getChildNodes(subNetList.at(j),QString("ConnectedAP[@iedName=%1]").arg(iedName));
            if(!conNodeList.isEmpty())
            {
                conNode =conNodeList.at(0);
                if(!conNode.isNull())
                {
                    addrNodeList = xmlhelplib.getChildNodes(conNode,"Address/P[@type=IP]");
                    if(!addrNodeList.isEmpty())
                    {
                        addrNode = addrNodeList.at(0);
                        if(!addrNode.isNull())
                        {
                            addrEle = addrNode.toElement();
                            if(subNetList.at(j).toElement().attribute("name").contains("A"))
                            {
                                ipA = addrNode.toElement().text();
                            }
                            else
                            {
                                ipB = addrNode.toElement().text();
                            }
                        }
                    }
                }
            }

            ied->ipa = ipA;
            ied->ipb = ipB;
        }

        ied->desc = iedEle.attribute("desc");
        ied->factory = iedEle.attribute("manufacturer");
        iedList.append(ied);
    }
    return iedList;
}

//获取访问点
QList<QString> ImportIED::getAccPoints(QDomNode iedNode)
{
    QList<QString> accList;
    QList<QDomNode> accNodeList= xmlhelplib.getChildNodes(iedNode,"AccessPoint");
    for(int i=0;i<accNodeList.size();i++)
    {
        QDomElement accEle = accNodeList.at(i).toElement();
        QString accName = accEle.attribute("name");
        accList.append(accName);
    }

    return accList;
}


void ImportIED::insertIED()
{
    ui->submitBtn->setEnabled(false);
    int rowCount = ui->iedTable->rowCount();
    QString path = "";
    for(int i=0;i<rowCount;i++)
    {
        if(ui->iedTable->item(i,0)->checkState() == Qt::Checked)
        {
            IED* ied = new IED();
            ied->name = ui->iedTable->item(i,1)->data(Qt::DisplayRole).toString();
            ied->desc = ui->iedTable->item(i,2)->data(Qt::DisplayRole).toString();
            ied->factory = ui->iedTable->item(i,3)->data(Qt::DisplayRole).toString();
            ied->ipa = ui->iedTable->item(i,4)->data(Qt::DisplayRole).toString();
            ied->ipb = ui->iedTable->item(i,5)->data(Qt::DisplayRole).toString();
            QString accPoints = ui->iedTable->item(i,6)->data(Qt::DisplayRole).toString();
            ied->accPoints = accPoints.split("->");

            path = ui->iedTable->item(i,1)->data(Qt::UserRole).toString();

            xmlhelplib.document.clear();
            xmlhelplib.loadXML(path);
            impIED(ied);
        }
    }
    ui->iedTable->setVisible(false);
    ui->submitBtn->setVisible(false);

    emit QDialog::accept();

}


void ImportIED::impIED(IED* ied)
{
    QDomNode iedNode;
    //*******
    QList<QDomNode> ldList;
    QList<QDomNode> dsList;
    QList<QDomNode> pointList;

    QDomElement ldEle;
    QDomElement dsEle;
    QDomNode ln0Node;

    //初始化
    dataTypeTemplates = xmlhelplib.selectNodesList("SCL/DataTypeTemplates").at(0);
    subNetList = xmlhelplib.selectNodesList("SCL/Communication/SubNetwork");
    allPointList.clear();
    QString iedName = ied->name;
    qDebug()<<"***Imp:"<<iedName;
    iedNode = xmlhelplib.selectSingleNode(QString("SCL/IED[@name=%1]").arg(iedName));

    //************TCP NET
//    QList<TcpNet*> netList = getNetList(iedName);

    //***LD
    ldList = getLdByIed(iedNode);
    for(int j=0;j<ldList.size();j++)
    {
        QDomNode ldNode = ldList.at(j);
        ldEle = ldNode.toElement();
        Ldevice* ld = new Ldevice;
        ld->name = ldEle.attribute("inst");
        ld->desc = ldEle.attribute("desc");

        //*********12.17日增加 logicnode 表************//
        ln0Node = xmlhelplib.getChildNode(ldEle,"LN0");//*
        QList<QDomNode> lnList = xmlhelplib.getChildNodes(ldNode,"LN");
        lnList.insert(0,ln0Node);
        //插入逻辑节点,并返回逻辑节点的Hash
        QHash<QString,QDomNode> lnHash;
        QString ln0NodeId;
        QString ln0NodeChildID;
        foreach(QDomNode lnNode,lnList)
        {
            LdNode* ln = getLN(lnNode);
            if(ln->lnClass == "LLN0")
            {
                ln0NodeId = ln->id;
                ln0NodeChildID = ln->cId;
            }

            QString key = QString("%1%2%3").arg(ln->prefix).arg(ln->lnClass).arg(ln->inst);
            lnHash.insert(key,lnNode);
        }

        //***控制点集合
        QList<Pointdef*> ctrlPointList = getCtlPoints(lnList);
        if(!ctrlPointList.isEmpty())
        {
            Dataset* ctrlDS = new Dataset;
            ctrlDS->name = "dsCtrl";
            ctrlDS->desc = tr("dsCtrl");

            for(int n=0;n<ctrlPointList.size();n++)
            {
                Pointdef *point = ctrlPointList[n];
                allPointList.append(point);
//                insertCtrlPoints2DB(ctrlDS->id,ctrlDS->cId,point); //插入控制点
            }
        }

        //***ds数据集处理
        dsList = getDsByLd(ldEle);
        for(int k=0;k<dsList.size();k++)
        {
            dsEle = dsList.at(k).toElement();
            Dataset* ds = new Dataset;
            ds->name = dsEle.attribute("name");
            ds->desc = dsEle.attribute("desc");

            //***点
            pointList = getPointByDs(dsList.at(k));
            for(int m=0;m<pointList.size();m++)
            {
                QDomElement pointEle = pointList.at(m).toElement();
                QDomElement pointLN = getPointLN(pointEle,lnHash);

                Pointdef* po = getPoint(pointEle,pointLN);
                allPointList.append(po);
            }
        }
    }
}


QList<QDomNode> ImportIED::getDsByLd(QDomNode ldNode)
{
    QList<QDomNode> resList;
    QList<QDomNode> dsList;
    QDomElement dsEle;
    QString dsName;
    QString dsNameUpper;
    QString dsDesc;
    QString xpath = "LN0/DataSet";
    dsList = xmlhelplib.getChildNodes(ldNode,xpath);
    for(int i=0;i<dsList.size();i++)
    {
        dsEle = dsList.at(i).toElement();
        dsName = dsEle.attribute("name");
        dsNameUpper = dsName.toUpper();
        dsDesc = dsEle.attribute("desc");
        if(!(dsNameUpper.contains("DSSV") || dsNameUpper.contains("DSGOOSE")))
        {
            resList.append(dsEle);
        }

    }
    return resList;
}

QString ImportIED::getCtlCDC(QString doName,QString lnType)
{
    QString cdc = "";
    QString lnTypeXPath = QString("LNodeType[@id=%1]/DO[@name=%2]").arg(lnType).arg(doName);

    QDomNode lnTypeNode = xmlhelplib.getChildNode(dataTypeTemplates,lnTypeXPath);

    if(!lnTypeNode.isElement())
    {
        return "";
    }
    QDomElement lnDoEle = lnTypeNode.toElement();

    QString doId = lnDoEle.attribute("type");
    QString doXPath = QString("DOType[@id=%1]").arg(doId);
    QDomNode doTypeNode = xmlhelplib.getChildNode(dataTypeTemplates,doXPath);
    if(!doTypeNode.isElement())
    {
        return "";
    }
    QDomElement doTypeEle = doTypeNode.toElement();
    cdc = doTypeEle.attribute("cdc");

    return cdc;
}


QList<Pointdef*> ImportIED::getCtlPoints(QList<QDomNode> lnList)
{
    QList<Pointdef*> pointList;

    for(int n=0;n<lnList.size();n++)
    {
        QDomElement lnEle = lnList[n].toElement();
        QList<QDomNode> doiList = xmlhelplib.getChildNodes(lnList[n],"DOI");
        QString lnType = lnList[n].toElement().attribute("lnType");
        QString prefix = lnEle.attribute("prefix");
        QString lnClass = lnEle.attribute("lnClass");
        QString lnInst = lnEle.attribute("inst");
        for(int i=0;i<doiList.size();i++)
        {
            QString ctrlMode =  xmlhelplib.getChildNode(doiList[i],"DAI[@name=ctlModel]/Val").toElement().text();
            if(ctrlMode != "")
            {
                QDomElement doiEle = doiList[i].toElement();
                QString doName = doiEle.attribute("name");
                QString desc = doiEle.attribute("desc");
                QString cdc = getCtlCDC(doName,lnType);
                QString fc = "CO"; //???

                QString pointName = "";
                pointName.append(prefix)
                        .append(lnClass).append(lnInst).append("$").append(fc);

                if(doName != "")
                {
                    pointName.append("$").append(doName);
                }
                pointName = pointName.replace(".","$");

                Pointdef *point = new Pointdef;
                point->name = pointName;
                point->desc = desc;
                point->cdc = cdc;
                point->fc = fc;

                pointList.append(point);
            }
        }
    }

    return pointList;
}


QList<QDomNode> ImportIED::getLdByIed(QDomNode iedNode)
{
    QList<QDomNode> resList;
    QList<QDomNode> ldList;
    QList<QString> accessPoint;
    accessPoint<<"S1"<<"G1"<<"M1";
    QString xpath = "AccessPoint[@name=%1]/Server/LDevice";

    QDomElement ldEle;
    QString ldName;
    for(int acc=0;acc<accessPoint.size();acc++)
    {
        ldList = xmlhelplib.getChildNodes(iedNode,xpath.arg(accessPoint[acc]));
        for(int i=0;i<ldList.size();i++)
        {
            ldEle =  ldList.at(i).toElement();
            ldName = ldEle.attribute("inst").toUpper();
            if(!(ldName.contains("MU") || ldName.contains("RPIT") || ldName.contains("SVLD") || ldName.contains("GOLD") || ldName.contains("PI")))
            {
                resList.append(ldList.at(i));
            }
        }
    }
    return resList;
}


Pointdef* ImportIED::getPoint(QDomElement pointEle,QDomElement pointLN)
{
    Pointdef* po = new Pointdef;
    po->fc = pointEle.attribute("fc");
    QString pointName = "";
    pointName.append(pointEle.attribute("prefix"))
            .append(pointEle.attribute("lnClass")).append(pointEle.attribute("lnInst")).append("$").append(po->fc);

    if(NULL != pointEle.attribute("doName"))
    {
        pointName.append("$").append(pointEle.attribute("doName"));
    }
    if(NULL != pointEle.attribute("daName"))
    {
        pointName.append("$").append(pointEle.attribute("daName"));
    }

    po->name = pointName.replace(".","$");
    po->desc = getFCDADesc(pointEle,pointLN);
    po->cdc = getCDC(pointEle,pointLN);
    return po;
}

QString ImportIED::getCDC(QDomElement fcda,QDomElement lnEle)
{
    if(lnEle.isNull())
    {
        return "";
    }
    QString cdc = "";
    QString doName = fcda.attribute("doName");
    QString sdoName = "";

    if(doName.contains("."))
    {
        QStringList doList = doName.split(".");
        doName = doList.at(0);
        sdoName = doList.at(1);
    }

    QString lnType = lnEle.attribute("lnType");
    QString lnTypeXPath = QString("LNodeType[@id=%1]/DO[@name=%2]").arg(lnType).arg(doName);

    QDomNode lnTypeNode = xmlhelplib.getChildNode(dataTypeTemplates,lnTypeXPath);

    if(!lnTypeNode.isElement())
    {
        return "";
    }
    QDomElement lnDoEle = lnTypeNode.toElement();

    QString doId = lnDoEle.attribute("type");
    QString doXPath = QString("DOType[@id=%1]").arg(doId);
    QDomNode doTypeNode = xmlhelplib.getChildNode(dataTypeTemplates,doXPath);
    if(!doTypeNode.isElement())
    {
        return "";
    }
    QDomElement doTypeEle = doTypeNode.toElement();

    if(sdoName != "")
    {
        QDomNode sdoNode = xmlhelplib.getChildNode(doTypeEle,QString("SDO[@name=%1]").arg(sdoName));
        if(!sdoNode.isElement())
        {
            return "";
        }
        QString sdoType = sdoNode.toElement().attribute("type");
        QString doXPath1 = QString("DOType[@id=%1]").arg(sdoType);
        doTypeEle = xmlhelplib.getChildNode(dataTypeTemplates,doXPath1).toElement();
    }
    cdc = doTypeEle.attribute("cdc");

    return cdc;
}


QString ImportIED::getFCDADesc(QDomElement fcda,QDomElement lnEle)
{
    if(lnEle.isNull())
    {
        return "";
    }
    QString pointDesc;
    QDomNodeList doiNodes;
    QString doiName = fcda.attribute("doName");
    QString daiName = fcda.attribute("daName");

    if("" != daiName)
    {
        doiName.append(".").append(daiName);
    }

    QDomElement doiEle;
    QList<QString> doiNameList = doiName.split(".");

    doiNodes = lnEle.childNodes();
    pointDesc = lnEle.attribute("desc");

    while(doiNameList.size()>0)
    {
         doiName = doiNameList.at(0);
         for(int i=0;i<doiNodes.size();i++)
         {
             doiEle = doiNodes.at(i).toElement();
             if(doiName == doiEle.attribute("name"))
             {
                 pointDesc = ("" == doiEle.attribute("desc")) ? pointDesc : doiEle.attribute("desc");
                 doiNodes = doiEle.childNodes();
             }
         }
         doiNameList.takeAt(0);
    }

    return pointDesc;
}


QDomElement ImportIED::getPointLN(QDomElement fcda,QHash<QString,QDomNode> lnHash)
{
    QString lnClass = fcda.attribute("lnClass");
    QDomNode lnNode;
    if("LLN0" == lnClass)
    {
        lnNode = lnHash.value("LLN0");
    }
    else
    {
        QString prefix = fcda.attribute("prefix");
        QString lnInst = fcda.attribute("lnInst");
        QString lnXPath = prefix.append(lnClass).append(lnInst);

        lnNode = lnHash.value(lnXPath);
    }
    return lnNode.toElement();
}

LdNode* ImportIED::getLN(QDomNode lnNode)
{
    QDomElement lnE = lnNode.toElement();
    LdNode* ln = new LdNode;
    ln->prefix = lnE.attribute("prefix");
    ln->lnClass = lnE.attribute("lnClass");
    ln->inst = lnE.attribute("inst");
    ln->lnType = lnE.attribute("lnType");
    ln->desc = lnE.attribute("desc");
    if(ln->lnClass == "LLN0")
    {
        ln->desc = "LN0";
    }

    return ln;
}


QList<QDomNode> ImportIED::getPointByDs(QDomNode dsNode)
{
    QList<QDomNode> resList;
    QList<QDomNode> pointList;
    QDomElement pointEle;
    QString fc;
    pointList = xmlhelplib.getChildNodes(dsNode,"FCDA");
    for(int i=0;i<pointList.size();i++)
    {
        pointEle = pointList.at(i).toElement();
        fc = pointEle.attribute("fc");
        resList.append(pointEle);
    }
    return resList;
}




ImportIED::~ImportIED()
{
    delete ui;
}
