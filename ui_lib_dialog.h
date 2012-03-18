/********************************************************************************
** Form generated from reading UI file 'lib_dialog.ui'
**
** Created: Mon Feb 6 20:20:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIB_DIALOG_H
#define UI_LIB_DIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <graph_widget.h>

QT_BEGIN_NAMESPACE

class Ui_Lib_dialog
{
public:
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout;
    QTextEdit *MaxY;
    QSpacerItem *verticalSpacer;
    QTextEdit *LY;
    QSpacerItem *verticalSpacer_2;
    QTextEdit *gridY;
    QSpacerItem *verticalSpacer_4;
    QTextEdit *MinY;
    QSpacerItem *verticalSpacer_3;
    Graph_widget *widget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *MinX;
    QSpacerItem *horizontalSpacer;
    QTextEdit *LX;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *gridX;
    QSpacerItem *horizontalSpacer_3;
    QTextEdit *MaxX;

    void setupUi(QDialog *Lib_dialog)
    {
        if (Lib_dialog->objectName().isEmpty())
            Lib_dialog->setObjectName(QString::fromUtf8("Lib_dialog"));
        Lib_dialog->resize(660, 365);
        gridLayout = new QGridLayout(Lib_dialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_5 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_5, 0, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        MaxY = new QTextEdit(Lib_dialog);
        MaxY->setObjectName(QString::fromUtf8("MaxY"));
        MaxY->setMinimumSize(QSize(70, 20));
        MaxY->setMaximumSize(QSize(70, 20));

        verticalLayout->addWidget(MaxY);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        LY = new QTextEdit(Lib_dialog);
        LY->setObjectName(QString::fromUtf8("LY"));
        LY->setMinimumSize(QSize(70, 20));
        LY->setMaximumSize(QSize(70, 2));

        verticalLayout->addWidget(LY);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        gridY = new QTextEdit(Lib_dialog);
        gridY->setObjectName(QString::fromUtf8("gridY"));
        gridY->setMinimumSize(QSize(70, 20));
        gridY->setMaximumSize(QSize(70, 20));

        verticalLayout->addWidget(gridY);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        MinY = new QTextEdit(Lib_dialog);
        MinY->setObjectName(QString::fromUtf8("MinY"));
        MinY->setMinimumSize(QSize(70, 20));
        MinY->setMaximumSize(QSize(70, 2));

        verticalLayout->addWidget(MinY);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout, 1, 0, 2, 1);

        widget = new Graph_widget(Lib_dialog);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(400, 200));
        widget->setMaximumSize(QSize(100000, 600000));
        widget->setMouseTracking(true);

        gridLayout->addWidget(widget, 1, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        MinX = new QTextEdit(Lib_dialog);
        MinX->setObjectName(QString::fromUtf8("MinX"));
        MinX->setMinimumSize(QSize(70, 20));
        MinX->setMaximumSize(QSize(70, 20));

        horizontalLayout->addWidget(MinX);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        LX = new QTextEdit(Lib_dialog);
        LX->setObjectName(QString::fromUtf8("LX"));
        LX->setMinimumSize(QSize(70, 20));
        LX->setMaximumSize(QSize(70, 20));

        horizontalLayout->addWidget(LX);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        gridX = new QTextEdit(Lib_dialog);
        gridX->setObjectName(QString::fromUtf8("gridX"));
        gridX->setMinimumSize(QSize(70, 20));
        gridX->setMaximumSize(QSize(70, 20));

        horizontalLayout->addWidget(gridX);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        MaxX = new QTextEdit(Lib_dialog);
        MaxX->setObjectName(QString::fromUtf8("MaxX"));
        MaxX->setMinimumSize(QSize(70, 20));
        MaxX->setMaximumSize(QSize(70, 20));

        horizontalLayout->addWidget(MaxX);


        gridLayout->addLayout(horizontalLayout, 2, 1, 1, 1);


        retranslateUi(Lib_dialog);

        QMetaObject::connectSlotsByName(Lib_dialog);
    } // setupUi

    void retranslateUi(QDialog *Lib_dialog)
    {
        Lib_dialog->setWindowTitle(QApplication::translate("Lib_dialog", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Lib_dialog: public Ui_Lib_dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIB_DIALOG_H
