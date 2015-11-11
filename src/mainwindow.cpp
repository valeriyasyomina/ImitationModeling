#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Queue<int> q(10);
    q.Add(1);
    q.Add(2);
    q.Add(3);

    q = q;

  /*  Queue<int> q2(2);
       q2.Add(5);
    q = q2;*/

    int a = 0;
    a = a + 9;
    a++;
  //  int a = q.Get();
   // int b = a + 1;
}
