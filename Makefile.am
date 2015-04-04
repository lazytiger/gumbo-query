#
ACLOCAL_AMFLAGS = -I m4

# http://www.gnu.org/software/automake/manual/html_node/Libtool-Libraries.html
lib_LTLIBRARIES = libgumbo_query.la
libgumbo_query_la_CXXFLAGS = -Wall
libgumbo_query_la_LDFLAGS = -lgumbo
libgumbo_query_la_SOURCES = \
src/Document.cpp \
src/Document.h \
src/Node.cpp \
src/Node.h \
src/Object.cpp \
src/Object.h \
src/Parser.cpp \
src/Parser.h \
src/QueryUtil.cpp \
src/QueryUtil.h \
src/Selection.cpp \
src/Selection.h \
src/Selector.cpp \
src/Selector.h

include_HEADERS = \
src/Document.h \
src/Node.h \
src/Object.h \
src/Parser.h \
src/QueryUtil.h \
src/Selection.h \
src/Selector.h

noinst_PROGRAMS = main

LDADD = libgumbo_query.la

AM_CPPFLAGS = -I"$(srcdir)/src"

main_SOURCES = examples/main.cpp