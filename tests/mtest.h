#ifndef MTEST_H
#define MTEST_H

#include <gtest/gtest.h>
#include <QDir>
#include <QFile>

#include "common.h"
#include "_text.h"

TEST(mtest, begin_word)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "|qwerty qwert\n";
            append_line(txt, "qwerty qwert");
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mtest, middle_word)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "qwe|rty qwert\n";
            append_line(txt, "qwerty qwert");
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 3);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mtest, end_word)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "qwerty| qwert\n";
            append_line(txt, "qwerty qwert");
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 6);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mtest, negative_pos)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "|qwerty qwert\n";
            append_line(txt, "qwerty qwert");
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 0);
    m(txt, 3, -1);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mtest, negative_str)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "|qwerty qwert\n";
            append_line(txt, "qwerty qwert");
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 0);
    m(txt, -3, 1);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mtest, bigger_than_len_str)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "qwerty qwert|\n";
            append_line(txt, "qwerty qwert");
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 100);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mtest, bigger_than_str)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "|qwerty qwert\n";
            append_line(txt, "qwerty qwert");
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 0);
    m(txt, 100, 100);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mtest, empty)
{
    text txt = create_text();
    std::string out = "";

    testing::internal::CaptureStderr();

    m(txt, 0, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStderr();
    ASSERT_TRUE(text == "There are already no any lines in the text!\n");
}

#endif // MTEST_H
