SRC += zachthieme.c babblePaste.c babl_windows.c babl_mac.c babl_linux.c

# LEADER_ENABLE = yes # Enable the leader key
COMBO_ENABLE = no
NKRO_ENABLE = no
TAP_DANCE_ENABLE = no
LTO_ENABLE = yes # Reduces the compiled firmware size

ifeq ($(strip $(USE_BABBLEPASTE)), yes)
	SRC += babblePaste.c
endif
