# $NetBSD: Makefile,v 1.19 2018/05/13 11:24:44 markd Exp $

DISTNAME=	kpathsea
PKGNAME=	tex-${DISTNAME}-2018
TEXLIVE_REV=	47198

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ctan.org/pkg/kpathsea
COMMENT=	Translation tables for TeX
LICENSE=	gnu-lgpl-v2

CONFLICTS+=	tex-bin-kpathsea-[0-9]*
CONFLICTS+=	texlive-tetex<=2011nb2
SUPERSEDES=	tex-bin-kpathsea<=2008.12897

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/web2c
CONF_FILES+=	${PREFIX}/share/texmf-dist/web2c/fmtutil.cnf \
		${PKG_SYSCONFDIR}/web2c/fmtutil.cnf

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR} ${PREFIX}/share/texmf-dist

TEXLIVE_IGNORE_PATTERNS=	texmf-dist/web2c/mktex.opt \
				texmf-dist/web2c/mktex[a-z]* \
				texmf-dist/web2c/texmf.cnf

.include "../../print/texlive/package.mk"
.include "../../mk/bsd.pkg.mk"
