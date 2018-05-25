/********************************************************************************
** Form generated from reading UI file 'register_.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTER__H
#define UI_REGISTER__H

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

class Ui_register_
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *accountLineEdit;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *passwordLineEdit;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *repeatPasswordLineEdit;
    QPushButton *registerButton;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *userNameLineEdit;
    QPushButton *returnButton;

    void setupUi(QDialog *register_)
    {
        if (register_->objectName().isEmpty())
            register_->setObjectName(QStringLiteral("register_"));
        register_->resize(541, 429);
        register_->setStyleSheet(QStringLiteral("font-size:12px"));
        groupBox = new QGroupBox(register_);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(50, 20, 431, 411));
        groupBox->setStyleSheet(QString::fromUtf8("font: 75 14pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";"));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(90, 100, 261, 33));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setStyleSheet(QLatin1String("height:25px;\n"
"width:25px;\n"
"font-size:12px"));

        horizontalLayout_2->addWidget(label_2);

        accountLineEdit = new QLineEdit(layoutWidget);
        accountLineEdit->setObjectName(QStringLiteral("accountLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(accountLineEdit->sizePolicy().hasHeightForWidth());
        accountLineEdit->setSizePolicy(sizePolicy);
        accountLineEdit->setStyleSheet(QLatin1String("height:25px;\n"
"font-size:12px;\n"
""));

        horizontalLayout_2->addWidget(accountLineEdit);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(90, 150, 261, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setStyleSheet(QLatin1String("height:25px;\n"
"width:25px;\n"
"font-size:12px"));

        horizontalLayout_3->addWidget(label_3);

        passwordLineEdit = new QLineEdit(layoutWidget_2);
        passwordLineEdit->setObjectName(QStringLiteral("passwordLineEdit"));
        passwordLineEdit->setStyleSheet(QLatin1String("height:25px;\n"
"font-size:12px;\n"
""));

        horizontalLayout_3->addWidget(passwordLineEdit);

        layoutWidget_3 = new QWidget(groupBox);
        layoutWidget_3->setObjectName(QStringLiteral("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(90, 200, 261, 33));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(layoutWidget_3);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setStyleSheet(QLatin1String("height:25px;\n"
"width:25px;\n"
"font-size:12px"));

        horizontalLayout_4->addWidget(label_4);

        repeatPasswordLineEdit = new QLineEdit(layoutWidget_3);
        repeatPasswordLineEdit->setObjectName(QStringLiteral("repeatPasswordLineEdit"));
        repeatPasswordLineEdit->setStyleSheet(QLatin1String("height:25px;\n"
"font-size:12px;\n"
""));

        horizontalLayout_4->addWidget(repeatPasswordLineEdit);

        registerButton = new QPushButton(groupBox);
        registerButton->setObjectName(QStringLiteral("registerButton"));
        registerButton->setGeometry(QRect(120, 300, 191, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(9);
        registerButton->setFont(font);
        registerButton->setStyleSheet(QLatin1String("    color: white;\n"
"    border-radius: 10px;\n"
"    background-color: rgb(21,87,153);\n"
"    background-clip: border-box;\n"
"    background-origin: border-box;\n"
"    box-shadow: none;\n"
"    padding: 0;\n"
"    border: 0;\n"
"	font-size:16px;"));
        layoutWidget_4 = new QWidget(groupBox);
        layoutWidget_4->setObjectName(QStringLiteral("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(90, 50, 261, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget_4);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget_4);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("font-size:12px"));

        horizontalLayout->addWidget(label);

        userNameLineEdit = new QLineEdit(layoutWidget_4);
        userNameLineEdit->setObjectName(QStringLiteral("userNameLineEdit"));
        userNameLineEdit->setStyleSheet(QLatin1String("height:25px;\n"
"font-size:12px;\n"
""));

        horizontalLayout->addWidget(userNameLineEdit);

        returnButton = new QPushButton(groupBox);
        returnButton->setObjectName(QStringLiteral("returnButton"));
        returnButton->setGeometry(QRect(120, 260, 201, 31));
        returnButton->setFont(font);
        returnButton->setStyleSheet(QLatin1String("    color: black;\n"
"    background-color: transparent;\n"
"    box-shadow: none;\n"
"    padding: 0;\n"
"    border: 0;\n"
"	font-size:12px;"));

        retranslateUi(register_);

        QMetaObject::connectSlotsByName(register_);
    } // setupUi

    void retranslateUi(QDialog *register_)
    {
        register_->setWindowTitle(QApplication::translate("register_", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("register_", "\347\224\250\346\210\267\346\263\250\345\206\214", nullptr));
        label_2->setText(QApplication::translate("register_", "\350\264\246\345\217\267\357\274\232      ", nullptr));
        label_3->setText(QApplication::translate("register_", "\345\257\206\347\240\201\357\274\232      ", nullptr));
        label_4->setText(QApplication::translate("register_", "\345\257\206\347\240\201\357\274\232      ", nullptr));
        registerButton->setText(QApplication::translate("register_", "\346\263\250\345\206\214", nullptr));
        label->setText(QApplication::translate("register_", "\347\224\250\346\210\267\345\220\215\357\274\232   ", nullptr));
        returnButton->setText(QApplication::translate("register_", "\345\267\262\346\234\211\350\264\246\345\217\267\357\274\237\347\253\213\345\215\263\347\231\273\345\275\225>>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class register_: public Ui_register_ {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTER__H
