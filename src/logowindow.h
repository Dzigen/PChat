#ifndef LOGOWINDOW_H
#define LOGOWINDOW_H

#include <QMainWindow>
#include "loginwindow.h"
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui { class LogoWindow; }
QT_END_NAMESPACE

class LogoWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* Constructor */
    LogoWindow(QWidget *parent = nullptr);
    /* Destructor */
    ~LogoWindow();

private slots:
    /* Close logo window and open uthorization window */
    void on_start_button_clicked();

private:
    /* Pinter on current window */
    Ui::LogoWindow *ui;
    /* Pointer on authoriztion window */
    LoginWindow *login;
};
#endif // LOGOWINDOW_H
