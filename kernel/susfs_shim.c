// SPDX-License-Identifier: GPL-2.0
/*
 * KernelSU-Next Waydroid SUSFS load shim.
 *
 * The dev-susfs KernelSU module references a set of symbols that in a real
 * SUSFS setup are provided by the SUSFS-patched host kernel (fs/susfs.c and
 * the security/selinux SUSFS hooks). The CachyOS Waydroid host kernel is not
 * SUSFS-patched and has SELinux inactive, so those symbols do not exist.
 *
 * This file defines inert stubs for every kernel-side SUSFS symbol the module
 * touches, so the module links and loads and continues to deliver plain root.
 * All SUSFS hiding/spoofing features are no-ops here.
 */

#include <linux/susfs.h>
#include <linux/susfs_def.h>

#include <linux/workqueue.h>
#include <linux/jump_label.h>
#include <linux/string.h>
#include <linux/sched.h>

/* ---- kernel-side SUSFS variables ---- */

bool boot_completed = false;

DEFINE_STATIC_KEY_FALSE(susfs_is_avc_log_spoofing_enabled);
DEFINE_STATIC_KEY_FALSE(susfs_is_uname_spoof_buffer_set);

static void susfs_extra_work_func(struct work_struct *work)
{
	(void)work;
}

struct work_struct susfs_extra_works;
static int susfs_extra_works_initialized;

static void susfs_ensure_extra_works_init(void)
{
	if (!susfs_extra_works_initialized) {
		INIT_WORK(&susfs_extra_works, susfs_extra_work_func);
		susfs_extra_works_initialized = 1;
	}
}

/* ---- helper functions (susfs_def) ---- */

bool susfs_is_current_proc_no_su(void)
{
	return false;
}

void susfs_set_current_proc_no_su(void)
{
}

void susfs_set_current_proc_umounted(void)
{
}

void susfs_set_current_proc_umounted_for_zygote_next(void)
{
}

bool susfs_starts_with(const char *s, const char *prefix)
{
	size_t plen;

	if (!s || !prefix)
		return false;
	plen = strlen(prefix);
	return strncmp(s, prefix, plen) == 0;
}

bool susfs_ends_with(const char *s, const char *suffix)
{
	size_t slen, xlen;

	if (!s || !suffix)
		return false;
	slen = strlen(s);
	xlen = strlen(suffix);
	if (xlen > slen)
		return false;
	return strcmp(s + slen - xlen, suffix) == 0;
}

void susfs_start_sdcard_monitor_fn(void)
{
	susfs_ensure_extra_works_init();
}

/* ---- supercall handlers (all inert) ---- */

int susfs_add_sus_path(void __user **arg)
{
	susfs_ensure_extra_works_init();
	return 0;
}

int susfs_add_sus_path_loop(void __user **arg)
{
	return 0;
}

int susfs_set_hide_sus_mnts_for_non_su_procs(void __user **arg)
{
	return 0;
}

int susfs_add_sus_kstat(void __user **arg)
{
	return 0;
}

int susfs_update_sus_kstat(void __user **arg)
{
	return 0;
}

int susfs_set_uname(void __user **arg)
{
	return 0;
}

int susfs_enable_log(void __user **arg)
{
	return 0;
}

int susfs_set_cmdline_or_bootconfig(void __user **arg)
{
	return 0;
}

int susfs_add_open_redirect(void __user **arg)
{
	return 0;
}

int susfs_add_sus_map(void __user **arg)
{
	return 0;
}

int susfs_set_avc_log_spoofing(void __user **arg)
{
	return 0;
}

/* ---- show/hide info: report "unsupported"/empty for an unpatched kernel ---- */

int susfs_get_enabled_features(void __user **arg)
{
	return 0;
}

int susfs_show_variant(void __user **arg)
{
	return 0;
}

int susfs_show_version(void __user **arg)
{
	return 0;
}

void susfs_init(void)
{
	susfs_ensure_extra_works_init();
}
