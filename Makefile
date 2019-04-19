# Set the keyboard you'd like to build here
KEYBOARD?=planck/rev6

###########################################################
# Leave the rest as-is, unless you know what you're doing #
###########################################################

# Leave this blank, as the keymap name isn't used
KEYMAP:=

# The folder we have QMK checked out in
TOP_DIR:=qmk_firmware

# Name the compiled file with a filesystem safe version of keyboard name
TARGET:=firmware
# TARGET:=$(subst /,_,$(KEYBOARD))

planck:
	$(MAKE) KEYBOARD=planck/rev6 TARGET=planck_rev6-1.0.0.x dfu-util-wait

preonic:
	$(MAKE) KEYBOARD=preonic/rev3 TARGET=preonic_rev3-1.0.0.x dfu-util-wait

release:
	$(MAKE) clean
	$(MAKE) KEYBOARD=planck/rev6 TARGET=planck_rev6-1.0.0.x
	$(MAKE) KEYBOARD=preonic/rev3 TARGET=preonic_rev3-1.0.0.x

# include the core building makefile from QMK
include ${TOP_DIR}/build_keyboard.mk
