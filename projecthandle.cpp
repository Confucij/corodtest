#include "projecthandle.h"
#include <iostream>
#include <stdio.h>
#include <QFileDialog>
#include <QByteArray>

ProjectHandle::ProjectHandle(QObject *parent) :    QObject(parent)
{
    map=NULL;
    colorMap=NULL;
    projName="Default project";
    path="";
    libPath="lib/lib.lst";
    projObjects.clear();
    version="0.01a";
}

void ProjectHandle::save_map(const char* filename){
    FILE *f=fopen(filename,"wb");
    fwrite((void*)map->data,map->sizeX*map->sizeY,1,f);
    fclose(f);
    return;
}

void ProjectHandle::loadData(){

    QString Name = QFileDialog::getOpenFileName(NULL,tr("Open picture"), ".",tr("Project files (*.bmp *.jpg *.jpeg *.png)"));
    if (Name.isEmpty()){
        return;
    }

    map=NULL;

    if(colorMap!=NULL){
        delete colorMap;
        colorMap = NULL;
    }

    QFileInfo inf(Name);
    colorMap = new QImage(Name);

    New_dlg dlg(libPath);
    QPixmap pic =QPixmap::fromImage(colorMap->scaled(dlg.pic_label->size())) ;
    dlg.pic_label->setPixmap(pic);

    QFile libFile(libPath);
    if(!libFile.open(QFile::ReadOnly | QFile::WriteOnly)){
        emit addToLog("Не найден файл библиотек");
        QDir dir;
        QFileInfo inf(libPath);
        dir=inf.dir();
        dir.mkdir(dir.absolutePath());
        QTextStream s(&libFile);
        s << "";
    }else{

    QTextStream readS(&libFile);
    while(!readS.atEnd()){
        QString inp;
        readS >> inp;
        dlg.material_Box->addItem(inp);
    }
    }

//    connect(dlg.add_Button,SIGNAL(clicked()),this,SLOT(openLib()));

    if(!dlg.exec()){
        delete colorMap;
        return;
    }


    PObject object;
    if(dlg.width_sizeBox->currentText()=="um"){
        object.width = dlg.width_SpinBox->value();
    }else{
        object.width = dlg.width_SpinBox->value()*1000;
    }

    if(dlg.height_sizeBox->currentText()=="um"){
        object.height = dlg.height_SpinBox->value();
    }else{
        object.height = dlg.height_SpinBox->value()*1000;
    }

    object.map = new Image;
    object.map->data = new uchar[colorMap->width()*colorMap->height()];

    object.material     =   dlg.material_Box->currentText();
    object.map->sizeX   =   colorMap->width() ;
    object.map->sizeY   =   colorMap->height() ;


    int k=0;
    for(int i=0;i<(colorMap->height());i++){
        for(int j=0;j<colorMap->width();j++){
            QRgb tmp=colorMap->pixel(j,i);
            uchar t=static_cast<uchar>(qBlue(tmp));
            object.map->data[k]=t;
            k++;
        }
    }

    calculate(&object);

    map=object.map;
    object.path=Name;

    projObjects.insert(inf.fileName(),object);


    emit addToList(inf.fileName());

    emit cleanGl();

    emit set_glwMap(map);
    emit imageLoad(map->sizeX,map->sizeY);
}

