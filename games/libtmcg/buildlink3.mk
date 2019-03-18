# $NetBSD$

BUILDLINK_TREE+=	libtmcg

.if !defined(LIBTMCG_BUILDLINK3_MK)
LIBTMCG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtmcg+=	libtmcg>=1.3.17
BUILDLINK_PKGSRCDIR.libtmcg?=	../../games/libtmcg

.include "../../security/libgpg-error/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif	# LIBTMCG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtmcg
