PROG=	rpass

PREFIX	= /usr/local
BINDIR	= $(PREFIX)/bin
MANDIR	= $(PREFIX)/man

CFLAGS	+= -Wall -Wextra -pedantic-errors

INSTALL_BIN	= install -m 0555
INSTALL_MAN	= install -m 0444

INSTALL_DIR=  install -dm 755
INSTALL_BIN=  install -m 555
INSTALL_MAN=  install -m 444

VERSION_MAJOR	= 0
VERSION_MINOR	= 2
VERSION_PATCH	= 1

rpass: rpass.c
	${CC} ${CFLAGS} -DVERSION_MAJOR=${VERSION_MAJOR} \
	    -DVERSION_MINOR=${VERSION_MINOR} -DVERSION_PATCH=${VERSION_PATCH} \
	    rpass.c -o $@ -lm

rpass.1.html:  rpass.1
	mandoc -T html -O style=man.css rpass.1 > rpass.1.html

.PHONY: manhtml clean install
manhtml: rpass.1.html

clean:
	rm -f rpass rpass.1.html

install:
	${INSTALL_DIR} ${DESTDIR}${BINDIR}
	${INSTALL_DIR} ${DESTDIR}${MANDIR}/man1
	${INSTALL_BIN} ${PROG} ${DESTDIR}${BINDIR}
	${INSTALL_MAN} ${PROG}.1 ${DESTDIR}${MANDIR}/man1
