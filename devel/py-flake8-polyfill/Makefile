# $NetBSD: Makefile,v 1.2 2018/01/01 21:26:15 adam Exp $

DISTNAME=	flake8-polyfill-1.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/flake8-polyfill/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://gitlab.com/pycqa/flake8
COMMENT=	Polyfill package for Flake8 plugins
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-pep8-[0-9]*:../../devel/py-pep8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

# needs to be installed
do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
