#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //应用qss样式表
    QFile qss(":/new/prefix1/stylesheet.qss");
    qss.open(QFile::ReadOnly);
    a.setStyleSheet(qss.readAll());
    qss.close();

    a.setWindowIcon(QIcon(":/new/prefix1/picture/favicon-20180531013632939.ico"));

    login w;
    w.show();

    return a.exec();
}
