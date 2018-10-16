diff ... libdrm_lists.h
--- libdrm_lists.h.orig	Thu Feb 14 10:14:08 2013
+++ libdrm_lists.h	Sat Oct 29 18:53:40 2016
@@ -96,18 +96,18 @@
 	     (__item) = (__temp), (__temp) = (__item)->prev)
 
 #define DRMLISTFOREACHENTRY(__item, __list, __head)                            \
-	for ((__item) = DRMLISTENTRY(typeof(*__item), (__list)->next, __head); \
+	for ((__item) = DRMLISTENTRY(__typeof(*__item), (__list)->next, __head); \
 	     &(__item)->__head != (__list);                                    \
-	     (__item) = DRMLISTENTRY(typeof(*__item),                          \
+	     (__item) = DRMLISTENTRY(__typeof(*__item),                          \
 				     (__item)->__head.next, __head))
 
 #define DRMLISTFOREACHENTRYSAFE(__item, __temp, __list, __head)                \
-	for ((__item) = DRMLISTENTRY(typeof(*__item), (__list)->next, __head), \
-	     (__temp) = DRMLISTENTRY(typeof(*__item),                          \
+	for ((__item) = DRMLISTENTRY(__typeof(*__item), (__list)->next, __head), \
+	     (__temp) = DRMLISTENTRY(__typeof(*__item),                          \
 				     (__item)->__head.next, __head);           \
 	     &(__item)->__head != (__list);                                    \
 	     (__item) = (__temp),                                              \
-	     (__temp) = DRMLISTENTRY(typeof(*__item),                          \
+	     (__temp) = DRMLISTENTRY(__typeof(*__item),                          \
 				     (__temp)->__head.next, __head))
 
 #define DRMLISTJOIN(__list, __join) if (!DRMLISTEMPTY(__list)) {	\
