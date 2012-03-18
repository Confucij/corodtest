/********************************************************************************
** Form generated from reading UI file 'window.ui'
**
** Created: Mon Feb 6 20:20:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOW_H
#define UI_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Window
{
public:
    QAction *action_OpenProj;
    QAction *action_SaveProj;
    QAction *action_NewProj;
    QAction *action_Exit;
    QAction *action;
    QAction *action_2;
    QAction *action_Close;
    QAction *action_Import;
    QAction *action_Lib;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *graphic_tab;
    QWidget *tab_2;
    QGridLayout *gridLayout;
    QVBoxLayout *tab3d_layout;
    GLWidget *glWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QSlider *xSlider;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QSlider *ySlider;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_4;
    QSlider *zSlider;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_7;
    QSlider *angleSlider;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QSlider *zoomSlider;
    QLabel *label_4;
    QListWidget *itemsList;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_3;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Window)
    {
        if (Window->objectName().isEmpty())
            Window->setObjectName(QString::fromUtf8("Window"));
        Window->resize(735, 425);
        Window->setMaximumSize(QSize(1200, 1000));
        action_OpenProj = new QAction(Window);
        action_OpenProj->setObjectName(QString::fromUtf8("action_OpenProj"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/open.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_OpenProj->setIcon(icon);
        action_OpenProj->setIconVisibleInMenu(true);
        action_SaveProj = new QAction(Window);
        action_SaveProj->setObjectName(QString::fromUtf8("action_SaveProj"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_SaveProj->setIcon(icon1);
        action_SaveProj->setIconVisibleInMenu(true);
        action_NewProj = new QAction(Window);
        action_NewProj->setObjectName(QString::fromUtf8("action_NewProj"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_NewProj->setIcon(icon2);
        action_NewProj->setIconVisibleInMenu(true);
        action_Exit = new QAction(Window);
        action_Exit->setObjectName(QString::fromUtf8("action_Exit"));
        action = new QAction(Window);
        action->setObjectName(QString::fromUtf8("action"));
        action_2 = new QAction(Window);
        action_2->setObjectName(QString::fromUtf8("action_2"));
        action_Close = new QAction(Window);
        action_Close->setObjectName(QString::fromUtf8("action_Close"));
        action_Import = new QAction(Window);
        action_Import->setObjectName(QString::fromUtf8("action_Import"));
        action_Lib = new QAction(Window);
        action_Lib->setObjectName(QString::fromUtf8("action_Lib"));
        centralwidget = new QWidget(Window);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        graphic_tab = new QTabWidget(centralwidget);
        graphic_tab->setObjectName(QString::fromUtf8("graphic_tab"));
        graphic_tab->setEnabled(true);
        graphic_tab->setMinimumSize(QSize(0, 100));
        graphic_tab->setMaximumSize(QSize(800, 600));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout = new QGridLayout(tab_2);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tab3d_layout = new QVBoxLayout();
        tab3d_layout->setObjectName(QString::fromUtf8("tab3d_layout"));
        tab3d_layout->setSizeConstraint(QLayout::SetMaximumSize);
        glWidget = new GLWidget(tab_2);
        glWidget->setObjectName(QString::fromUtf8("glWidget"));

        tab3d_layout->addWidget(glWidget);


        gridLayout->addLayout(tab3d_layout, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        xSlider = new QSlider(tab_2);
        xSlider->setObjectName(QString::fromUtf8("xSlider"));
        xSlider->setMaximumSize(QSize(500, 16777215));
        xSlider->setMinimum(0);
        xSlider->setMaximum(1000);
        xSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(xSlider);

        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        ySlider = new QSlider(tab_2);
        ySlider->setObjectName(QString::fromUtf8("ySlider"));
        ySlider->setMaximumSize(QSize(500, 16777215));
        ySlider->setMinimum(0);
        ySlider->setMaximum(300);
        ySlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(ySlider);

        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        zSlider = new QSlider(tab_2);
        zSlider->setObjectName(QString::fromUtf8("zSlider"));
        zSlider->setMaximumSize(QSize(500, 16777215));
        zSlider->setMinimum(0);
        zSlider->setMaximum(4000);
        zSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(zSlider);

        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        angleSlider = new QSlider(tab_2);
        angleSlider->setObjectName(QString::fromUtf8("angleSlider"));
        angleSlider->setMaximum(255);
        angleSlider->setValue(50);
        angleSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(angleSlider);

        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        zoomSlider = new QSlider(tab_2);
        zoomSlider->setObjectName(QString::fromUtf8("zoomSlider"));
        zoomSlider->setMinimum(-180);
        zoomSlider->setMaximum(180);
        zoomSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(zoomSlider);

        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 1, 0, 1, 1);

        graphic_tab->addTab(tab_2, QString());

        verticalLayout_2->addWidget(graphic_tab);

        itemsList = new QListWidget(centralwidget);
        itemsList->setObjectName(QString::fromUtf8("itemsList"));
        itemsList->setMaximumSize(QSize(800, 16777215));
        itemsList->setFlow(QListView::TopToBottom);
        itemsList->setResizeMode(QListView::Adjust);
        itemsList->setViewMode(QListView::IconMode);

        verticalLayout_2->addWidget(itemsList);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_2);

        Window->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Window);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 735, 22));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        Window->setMenuBar(menubar);
        statusbar = new QStatusBar(Window);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Window->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(action_NewProj);
        menu->addAction(action_OpenProj);
        menu->addAction(action_SaveProj);
        menu->addSeparator();
        menu->addAction(action_Close);
        menu->addSeparator();
        menu->addAction(action_Import);
        menu->addSeparator();
        menu->addAction(action_Exit);
        menu_3->addAction(action);
        menu_3->addAction(action_2);
        menu_3->addAction(action_Lib);

        retranslateUi(Window);

        graphic_tab->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Window);
    } // setupUi

    void retranslateUi(QMainWindow *Window)
    {
        Window->setWindowTitle(QApplication::translate("Window", "MainWindow", 0, QApplication::UnicodeUTF8));
        action_OpenProj->setText(QApplication::translate("Window", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        action_OpenProj->setStatusTip(QApplication::translate("Window", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \321\201\321\203\321\211\320\265\321\201\321\202\320\262\321\203\321\216\321\211\320\270\320\271 \320\277\321\200\320\276\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_SaveProj->setText(QApplication::translate("Window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\277\321\200\320\276\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        action_SaveProj->setStatusTip(QApplication::translate("Window", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\262 \321\202\320\265\320\272\321\203\321\211\320\265\320\274 \320\277\321\200\320\276\320\265\320\272\321\202\320\265", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_NewProj->setText(QApplication::translate("Window", "\320\235\320\276\320\262\321\213\320\271 \320\277\321\200\320\276\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_STATUSTIP
        action_NewProj->setStatusTip(QApplication::translate("Window", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\275\320\276\320\262\321\213\320\271 \320\277\321\200\320\276\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_STATUSTIP
        action_Exit->setText(QApplication::translate("Window", "\320\222\321\213\321\205\320\276\320\264", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("Window", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\321\200\320\276\320\265\320\272\321\202\320\260", 0, QApplication::UnicodeUTF8));
        action_2->setText(QApplication::translate("Window", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\321\213", 0, QApplication::UnicodeUTF8));
        action_Close->setText(QApplication::translate("Window", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214 \320\277\321\200\320\276\320\265\320\272\321\202", 0, QApplication::UnicodeUTF8));
        action_Import->setText(QApplication::translate("Window", "\320\230\320\274\320\277\320\276\321\200\321\202", 0, QApplication::UnicodeUTF8));
        action_Lib->setText(QApplication::translate("Window", "\320\221\320\270\320\261\320\273\320\270\320\276\321\202\320\265\320\272\320\260 \320\274\320\260\321\202\320\265\321\200\320\270\320\260\320\273\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Window", "X possition", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Window", "Y possition", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Window", "Z possition", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Window", "Angle", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Window", "Rotate", 0, QApplication::UnicodeUTF8));
        graphic_tab->setTabText(graphic_tab->indexOf(tab_2), QApplication::translate("Window", "3D", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("Window", "\320\244\320\260\320\271\320\273", 0, QApplication::UnicodeUTF8));
        menu_3->setTitle(QApplication::translate("Window", "\320\236\320\277\321\206\320\270\320\270", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window: public Ui_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOW_H
