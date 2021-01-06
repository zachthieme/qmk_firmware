SRC += zachthieme.c babblePaste.c babl_windows.c babl_mac.c babl_linux.c

LTO_ENABLE = no # Reduces the compiled firmware size

ifeq ($(strip $(USE_BABBLEPASTE)), yes)
	SRC += babblePaste.c
endif
   
