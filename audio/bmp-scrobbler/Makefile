# $NetBSD: Makefile,v 1.44 2018/11/14 22:21:00 kleink Exp $

DISTNAME=	xmms-scrobbler-0.4.0
PKGNAME=	${DISTNAME:S/xmms/bmp/}
PKGREVISION=	41
CATEGORIES=	audio
MASTER_SITES=	http://armish.linux-sevenler.org/downloads/pub/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.last.fm/
COMMENT=	BMP plugin for last.fm

LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES
USE_TOOLS+=	gmake pkg-config
CONFIGURE_ARGS+=	--disable-xmms-plugin

.include "../../audio/musicbrainz/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/bmp/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
