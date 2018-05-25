#include "login.h"
#include "ui_login.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    QImage *qImage = new QImage(":/new/prefix1/picture/userIcon.png");
    QImage qScaledImage = ScaleImage2Label(*qImage,ui->accountLabel);
    ui->accountLabel->setPixmap(QPixmap::fromImage(qScaledImage));
    ui->accountLabel->setAlignment(Qt::AlignCenter);
    ui->accountLabel->show();
    qImage = new QImage(":/new/prefix1/picture/pwdIcon.png");
    qScaledImage = ScaleImage2Label(*qImage,ui->passwordLabel);
    ui->passwordLabel->setPixmap(QPixmap::fromImage(qScaledImage));
    ui->passwordLabel->setAlignment(Qt::AlignCenter);
    ui->passwordLabel->show();

    ui->accountLineEdit->setPlaceholderText("请输入账号");
    ui->passwordLineEdit->setPlaceholderText("请输入密码");

    mMoveing=false;
    ui->loginButton->setEnabled(false);
    this->setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint |Qt::WindowStaysOnTopHint);
    //说不好加图片的时候要用
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    QObject::connect(ui->accountLineEdit,SIGNAL(textChanged(QString)),this,SLOT(loginButtonToUse()));
    QObject::connect(ui->passwordLineEdit,SIGNAL(textChanged(QString)),this,SLOT(loginButtonToUse()));
}

login::~login()
{
    delete ui;
}

QImage login::ScaleImage2Label(QImage qImage, QLabel* qLabel)
{
    QImage qScaledImage;
    QSize qImageSize = qImage.size();
    QSize qLabelSize = qLabel->size();
    double dWidthRatio = 1.0*qImageSize.width() / qLabelSize.width();
    double dHeightRatio = 1.0*qImageSize.height() / qLabelSize.height();
    if (dWidthRatio>dHeightRatio)
    {
        qScaledImage = qImage.scaledToWidth(qLabelSize.width());
    }
    else
    {
        qScaledImage = qImage.scaledToHeight(qLabelSize.height());
    }
    return qScaledImage;
}

void login::loginButtonToUse()
{
    ui->loginButton->setEnabled(true);
}

void login::mousePressEvent(QMouseEvent *event)
{
    mMoveing = true;
    mMovePosition = event->globalPos() - pos();
    return QDialog::mousePressEvent(event);
}

void login::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
        && (event->globalPos()-mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

void login::mouseReleaseEvent()
{
    mMoveing = false;
}

void login::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.fillRect(rect(),QColor(255,255,255,100));
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QPixmap(":/new/prefix1/picture/background.jpg").scaled(this->size())));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 10, 10);

    QPixmap pix;
    pix.load(":/new/prefix1/picture/logoBlue.png");
    painter.drawPixmap(190,50,160,80,pix);
}

void login::on_loginButton_clicked()
{
    if(!judgeEmpty())
    {
        ui->passwordLineEdit->clear();
        return ;
    }
    QString name;
    QString account;
    QString fileName="User.dat";
    bool find=findRegisterUser(fileName,name,account);
    if(find)
    {
        ui->accountLineEdit->clear();
        ui->passwordLineEdit->clear();
        startpage *start=new startpage;
        QObject::connect(start,SIGNAL(toDialog()),this,SLOT(showNormal()));
        start->show();
        connect(this,SIGNAL(toStartPage(QString,QString)),start,SLOT(comeDialog(QString,QString)));
        emit toStartPage(name,account);
        this->hide();
    }
    else
    {
        ui->accountLineEdit->clear();
        ui->passwordLineEdit->clear();
        QMessageBox::warning(this,"警告","登录失败！请检查您的用户名和密码或重新注册");
    }
}

void login::on_registerButton_clicked()
{
    register_ *r=new register_;
    this->hide();
    r->show();
}

void login::on_exitButton_clicked()
{
    close();
}

bool login::judgeEmpty()
{
    if(ui->accountLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","用户名不能为空");
        return false;
    }
    else if(ui->passwordLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","密码不能为空");
        return false;
    }
    else
        return true;
}

bool login::findRegisterUser(QString &registerName, QString &_name, QString &_account)
{
    bool find=false;
    QFile file(registerName);
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QDataStream in(&file);
    QString name,account,password;
    while(!in.atEnd())
    {
        in>>name>>account>>password;
        if((account==ui->accountLineEdit->text())&&(password==ui->passwordLineEdit->text()))
        {
            find=true;
            _name=name;
            _account=account;
            break;
        }
    }
    file.close();
    return find;
}


