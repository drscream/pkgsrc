# $NetBSD: Makefile,v 1.6 2018/11/14 22:21:29 kleink Exp $

DISTNAME=	SecureSkat-2.14
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	http://download.savannah.gnu.org/releases/secureskat/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/secureskat/
COMMENT=	P2P implementation of the card game Skat
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../databases/gdbm/buildlink3.mk"
.include "../../games/libtmcg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
