# $NetBSD: Makefile,v 1.20 2018/07/04 13:40:40 jperkin Exp $
#

DISTNAME=	larswm-7.5.3
PKGREVISION=	1
CATEGORIES=	wm x11
#MASTER_SITES=	http://home.earthlink.net/~lab1701/larswm/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DOCFILES}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://home.earthlink.net/~lab1701/larswm/
COMMENT=	9wm-like window manager

EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

DOCFILES=	keyboard_refcard.pdf mouse_refcard.pdf

USE_IMAKE=	YES

EGDIR=		${PREFIX}/share/examples/larswm
CONF_FILES=	${EGDIR}/sample.larswmrc ${PKG_SYSCONFDIR}/larswmrc

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=	-DPKG_SYSCONFDIR=\"${PKG_SYSCONFDIR:Q}\"

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	larswm.man
SUBST_SED.paths+=	-e 's,@PKG_SYSCONFDIR@,${PKG_SYSCONFDIR},g'
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	share/doc/larswm share/examples/larswm

post-install:
.for pdf in ${DOCFILES}
	${INSTALL_DATA} ${DISTDIR}/${pdf} ${DESTDIR}${PREFIX}/share/doc/larswm
.endfor
	${INSTALL_DATA} ${WRKSRC}/sample.* ${DESTDIR}${EGDIR}

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
