NULL =

desktop_gschemas =						\
	org.gnome.desktop.default-applications.gschema.xml	\
	org.gnome.desktop.interface.gschema.xml			\
	org.gnome.desktop.lockdown.gschema.xml			\
	org.gnome.desktop.url-handlers.gschema.xml		\
	org.gnome.system.proxy.gschema.xml			\
	$(NULL)

desktop_gschemas_in =						\
	org.gnome.desktop.background.gschema.xml.in		\
	$(NULL)

desktop_gschemas_in_processed = $(desktop_gschemas_in:.gschema.xml.in=.gschema.xml)

gsettings_ENUM_NAMESPACE = org.gnome.desktop
gsettings_ENUM_FILES = $(top_srcdir)/headers/*.h

gsettings_SCHEMAS =				\
	$(desktop_gschemas)			\
	$(desktop_gschemas_in_processed)	\
	$(NULL)

%.gschema.xml: %.gschema.xml.in Makefile
	$(AM_V_GEN) $(SED) -e 's^\@datadir\@^$(datadir)^g' < $< > $@

@GSETTINGS_RULES@

EXTRA_DIST =			\
	$(desktop_gschemas)	\
	$(desktop_gschemas_in)	\
	$(NULL)

CLEANFILES =					\
	$(gsettings__enum_file)			\
	$(desktop_gschemas_in_processed)	\
	*.gschema.valid				\
	$(NULL)

-include $(top_srcdir)/git.mk
