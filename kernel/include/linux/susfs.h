/*
 * KernelSU-Next Waydroid SUSFS shim header.
 *
 * This is a compile/load shim replacing the susfs.h installed by the
 * SUSFS kernel patch (fs + security/selinux hooks) in a SUSFS-patched
 * kernel. The CachyOS Waydroid host kernel is NOT SUSFS-patched and has
 * SELinux disabled, so the real SUSFS feature layer cannot run here.
 *
 * This header provides the ABI surface (constants, structs, prototypes)
 * the KernelSU-Next dev-susfs module references so that the module can be
 * compiled and loaded to deliver plain root. All SUSFS feature functions
 * declared here are implemented as inert no-ops in kernel/susfs_shim.c.
 */
#ifndef KSU_SUSFS_H
#define KSU_SUSFS_H

#include <linux/types.h>
#include <linux/utsname.h>
#include <linux/version.h>

/* KSU install magic + SUSFS magic (must match userspace ksu_susfs tool) */
/* KSU_INSTALL_MAGIC1 is already declared as a static const in uapi/supercall.h */
#define SUSFS_MAGIC        0xFAFAFAFAUL

/* CMDs: SHOW_* values must match userspace/ksud/src/susfsd.rs */
#define CMD_SUSFS_SHOW_VERSION             0x555e1
#define CMD_SUSFS_SHOW_ENABLED_FEATURES    0x555e2
#define CMD_SUSFS_SHOW_VARIANT             0x555e3
#define CMD_SUSFS_ADD_SUS_PATH             0x55550
#define CMD_SUSFS_ADD_SUS_PATH_LOOP        0x55551
#define CMD_SUSFS_HIDE_SUS_MNTS_FOR_NON_SU_PROCS 0x55552
#define CMD_SUSFS_ADD_SUS_KSTAT            0x55553
#define CMD_SUSFS_UPDATE_SUS_KSTAT         0x55554
#define CMD_SUSFS_ADD_SUS_KSTAT_STATICALLY 0x55555
#define CMD_SUSFS_SET_UNAME                0x55556
#define CMD_SUSFS_ENABLE_LOG               0x55557
#define CMD_SUSFS_SET_CMDLINE_OR_BOOTCONFIG 0x55558
#define CMD_SUSFS_ADD_OPEN_REDIRECT        0x55559
#define CMD_SUSFS_ADD_SUS_MAP              0x5555a
#define CMD_SUSFS_ENABLE_AVC_LOG_SPOOFING  0x5555b

#define SUSFS_ENABLED_FEATURES_SIZE 8192
#define SUSFS_MAX_VERSION_BUFSIZE   16
#define SUSFS_MAX_VARIANT_BUFSIZE   16

struct st_susfs_uname {
	char sysname[__NEW_UTS_LEN + 1];
	char nodename[__NEW_UTS_LEN + 1];
	char release[__NEW_UTS_LEN + 1];
	char version[__NEW_UTS_LEN + 1];
	char machine[__NEW_UTS_LEN + 1];
};

struct st_susfs_avc_log_spoofing {
	bool enabled;
};

extern int susfs_add_sus_path(void __user **arg);
extern int susfs_add_sus_path_loop(void __user **arg);
extern int susfs_set_hide_sus_mnts_for_non_su_procs(void __user **arg);
extern int susfs_add_sus_kstat(void __user **arg);
extern int susfs_update_sus_kstat(void __user **arg);
extern int susfs_set_uname(void __user **arg);
extern int susfs_enable_log(void __user **arg);
extern int susfs_set_cmdline_or_bootconfig(void __user **arg);
extern int susfs_add_open_redirect(void __user **arg);
extern int susfs_add_sus_map(void __user **arg);
extern int susfs_set_avc_log_spoofing(void __user **arg);
extern int susfs_get_enabled_features(void __user **arg);
extern int susfs_show_variant(void __user **arg);
extern int susfs_show_version(void __user **arg);

extern void susfs_start_sdcard_monitor_fn(void);

extern void susfs_init(void);

#endif /* KSU_SUSFS_H */
