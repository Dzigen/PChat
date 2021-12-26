#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QDebug>
#include <QRegExp>
#include <QFont>
#include <QPalette>

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    ui->err_message->setVisible(false);
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_registration_label_clicked()
{
    this->setWindowTitle("Регистрация");

    QFont f("Inter", 15);
    f.setUnderline(true);
    f.setBold(true);
    ui->registration_label->setFont(f);
    ui->registration_label->setStyleSheet("QPushButton { color: #5C3566; }");

    f.setUnderline(false);
    f.setBold(false);
    ui->login_label->setFont(f);
    ui->login_label->setStyleSheet("QPushButton { color: #BA6A9C; }");

    ui->err_message->setVisible(false);
    ui->login_button->setText("Создать аккаунт");
}


void LoginWindow::on_login_label_clicked()
{
    this->setWindowTitle("Вход");

    QFont f("Inter", 15);
    f.setUnderline(true);
    f.setBold(true);
    ui->login_label->setFont(f);
    ui->login_label->setStyleSheet("QPushButton { color: #5C3566; }");

    f.setUnderline(false);
    f.setBold(false);
    ui->registration_label->setFont(f);
    ui->registration_label->setStyleSheet("QPushButton { color: #BA6A9C; }");

    ui->login_button->setText("Войти");
}


void LoginWindow::on_login_button_clicked()
{
    QString password = ui->password_input->text();
    QString login = ui->login_input->text();
    int msg = check_input_data(password, login);
    if (msg != 0)
    {
        ui->err_message->setVisible(true);
        ui->err_message->setText(errors_map[msg]);
    }
    else
    {
        ui->err_message->setVisible(false);
        if (this->windowTitle() == "Вход")
        {
            if (is_data_correct(password, login, exp_correct_data))
            {
                authorized = true;
                auth_user(password, login);
            }
            else
            {
                ui->err_message->setVisible(true);
                ui->err_message->setText("Пароль или логин введены неверно");
            }
        }
        else
        {
            if (is_user_exist(login, exp_user_exists))
            {
                ui->err_message->setVisible(true);
                ui->err_message->setText("Пользователь с таким логином уже существует");
            }
            else
            {
                register_user(password, login);
                ui->err_message->setVisible(true);
                ui->err_message->setText("Регистрация прошла успешно");
                ui->login_label->click();
            }
        }
    }
}


int check_input_data(QString pswrd, QString login)
{
    if (pswrd == ""|| login == ""){
        return 1;
    }
    if (pswrd.length() < 8) { return 2; }
    if (login.length() < 4) { return 3; }
    if (login.length() > 18) { return 4; }
    if (pswrd.length() > 32) { return 5; }
    QRegExp rx("^[a-z0-9_-]*$");
    if (rx.indexIn(login) == -1) { return 6; }
    if (rx.indexIn(pswrd) == -1) { return 7; }
    return 0;
}

void auth_user(QString pswrd, QString log)
{
}

void register_user(QString pswrd, QString log)
{
}

bool is_data_correct(QString pswrd, QString log, bool expected)
{
    return expected;
}

bool is_user_exist(QString log, bool expected)
{
    return expected;
}

