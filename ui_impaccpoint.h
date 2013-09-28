/********************************************************************************
** Form generated from reading UI file 'impaccpoint.ui'
**
** Created: Fri Sep 27 16:09:54 2013
**      by: Qt User Interface Compiler version 4.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMPACCPOINT_H
#define UI_IMPACCPOINT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ImpAccPoint
{
public:
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImpAccPoint)
    {
        if (ImpAccPoint->objectName().isEmpty())
            ImpAccPoint->setObjectName(QString::fromUtf8("ImpAccPoint"));
        ImpAccPoint->resize(175, 155);
        verticalLayout = new QVBoxLayout(ImpAccPoint);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(ImpAccPoint);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);

        buttonBox = new QDialogButtonBox(ImpAccPoint);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(ImpAccPoint);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImpAccPoint, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImpAccPoint, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImpAccPoint);
    } // setupUi

    void retranslateUi(QDialog *ImpAccPoint)
    {
        ImpAccPoint->setWindowTitle(QApplication::translate("ImpAccPoint", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImpAccPoint: public Ui_ImpAccPoint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMPACCPOINT_H
