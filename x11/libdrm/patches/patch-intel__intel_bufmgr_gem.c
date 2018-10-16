--- intel/intel_bufmgr_gem.c.orig	Wed May  9 22:26:03 2018
+++ intel/intel_bufmgr_gem.c	Tue Sep 25 08:10:26 2018
@@ -3422,6 +3422,16 @@
 static pthread_mutex_t bufmgr_list_mutex = PTHREAD_MUTEX_INITIALIZER;
 static drmMMListHead bufmgr_list = { &bufmgr_list, &bufmgr_list };
 
+static int
+compare_file_descriptor(int fd1, int fd2) {
+	struct stat stat1, stat2;
+	if (fstat (fd1, &stat1) < 0)
+		return -1;
+	if (fstat (fd2, &stat2) < 0)
+		return -1;
+	return (stat1.st_dev == stat2.st_dev) && (stat1.st_ino == stat2.st_ino);
+}
+
 static drm_intel_bufmgr_gem *
 drm_intel_bufmgr_gem_find(int fd)
 {
@@ -3428,7 +3438,8 @@
 	drm_intel_bufmgr_gem *bufmgr_gem;
 
 	DRMLISTFOREACHENTRY(bufmgr_gem, &bufmgr_list, managers) {
-		if (bufmgr_gem->fd == fd) {
+		if (bufmgr_gem->fd == fd ||
+		    compare_file_descriptor (bufmgr_gem->fd, fd)) {
 			atomic_inc(&bufmgr_gem->refcount);
 			return bufmgr_gem;
 		}
