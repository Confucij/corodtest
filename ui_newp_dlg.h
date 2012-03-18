/********************************************************************************
** Form generated from reading UI file 'newp_dlg.ui'
**
** Created: Mon Feb 6 20:20:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWP_DLG_H
#define UI_NEWP_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Newp_dlg
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *width_label;
    QDoubleSpinBox *width_SpinBox;
    QComboBox *width_sizeBox;
    QHBoxLayout *horizontalLayout;
    QLabel *height_label;
    QDoubleSpinBox *height_SpinBox;
    QComboBox *height_sizeBox;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QComboBox *material_Box;
    QPushButton *add_Button;
    QSpacerItem *verticalSpacer;
    QLabel *pic_label;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Newp_dlg)
    {
        if (Newp_dlg->objectName().isEmpty())
            Newp_dlg->setObjectName(QString::fromUtf8("Newp_dlg"));
        Newp_dlg->resize(610, 450);
        Newp_dlg->setMinimumSize(QSize(500, 450));
        Newp_dlg->setMaximumSize(QSize(610, 450));
        gridLayout = new QGridLayout(Newp_dlg);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        splitter = new QSplitter(Newp_dlg);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        layoutWidget = new QWidget(splitter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        width_label = new QLabel(layoutWidget);
        width_label->setObjectName(QString::fromUtf8("width_label"));

        horizontalLayout_2->addWidget(width_label);

        width_SpinBox = new QDoubleSpinBox(layoutWidget);
        width_SpinBox->setObjectName(QString::fromUtf8("width_SpinBox"));

        horizontalLayout_2->addWidget(width_SpinBox);

        width_sizeBox = new QComboBox(layoutWidget);
        width_sizeBox->setObjectName(QString::fromUtf8("width_sizeBox"));
        width_sizeBox->setMaximumSize(QSize(60, 50));

        horizontalLayout_2->addWidget(width_sizeBox);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        height_label = new QLabel(layoutWidget);
        height_label->setObjectName(QString::fromUtf8("height_label"));

        horizontalLayout->addWidget(height_label);

        height_SpinBox = new QDoubleSpinBox(layoutWidget);
        height_SpinBox->setObjectName(QString::fromUtf8("height_SpinBox"));

        horizontalLayout->addWidget(height_SpinBox);

        height_sizeBox = new QComboBox(layoutWidget);
        height_sizeBox->setObjectName(QString::fromUtf8("height_sizeBox"));
        height_sizeBox->setMaximumSize(QSize(60, 50));

        horizontalLayout->addWidget(height_sizeBox);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        material_Box = new QComboBox(layoutWidget);
        material_Box->setObjectName(QString::fromUtf8("material_Box"));
        material_Box->setMinimumSize(QSize(150, 25));
        material_Box->setMaximumSize(QSize(200, 25));

        horizontalLayout_3->addWidget(material_Box);


        verticalLayout_2->addLayout(horizontalLayout_3);

        splitter->addWidget(layoutWidget);
        add_Button = new QPushButton(splitter);
        add_Button->setObjectName(QString::fromUtf8("add_Button"));
        add_Button->setMinimumSize(QSize(150, 0));
        add_Button->setMaximumSize(QSize(150, 25));
        splitter->addWidget(add_Button);

        verticalLayout_3->addWidget(splitter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_4->addLayout(verticalLayout_3);

        pic_label = new QLabel(Newp_dlg);
        pic_label->setObjectName(QString::fromUtf8("pic_label"));
        pic_label->setMinimumSize(QSize(350, 300));
        pic_label->setMaximumSize(QSize(350, 250));
        pic_label->setAutoFillBackground(true);

        horizontalLayout_4->addWidget(pic_label);


        verticalLayout_4->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        buttonBox = new QDialogButtonBox(Newp_dlg);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_4->addWidget(buttonBox);


        gridLayout->addLayout(verticalLayout_4, 0, 0, 1, 1);


        retranslateUi(Newp_dlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), Newp_dlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Newp_dlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(Newp_dlg);
    } // setupUi

    void retranslateUi(QDialog *Newp_dlg)
    {
        Newp_dlg->setWindowTitle(QApplication::translate("Newp_dlg", "Image import", 0, QApplication::UnicodeUTF8));
        width_label->setText(QApplication::translate("Newp_dlg", "Width", 0, QApplication::UnicodeUTF8));
        width_sizeBox->clear();
        width_sizeBox->insertItems(0, QStringList()
         << QApplication::translate("Newp_dlg", "um", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Newp_dlg", "mm", 0, QApplication::UnicodeUTF8)
        );
        height_label->setText(QApplication::translate("Newp_dlg", "Height", 0, QApplication::UnicodeUTF8));
        height_sizeBox->clear();
        height_sizeBox->insertItems(0, QStringList()
         << QApplication::translate("Newp_dlg", "um", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("Newp_dlg", "mm", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("Newp_dlg", "\320\234\320\260\321\202\320\265\321\200\320\270\320\260\320\273", 0, QApplication::UnicodeUTF8));
        add_Button->setText(QApplication::translate("Newp_dlg", "Add new material", 0, QApplication::UnicodeUTF8));
        pic_label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Newp_dlg: public Ui_Newp_dlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWP_DLG_H
