#ifndef SHOWFIRSTWORDSTEST_H
#define SHOWFIRSTWORDSTEST_H

#include <gtest/gtest.h>
#include <QDir>
#include <QFile>

#include "common.h"
#include "_text.h"

TEST(sfwtest, noempty)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        append_line(txt, "qwerty qwert");
        out += "qwerty\n";
    }

    testing::internal::CaptureStdout();

    showfirstwords(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(sfwtest, only_first_words)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        append_line(txt, "qwerty");
        out += "qwerty\n";
    }

    testing::internal::CaptureStdout();

    showfirstwords(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(sfwtest, spaces_before_first_words)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        append_line(txt, "  qwerty");
        out += "qwerty\n";
    }

    testing::internal::CaptureStdout();

    showfirstwords(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(sfwtest, empty_strings)
{
    text txt = create_text();
    std::string out = "";

    for (int i = 0; i < 10; i++) {
        append_line(txt, "");
        out += "\n";
    }

    testing::internal::CaptureStdout();

    showfirstwords(txt);
    std::string text = testing::internal::GetCapturedStdout();
    ASSERT_TRUE(text == out);
}

TEST(sfwtest, one_string)
{
    text txt = create_text();
    std::string out = "";

    append_line(txt, "");

    testing::internal::CaptureStderr();

    showfirstwords(txt);
    std::string text = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(text.c_str(), "");
}

TEST(sfwtest, empty)
{
    text txt = create_text();
    std::string out = "";

    testing::internal::CaptureStderr();

    showfirstwords(txt);
    std::string text = testing::internal::GetCapturedStderr();
    ASSERT_STREQ(text.c_str(), "There are already no any lines in the text!\n");
}

#endif // SHOWFIRSTWORDSTEST_H
