#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

//select path
void Widget::on_btn1_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "choose src Directory", "/");

    if (path.isEmpty())
    {
        return;
    }
    else
    {
        path.replace(QRegExp("\\/"), "\\");  //使用正则表达式替换分割符
        ui->lineEdit1->setText(path);
    }
}

//select single files
void Widget::on_btn2_clicked()
{
    QString file = QFileDialog::getOpenFileName(
                    this, "选择要播放的文件",
                    "/",
                    "视频文件 (*.flv *.rmvb *.avi *.mp4);; 所有文件 (*.*);; ");

    if(!(file.isEmpty()))
    {
        ui->lineEdit2->setText(file);
    }
}

//select multy files
void Widget::on_btn3_clicked()
{
    QStringList pathlist = QFileDialog::getOpenFileNames(
                this, QString::fromLocal8Bit("选择转码文件"),
                "/",
                QString::fromLocal8Bit("视频文件(*.mp4 *.m3u8);;所有文件（*.*);;"));

    for (int i = 0; i < pathlist.size(); i++)
    {
        QString strName = pathlist[i];
        ui->comboBox->addItem(strName);
    }
}
