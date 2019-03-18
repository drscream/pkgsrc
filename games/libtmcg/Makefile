# $NetBSD: Makefile,v 1.6 2018/11/14 22:21:29 kleink Exp $

DISTNAME=	libTMCG-1.3.17
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	http://download.savannah.gnu.org/releases/libtmcg/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/libtmcg/
COMMENT=	C++ library for creating secure and verifiable online card games
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c c++
GNU_CONFIGURE=	yes
USE_TOOLS+=	autoconf automake
USE_LIBTOOL=	yes
INFO_FILES=	yes

BUILD_DEPENDS+=	gtexinfo-[0-9]*:../../devel/gtexinfo

CONFIGURE_ARGS+=	--infodir=${PREFIX:Q}/${PKGINFODIR:Q}

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
