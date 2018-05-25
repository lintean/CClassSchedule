#ifndef LOGIN_H
#define LOGIN_H

#include "register_.h"
#include "startpage.h"
#include <QDialog>
#include <QtDebug>
#include <QDataStream>
#include <QFile>
#include <QIODevice>
#include <QButtonGroup>
#include <QGraphicsOpacityEffect>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QMessageBox>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private:
    Ui::login *ui;
    //TeacherManage *teacher;
    //Ui::startpage *start;说不定会出BUG
    bool mMoveing;
    QPoint mMovePosition;

private:
    bool judgeEmpty();
    bool findRegisterUser(QString &registerName,QString&,QString&);
    QImage ScaleImage2Label(QImage qImage, QLabel* qLabel);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent();
    void paintEvent(QPaintEvent *);

//跳转页面信号
signals:
    void toStartPage(QString,QString);
    //void toTeacherManage(QString,QString);

private slots:
    void on_loginButton_clicked();
    void on_registerButton_clicked();
    void on_exitButton_clicked();
    void loginButtonToUse();
};

#endif // LOGIN_H
