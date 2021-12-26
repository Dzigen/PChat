#include "logowindow.h"
#include "ui_logowindow.h"
#include "loginwindow.h"


LogoWindow::LogoWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LogoWindow)
{
    ui->setupUi(this);
    login = new LoginWindow();
}

LogoWindow::~LogoWindow()
{
    delete ui;
}



void LogoWindow::on_start_button_clicked()
{
    login->show();
    this->close();
    this->~LogoWindow();
}

