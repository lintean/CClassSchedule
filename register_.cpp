#include "register_.h"
#include "ui_register_.h"

register_::register_(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::register_)
{
    ui->setupUi(this);

    QImage *qImage = new QImage(":/new/prefix1/picture/userIcon.png");
    QImage qScaledImage = ScaleImage2Label(*qImage,ui->label_2);
    ui->label_2->setPixmap(QPixmap::fromImage(qScaledImage));
    ui->label_2->setAlignment(Qt::AlignCenter);
    ui->label_2->show();
    qImage = new QImage(":/new/prefix1/picture/pwdIcon.png");
    qScaledImage = ScaleImage2Label(*qImage,ui->label_3);
    ui->label_3->setPixmap(QPixmap::fromImage(qScaledImage));
    ui->label_3->setAlignment(Qt::AlignCenter);
    ui->label_3->show();
    ui->label_4->setPixmap(QPixmap::fromImage(qScaledImage));
    ui->label_4->setAlignment(Qt::AlignCenter);
    ui->label_4->show();
    qImage = new QImage(":/new/prefix1/picture/nameIcon.png");
    qScaledImage = ScaleImage2Label(*qImage,ui->label);
    ui->label->setPixmap(QPixmap::fromImage(qScaledImage));
    ui->label->setAlignment(Qt::AlignCenter);
    ui->label->show();

    ui->userNameLineEdit->setPlaceholderText("请输入用户名");
    ui->accountLineEdit->setPlaceholderText("请输入账号");
    ui->passwordLineEdit->setPlaceholderText("请输入密码");
    ui->repeatPasswordLineEdit->setPlaceholderText("请再次输入密码");

    mMoveing=false;
    this->setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint |Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);
    ui->passwordLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->repeatPasswordLineEdit->setEchoMode(QLineEdit::PasswordEchoOnEdit);
    ui->registerButton->setEnabled(false);
    QObject::connect(ui->userNameLineEdit,SIGNAL(textChanged(QString)),this,SLOT(registerButtonToUse()));
    QObject::connect(ui->accountLineEdit,SIGNAL(textChanged(QString)),this,SLOT(registerButtonToUse()));
    QObject::connect(ui->passwordLineEdit,SIGNAL(textChanged(QString)),this,SLOT(registerButtonToUse()));
}

register_::~register_()
{
    delete ui;
}

QImage register_::ScaleImage2Label(QImage qImage, QLabel* qLabel)
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

void register_::mousePressEvent(QMouseEvent *event)
{
    mMoveing = true;
    mMovePosition = event->globalPos() - pos();
    return QDialog::mousePressEvent(event);
}

void register_::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
        && (event->globalPos()-mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QDialog::mouseMoveEvent(event);
}

void register_::mouseReleaseEvent()
{
    mMoveing = false;
}

void register_::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QPixmap(":/new/prefix1/picture/background.jpg").scaled(this->size())));
    painter.setPen(Qt::transparent);
    QRect rect = this->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, 10, 10);
}


void register_::on_returnButton_clicked()
{
    login *l=new login;
    this->hide();
    l->show();
}

void register_::registerButtonToUse()
{
    ui->registerButton->setEnabled(true);
}

void register_::on_registerButton_clicked()
{
    if(!judegEmpty())
    {
        ui->passwordLineEdit->clear();
        ui->repeatPasswordLineEdit->clear();
        return ;
    }

    if(ui->passwordLineEdit->text()!=ui->repeatPasswordLineEdit->text())
    {
        QMessageBox::warning(this,"警告","两次输入密码不一致",QMessageBox::Yes);
        ui->passwordLineEdit->clear();
        ui->repeatPasswordLineEdit->clear();
        return ;
    }
    QString file="User.dat";
    bool find=findFile(file);
    if(find)
    {
        QMessageBox::warning(this,"警告","该ID已存在");
        clearAll();
        return ;
    }
    else
    {
        setFile(file);
        QMessageBox::information(this,"通知","恭喜，您已成功注册");
        clearAll();
    }
}
bool register_::judegEmpty()
{
    if(ui->userNameLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","用户名不能为空");
        return false;
    }
    else if(ui->accountLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","账户不能为空");
        return false;
    }
    else if(ui->passwordLineEdit->text().isEmpty()||ui->repeatPasswordLineEdit->text().isEmpty())
    {
        QMessageBox::warning(this,"警告","密码不能为空");
        return false;
    }
    else
        return true;
}
void register_::clearAll()
{
    ui->userNameLineEdit->clear();
    ui->accountLineEdit->clear();
    ui->passwordLineEdit->clear();
    ui->repeatPasswordLineEdit->clear();
}

bool register_::findFile(QString &fileName)
{
    bool find=false;
    QFile file;
    file.setFileName(fileName);
    if(!file.open(QIODevice::ReadOnly))
    {
        return false;
    }
    QString userName,account,password;
    QDataStream in(&file);
    while(!in.atEnd())
    {
        in>>userName>>account>>password;
        if(account==ui->accountLineEdit->text())
        {
            find=true;
            break;
        }
    }
    file.close();
    return find;
}
void register_::setFile(QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::Append))
    {
        QMessageBox::warning(this,"警告","注册失败");
        return ;
    }
    QDataStream out(&file);
    QString userName,account,password;
    userName=ui->userNameLineEdit->text();
    account=ui->accountLineEdit->text();
    password=ui->passwordLineEdit->text();
    out<<userName<<account<<password;
    file.close();
}
