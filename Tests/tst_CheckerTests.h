#ifndef TST_CHECKERTESTS_H
#define TST_CHECKERTESTS_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <QString>
#include <QMap>
#include <QRegExp>

using namespace testing;

int check_input_data(QString pswrd, QString login)
{
    if (pswrd == ""|| login == ""){ return 1; }
    if (pswrd.length() < 8) { return 2; }
    if (login.length() < 4) { return 3; }
    if (login.length() > 18) { return 4; }
    if (pswrd.length() > 32) { return 5; }
    QRegExp rx("^[a-z0-9_-]*$");
    if (rx.indexIn(login) == -1) { return 6; }
    if (rx.indexIn(pswrd) == -1) { return 7; }
    return 0;
}

QMap<int, QString> errors_map = {
    {1, "Присутствуют незаполненные поля"},
    {2, "Длина пароля меньше 8 символов"},
    {3, "Длина логина меньше 4 символов"},
    {4, "Длина логина больше 18 символов"},
    {5, "Длина пароля больше 32 символов"},
    {6, "Недопустимые символы в логине"},
    {7, "Недопустимые символы в пароле"}
};


TEST(CheckerTests, BlockTests7)
{
    ASSERT_EQ(check_input_data("", ""), 1);
}

TEST(CheckerTests, BlockTests8)
{
    ASSERT_EQ(check_input_data("12", "12345"), 2);
}

TEST(CheckerTests, BlockTests9)
{
    ASSERT_EQ(check_input_data("12345678", "12"), 3);
}

TEST(CheckerTests, BlockTests10)
{
    ASSERT_EQ(check_input_data("12345678", "1234567891234567890"), 4);
}

TEST(CheckerTests, BlockTests11)
{
    ASSERT_EQ(check_input_data("123456789123456789123456789123456",
                               "12345678"),
              5);
}

TEST(CheckerTests, BlockTests12)
{
    ASSERT_EQ(check_input_data("1235#32433", "a#sawqedsaa"), 6);
}

TEST(CheckerTests, BlockTests13)
{
    ASSERT_EQ(check_input_data("1234$6789", "123456789"), 7);
}

#endif // TST_CHECKERTESTS_H
