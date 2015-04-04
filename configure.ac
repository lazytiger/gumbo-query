#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.
# https://www.gnu.org/software/autoconf/manual/autoconf-2.63/html_node/Setup.html

AC_PREREQ([2.65])
AC_INIT([gumbo-query], [0.0.1])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_SRCDIR([src/Document.cpp])
#AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile gumbo-query.pc])

# Check for compilers.
AC_PROG_CXX

# Check for libraries.
AC_CHECK_LIB([libgumbo])

# Check for header files.
AC_CHECK_HEADERS([gumbo.h])

# Init Automake & libtool
AM_INIT_AUTOMAKE([foreign subdir-objects])

m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])

LT_INIT

AC_OUTPUT
# need newline at end to avoid errors.
