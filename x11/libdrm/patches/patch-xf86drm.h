--- xf86drm.h.orig	Tue Sep 25 07:53:24 2018
+++ xf86drm.h	Tue Sep 25 08:18:22 2018
@@ -484,6 +484,17 @@
 #endif /* architecture */
 #endif /* __GNUC__ >= 2 */
 
+#if defined(__SUNPRO_C)
+#include <atomic.h>
+#define atomic_cmpset_int(p, c, n) ((c == atomic_cas_uint(p, c, n)) ? 1 : 0)
+#define DRM_CAS(lock,old,new,__ret)          \
+               do {                          \
+                                       unsigned int __result, __old = (old);\
+                                       __result = !atomic_cmpset_int(lock,__old,new);\
+                                       __ret = __result;          \
+                               } while(0)
+#endif
+
 #ifndef DRM_CAS
 #define DRM_CAS(lock,old,new,ret) do { ret=1; } while (0) /* FAST LOCK FAILS */
 #endif
@@ -888,6 +899,14 @@
 extern int drmSyncobjReset(int fd, const uint32_t *handles, uint32_t handle_count);
 extern int drmSyncobjSignal(int fd, const uint32_t *handles, uint32_t handle_count);
 
+#ifdef __sun
+extern int _sun_drm_get_major(void);
+extern int _sun_drm_find_device(int min, char **pathp);
+extern int _sun_drm_get_subsystem(char *path);
+extern int _sun_drm_get_pci_bus_info(char *path, drmPciBusInfo *bus);
+extern int _sun_drm_get_pci_dev_info(char *path, drmPciDeviceInfo *dev);
+#endif /* __sun */
+
 #if defined(__cplusplus)
 }
 #endif
