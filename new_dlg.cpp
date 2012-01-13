#include "new_dlg.h"
#include "ui_newp_dlg.h"
 #include <QFileDialog>


New_dlg::New_dlg(QWidget *parent) :
    QDialog(parent)

{
    setupUi(this);
//    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
//    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

}


New_dlg::New_dlg(QString lib,QWidget *parent) :
    QDialog(parent)

{
    setupUi(this);

    libPath=lib;
//    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
//    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

}


New_dlg::~New_dlg()
{

}




void New_dlg::on_add_Button_clicked()
{
    Lib_dialog *lib=new Lib_dialog(libPath);
    lib->exec();
    delete lib;

    material_Box->clear();

    QFile libFile(libPath);
    if(!libFile.open(QFile::ReadOnly | QFile::WriteOnly)){
        libFile.close();

    }else{

    QTextStream readS(&libFile);
    while(!readS.atEnd()){
        QString inp;
        readS >> inp;
       material_Box->addItem(inp);
    }
    }
}
