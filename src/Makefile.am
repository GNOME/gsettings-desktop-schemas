gdesktopincludedir = $(includedir)/gsettings-desktop-schemas

gdesktopinclude_HEADERS = \
	gdesktop-enums.h

nodist_gdesktopinclude_HEADERS = \
	gdesktop-type-builtins.h \
	gdesktop-type-builtins.c 

gdesktop-type-builtins.h: gdesktop-type-builtins.h.template $(gdesktopinclude_HEADERS) Makefile
	$(AM_V_GEN) $(GLIB_MKENUMS) --template $< $(filter %.h,$^) > xgen-gtbh \
	&& (cmp -s xgen-gtbh gdesktop-type-builtins.h || cp xgen-gtbh gdesktop-type-builtins.h ) \
	&& rm -f xgen-gtbh

gdesktop-type-builtins.c: gdesktop-type-builtins.c.template $(gdesktopinclude_HEADERS) Makefile
	$(AM_V_GEN) $(GLIB_MKENUMS) --template $< $(filter %.h,$^) > xgen-gtbc \
	&& (cmp -s xgen-gtbc gdesktop-type-builtins.c || cp xgen-gtbc gdesktop-type-builtins.c ) \
	&& rm -f xgen-gtbc

# Note: this library only exists so we can use gtk-doc

noinst_LTLIBRARIES = libgdesktoptypebuiltins.la

BUILT_SOURCES = \
	gdesktop-type-builtins.h \
	gdesktop-type-builtins.c

libgdesktoptypebuiltins_la_SOURCES = \
	$(top_builddir)/src/gdesktop-type-builtins.c \
	$(top_builddir)/src/gdesktop-type-builtins.h
libgdesktoptypebuiltins_la_CPPFLAGS = \
	-DGDESKTOP_COMPILATION \
	$(AM_CPPFLAGS)
libgdesktoptypebuiltins_la_CFLAGS = \
	$(GOBJECT_CFLAGS) \
	$(AM_CFLAGS)
libgdesktoptypebuiltins_la_LIBADD = \
	$(GOBJECT_LIBS)

CLEANFILES = $(BUILT_SOURCES)

-include $(top_srcdir)/git.mk
