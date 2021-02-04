SRC += zachthieme.c babblePaste.c babl_windows.c babl_mac.c

ifneq ($(strip $(NO_SECRETS)), yes)
    ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
        SRC += secrets.c
    endif
endif

CONSOLE_ENABLE = no
COMBO_ENABLE = no
NKRO_ENABLE = no
TAP_DANCE_ENABLE = no
EXTRAKEY_ENABLE = no
MOUSEKEY_ENABLE = yes
LTO_ENABLE = yes # Reduces the compiled firmware size
EXTRAFLAGS += -flto

ifeq ($(strip $(USE_BABBLEPASTE)), yes)
	SRC += babblePaste.c
endif
