/********************************************************************************
** Form generated from reading UI file 'startpage.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGE_H
#define UI_STARTPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_startpage
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *returnButton;
    QPushButton *import_2;
    QPushButton *export_demo;
    QWidget *tab_2;
    QLineEdit *Time;
    QLineEdit *room_num;
    QLineEdit *stu_num;
    QLineEdit *class_num;
    QLineEdit *Day;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab_3;
    QPushButton *start;
    QWidget *tab_4;
    QPushButton *export_2;
    QLabel *label_7;
    QLineEdit *ID;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *startpage)
    {
        if (startpage->objectName().isEmpty())
            startpage->setObjectName(QStringLiteral("startpage"));
        startpage->resize(800, 600);
        centralwidget = new QWidget(startpage);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setMaximumSize(QSize(782, 16777215));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        returnButton = new QPushButton(tab);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(600, 470, 151, 20));
        import_2 = new QPushButton(tab);
        import_2->setObjectName(QStringLiteral("import_2"));
        import_2->setGeometry(QRect(340, 230, 80, 20));
        export_demo = new QPushButton(tab);
        export_demo->setObjectName(QStringLiteral("export_demo"));
        export_demo->setGeometry(QRect(640, 70, 80, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Time = new QLineEdit(tab_2);
        Time->setObjectName(QStringLiteral("Time"));
        Time->setGeometry(QRect(270, 150, 113, 20));
        room_num = new QLineEdit(tab_2);
        room_num->setObjectName(QStringLiteral("room_num"));
        room_num->setGeometry(QRect(270, 200, 113, 20));
        stu_num = new QLineEdit(tab_2);
        stu_num->setObjectName(QStringLiteral("stu_num"));
        stu_num->setGeometry(QRect(270, 260, 113, 20));
        class_num = new QLineEdit(tab_2);
        class_num->setObjectName(QStringLiteral("class_num"));
        class_num->setGeometry(QRect(270, 320, 113, 20));
        Day = new QLineEdit(tab_2);
        Day->setObjectName(QStringLiteral("Day"));
        Day->setGeometry(QRect(270, 90, 113, 20));
        label = new QLabel(tab_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 95, 81, 21));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(160, 155, 91, 21));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(160, 205, 91, 21));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(160, 265, 91, 21));
        label_5 = new QLabel(tab_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 330, 54, 12));
        label_6 = new QLabel(tab_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, 40, 171, 31));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        start = new QPushButton(tab_3);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(330, 260, 80, 20));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        export_2 = new QPushButton(tab_4);
        export_2->setObjectName(QStringLiteral("export_2"));
        export_2->setGeometry(QRect(570, 390, 80, 20));
        label_7 = new QLabel(tab_4);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(520, 290, 54, 21));
        ID = new QLineEdit(tab_4);
        ID->setObjectName(QStringLiteral("ID"));
        ID->setGeometry(QRect(560, 290, 113, 20));
        tabWidget->addTab(tab_4, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        startpage->setCentralWidget(centralwidget);
        menubar = new QMenuBar(startpage);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 21));
        startpage->setMenuBar(menubar);
        statusbar = new QStatusBar(startpage);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        startpage->setStatusBar(statusbar);

        retranslateUi(startpage);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(startpage);
    } // setupUi

    void retranslateUi(QMainWindow *startpage)
    {
        startpage->setWindowTitle(QApplication::translate("startpage", "MainWindow", nullptr));
        returnButton->setText(QApplication::translate("startpage", "\350\277\224\345\233\236", nullptr));
        import_2->setText(QApplication::translate("startpage", "\345\257\274\345\205\245\346\226\207\344\273\266", nullptr));
        export_demo->setText(QApplication::translate("startpage", "\346\237\245\347\234\213\346\250\241\346\235\277", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("startpage", "\345\257\274\345\205\245\346\226\207\344\273\266", nullptr));
        label->setText(QApplication::translate("startpage", "\346\257\217\345\221\250\344\270\212\350\257\276\345\244\251\346\225\260", nullptr));
        label_2->setText(QApplication::translate("startpage", "\346\257\217\345\244\251\344\270\212\350\257\276\350\212\202\346\225\260", nullptr));
        label_3->setText(QApplication::translate("startpage", "\346\225\231\345\256\244\346\225\260\347\233\256", nullptr));
        label_4->setText(QApplication::translate("startpage", "\346\225\231\345\256\244\345\256\271\347\272\263\351\207\217", nullptr));
        label_5->setText(QApplication::translate("startpage", "\347\217\255\347\272\247\346\225\260\351\207\217", nullptr));
        label_6->setText(QApplication::translate("startpage", "\345\241\253\345\206\231\346\225\260\345\255\227\345\215\263\345\217\257", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("startpage", "\346\267\273\345\212\240\347\272\246\346\235\237", nullptr));
        start->setText(QApplication::translate("startpage", "\345\274\200\345\247\213\346\216\222\350\257\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("startpage", "\345\274\200\345\247\213\346\216\222\350\257\276", nullptr));
        export_2->setText(QApplication::translate("startpage", "\345\257\274\345\207\272\346\226\207\344\273\266", nullptr));
        label_7->setText(QApplication::translate("startpage", "ID", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("startpage", "\345\257\274\345\207\272\350\257\276\350\241\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class startpage: public Ui_startpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGE_H
