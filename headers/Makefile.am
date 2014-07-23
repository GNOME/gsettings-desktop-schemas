gdesktopincludedir = $(includedir)/gsettings-desktop-schemas
gdesktopinclude_HEADERS = gdesktop-enums.h

INTROSPECTION_GIRS =
INTROSPECTION_SCANNER_ENV = CC="$(CC)"
INTROSPECTION_SCANNER_ARGS = --add-include-path=$(srcdir)
INTROSPECTION_COMPILER_ARGS = --includedir=$(srcdir)

CLEANFILES =

if HAVE_INTROSPECTION

GDesktopEnums_3_0_gir_CFLAGS = -I$(srcdir)
GDesktopEnums_3_0_gir_FILES = gdesktop-enums.h
GDesktopEnums_3_0_gir_SCANNERFLAGS = --header-only --identifier-prefix=GDesktop
INTROSPECTION_GIRS += GDesktopEnums-3.0.gir

girdir = $(datadir)/gir-1.0
gir_DATA = $(INTROSPECTION_GIRS)

typelibdir = $(libdir)/girepository-1.0
typelib_DATA = $(INTROSPECTION_GIRS:.gir=.typelib)

CLEANFILES += $(gir_DATA) $(typelib_DATA)
endif

-include $(top_srcdir)/git.mk
-include $(INTROSPECTION_MAKEFILE)
