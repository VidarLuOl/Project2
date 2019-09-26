TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += C:\armadillo-9.600.6\include
DEPENDPATH += C:\armadillo-9.600.6\include

LIBS += \
        -larmadillo -lblas -llapack

INCLUDEPATH += \


SOURCES += \
        tests-main.cpp \
        test-jacobi.cpp \
        ../main-program/jacobi.cpp

HEADERS += \
#        ../main-program/jacobi.h \
        catch.hpp

