#ifndef RNTEST_H
#define RNTEST_H

#include <gtest/gtest.h>
#include <QDir>
#include <QFile>

#include "common.h"
#include "_text.h"

TEST(rntest, noempty)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            append_line(txt, "qwerty qwert");
        } else if (i == 4) {
            append_line(txt, "qwerty qwert");
            out += "|qwerty qwert\n";
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 0);
    rn(txt, 3);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(rntest, begin_text)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            append_line(txt, "qwerty qwert");
        } else if (i == 1) {
            append_line(txt, "qwerty qwert");
            out += "|qwerty qwert\n";
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    rn(txt, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(rntest, end_text)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            append_line(txt, "qwerty qwert");
        } else if (i == 8) {
            append_line(txt, "qwerty qwert");
            out += "|qwerty qwert\n";
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 9, 0);
    rn(txt, 9);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(rntest, move_cursor)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            append_line(txt, "qwerty qwert");
        } else if (i == 8) {
            append_line(txt, "qwerty qwert");
            out += "qwer|ty qwert\n";
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 9, 4);
    rn(txt, 9);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(rntest, negative_pos)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 9) {
            append_line(txt, "qwerty qwert");
            out += "qwer|ty qwert\n";
        } else {
            append_line(txt, "qwerty qwert");
            out += "qwerty qwert\n";
        }
    }

    testing::internal::CaptureStderr();

    m(txt, 9, 4);
    rn(txt, -9);
    show(txt);
    std::string text = testing::internal::GetCapturedStderr();
    ASSERT_TRUE(text == "Invalid arguments");
}

TEST(rntest, one_string)
{
    text txt = create_text();

    append_line(txt, "");

    testing::internal::CaptureStderr();

    m(txt, 0, 0);
    rn(txt, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStderr();
    ASSERT_TRUE(text == "There are already no any lines in the text!\n");
}

TEST(rntest, empty)
{
    text txt = create_text();

    testing::internal::CaptureStderr();

    rn(txt, 0);
    show(txt);
    std::string text = testing::internal::GetCapturedStderr();
    ASSERT_TRUE(text == "There are already no any lines in the text!\nThere are already no any lines in the text!\n");
}

#endif // RNTEST_H
