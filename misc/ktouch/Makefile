# $NetBSD: Makefile,v 1.38 2018/08/16 18:55:02 adam Exp $

DISTNAME=	ktouch-${_KDE_VERSION}
PKGREVISION=	12
CATEGORIES=	misc
COMMENT=	KDE touch typing tutor

.include "../../meta-pkgs/kde4/Makefile.kde4"

.include "../../meta-pkgs/kde4/kde4.mk"

DEPENDS+=	kqtquickcharts-[0-9]*:../../graphics/kqtquickcharts4
DEPENDS+=	qt4-sqlite3-[0-9]*:../../x11/qt4-sqlite3

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libxkbfile/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
