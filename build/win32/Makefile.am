if HAVE_INTROSPECTION
GENERATED_ITEMS = \
	introspection.body.mak	\
	GDesktopEnums_3_0_gir_list

introspection.body.mak: GDesktopEnums-3.0.gir.msvc.introspect
	-$(RM) introspection.body.mak
	for F in `ls *.msvc.introspect`; do \
		case $$F in \
			*)	cat $$F >>introspection.body.mak \
			;; \
		esac; \
	done
	$(RM) GDesktopEnums-3.0.gir.msvc.introspect

DISTCLEANFILES = $(GENERATED_ITEMS)

else
GENERATED_ITEMS =
endif

EXTRA_DIST = \
	detectenv-msvc.mak			\
	gsettings-desktop-schemas-msvc.mak.in	\
	gsettings-desktop-schemas-msvc.mak	\
	introspection-msvc.mak			\
	genschema.py				\
	replace.py				\
	uri.py					\
	README.txt				\
	$(GENERATED_ITEMS)

-include $(top_srcdir)/git.mk
