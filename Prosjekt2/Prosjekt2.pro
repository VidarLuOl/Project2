TEMPLATE = subdirs
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SUBDIRS += \
    main-program \
    tests

tests.depends = main-program
