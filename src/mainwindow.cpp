#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(Singleton::Instance().GetControlProgram(), SIGNAL(StatisticsCollectedSignal(int,int,int,double)), this,
            SLOT(StatisticsCollected(int,int,int,double)));
    connect(Singleton::Instance().GetControlProgram(), SIGNAL(ModelingFinishedSignal()), this,
            SLOT(ModelingFinished()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnStartModeling_clicked()
{
    try
    {
        if (ui->edtModelingTime->text() == "" || ui->edtMaxMemorySize->text() == "" || ui->edtA->text() == "" ||
                ui->edtB->text() == "" || ui->edtSigma->text() == "" || ui->edtMatExp->text() == "" ||
                ui->edtMaxBorder->text() == "" || ui->edtRequestDropPercent->text() == "" ||
                ui->edtRequestReturnPercent->text() == "")
            QMessageBox::information(this, "Error", "You have not inputed all data!", QMessageBox::Ok);
        else
        {
            ui->lwStatistics->addItem("");
            double endModelingTime = ui->edtModelingTime->text().toDouble();
            int maxMemorySize = ui->edtMaxMemorySize->text().toInt();
            double a = ui->edtA->text().toDouble();
            double b = ui->edtB->text().toDouble();
            double sigma = ui->edtSigma->text().toDouble();
            double matExp = ui->edtMatExp->text().toDouble();
            double maxBorder = ui->edtMaxBorder->text().toDouble();
            int requestDropPercent = ui->edtRequestDropPercent->text().toInt();
            int requestReturnPercent = ui->edtRequestReturnPercent->text().toInt();

            Singleton::Instance().GetControlProgram()->ConfigureSystem(endModelingTime, maxMemorySize, a, b, matExp,
                                                                       sigma, maxBorder, requestDropPercent,
                                                                       requestReturnPercent);
            Singleton::Instance().GetControlProgram()->StartModeling();
        }
    }
    catch (Exception& exception)
    {
        QMessageBox::information(this, "Error", exception.GetMessage(), QMessageBox::Ok);
    }
}

void MainWindow::ModelingFinished()
{
    QMessageBox::information(this, "Процесс завершен", "Процесс моделирования завершен", QMessageBox::Ok);
}

void MainWindow::StatisticsCollected(int currentRequestsNumberInMemory, int dropRequestNumber,
                                     int optimalQueueSize, double procUnitLoadKoff)
{
    QString statisticsString = "Число заявок в очереди = " + QString::number(currentRequestsNumberInMemory) + "\n" +
            "Число потерянных заявок = " +  QString::number(dropRequestNumber) + "\n" +
            "Оптимальный размер очереди = " + QString::number(optimalQueueSize) + "\n" +
            "Коэффициент загрузки обраб. аппарата = " + QString::number(procUnitLoadKoff) + "\n";
    ui->lwStatistics->addItem(statisticsString);
}
