#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new MyGraphicsScene(this))
{
    ui->setupUi(this);

    setWindowTitle("My Graphics World: By 龚建波");
    //本来想的是参照示例diagramscene做拖拽式然后锚定，但是太费时间了

    ui->graphicsView->setScene(scene);
    //scene->setSceneRect(0,0,1000,1000);

    //测试下关联，貌似qgwidget才可以layoutanchor，qgitem是通过父子关系来绑定
    MyBody *bd1=new MyBody;
    MyBody *bd2=new MyBody(bd1);
    bd2->setColor(Qt::darkCyan);
    bd2->setPos(100,100);
    bd2->setTransformOriginPoint(50,50);
    bd2->setRotation(45);

    scene->addItem(bd1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

