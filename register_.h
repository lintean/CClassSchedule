#ifndef REGISTER__H
#define REGISTER__H

#include "login.h"
#include <QDialog>
#include <QMessageBox>
#include <QButtonGroup>
#include <QDataStream>
#include <QFile>
#include <QIODevice>
#include <QGraphicsOpacityEffect>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>

namespace Ui {
class register_;
}

class register_ : public QDialog
{
    Q_OBJECT

public:
    explicit register_(QWidget *parent = 0);
    ~register_();

private:
    Ui::register_ *ui;
    bool judegEmpty();
    bool findFile(QString &fileName);
    void setFile(QString &fileName);
    QImage ScaleImage2Label(QImage qImage, QLabel* qLabel);

private:
    bool mMoveing;
    QPoint mMovePosition;

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent();
    void paintEvent(QPaintEvent *event);

private slots:
    void registerButtonToUse();
    void on_registerButton_clicked();
    void on_returnButton_clicked();
    void clearAll();
};

#endif // REGISTER__H
