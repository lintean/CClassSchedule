/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QGroupBox *groupBox;
    QPushButton *loginButton;
    QPushButton *registerButton;
    QPushButton *exitButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *accountLabel;
    QLineEdit *accountLineEdit;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QStringLiteral("login"));
        login->resize(541, 429);
        groupBox = new QGroupBox(login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 10, 431, 411));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(14);
        groupBox->setFont(font);
        groupBox->setStyleSheet(QStringLiteral(""));
        loginButton = new QPushButton(groupBox);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(120, 280, 201, 31));
        QFont font1;
        loginButton->setFont(font1);
        loginButton->setStyleSheet(QLatin1String("    color: white;\n"
"    border-radius: 10px;\n"
"    background-color: rgb(21,87,153);\n"
"    background-clip: border-box;\n"
"    background-origin: border-box;\n"
"    box-shadow: none;\n"
"    padding: 0;\n"
"    border: 0;\n"
"	font-size:16px;"));
        registerButton = new QPushButton(groupBox);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(130, 240, 171, 21));
        registerButton->setFont(font1);
        registerButton->setStyleSheet(QLatin1String("    color: black;\n"
"    background-color: transparent;\n"
"    box-shadow: none;\n"
"    padding: 0;\n"
"    border: 0;\n"
"	font-size:12px;"));
        exitButton = new QPushButton(groupBox);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(120, 320, 201, 31));
        exitButton->setFont(font1);
        exitButton->setStyleSheet(QLatin1String("    color: white;\n"
"    border-radius: 10px;\n"
"    background-color: rgb(21,87,153);\n"
"    background-clip: border-box;\n"
"    background-origin: border-box;\n"
"    box-shadow: none;\n"
"    padding: 0;\n"
"    border: 0;\n"
"	font-size:16px;"));
        horizontalLayoutWidget = new QWidget(groupBox);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(70, 150, 301, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        accountLabel = new QLabel(horizontalLayoutWidget);
        accountLabel->setObjectName(QStringLiteral("accountLabel"));
        accountLabel->setMinimumSize(QSize(0, 29));
        accountLabel->setMaximumSize(QSize(16777215, 16777215));
        accountLabel->setStyleSheet(QLatin1String("height:25px;\n"
"width:25px;\n"
""));

        horizontalLayout->addWidget(accountLabel);

        accountLineEdit = new QLineEdit(horizontalLayoutWidget);
        accountLineEdit->setObjectName(QStringLiteral("accountLineEdit"));
        accountLineEdit->setFont(font1);
        accountLineEdit->setStyleSheet(QLatin1String("height:25px;\n"
"background-color:rgb(243,243,243);\n"
"font-size:12px;"));

        horizontalLayout->addWidget(accountLineEdit);

        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(70, 200, 301, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        passwordLabel = new QLabel(horizontalLayoutWidget_2);
        passwordLabel->setObjectName(QStringLiteral("passwordLabel"));
        passwordLabel->setStyleSheet(QLatin1String("height:25px;\n"
"width:25px;"));

        horizontalLayout_3->addWidget(passwordLabel);

        passwordLineEdit = new QLineEdit(horizontalLayoutWidget_2);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setFont(font1);
        passwordLineEdit->setStyleSheet(QLatin1String("height:25px;\n"
"background-color:rgb(243,243,243);\n"
"font-size:12px;\n"
""));

        horizontalLayout_3->addWidget(passwordLineEdit);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QApplication::translate("login", "login", nullptr));
        groupBox->setTitle(QApplication::translate("login", "\346\231\272\350\203\275\346\216\222\350\257\276\347\263\273\347\273\237", nullptr));
        loginButton->setText(QApplication::translate("login", "\347\231\273\351\231\206", nullptr));
        registerButton->setText(QApplication::translate("login", "\350\277\230\346\262\241\346\234\211\350\264\246\345\217\267\357\274\237\345\205\215\350\264\271\346\263\250\345\206\214>>", nullptr));
        exitButton->setText(QApplication::translate("login", "\351\200\200\345\207\272", nullptr));
        accountLabel->setText(QApplication::translate("login", "\350\264\246\345\217\267 \357\274\232", nullptr));
        passwordLabel->setText(QApplication::translate("login", "\345\257\206\347\240\201 \357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
