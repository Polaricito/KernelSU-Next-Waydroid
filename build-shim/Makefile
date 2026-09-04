export CONFIG_KSU := m
export CONFIG_KSU_NON_ANDROID := y
export CONFIG_KSU_SELINUX := n
export CONFIG_KSU_DEBUG := n
export CONFIG_KSU_HANDLE_INPUT_EVENTS := n
export CONFIG_KSU_X86_PATCH_SYSCALL_DISPATCHER := y
export CONFIG_KSU_SUSFS := y
export CONFIG_KSU_SUSFS_SUS_PATH := y
export CONFIG_KSU_SUSFS_SUS_MOUNT := y
export CONFIG_KSU_SUSFS_SUS_KSTAT := y
export CONFIG_KSU_SUSFS_SPOOF_UNAME := y
export CONFIG_KSU_SUSFS_ENABLE_LOG := y
export CONFIG_KSU_SUSFS_SPOOF_CMDLINE_OR_BOOTCONFIG := y
export CONFIG_KSU_SUSFS_OPEN_REDIRECT := y
export CONFIG_KSU_SUSFS_SUS_MAP := y
export CONFIG_KSU_SUSFS_WAYDROID_SHIM := y
export CONFIG_KSU_SUSFS_HIDE_KSU_SUSFS_SYMBOLS := n

KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	make -C $(KDIR) M=$(shell dirname $(CURDIR))/kernel KBUILD_MODPOST_WARN=1 LLVM=1 modules

clean:
	make -C $(KDIR) M=$(shell dirname $(CURDIR))/kernel LLVM=1 clean
