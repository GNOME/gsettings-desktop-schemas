include Makefile-schemas.include

gsettings_ENUM_NAMESPACE = org.gnome.desktop
gsettings_ENUM_FILES = $(top_srcdir)/headers/*.h

gsettings_SCHEMAS = $(desktop_gschemas_in:.xml.in=.xml)

%.gschema.xml: %.gschema.xml.in Makefile
	$(AM_V_GEN) $(SED) -e 's^\@datadir\@^$(datadir)^g' -e 's^\@GETTEXT_PACKAGE\@^$(GETTEXT_PACKAGE)^g' < $< > $@

@GSETTINGS_RULES@

convertdir=$(datadir)/GConf/gsettings
convert_DATA=gsettings-desktop-schemas.convert wm-schemas.convert

EXTRA_DIST =				\
	$(desktop_gschemas_in)	\
	$(convert_DATA)

CLEANFILES =					\
	$(gsettings__enum_file)			\
	$(gsettings_SCHEMAS)			\
	$(desktop_gschemas_in:.xml.in=.xml)	\
	*.gschema.valid

-include $(top_srcdir)/git.mk
