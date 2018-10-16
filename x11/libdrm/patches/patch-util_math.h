diff ... util_math.h
--- util_math.h.orig	Fri Oct 23 13:58:02 2015
+++ util_math.h	Sat Oct 29 20:59:51 2016
@@ -29,6 +29,6 @@
 #define MAX3( A, B, C ) ((A) > (B) ? MAX2(A, C) : MAX2(B, C))
 
 #define __align_mask(value, mask)  (((value) + (mask)) & ~(mask))
-#define ALIGN(value, alignment)    __align_mask(value, (typeof(value))((alignment) - 1))
+#define ALIGN(value, alignment)    __align_mask(value, (__typeof(value))((alignment) - 1))
 
 #endif /*_UTIL_MATH_H_*/
