PROG=   rpass

USRDIR=  /usr/local
BINDIR=  $(USRDIR)/bin
MANDIR=  $(USRDIR)/man

INSTALL_DIR=  install -dm 755
INSTALL_BIN=  install -m 555
INSTALL_MAN=  install -m 444

rpass: rpass.c
	cc -Wall -std=c99 -o rpass rpass.c -lm

.PHONY: clean install
clean:
	rm -f ${OBJS} ${COMPAT} rpass

install:
	${INSTALL_DIR} ${DESTDIR}${BINDIR}
	${INSTALL_DIR} ${DESTDIR}${MANDIR}/man1
	${INSTALL_BIN} ${PROG} ${DESTDIR}${BINDIR}
	${INSTALL_MAN} ${PROG}.1 ${DESTDIR}${MANDIR}/man1
