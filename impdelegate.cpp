#include "impdelegate.h"

ImpDelegate::ImpDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    impAccPointDlg = new ImpAccPoint();
}


//双击表格前，初始化表格时
void ImpDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}


//双击表格后构造编辑器
QWidget *ImpDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QLineEdit *lineEdit = new QLineEdit(parent);

    QString curAcc = index.data(Qt::DisplayRole).toString().trimmed();
    QString allAcc = index.data(Qt::UserRole).toString().trimmed();

    switch(index.column())
    {
    case 6:
    {        
        impAccPointDlg->setAccPointCheckBox(curAcc,allAcc);
        if(impAccPointDlg->exec() == QDialog::Accepted)
        {
            QString acc = impAccPointDlg->accPointsTxt;
            lineEdit->setText(acc);
        }

        return lineEdit;
    }    
    default:
    {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
    }
}


void ImpDelegate::commitAndCloseEditor()
{
    QComboBox *edit = qobject_cast<QComboBox *>(sender());
    emit commitData(edit);
    emit closeEditor(edit);
}

//编辑时数据
void ImpDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column() == 6) //已选访问点
    {
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
        lineEdit->setText(impAccPointDlg->accPointsTxt);
    }    
    else
    {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}


//编辑完成后数据设置
void ImpDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.column() == 6) //已选访问点
    {
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
        lineEdit->setText(impAccPointDlg->accPointsTxt);
        model->setData(index, lineEdit->displayText());
    }    
    else
    {
        QStyledItemDelegate::setModelData(editor, model, index);
    }

}
