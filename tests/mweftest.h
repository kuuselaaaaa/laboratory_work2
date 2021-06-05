#ifndef MWEFTEST_H
#define MWEFTEST_H

#include <gtest/gtest.h>
#include <QDir>
#include <QFile>

#include "common.h"
#include "_text.h"

TEST(mweftest, noempty)
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

    m(txt, 3, 3);
    mwef(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mweftest, second_word)
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

    m(txt, 3, 8);
    mwef(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mweftest, begin_word)
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

    m(txt, 3, 0);
    mwef(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mweftest, spaces)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "qwerty | qwert\n";
            append_line(txt, "qwerty  qwert");
        } else {
            append_line(txt, "qwerty  qwert");
            out += "qwerty  qwert\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 7);
    mwef(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mweftest, empty_strings)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        if (i == 3) {
            out += "|\n";
            append_line(txt, "");
        } else {
            append_line(txt, "");
            out += "\n";
        }
    }

    testing::internal::CaptureStdout();

    m(txt, 3, 7);
    mwef(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(mweftest, empty)
{
    text txt = create_text();
    append_line(txt, "");
    std::string out = "|\n";

    testing::internal::CaptureStdout();

    m(txt, 0, 0);
    mwef(txt);
    show(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}


#endif // MWEFTEST_H
