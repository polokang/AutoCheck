/********************************************************************************
** Form generated from reading UI file 'importied.ui'
**
** Created: Fri Sep 27 16:09:50 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPORTIED_H
#define UI_IMPORTIED_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_ImportIED
{
public:
    QGridLayout *gridLayout;
    QTableWidget *iedTable;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *submitBtn;
    QPushButton *cancelBtn;

    void setupUi(QDialog *ImportIED)
    {
        if (ImportIED->objectName().isEmpty())
            ImportIED->setObjectName(QString::fromUtf8("ImportIED"));
        ImportIED->resize(750, 520);
        gridLayout = new QGridLayout(ImportIED);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        iedTable = new QTableWidget(ImportIED);
        if (iedTable->columnCount() < 8)
            iedTable->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        iedTable->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        iedTable->setObjectName(QString::fromUtf8("iedTable"));
        iedTable->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iedTable->sizePolicy().hasHeightForWidth());
        iedTable->setSizePolicy(sizePolicy);
        iedTable->setTextElideMode(Qt::ElideMiddle);
        iedTable->horizontalHeader()->setVisible(true);
        iedTable->horizontalHeader()->setCascadingSectionResizes(false);
        iedTable->horizontalHeader()->setDefaultSectionSize(45);
        iedTable->horizontalHeader()->setHighlightSections(false);
        iedTable->horizontalHeader()->setStretchLastSection(true);
        iedTable->verticalHeader()->setVisible(false);
        iedTable->verticalHeader()->setHighlightSections(true);

        gridLayout->addWidget(iedTable, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        submitBtn = new QPushButton(ImportIED);
        submitBtn->setObjectName(QString::fromUtf8("submitBtn"));

        horizontalLayout->addWidget(submitBtn);

        cancelBtn = new QPushButton(ImportIED);
        cancelBtn->setObjectName(QString::fromUtf8("cancelBtn"));

        horizontalLayout->addWidget(cancelBtn);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(ImportIED);

        QMetaObject::connectSlotsByName(ImportIED);
    } // setupUi

    void retranslateUi(QDialog *ImportIED)
    {
        ImportIED->setWindowTitle(QApplication::translate("ImportIED", "IED List Dialog", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = iedTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ImportIED", "Select", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = iedTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ImportIED", "Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = iedTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ImportIED", "Descript", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = iedTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ImportIED", "Manufacturer", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = iedTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ImportIED", "A Net", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = iedTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ImportIED", "B Net", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = iedTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ImportIED", "AccPoint", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = iedTable->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ImportIED", "AccessPoint", 0, QApplication::UnicodeUTF8));
        submitBtn->setText(QApplication::translate("ImportIED", "Submit", 0, QApplication::UnicodeUTF8));
        cancelBtn->setText(QApplication::translate("ImportIED", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImportIED: public Ui_ImportIED {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPORTIED_H
