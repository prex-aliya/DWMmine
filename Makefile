#include config.mk

cc = gcc
VERSION		=	0.1



X11INC = /usr/local/include
X11LIB = /usr/local/lib

INCS			= -I${X11INC}
VARMACRO	=	-DVERSION=\"${VERSION}\"
CFLAGS 		= -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS}


all:
	${CC} main.c ${VARMACRO} -c ${CFLAGS}
