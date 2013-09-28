#ifndef IMPDELEGATE_H
#define IMPDELEGATE_H
#include <QtGui/QStyledItemDelegate>
#include <QLineEdit>
#include <QComboBox>
#include <QTextOption>
#include <QPainter>

#include "impaccpoint.h"

#define OPTYPE_MODIFY             0
#define OPTYPE_COVER              1
#define OPTYPE_INSERT             2

class ImpDelegate : public QStyledItemDelegate
{
    Q_OBJECT

public:

    ImpDelegate(QObject *paren=0);
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const;

    ImpAccPoint *impAccPointDlg;

private slots:
    void commitAndCloseEditor();

};

#endif // IMPDELEGATE_H
