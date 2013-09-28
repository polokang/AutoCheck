#include "configdlg.h"

ConfigDlg::ConfigDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfigDlg)
{
    ui->setupUi(this);

    xmlFile = ".";
    excelPath = ".";

    connect(ui->impICD,SIGNAL(clicked()),this,SLOT(impICD()));
    connect(ui->impEXC,SIGNAL(clicked()),this,SLOT(impExcel()));
    connect(ui->tabEXC,SIGNAL(currentChanged(int)),this,SLOT(dymicICDTab(int)));
    connect(ui->tabICD,SIGNAL(currentChanged(int)),this,SLOT(dymicEXCTab(int)));
    connect(ui->buttonBox,SIGNAL(accepted()),this,SLOT(setConfList()));

    ui->impICD->setEnabled(false);
}


void ConfigDlg::setConfList()
{
//    confList.append();
}

void ConfigDlg::dymicICDTab(int ind)
{
    ui->tabICD->setCurrentIndex(ind);
}

void ConfigDlg::dymicEXCTab(int ind)
{
    ui->tabEXC->setCurrentIndex(ind);
}


void ConfigDlg::impICD()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Xml"), xmlFile, tr("XML files (*.xml *.scd *.icd *.cid)"));
    if(path.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."),tr("Ok"));
    }
    else
    {
        ImportIED *imp = new ImportIED();
        imp->parseFile(path);
        if(imp->exec() == QDialog::Accepted)
        {
            xmlFile = path;
            QList<Pointdef*> yxList;
            QList<Pointdef*> ycList;
            QList<Pointdef*> ykList;
            foreach (Pointdef* point, imp->allPointList)
            {
                if(point->fc == "ST")
                {
                    ycList.append(point);
                }
                else if (point->fc == "MX")
                {
                    yxList.append(point);
                }
                else if (point->fc == "CO")
                {
                    ykList.append(point);
                }
            }

            //填写表格
            ui->iTable_YX->setRowCount(yxList.size());
            ui->iTable_YC->setRowCount(ycList.size());
            ui->iTable_YK->setRowCount(ykList.size());
            for(int i=0;i<yxList.size();i++)
            {
                ui->iTable_YX->setItem(i,0,new QTableWidgetItem(yxList.at(i)->name));
                ui->iTable_YX->setItem(i,1,new QTableWidgetItem(yxList.at(i)->desc));
            }
            for(int i=0;i<ycList.size();i++)
            {
                ui->iTable_YC->setItem(i,0,new QTableWidgetItem(ycList.at(i)->name));
                ui->iTable_YC->setItem(i,1,new QTableWidgetItem(ycList.at(i)->desc));
            }
            for(int i=0;i<ykList.size();i++)
            {
                ui->iTable_YK->setItem(i,0,new QTableWidgetItem(ykList.at(i)->name));
                ui->iTable_YK->setItem(i,1,new QTableWidgetItem(ykList.at(i)->desc));
            }

            ui->iTable_YX->resizeColumnsToContents();
            ui->iTable_YC->resizeColumnsToContents();
            ui->iTable_YK->resizeColumnsToContents();

            ui->iTable_YX->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->iTable_YC->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->iTable_YK->setSelectionBehavior(QAbstractItemView::SelectRows);

            curIndex_YX = 0;
            curIndex_YC = 0;
            curIndex_YK = 0;

            connect(ui->iTable_YX,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(dymicPoint(QTableWidgetItem*)));
            connect(ui->iTable_YC,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(dymicPoint(QTableWidgetItem*)));
            connect(ui->iTable_YK,SIGNAL(itemDoubleClicked(QTableWidgetItem*)),this,SLOT(dymicPoint(QTableWidgetItem*)));

        }
    }
}


void ConfigDlg::dymicPoint(QTableWidgetItem* item)
{
    QString name = item->data(Qt::DisplayRole).toString();
    if(ui->tabEXC->currentIndex() == 0)
    {
        ui->eTable_YX->setCurrentCell(curIndex_YX,1,QItemSelectionModel::SelectCurrent);
        ui->eTable_YX->setItem(curIndex_YX,1,new QTableWidgetItem(name));
        if(curIndex_YX < ui->eTable_YX->rowCount())
        {
            curIndex_YX++;
        }
    }
    else if(ui->tabEXC->currentIndex() == 1)
    {
        ui->eTable_YC->setCurrentCell(curIndex_YC,1,QItemSelectionModel::SelectCurrent);
        ui->eTable_YC->setItem(curIndex_YC,1,new QTableWidgetItem(name));
        if(curIndex_YC < ui->eTable_YC->rowCount())
        {
            curIndex_YC++;
        }
    }
    else if(ui->tabEXC->currentIndex() == 2)
    {
        ui->eTable_YK->setCurrentCell(curIndex_YK,1,QItemSelectionModel::SelectCurrent);
        ui->eTable_YK->setItem(curIndex_YK,1,new QTableWidgetItem(name));
        if(curIndex_YK < ui->eTable_YK->rowCount())
        {
            curIndex_YK++;
        }
    }
}

void ConfigDlg::impExcel()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open xls"), excelPath, tr("XLS files (*.xls)"));
    if(path.length() == 0)
    {
        QMessageBox::information(NULL, tr("Path"), tr("You didn't select any files."),tr("Ok"));
    }
    else
    {
        ExcelEngine excel; //创建excl对象
        excel.Open(path,1,false); //打开指定的xls文件的指定sheet，且指定是否可见
        if(excel.IsValid())
        {
            //获取 excel数据
            UINT row = excel.GetRowCount();
            for(UINT i=2;i<=row;i++)
            {
                QString name = excel.GetCellData(i,2).toString();
                QString type = excel.GetCellData(i,3).toString().trimmed();

                if(!name.isEmpty() || !type.isEmpty())
                {
                    Pointdef* point = new Pointdef;
                    point->name = name;
                    point->fc = type;

                    if(type == YX)
                    {
                        confList_yx.append(point);
                    }
                    else if(type == YC)
                    {
                        confList_yc.append(point);
                    }
                    else if(type == YK)
                    {
                        confList_yk.append(point);
                    }
                }
            }
            excel.Close();

            //填写表格
            ui->eTable_YX->setRowCount(confList_yx.size());
            ui->eTable_YC->setRowCount(confList_yc.size());
            ui->eTable_YK->setRowCount(confList_yk.size());
            for(int i=0;i<confList_yx.size();i++)
            {                
                ui->eTable_YX->setItem(i,0,new QTableWidgetItem(confList_yx.at(i)->name));
            }
            for(int i=0;i<confList_yc.size();i++)
            {                
                ui->eTable_YC->setItem(i,0,new QTableWidgetItem(confList_yc.at(i)->name));
            }
            for(int i=0;i<confList_yk.size();i++)
            {                
                ui->eTable_YK->setItem(i,0,new QTableWidgetItem(confList_yk.at(i)->name));
            }

            ui->eTable_YX->resizeColumnsToContents();
            ui->eTable_YC->resizeColumnsToContents();
            ui->eTable_YK->resizeColumnsToContents();

            ui->impICD->setEnabled(true);
        }

    }
}

ConfigDlg::~ConfigDlg()
{
    delete ui;
}
