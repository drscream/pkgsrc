--- include/drm/i915_drm.h.orig	Wed May  9 22:26:03 2018
+++ include/drm/i915_drm.h	Tue Sep 25 08:09:58 2018
@@ -184,6 +184,7 @@
 	int pf_current_page;	/* which buffer is being displayed? */
 	int perf_boxes;		/* performance boxes to be displayed */
 	int width, height;      /* screen size in pixels */
+	int pad0;
 
 	drm_handle_t front_handle;
 	int front_offset;
@@ -223,6 +224,8 @@
 	int pipeB_w;
 	int pipeB_h;
 
+	int pad1;
+
 	/* fill out some space for old userspace triple buffer */
 	drm_handle_t unused_handle;
 	__u32 unused1, unused2, unused3;
@@ -324,11 +327,14 @@
 #define DRM_IOCTL_I915_FLUSH		DRM_IO ( DRM_COMMAND_BASE + DRM_I915_FLUSH)
 #define DRM_IOCTL_I915_FLIP		DRM_IO ( DRM_COMMAND_BASE + DRM_I915_FLIP)
 #define DRM_IOCTL_I915_BATCHBUFFER	DRM_IOW( DRM_COMMAND_BASE + DRM_I915_BATCHBUFFER, drm_i915_batchbuffer_t)
-#define DRM_IOCTL_I915_IRQ_EMIT         DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_IRQ_EMIT, drm_i915_irq_emit_t)
+/* I915_IRQ_EMIT is IOW not IOWR because it does its own copyout. */
+#define DRM_IOCTL_I915_IRQ_EMIT         DRM_IOW( DRM_COMMAND_BASE + DRM_I915_IRQ_EMIT, drm_i915_irq_emit_t)
 #define DRM_IOCTL_I915_IRQ_WAIT         DRM_IOW( DRM_COMMAND_BASE + DRM_I915_IRQ_WAIT, drm_i915_irq_wait_t)
-#define DRM_IOCTL_I915_GETPARAM         DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_GETPARAM, drm_i915_getparam_t)
+/* I915_GETPARAM is IOW not IOWR because it does its own copyout. */
+#define DRM_IOCTL_I915_GETPARAM         DRM_IOW( DRM_COMMAND_BASE + DRM_I915_GETPARAM, drm_i915_getparam_t)
 #define DRM_IOCTL_I915_SETPARAM         DRM_IOW( DRM_COMMAND_BASE + DRM_I915_SETPARAM, drm_i915_setparam_t)
-#define DRM_IOCTL_I915_ALLOC            DRM_IOWR(DRM_COMMAND_BASE + DRM_I915_ALLOC, drm_i915_mem_alloc_t)
+/* I915_ALLOC is IOW not IOWR because it's a noop */
+#define DRM_IOCTL_I915_ALLOC            DRM_IOW( DRM_COMMAND_BASE + DRM_I915_ALLOC, drm_i915_mem_alloc_t)
 #define DRM_IOCTL_I915_FREE             DRM_IOW( DRM_COMMAND_BASE + DRM_I915_FREE, drm_i915_mem_free_t)
 #define DRM_IOCTL_I915_INIT_HEAP        DRM_IOW( DRM_COMMAND_BASE + DRM_I915_INIT_HEAP, drm_i915_mem_init_heap_t)
 #define DRM_IOCTL_I915_CMDBUFFER	DRM_IOW( DRM_COMMAND_BASE + DRM_I915_CMDBUFFER, drm_i915_cmdbuffer_t)
@@ -390,6 +396,15 @@
 	struct drm_clip_rect *cliprects;	/* pointer to userspace cliprects */
 } drm_i915_batchbuffer_t;
 
+typedef struct drm_i915_batchbuffer32 {
+	int start;		/* agp offset */
+	int used;		/* nr bytes in use */
+	int DR1;		/* hw flags for GFX_OP_DRAWRECT_INFO */
+	int DR4;		/* window origin for GFX_OP_DRAWRECT_INFO */
+	int num_cliprects;	/* mulitpass with multiple cliprects? */
+	caddr32_t cliprects;	/* pointer to userspace cliprects */
+} drm_i915_batchbuffer32_t;
+
 /* As above, but pass a pointer to userspace buffer which can be
  * validated by the kernel prior to sending to hardware.
  */
@@ -402,6 +417,15 @@
 	struct drm_clip_rect *cliprects;	/* pointer to userspace cliprects */
 } drm_i915_cmdbuffer_t;
 
+typedef struct drm_i915_cmdbuffer32 {
+	caddr32_t buf;	/* pointer to userspace command buffer */
+	int sz;			/* nr bytes in buf */
+	int DR1;		/* hw flags for GFX_OP_DRAWRECT_INFO */
+	int DR4;		/* window origin for GFX_OP_DRAWRECT_INFO */
+	int num_cliprects;	/* mulitpass with multiple cliprects? */
+	caddr32_t cliprects;	/* pointer to userspace cliprects */
+} drm_i915_cmdbuffer32_t;
+
 /* Userspace can request & wait on irq's:
  */
 typedef struct drm_i915_irq_emit {
@@ -408,6 +432,10 @@
 	int *irq_seq;
 } drm_i915_irq_emit_t;
 
+typedef struct drm_i915_irq_emit32 {
+	caddr32_t irq_seq;
+} drm_i915_irq_emit32_t;
+
 typedef struct drm_i915_irq_wait {
 	int irq_seq;
 } drm_i915_irq_wait_t;
@@ -538,6 +566,11 @@
 	int *value;
 } drm_i915_getparam_t;
 
+typedef struct drm_i915_getparam32 {
+	int param;
+	caddr32_t value;
+} drm_i915_getparam32_t;
+
 /* Ioctl to set kernel params:
  */
 #define I915_SETPARAM_USE_MI_BATCHBUFFER_START            1
@@ -561,6 +594,13 @@
 	int *region_offset;	/* offset from start of fb or agp */
 } drm_i915_mem_alloc_t;
 
+typedef struct drm_i915_mem_alloc32 {
+	int region;
+	int alignment;
+	int size;
+	caddr32_t region_offset;	/* offset from start of fb or agp */
+} drm_i915_mem_alloc32_t;
+
 typedef struct drm_i915_mem_free {
 	int region;
 	int region_offset;
