TEMPLATE = lib
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    *.cpp \

HEADERS += \
    text.h \
    _text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
