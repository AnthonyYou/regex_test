TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /home/frontier/Documents/boost_1_60_0 \
            += /usr/include/curl

SOURCES += main.cpp \
    boost_regex/c_regex_traits.cpp \
    boost_regex/cpp_regex_traits.cpp \
    boost_regex/cregex.cpp \
    boost_regex/fileiter.cpp \
    boost_regex/icu.cpp \
    boost_regex/instances.cpp \
    boost_regex/posix_api.cpp \
    boost_regex/regex.cpp \
    boost_regex/regex_debug.cpp \
    boost_regex/regex_raw_buffer.cpp \
    boost_regex/regex_traits_defaults.cpp \
    boost_regex/static_mutex.cpp \
    boost_regex/usinstances.cpp \
    boost_regex/w32_regex_traits.cpp \
    boost_regex/wc_regex_traits.cpp \
    boost_regex/wide_posix_api.cpp \
    boost_regex/winstances.cpp

HEADERS += \
    boost_regex/internals.hpp

LIBS += -lcurl

