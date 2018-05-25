#include "startpage.h"
#include "ui_startpage.h"

QString file_stu,file_tea,day,time_pw,stu_num,room_num,class_num,export_filename;
Export e;

startpage::startpage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::startpage)
{
    ui->setupUi(this);
    mMoveing=false;
    this->setWindowOpacity(1);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinimizeButtonHint |Qt::WindowStaysOnTopHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

}

startpage::~startpage()
{
    delete ui;
}

void startpage::mousePressEvent(QMouseEvent *event)
{
    mMoveing = true;
    mMovePosition = event->globalPos() - pos();
    return QMainWindow::mousePressEvent(event);
}

void startpage::mouseMoveEvent(QMouseEvent *event)
{
    if (mMoveing && (event->buttons() && Qt::LeftButton)
        && (event->globalPos()-mMovePosition).manhattanLength() > QApplication::startDragDistance())
    {
        move(event->globalPos()-mMovePosition);
        mMovePosition = event->globalPos() - pos();
    }
    return QMainWindow::mouseMoveEvent(event);
}

void startpage::mouseReleaseEvent()
{
    mMoveing = false;
}



void startpage::paintEvent(QPaintEvent *)
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

void startpage::on_returnButton_clicked()
{
    login *l=new login;
    this->hide();
    l->show();
}

void startpage::on_import_2_clicked()
{
    QStringList    fileNameList;

    QFileDialog* fd = new QFileDialog(this);//创建对话框

    fd->resize(240,320);    //设置显示的大小
    //fd->setFilter("Allfile(*.*);;mp3file(*.mp3);;wmafile(*.wma);;wavefile(*.wav)"); //设置文件过滤器
    fd->setViewMode(QFileDialog::List);  //设置浏览模式，有 列表（list） 模式和 详细信息（detail）两种方式
    fd->setFileMode(QFileDialog::ExistingFiles); //ExistingFiles & ExistingFile 前者是多选文件，后者是单选文件


    if ( fd->exec() == QDialog::Accepted )   //如果成功的执行
    {
        fileNameList = fd->selectedFiles();//返回文件列表的名称

        if(fileNameList.size()<2)
        {
            QMessageBox msgbox ;
            msgbox.setText("请导入两个文件");
            msgbox.exec();
            return ;

        }

        //当没有导入两个文件的时候进行阻塞并挂起



        if(fileNameList[1].contains("Teacher",Qt::CaseSensitive) || fileNameList[1].contains("teacher",Qt::CaseSensitive))
        {
            file_stu = fileNameList[0];
            file_tea  = fileNameList[1];
        }
        else
        {
            file_stu = fileNameList[1];
            file_tea  = fileNameList[0];
        }

        //for test
       // qDebug()<<file_stu<<"   "<<file_tea<<endl;



    }
    else
    fd->close();
}


void startpage::on_start_clicked()
{
    //初始化上课天数和上课节数以及教室数目和容纳人数
    day = ui->Day->text();
    time_pw = ui->Time->text();
    stu_num = ui->stu_num->text();
    room_num = ui->room_num->text();
    class_num = ui->class_num->text();

     qDebug()<<file_stu<<"   "<<file_tea<<" "<<stu_num<<"人 "<<room_num<<endl;
    QXlsx::Document xlsx_stu(file_stu);//学生选课表
    QXlsx::Document xlsx_tea(file_tea);//教师任课表
    std::ofstream out;
    out.open("out.txt");
    int row ,col;

    //输出以下四个数据到txt中
    out<<day.toStdString()<<" "<<time_pw.toStdString()<<endl;
    out<<room_num.toStdString()<<" "<<stu_num.toStdString()<<endl;

    //先读取输出教师任课
    for(row = 1 ; xlsx_tea.read(row , 1).toString() !="";row++)
    {
        for(col = 1 ; xlsx_tea.read(row,col).toString() !="";col++)
        {
            string str = xlsx_tea.read(row,col).toString().toStdString();
             out << str<<" ";
        }
        out<<endl;
    }

    //输出班级数量
    out<<class_num.toStdString()<<endl;

    //再读取输出学生选课
    int row_global=1;
    int count;
    QString classname;//保存当前班别的名字
    if(xlsx_stu.read(601 , 1).toString() =="")
    {
        qDebug()<<"601 is empty"<<endl;

    }
   while(xlsx_stu.read(row , 1).toString() !="")//每个班级循环一次
   {
       qDebug()<<"begin";
     count = 0;//人数
    classname = xlsx_stu.read(row_global,3).toString();//此处格式设定第三列为学生的班级
    for(;xlsx_stu.read(row_global , 3).toString() ==classname;row_global++,count++);
    out<<count<<endl;

    row_global -=count;//回到当前班级的第一个同学的位置
    int temp = row_global+count;
    //输出该班别同学的所有信息
    for(row = row_global ; row<temp ;row++,row_global++)
    {
        for(col = 1 ; xlsx_stu.read(row,col).toString() !=""  ;col++)
        {
            string str = xlsx_stu.read(row,col).toString().toStdString();
             out << str<<" ";
        }
        out<<endl;
    }
    qDebug()<<"row: "<<row<<"     "<<"row_global"<<row_global<<endl;
   }






   qDebug()<<"End"<<endl;
    out.close();
}


