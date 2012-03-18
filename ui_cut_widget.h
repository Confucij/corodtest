/********************************************************************************
** Form generated from reading UI file 'cut_widget.ui'
**
** Created: Mon Feb 6 20:20:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUT_WIDGET_H
#define UI_CUT_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cut_widget
{
public:
    QGridLayout *gridLayout;
    QLabel *display_Label;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *pushButton;
    QVBoxLayout *verticalLayout;
    QRadioButton *x_rButton;
    QRadioButton *y_rButton;
    QDoubleSpinBox *pos_sBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Cut_widget)
    {
        if (Cut_widget->objectName().isEmpty())
            Cut_widget->setObjectName(QString::fromUtf8("Cut_widget"));
        Cut_widget->resize(641, 466);
        gridLayout = new QGridLayout(Cut_widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        display_Label = new QLabel(Cut_widget);
        display_Label->setObjectName(QString::fromUtf8("display_Label"));
        display_Label->setMinimumSize(QSize(400, 400));

        gridLayout->addWidget(display_Label, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pushButton = new QPushButton(Cut_widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        x_rButton = new QRadioButton(Cut_widget);
        x_rButton->setObjectName(QString::fromUtf8("x_rButton"));
        x_rButton->setChecked(true);

        verticalLayout->addWidget(x_rButton);

        y_rButton = new QRadioButton(Cut_widget);
        y_rButton->setObjectName(QString::fromUtf8("y_rButton"));

        verticalLayout->addWidget(y_rButton);


        verticalLayout_2->addLayout(verticalLayout);


        verticalLayout_3->addLayout(verticalLayout_2);

        pos_sBox = new QDoubleSpinBox(Cut_widget);
        pos_sBox->setObjectName(QString::fromUtf8("pos_sBox"));

        verticalLayout_3->addWidget(pos_sBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        retranslateUi(Cut_widget);
        QObject::connect(pos_sBox, SIGNAL(valueChanged(double)), Cut_widget, SLOT(draw_cut()));

        QMetaObject::connectSlotsByName(Cut_widget);
    } // setupUi

    void retranslateUi(QWidget *Cut_widget)
    {
        Cut_widget->setWindowTitle(QApplication::translate("Cut_widget", "Form", 0, QApplication::UnicodeUTF8));
        display_Label->setText(QString());
        pushButton->setText(QApplication::translate("Cut_widget", "Save", 0, QApplication::UnicodeUTF8));
        x_rButton->setText(QApplication::translate("Cut_widget", "X", 0, QApplication::UnicodeUTF8));
        y_rButton->setText(QApplication::translate("Cut_widget", "Y", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Cut_widget: public Ui_Cut_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUT_WIDGET_H
