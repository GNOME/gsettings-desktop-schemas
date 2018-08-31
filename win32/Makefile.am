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
	build-rules-msvc.mak		\
	config-msvc.mak			\
	config-msvc.mak.in		\
	create-lists.bat		\
	create-lists-msvc.mak		\
	detectenv-msvc.mak		\
	generate-msvc.mak		\
	genschema.py			\
	genpc.py			\
	introspection-msvc.mak		\
	Makefile.vc			\
	pc_base.py			\
	replace.py			\
	README.txt			\
	$(GENERATED_ITEMS)

-include $(top_srcdir)/git.mk