void startpage::on_export_2_clicked()
{
    QVector<QString> buf_out;
    QString ID ;
    ID = ui->ID->text();

    //找不到该ID就无法导出
    if(!e.searchSchedule(ID,buf_out)) return;
    //要导出的文件的目录

    export_filename = ID+".xlsx";
    QXlsx::Document xlsx_ex;

    //执行写操作
    QStringList list;
    QStringList week={"星期一","星期二","星期三","星期四","星期五"};
    QStringList classes={"第一节","第二节","第三节","第四节","第五节","第六节","第七节","第八节","第九节","第十节","第十一节"};
    qDebug()<<buf_out[0];

    for(int row=1;row<6;row++)
    {
        QString temp= buf_out[row-1];
        qDebug()<<temp;
        list = temp.split('|');
        qDebug()<<list;
        qDebug()<<list.size();
        //写入星期几
        xlsx_ex.write(1,row+1,week[row-1]);


        for(int column=1;column<=list.size();column++)
        {
            //写入第几节
            if(row==1)
                xlsx_ex.write(column+1,1,classes[column-1]);
            qDebug()<<list[column-1];
            //写入课程表
            xlsx_ex.write(column+1,row+1,list[column-1]);
        }
    }


    xlsx_ex.saveAs(export_filename);

    //导出的文件夹的目录
    QString saveDir  = QFileDialog::getExistingDirectory(this,tr("文件另存为"),"",QFileDialog:: QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    qDebug()<<saveDir;
    if(saveDir == NULL)
    {
        QMessageBox msg;
        msg.setText("请选择导出路径");
    }
    else
    {
        //加个重写覆盖
        if(e.copyFileToPath("./"+export_filename,saveDir+"/"+export_filename,1))
            qDebug()<<"success : "<<saveDir+'/'+export_filename ;
        else
            qDebug()<<"lose";
    }
}

void startpage::on_export_demo_clicked()
{

    QString export_filename_stu = "Student.xlsx";
    QString export_filename_tea = "Teacher.xlsx";

    QDir dir_stu("./template/"+export_filename_stu);
    QDir dir_tea("./template/"+export_filename_tea);

    //导出的文件夹的目录
    QString saveDir  = QFileDialog::getExistingDirectory(this,tr("文件另存为"),"",QFileDialog:: QFileDialog::ShowDirsOnly
                                                    | QFileDialog::DontResolveSymlinks);
    qDebug()<<saveDir;
    if(saveDir == NULL)
    {
        QMessageBox msg;
        msg.setText("请选择导出路径");
        return ;
    }
    else
    {
        //加个重写覆盖
        if(e.copyFileToPath(dir_stu.absolutePath() , saveDir+"/"+export_filename_stu,1) && e.copyFileToPath(dir_tea.absolutePath(),saveDir+"/"+export_filename_tea,1))

            qDebug()<<"success : "<<dir_stu.absolutePath()  ;
        else

            qDebug()<<"lose"<<"    "<<dir_stu.absolutePath() ;
    }
}
