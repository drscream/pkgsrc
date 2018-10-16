diff ... util_double_list.h
--- util_double_list.h.orig	Tue Aug  2 16:22:45 2016
+++ util_double_list.h	Sat Nov 19 10:37:40 2016
@@ -110,7 +110,7 @@
 #ifndef container_of
 #define container_of(ptr, sample, member)				\
     (void *)((char *)(ptr)						\
-	     - ((char *)&((typeof(sample))0)->member))
+	     - ((char *)&((__typeof(sample))0)->member))
 #endif
 
 #define LIST_FOR_EACH_ENTRY(pos, head, member)				\
