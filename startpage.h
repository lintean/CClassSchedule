#ifndef STARTPAGE_H
#define STARTPAGE_H

#include <QMainWindow>
#include "login.h"
#include <QMainWindow>
#include <QMessageBox>
#include <QButtonGroup>
#include <QDataStream>
#include <QFile>
#include <QIODevice>
#include <QGraphicsOpacityEffect>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <QFileDialog>
#include<QString>
#include<QDir>
#include<QDebug>
#include<QtXlsx/QtXlsx>
#include<fstream>
#include<stdlib.h>
#include<string>
#include<QMessageBox>
#include <QLineEdit>
#include<QVector>
#include"export.h"


namespace Ui {
class startpage;
}

class startpage : public QMainWindow
{
    Q_OBJECT

public:
    explicit startpage(QWidget *parent = 0);
    ~startpage();

private:
    Ui::startpage *ui;
    bool mMoveing;
    QPoint mMovePosition;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent();
    void paintEvent(QPaintEvent *event);
private slots:
    void on_returnButton_clicked();
    void on_import_2_clicked();
    void on_start_clicked();
    void on_export_2_clicked();
    void on_export_demo_clicked();
};

#endif // STARTPAGE_H
