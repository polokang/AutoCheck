#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mainToolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    ui->mainToolBar->addAction(ui->action_config);
    ui->mainToolBar->addAction(ui->action_download);

    configDlg = new ConfigDlg();

    ui->action_download->setEnabled(false);

    connect(ui->action_config,SIGNAL(triggered()),this,SLOT(startCfg()));
}

void MainWindow::startCfg()
{
    if(configDlg->exec() == QDialog::Accepted)
    {
//        qDebug()<<configDlg->ui->eTable_YC->item(0,0)->data(Qt::DisplayRole);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
