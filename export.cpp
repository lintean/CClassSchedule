#include "export.h"
#include<QString>
#include<QVector>
#include<QFile>
#include<QDir>
#include<QDebug>
#include<fstream>


Export::Export()
{

}
bool Export::copyFileToPath(QString sourceDir ,QString toDir, bool coverFileIfExist)
{
    toDir.replace("\\","/");


    //如果选择目录和当前目录相同
    if (sourceDir == toDir){
        return true;
    }
    if (!QFile::exists(sourceDir)){
        return false;
    }
    QDir *createfile     = new QDir;
    //如果已经存在则删除原本的文件
    bool exist = createfile->exists(toDir);
    if (exist){
        if(coverFileIfExist){
            createfile->remove(toDir);
        }
    }//end if

    if(!QFile::copy(sourceDir, toDir))
    {
        return false;
    }
    return true;
}
bool Export::searchSchedule(QString ID,QVector<QString> &buf_out )
{
    ifstream file ;
    string buf;
    QString Qbuf;
    file.open("table.txt");

    char buffer[100];

    while(!file.eof())
    {
        file.getline(buffer,100);
        buf = string(buffer);
        Qbuf = QString::fromStdString(buf);
        qDebug()<<Qbuf;
      if(Qbuf.contains("id "+ID))
      {
          for(int i = 0 ; i<5; i++)
          {
              //日后课程名称过长的时候出现bug则与此大小有关
               char temp_c[300];
               string  temp_s;
             file.getline(temp_c,300);
             temp_s = string(temp_c);
             buf_out.append(QString::fromStdString(temp_s));
             qDebug()<<QString::fromStdString(temp_s)<<endl;



          }
          qDebug()<<buf_out;
          qDebug()<<buf_out.size();
           return true;
      }


    }
    return false;



}
