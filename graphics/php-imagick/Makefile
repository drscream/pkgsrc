# $NetBSD: Makefile,v 1.16 2018/11/14 22:21:44 kleink Exp $

MODNAME=		imagick
PECL_VERSION=		3.4.3
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
PKGREVISION=		7
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	56 70 71 72

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

TEST_TARGET=		test

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
