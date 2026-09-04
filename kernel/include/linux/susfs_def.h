/*
 * KernelSU-Next Waydroid SUSFS shim: susfs_def.h.
 *
 * Declares the KernelSU-Next dev-susfs helper surface that the module
 * touches. Everything is implemented as inert no-ops in
 * kernel/susfs_shim.c because the host kernel is not SUSFS-patched.
 */
#ifndef KSU_SUSFS_DEF_H
#define KSU_SUSFS_DEF_H

#include <linux/susfs.h>

extern bool susfs_is_current_proc_no_su(void);
extern void susfs_set_current_proc_no_su(void);
extern void susfs_set_current_proc_umounted(void);
extern void susfs_set_current_proc_umounted_for_zygote_next(void);
extern bool susfs_starts_with(const char *s, const char *prefix);
extern bool susfs_ends_with(const char *s, const char *suffix);

#endif /* KSU_SUSFS_DEF_H */
