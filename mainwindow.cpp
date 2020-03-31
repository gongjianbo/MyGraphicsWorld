#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //测试配置
    //Qt5.12+VS2019 32bit
    setWindowTitle(u8"My Graphics World: By 龚建波");
    //本来想的是参照示例diagramscene做拖拽式然后拼接，但是太费时间了
}

MainWindow::~MainWindow()
{
    delete ui;
}