void ProjectHandle::loadData(PObject *obj){

//    colorMap = new QImage(obj->path);

//    obj->map = new Image;
//    obj->map->data = new uchar[colorMap->width()*colorMap->height()];
//    obj->map->sizeX =colorMap->width() ;
//    obj->map->sizeY =colorMap->height() ;

//    int k=0;
//    for(uint i=0;i<(obj->map->sizeY);i++){
//        for(uint j=0;j<obj->map->sizeX;j++){
//            QRgb tmp=colorMap->pixel(j,i);
//            uchar t=static_cast<uchar>(qBlue(tmp));
//            obj->map->data[k]=t;
//            k++;
//        }
//    }

//    calculate(obj);
}


 void ProjectHandle::changeCurrent(QModelIndex index){

    emit cleanGl();
    map=NULL;
    delete colorMap;

    map=projObjects[index.data().toString()].map;
    colorMap = new QImage(projObjects[index.data().toString()].path);

    if(map==NULL){
        PObject object = projObjects[index.data().toString()];
        object.map = new Image;
        object.map->data = new uchar[colorMap->width()*colorMap->height()];
        object.map->sizeX =colorMap->width() ;
        object.map->sizeY =colorMap->height() ;
        int k=0;
        for(int i=0;i<(colorMap->height());i++){
            for(int j=0;j<colorMap->width();j++){
                QRgb tmp=colorMap->pixel(j,i);
                uchar t=static_cast<uchar>(qBlue(tmp));
                object.map->data[k]=t;
                k++;
            }
        }
        calculate(&object);
        QFileInfo inf(object.path);
        projObjects.insert(inf.fileName(),object);
        map=object.map;
    }



    emit set_glwMap(map);
    emit imageLoad(map->sizeX,map->sizeY);

    return;
}

 void ProjectHandle::newProject(){

    if(path!=""){
        QMessageBox msgBox;
        msgBox.setText("Do you want to save your changes?");
        msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Save);
        int ret = msgBox.exec();

        switch (ret) {
        case QMessageBox::Save:
            // Save was clicked
            saveProject();
            clearProject();
            break;
        case QMessageBox::Discard:
            // Don't Save was clicked
            clearProject();
            break;
        case QMessageBox::Cancel:
            // Cancel was clicked
            return;
            break;
        default:
            // should never be reached
            break;
        }
    }

    QFileDialog dlg;
    dlg.setDefaultSuffix("fproj");
    QString path = dlg.getSaveFileName(NULL,tr("Project location"), ".",tr("Project files (*.fproj)"));
    if(path.isEmpty()){
        return;
    }
    QFileInfo inf(path);
    if(inf.suffix()!="fproj"){
        QString tmp=inf.baseName();
        tmp+=".fproj";
        path=inf.absolutePath()+"/"+tmp;
    }
    this->path=path;

    QDomDocument doc("xml version=\"1.0\" encoding=\"UTF-8\"");
    QDomElement root =  doc.createElement(inf.baseName());
    doc.appendChild(root);
    root.setAttribute("appVersion",version);

    QFile pfile(path);
    if(pfile.open(QIODevice::WriteOnly)){
        QTextStream stream(&pfile);
        stream << doc.toString();
        pfile.close();
        projName=inf.baseName();
    }

    return;

}

 void ProjectHandle::saveProject(){

    if(this->path==""){
        QFileDialog dlg;
        dlg.setDefaultSuffix("fproj");
        QString path = dlg.getSaveFileName(NULL,tr("Project location"), ".",tr("Project files (*.fproj)"));
        if(path.isEmpty()){
            return;
        }
        QFileInfo inf(path);
        if(inf.suffix()!="fproj"){
            QString tmp=inf.baseName();
            tmp+=".fproj";
            path=inf.absolutePath()+"/"+tmp;
        }
        this->path=path;
    }


    QFileInfo inf(path);
    QDomDocument doc(inf.baseName());
    QDomElement root =  doc.createElement("Project");
    doc.appendChild(root);
    root.setAttribute("appVersion",version);
    root.setAttribute("Name",projName);

    QHash<QString,PObject>::iterator iter;

    iter=projObjects.begin();
    for(int i=0;i<projObjects.size();i++){
        PObject tmp=iter.value();
        QDomElement obj = doc.createElement("Object");
        root.appendChild(obj);
            obj.setAttribute("Path",tmp.path);
            obj.setAttribute("Material",tmp.material);
            obj.setAttribute("Height",tmp.height);
            obj.setAttribute("Width",tmp.width);

        iter++;
    }

    QFile pfile(path);
    if(pfile.open(QIODevice::WriteOnly)){
        QTextStream stream(&pfile);
        stream << doc.toString();
        pfile.close();
        projName=inf.baseName();
    }
}

 void ProjectHandle::clearProject(){
    emit cleanGl();
    emit cleanWindow();
    if(map!=NULL){
        if(map->data!=NULL){
            delete map->data;
        }
        delete map;
        map=NULL;
    }
    if(colorMap!=NULL){
        delete colorMap;
        colorMap = NULL;
    }
    projName="Default project";
    path="";
    projObjects.clear();
}

 void ProjectHandle::closeProject(){
    QMessageBox msgBox;
    msgBox.setText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Save:
        // Save was clicked
        saveProject();
        clearProject();
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        clearProject();
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        return;
        break;
    default:
        // should never be reached
        break;
    }
    return;
}

 void ProjectHandle::openProject()
{
    QMessageBox msgBox;

    if(projObjects.size()!=0){
    msgBox.setText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Save:
        // Save was clicked
        saveProject();
        clearProject();
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        clearProject();
        break;
    case QMessageBox::Cancel:
        // Cancel was clicked
        return;
        break;
    default:
        // should never be reached
        break;
    }
    }
    QFileDialog dlg;
    QString path = dlg.getOpenFileName(NULL,tr("Project file"), ".",tr("Project files (*.fproj)"));
    if(path.isEmpty()){
        return;
    }
    this->path=path;
    QFile pfile(path);
    QDomDocument doc;
    doc.setContent(&pfile);
    QDomNode node = doc.documentElement();
    if(node.toElement().tagName()=="Project"){
        projName=node.toElement().attribute("Name");
        node=node.firstChild();
    }
    while(!node.isNull()){
        if(node.toElement().tagName()=="Object"){
            PObject obj;
            obj.path        =   node.toElement().attribute("Path");
            obj.material    =   node.toElement().attribute("Material");
            obj.height      =   node.toElement().attribute("Height").toFloat();
            obj.width       =   node.toElement().attribute("Width").toFloat();
            obj.map         =   NULL;
            QFileInfo inf(obj.path);
            projObjects.insert(inf.fileName(),obj);
            emit addToList(inf.fileName());
        }
        node=node.nextSibling();

    }


}

 void ProjectHandle::openLib()
{

    Lib_dialog *lib=new Lib_dialog(libPath);
    lib->exec();
    delete lib;
}

void ProjectHandle::calculate(PObject *obj)
{
    /*
      Sjuda pihaj raschet karty vysot. Poluchennuju kartu polozhish' v obj->map; U nej est' svojstvo data - sama karta.
      Kogda ona k tebe pridet ona budet soderzhat' znachenie kakogo-to cveta(na dannyj moment sinego). Dannye o vseh
      cvetah budut hranitsja v colorMap. obrabotannuju kartu polozhi tuda zhe.
      Ewe zhe nam ponadobjatsja dannye statistiki. Dopishi nuzhnye polja v tip PObject. Schitaj ih tut zhe i zapolnjaj obj.
      */



}
