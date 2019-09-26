TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += C:\armadillo-9.600.6\include
DEPENDPATH += C:\armadillo-9.600.6\include

LIBS += \
        -larmadillo -lblas -llapack

SOURCES += \
        jacobi.cpp \
        main.cpp \
        one_dimension.cpp \
        three_dimensions.cpp

HEADERS += \
        jacobi.h \ \
    one_dimension.h \
    three_dimensions.h

