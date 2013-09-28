/********************************************************************************
** Form generated from reading UI file 'configdlg.ui'
**
** Created: Fri Sep 27 16:09:47 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGDLG_H
#define UI_CONFIGDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDlg
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabEXC;
    QWidget *eTab_YX;
    QGridLayout *gridLayout_2;
    QTableWidget *eTable_YX;
    QWidget *eTab_YC;
    QGridLayout *gridLayout_4;
    QTableWidget *eTable_YC;
    QWidget *eTab_YK;
    QGridLayout *gridLayout_6;
    QTableWidget *eTable_YK;
    QTabWidget *tabICD;
    QWidget *iTab_YX;
    QGridLayout *gridLayout_3;
    QTableWidget *iTable_YX;
    QWidget *iTab_YC;
    QGridLayout *gridLayout_5;
    QTableWidget *iTable_YC;
    QWidget *iTab_YK;
    QGridLayout *gridLayout_7;
    QTableWidget *iTable_YK;
    QHBoxLayout *horizontalLayout;
    QPushButton *impEXC;
    QSpacerItem *horizontalSpacer;
    QPushButton *impICD;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ConfigDlg)
    {
        if (ConfigDlg->objectName().isEmpty())
            ConfigDlg->setObjectName(QString::fromUtf8("ConfigDlg"));
        ConfigDlg->resize(760, 510);
        ConfigDlg->setAcceptDrops(true);
        gridLayout = new QGridLayout(ConfigDlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabEXC = new QTabWidget(ConfigDlg);
        tabEXC->setObjectName(QString::fromUtf8("tabEXC"));
        tabEXC->setAcceptDrops(true);
        eTab_YX = new QWidget();
        eTab_YX->setObjectName(QString::fromUtf8("eTab_YX"));
        gridLayout_2 = new QGridLayout(eTab_YX);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        eTable_YX = new QTableWidget(eTab_YX);
        if (eTable_YX->columnCount() < 2)
            eTable_YX->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        eTable_YX->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        eTable_YX->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        eTable_YX->setObjectName(QString::fromUtf8("eTable_YX"));
        eTable_YX->setAcceptDrops(true);

        gridLayout_2->addWidget(eTable_YX, 0, 0, 1, 1);

        tabEXC->addTab(eTab_YX, QString());
        eTab_YC = new QWidget();
        eTab_YC->setObjectName(QString::fromUtf8("eTab_YC"));
        gridLayout_4 = new QGridLayout(eTab_YC);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        eTable_YC = new QTableWidget(eTab_YC);
        if (eTable_YC->columnCount() < 2)
            eTable_YC->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        eTable_YC->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        eTable_YC->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        eTable_YC->setObjectName(QString::fromUtf8("eTable_YC"));

        gridLayout_4->addWidget(eTable_YC, 0, 0, 1, 1);

        tabEXC->addTab(eTab_YC, QString());
        eTab_YK = new QWidget();
        eTab_YK->setObjectName(QString::fromUtf8("eTab_YK"));
        gridLayout_6 = new QGridLayout(eTab_YK);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        eTable_YK = new QTableWidget(eTab_YK);
        if (eTable_YK->columnCount() < 2)
            eTable_YK->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        eTable_YK->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        eTable_YK->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        eTable_YK->setObjectName(QString::fromUtf8("eTable_YK"));

        gridLayout_6->addWidget(eTable_YK, 0, 0, 1, 1);

        tabEXC->addTab(eTab_YK, QString());

        gridLayout->addWidget(tabEXC, 0, 0, 1, 1);

        tabICD = new QTabWidget(ConfigDlg);
        tabICD->setObjectName(QString::fromUtf8("tabICD"));
        tabICD->setAcceptDrops(true);
        iTab_YX = new QWidget();
        iTab_YX->setObjectName(QString::fromUtf8("iTab_YX"));
        gridLayout_3 = new QGridLayout(iTab_YX);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        iTable_YX = new QTableWidget(iTab_YX);
        if (iTable_YX->columnCount() < 2)
            iTable_YX->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        iTable_YX->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        iTable_YX->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        iTable_YX->setObjectName(QString::fromUtf8("iTable_YX"));
        iTable_YX->setMouseTracking(true);
        iTable_YX->setAcceptDrops(true);

        gridLayout_3->addWidget(iTable_YX, 0, 0, 1, 1);

        tabICD->addTab(iTab_YX, QString());
        iTab_YC = new QWidget();
        iTab_YC->setObjectName(QString::fromUtf8("iTab_YC"));
        gridLayout_5 = new QGridLayout(iTab_YC);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        iTable_YC = new QTableWidget(iTab_YC);
        if (iTable_YC->columnCount() < 2)
            iTable_YC->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        iTable_YC->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        iTable_YC->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        iTable_YC->setObjectName(QString::fromUtf8("iTable_YC"));

        gridLayout_5->addWidget(iTable_YC, 0, 0, 1, 1);

        tabICD->addTab(iTab_YC, QString());
        iTab_YK = new QWidget();
        iTab_YK->setObjectName(QString::fromUtf8("iTab_YK"));
        gridLayout_7 = new QGridLayout(iTab_YK);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        iTable_YK = new QTableWidget(iTab_YK);
        if (iTable_YK->columnCount() < 2)
            iTable_YK->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        iTable_YK->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        iTable_YK->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        iTable_YK->setObjectName(QString::fromUtf8("iTable_YK"));

        gridLayout_7->addWidget(iTable_YK, 0, 0, 1, 1);

        tabICD->addTab(iTab_YK, QString());

        gridLayout->addWidget(tabICD, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        impEXC = new QPushButton(ConfigDlg);
        impEXC->setObjectName(QString::fromUtf8("impEXC"));

        horizontalLayout->addWidget(impEXC);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        impICD = new QPushButton(ConfigDlg);
        impICD->setObjectName(QString::fromUtf8("impICD"));

        horizontalLayout->addWidget(impICD);

        buttonBox = new QDialogButtonBox(ConfigDlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);


        retranslateUi(ConfigDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDlg, SLOT(reject()));

        tabEXC->setCurrentIndex(0);
        tabICD->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDlg);
    } // setupUi

    void retranslateUi(QDialog *ConfigDlg)
    {
        ConfigDlg->setWindowTitle(QApplication::translate("ConfigDlg", "Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = eTable_YX->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ConfigDlg", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = eTable_YX->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ConfigDlg", "\345\205\263\350\201\224\345\217\266\345\255\220\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        tabEXC->setTabText(tabEXC->indexOf(eTab_YX), QApplication::translate("ConfigDlg", "\351\201\245\344\277\241", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = eTable_YC->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("ConfigDlg", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = eTable_YC->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("ConfigDlg", "\345\205\263\350\201\224\345\217\266\345\255\220\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        tabEXC->setTabText(tabEXC->indexOf(eTab_YC), QApplication::translate("ConfigDlg", "\351\201\245\346\265\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = eTable_YK->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("ConfigDlg", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = eTable_YK->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("ConfigDlg", "\345\205\263\350\201\224\345\217\266\345\255\220\350\212\202\347\202\271", 0, QApplication::UnicodeUTF8));
        tabEXC->setTabText(tabEXC->indexOf(eTab_YK), QApplication::translate("ConfigDlg", "\351\201\245\346\216\247", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = iTable_YX->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("ConfigDlg", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = iTable_YX->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("ConfigDlg", "\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        tabICD->setTabText(tabICD->indexOf(iTab_YX), QApplication::translate("ConfigDlg", "\351\201\245\344\277\241", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = iTable_YC->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("ConfigDlg", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = iTable_YC->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("ConfigDlg", "\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        tabICD->setTabText(tabICD->indexOf(iTab_YC), QApplication::translate("ConfigDlg", "\351\201\245\346\265\213", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = iTable_YK->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("ConfigDlg", "\345\220\215\347\247\260", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = iTable_YK->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("ConfigDlg", "\346\217\217\350\277\260", 0, QApplication::UnicodeUTF8));
        tabICD->setTabText(tabICD->indexOf(iTab_YK), QApplication::translate("ConfigDlg", "\351\201\245\346\216\247", 0, QApplication::UnicodeUTF8));
        impEXC->setText(QApplication::translate("ConfigDlg", "\345\257\274\345\205\245Excel\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        impICD->setText(QApplication::translate("ConfigDlg", "\345\257\274\345\205\245\346\250\241\345\236\213\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ConfigDlg: public Ui_ConfigDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDLG_H
