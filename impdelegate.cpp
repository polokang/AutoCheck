#include "impdelegate.h"

ImpDelegate::ImpDelegate(QObject *parent) : QStyledItemDelegate(parent)
{
    impAccPointDlg = new ImpAccPoint();
}


//˫�����ǰ����ʼ�����ʱ
void ImpDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QStyledItemDelegate::paint(painter, option, index);
}


//˫��������༭��
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

//�༭ʱ����
void ImpDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    if(index.column() == 6) //��ѡ���ʵ�
    {
        QLineEdit *lineEdit = qobject_cast<QLineEdit *>(editor);
        lineEdit->setText(impAccPointDlg->accPointsTxt);
    }    
    else
    {
        QStyledItemDelegate::setEditorData(editor, index);
    }
}


//�༭��ɺ���������
void ImpDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    if(index.column() == 6) //��ѡ���ʵ�
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
