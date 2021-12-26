#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* Map with authoriztin errors */
    QMap<int, QString> errors_map = {
        {1, "Присутствуют незаполненные поля"},
        {2, "Длина пароля меньше 8 символов"},
        {3, "Длина логина меньше 4 символов"},
        {4, "Длина логина больше 18 символов"},
        {5, "Длина пароля больше 32 символов"},
        {6, "Недопустимые символы в логине"},
        {7, "Недопустимые символы в пароле"}
    };
    /* Constructor */
    LoginWindow(QWidget *parent = nullptr);
    /* Destructor */
    ~LoginWindow();
    /* Plugs */
    bool exp_user_exists = false;
    bool exp_correct_data = false;
    bool authorized = false;

private slots:
    /* Open a section with registration */
    void on_registration_label_clicked();
    /* Open a section with authorization */
    void on_login_label_clicked();
    /* Registrate or authorize, depends on current section state */
    void on_login_button_clicked();

private:
    /* Pointer on current window */
    Ui::LoginWindow *ui;
};
#endif // LOGINWINDOW_H

/* Checker for input data from forms */
int check_input_data(QString pswrd, QString login);

/* Some plugs */
void auth_user(QString pswrd, QString log);

void register_user(QString pswrd, QString log);

bool is_data_correct(QString pswrd, QString log, bool expected);

bool is_user_exist(QString log, bool expected);



