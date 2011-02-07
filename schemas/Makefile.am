desktop_gschemas =						\
	org.gnome.desktop.default-applications.gschema.xml	\
	org.gnome.desktop.interface.gschema.xml			\
	org.gnome.desktop.lockdown.gschema.xml			\
	org.gnome.system.proxy.gschema.xml			\
	org.gnome.desktop.sound.gschema.xml			\
	org.gnome.desktop.thumbnail-cache.gschema.xml		\
	org.gnome.desktop.a11y.keyboard.gschema.xml		\
	org.gnome.desktop.a11y.applications.gschema.xml		\
	org.gnome.desktop.a11y.mouse.gschema.xml		\
	org.gnome.desktop.thumbnailers.gschema.xml		\
	org.gnome.desktop.session.gschema.xml

desktop_gschemas_in =						\
	org.gnome.desktop.background.gschema.xml.in		\
	org.gnome.desktop.media-handling.gschema.xml.in		\
	org.gnome.desktop.screensaver.gschema.xml.in

desktop_gschemas_in_processed = $(desktop_gschemas_in:.gschema.xml.in=.gschema.xml)

gsettings_ENUM_NAMESPACE = org.gnome.desktop
gsettings_ENUM_FILES = $(top_srcdir)/headers/*.h

gsettings_SCHEMAS =				\
	$(desktop_gschemas)			\
	$(desktop_gschemas_in_processed)

%.gschema.xml: %.gschema.xml.in Makefile
	$(AM_V_GEN) $(SED) -e 's^\@datadir\@^$(datadir)^g' < $< > $@

@GSETTINGS_RULES@

convertdir=$(datadir)/GConf/gsettings
convert_DATA=gsettings-desktop-schemas.convert

EXTRA_DIST =			\
	$(desktop_gschemas)	\
	$(desktop_gschemas_in)	\
	$(convert_DATA)

CLEANFILES =					\
	$(gsettings__enum_file)			\
	$(desktop_gschemas_in_processed)	\
	*.gschema.valid

-include $(top_srcdir)/git.mk
