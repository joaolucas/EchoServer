#include "mainview.h"
#include "ui_mainview.h"
#include <QTcpServer>

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainView),
    m_server(new QTcpServer(this))
{
    ui->setupUi(this);
}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_btnStopServer_clicked()
{
    StartServer();
    ui->btnStartServer->setEnabled(false);
    ui->btnStopServer->setEnabled(true);
}

void MainView::on_btnStartServer_clicked()
{
    StopServer();
    ui->btnStartServer->setEnabled(true);
    ui->btnStopServer->setEnabled(false);
}

bool  MainView::StartServer()
{

}

void  MainView::StopServer()
{

}
