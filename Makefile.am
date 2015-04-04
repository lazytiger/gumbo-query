#
ACLOCAL_AMFLAGS = -I m4

# http://www.gnu.org/software/automake/manual/html_node/Libtool-Libraries.html
lib_LTLIBRARIES = libgumboquery.la
libgumboquery_la_CXXFLAGS = -Wall
libgumboquery_la_LDFLAGS = -version-info 1:0:0 -no-undefined
libgumboquery_la_SOURCES = \
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

include_HEADERS = src/Document.h src/Node.h

noinst_PROGRAMS = main

LDADD = libgumboquery.la

AM_CPPFLAGS = -I"$(srcdir)/src"

main_SOURCES = examples/main.cpp