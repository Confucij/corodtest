#ifndef NEWP_DLG_H
#define NEWP_DLG_H

#include <QDialog>
#include <QTextStream>
#include "ui_newp_dlg.h"
#include "lib_dialog.h"
namespace Ui {
    class Newp_dlg;
}

class New_dlg : public QDialog, public Ui::Newp_dlg
{
    Q_OBJECT

public:
     New_dlg(QWidget *parent = 0);
     New_dlg(QString lib,QWidget *parent = 0);
    ~New_dlg();
private slots:
     void on_add_Button_clicked();

protected:
     QString libPath;
};

#endif // NEWP_DLG_H
