--- include/drm/drm.h.orig	Thu Aug 23 22:01:55 2018
+++ include/drm/drm.h	Tue Oct 16 10:46:48 2018
@@ -46,6 +46,7 @@
 
 #include <sys/ioccom.h>
 #include <sys/types.h>
+#include <sys/types32.h>
 typedef int8_t   __s8;
 typedef uint8_t  __u8;
 typedef int16_t  __s16;
@@ -681,7 +682,11 @@
 };
 
 #define DRM_RDWR O_RDWR
+#ifdef O_CLOEXEC
 #define DRM_CLOEXEC O_CLOEXEC
+#else
+#define DRM_CLOEXEC 0
+#endif
 struct drm_prime_handle {
 	__u32 handle;
 
