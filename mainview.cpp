#include "mainview.h"
#include "ui_mainview.h"
#include <QTcpServer>
#include <QMessageBox>

static int PORT_NUMBER = 23;
static int WAIT_FOR_DATA_MS = 200;

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
    if(StartServer()){
        ui->btnStartServer->setEnabled(false);
        ui->btnStopServer->setEnabled(true);
    }
}

void MainView::on_btnStartServer_clicked()
{
    StopServer();
    ui->btnStartServer->setEnabled(true);
    ui->btnStopServer->setEnabled(false);
}

bool  MainView::StartServer()
{
    bool result = m_server->listen(QHostAddress::Any,
                                   PORT_NUMBER);
    if(!result){

        QMessageBox::critical(this,tr("Echo Server"),
                              tr("Unable to start the server: %1")
                              .arg(m_server->errorString()));
        return false;
    }
    return true;
}

void  MainView::StopServer()
{

}
