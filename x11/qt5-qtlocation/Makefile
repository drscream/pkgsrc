# $NetBSD: Makefile,v 1.33 2018/12/09 18:52:13 adam Exp $

DISTNAME=	qtlocation-everywhere-src-${QTVERSION}
PKGNAME=	qt5-qtlocation-${QTVERSION}
PKGREVISION=	3
COMMENT=	Qt5 module for qtlocation

BUILD_TARGET=		sub-src
MAKE_ENV+=		QTDIR=${QTDIR}
INSTALL_ENV+=		INSTALL_ROOT=${DESTDIR}
INSTALLATION_DIRS+=	lib/pkgconfig

.include "../../x11/qt5-qtbase/Makefile.common"

post-install:
.for i in Qt5Location.pc Qt5Positioning.pc
	cd ${DESTDIR}${PREFIX}/lib/pkgconfig && \
	${LN} -f -s ${QTPREFIX}/lib/pkgconfig/${i} ${i}
.endfor

.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
