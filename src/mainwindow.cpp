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
    int a = 0;
    a = a + 9;
    a++;
}

void MainWindow::on_btnStartModeling_clicked()
{
    try
    {
        if (ui->edtModelingTime->text() == "" || ui->edtMaxMemorySize->text() == "" || ui->edtA->text() == "" ||
                ui->edtB->text() == "" || ui->edtSigma->text() == "" || ui->edtMatExp->text() == "" ||
                ui->edtMaxBorder->text() == "")
            QMessageBox::information(this, "Error", "You have not inputed all data!", QMessageBox::Ok);
        else
        {
            double endModelingTime = ui->edtModelingTime->text().toDouble();
            int maxMemorySize = ui->edtMaxMemorySize->text().toInt();
            double a = ui->edtA->text().toDouble();
            double b = ui->edtB->text().toDouble();
            double sigma = ui->edtSigma->text().toDouble();
            double matExp = ui->edtMatExp->text().toDouble();
            double maxBorder = ui->edtMaxBorder->text().toDouble();

            Singleton::Instance().GetControlProgram()->ConfigureSystem(endModelingTime, maxMemorySize, a, b, matExp,
                                                                       sigma, maxBorder);
            Singleton::Instance().GetControlProgram()->StartModeling();
        }
    }
    catch (Exception& exception)
    {
        QMessageBox::information(this, "Error", exception.GetMessage(), QMessageBox::Ok);
    }
}
