# $NetBSD: Makefile,v 1.8 2018/10/10 08:16:22 adam Exp $

DISTNAME=	async-timeout-3.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/async-timeout/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/aio-libs/async_timeout
COMMENT=	Timeout context manager for asyncio programs
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

.include "../../lang/python/pyversion.mk"

PYTHON_VERSIONS_INCOMPATIBLE=	27 34

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
