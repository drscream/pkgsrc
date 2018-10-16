--- xf86drm.c.orig	Tue Oct 16 10:26:26 2018
+++ xf86drm.c	Tue Oct 16 10:28:53 2018
@@ -95,6 +95,11 @@
 #endif
 #endif /* __OpenBSD__ */
 
+#if defined(__sun)
+/* Device majors are dynamic. */
+#define DRM_MAJOR	(_sun_drm_get_major())
+#endif /* __sun */
+
 #ifndef DRM_MAJOR
 #define DRM_MAJOR 226 /* Linux */
 #endif
@@ -362,9 +367,14 @@
     if (stat(DRM_DIR_NAME, &st)) {
         if (!isroot)
             return DRM_ERR_NOT_ROOT;
+#if defined(__sun)
+	/* Let the system do this. */
+	return DRM_ERR_NO_DEVICE;
+#else
         mkdir(DRM_DIR_NAME, DRM_DEV_DIRMODE);
         chown_check_return(DRM_DIR_NAME, 0, 0); /* root:root */
         chmod(DRM_DIR_NAME, DRM_DEV_DIRMODE);
+#endif
     }
 
     /* Check if the device node exists and create it if necessary. */
@@ -371,8 +381,13 @@
     if (stat(buf, &st)) {
         if (!isroot)
             return DRM_ERR_NOT_ROOT;
+#if defined(__sun)
+	/* Let the system do this. */
+	return DRM_ERR_NO_DEVICE;
+#else
         remove(buf);
         mknod(buf, S_IFCHR | devmode, dev);
+#endif
     }
 
     if (drm_server_info && drm_server_info->get_perms) {
@@ -418,6 +433,10 @@
     if (st.st_rdev != dev) {
         if (!isroot)
             return DRM_ERR_NOT_ROOT;
+#if defined(__sun)
+	/* Let the system do this. */
+	return DRM_ERR_NO_DEVICE;
+#else
         remove(buf);
         mknod(buf, S_IFCHR | devmode, dev);
         if (drm_server_info && drm_server_info->get_perms) {
@@ -424,6 +443,7 @@
             chown_check_return(buf, user, group);
             chmod(buf, devmode);
         }
+#endif
     }
     fd = open(buf, O_RDWR | O_CLOEXEC, 0);
     drmMsg("drmOpenDevice: open result is %d, (%s)\n",
@@ -545,6 +565,7 @@
     }
 }
 
+#ifndef __sun /* Avoid "static unused" warning */
 static const char *drmGetMinorName(int type)
 {
     switch (type) {
@@ -558,6 +579,7 @@
         return NULL;
     }
 }
+#endif /* __sun */
 
 /**
  * Open the device by bus ID.
@@ -1121,7 +1143,7 @@
     drm_map_t map;
 
     memclear(map);
-    map.handle = (void *)(uintptr_t)handle;
+    map.handle = (drm_handle_t)(uintptr_t)handle;
 
     if(drmIoctl(fd, DRM_IOCTL_RM_MAP, &map))
         return -errno;
@@ -2750,6 +2772,15 @@
     fstat(fd, &sbuf);
     d = sbuf.st_rdev;
 
+#if defined(__sun)
+    /*
+     * Get rid of clone-open bits in the minor number.
+     * See: the drm driver drm_sun_open()
+     * Don't have DRM_CLONEID_NBITS here.
+     */
+    d &= ~0x3fe00;
+#endif
+
     for (i = 0; i < DRM_MAX_MINOR; i++) {
         snprintf(name, sizeof name, DRM_DEV_NAME, DRM_DIR_NAME, i);
         if (stat(name, &sbuf) == 0 && sbuf.st_rdev == d)
@@ -2858,6 +2889,26 @@
 
     closedir(sysdir);
     return NULL;
+#elif defined(__sun)    /* illumos, OSol */
+    struct stat sbuf;
+    char *path = NULL;
+    int err, maj, min;
+
+    if (fstat(fd, &sbuf))
+        return (NULL);
+
+    maj = major(sbuf.st_rdev);
+    min = minor(sbuf.st_rdev);
+
+    if (maj != DRM_MAJOR || !S_ISCHR(sbuf.st_mode))
+        return (NULL);
+
+    /* Walk devices tree looking for this minor */
+    err = _sun_drm_find_device(min, &path);
+    if (err == 0)
+        return (path);
+    else
+        return NULL;
 #else
     struct stat sbuf;
     char buf[PATH_MAX + 1];
@@ -2992,6 +3043,20 @@
     return -EINVAL;
 #elif defined(__OpenBSD__)
     return DRM_BUS_PCI;
+#elif defined(__sun)	/* illumos, OSol */
+    char *path = NULL;
+    int ret;
+
+    if (maj != DRM_MAJOR)
+	    return -EINVAL;
+
+    ret = _sun_drm_find_device(min, &path);
+    if (ret != 0)
+	    return (ret);
+
+    ret = _sun_drm_get_subsystem(path);
+    free(path);
+    return (ret);
 #else
 #warning "Missing implementation of drmParseSubsystemType"
     return -EINVAL;
@@ -3064,6 +3129,21 @@
     info->func = pinfo.func;
 
     return 0;
+#elif defined(__sun)	/* illumos, OSol */
+    char *path = NULL;
+    int err;
+
+    if (maj != DRM_MAJOR)
+	    return -EINVAL;
+
+    err = _sun_drm_find_device(min, &path);
+    if (err != 0)
+	    return (err);
+
+    err = _sun_drm_get_pci_bus_info(path, info);
+    free(path);
+
+    return err;
 #else
 #warning "Missing implementation of drmParsePciBusInfo"
     return -EINVAL;
@@ -3234,6 +3314,21 @@
     device->subdevice_id = pinfo.subdevice_id;
 
     return 0;
+#elif defined(__sun)	/* illumos, OSol */
+    char *path = NULL;
+    int err;
+
+    if (maj != DRM_MAJOR)
+	    return -EINVAL;
+
+    err = _sun_drm_find_device(min, &path);
+    if (err != 0)
+	    return (err);
+
+    err = _sun_drm_get_pci_dev_info(path, device);
+    free(path);
+
+    return err;
 #else
 #warning "Missing implementation of drmParsePciDeviceInfo"
     return -EINVAL;
