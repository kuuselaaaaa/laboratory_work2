#ifndef SAVETEST_H
#define SAVETEST_H

#include <gtest/gtest.h>
#include <QDir>
#include <QFile>

#include "common.h"
#include "_text.h"

TEST(savetest, noempty)
{
    text txt = create_text();

    for (int i = 0; i < 10; i++) {
        append_line(txt, "qwerty");
    }

    save(txt, "save_test.txt");

    QFile file("save_test.txt");
    bool is_open = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(is_open, true);

    QString line_f;
    std::list<std::string>::iterator line_t = txt->lines->begin();

    for (int i = 0; i < 10; i++) {
        line_f = file.readLine();

        ASSERT_STREQ(line_f.toStdString().c_str(), (*line_t + "\n").c_str() );
        line_t++;
    }

    QDir dir(".");
    dir.remove("save_test.txt");
}

TEST(savetest, large_strings)
{
    text txt = create_text();

    for (int i = 0; i < 10; i++) {
        append_line(txt, "qwertyqwertyqwertyqwertyqwertyqwertyqwertyqwertyqwertyqwertyqwertyqwerty");
    }

    save(txt, "save_test.txt");

    QFile file("save_test.txt");
    bool is_open = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(is_open, true);

    QString line_f;
    std::list<std::string>::iterator line_t = txt->lines->begin();

    for (int i = 0; i < 10; i++) {
        line_f = file.readLine();

        ASSERT_STREQ(line_f.toStdString().c_str(), (*line_t + "\n").c_str() );
        line_t++;
    }

    QDir dir(".");
    dir.remove("save_test.txt");
}

TEST(savetest, empty_strings)
{
    text txt = create_text();

    for (int i = 0; i < 10; i++) {
        append_line(txt, "");
    }

    save(txt, "save_test.txt");

    QFile file("save_test.txt");
    bool is_open = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(is_open, true);

    QString line_f;
    std::list<std::string>::iterator line_t = txt->lines->begin();

    for (int i = 0; i < 10; i++) {
        line_f = file.readLine();

        ASSERT_STREQ(line_f.toStdString().c_str(), (*line_t + "\n").c_str() );
        line_t++;
    }

    QDir dir(".");
    dir.remove("save_test.txt");
}

TEST(savetest, with_empty_strings)
{
    text txt = create_text();

    for (int i = 0; i < 10; i++) {
        append_line(txt, "qwerty");
        append_line(txt, "");
    }

    save(txt, "save_test.txt");

    QFile file("save_test.txt");
    bool is_open = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(is_open, true);

    QString line_f;
    std::list<std::string>::iterator line_t = txt->lines->begin();

    for (int i = 0; i < 10; i++) {
        line_f = file.readLine();

        ASSERT_STREQ(line_f.toStdString().c_str(), (*line_t + "\n").c_str() );
        line_t++;
    }

    QDir dir(".");
    dir.remove("save_test.txt");
}

TEST(savetest, empty)
{
    text txt = create_text();

    save(txt, "save_test.txt");
    QFile file("save_test.txt");
    bool is_open = file.open(QIODevice::ReadOnly);
    ASSERT_EQ(is_open, true);

    QString line_f;
    std::list<std::string>::iterator line_t = txt->lines->begin();

    line_f = file.readLine();

    ASSERT_FALSE(line_f.toStdString().c_str() == "");
    ASSERT_TRUE((* line_t).c_str() == nullptr);

    QDir dir(".");
    dir.remove("save_test.txt");
}

#endif // SAVETEST_H
