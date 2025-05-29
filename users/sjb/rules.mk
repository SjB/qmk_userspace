LTO_ENABLE = yes
LINK_TIME_OPTIMIZATION_ENABLE = yes
BOOTMAGIC_ENABLE = lite
NKRO_ENABLE = yes
MOUSEKEY_ENABLE = yes
EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
LAYER_LOCK_ENABLE = yes
CAPS_WORD_ENABLE = yes
ACHORDION_ENABLE = yes
SMTD_ENABLE = no
# ORBITAL_MOUSE_ENABLE = no

# SB_LR_HOMEROW_LAYER = yes # homerow layer
# SB_LAYER_SWITCH_COMBO_KEY = no
# SB_HR_COMBO_KEY = no
SB_HOMEROW_LAYER = yes
SB_MOUSE_BTN_HOLD = yes
SB_RSTL_ENABLE = yes

SRC += sjb.c

ifeq ($(strip $(ACHORDION_ENABLE)), yes)
SRC += features/achordion.c
OPT_DEFS += -DACHORDION_ENABLE
endif

ifeq ($(strip $(SMTD_ENABLE)), yes)
DEFERRED_EXEC_ENABLE = yes
OPT_DEFS += -DSMTD_ENABLE
endif

ifeq ($(strip $(ORBITAL_MOUSE_ENABLE)), yes)
MOUSEKEY_ENABLE = no
KEY_LOCK_ENABLE = no
MOUSE_ENABLE = yes
SRC += features/orbital_mouse.c
OPT_DEFS += -DORBITAL_MOUSE_ENABLE
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
INTROSPECTION_KEYMAP_C += combos.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += encoder.c
OPT_DEFS += -DENCODER_ENABLE
endif

ifeq ($(strip $(SB_LR_HOMEROW_LAYER)), yes)
OPT_DEFS += -DSB_LR_HOMEROW_LAYER
endif

ifeq ($(strip $(SB_HOMEROW_LAYER)), yes)
OPT_DEFS += -DSB_HOMEROW_LAYER
endif

ifeq ($(strip $(SB_MOUSE_BTN_HOLD)), yes)
OPT_DEFS += -DSB_MOUSE_BTN_HOLD
endif

ifeq ($(strip $(SB_LAYER_SWITCH_COMBO_KEY)), yes)
OPT_DEFS += -DSB_LAYER_SWITCH_COMBO_KEY
endif

ifeq ($(strip $(SB_RSTL_ENABLE)), yes)
OPT_DEFS += -DSB_RSTL_ENABLE
endif
