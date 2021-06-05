include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG += qt

QMAKE_CXXFLAGS += -Wall -Wextra
QMAKE_CFLAGS += -Wall -Wextra

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

SOURCES += main.cpp \
    ../app/save.cpp \
    ../app/show.cpp \
    ../app/showfirstwords.cpp \
    ../app/text/append_line.cpp \
    ../app/text/create_text.cpp \
    ../app/text/m.cpp \
    ../app/text/mwef.cpp \
    ../app/text/process_forward.cpp \
    ../app/text/remove_all.cpp \
    ../app/text/rn.cpp

INCLUDEPATH += ../app ../app/text
 

HEADERS += \
    ../app/common.h \
    ../app/text/_text.h \
    ../app/text/text.h \
    mweftest.h \
    savetest.h \
    showfirstwordstest.h
