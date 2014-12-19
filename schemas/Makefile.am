desktop_gschemas_in =						\
	org.gnome.desktop.default-applications.gschema.xml.in	\
	org.gnome.desktop.interface.gschema.xml.in		\
	org.gnome.desktop.lockdown.gschema.xml.in		\
	org.gnome.system.locale.gschema.xml.in			\
	org.gnome.system.location.gschema.xml.in		\
	org.gnome.system.proxy.gschema.xml.in			\
	org.gnome.desktop.sound.gschema.xml.in			\
	org.gnome.desktop.thumbnail-cache.gschema.xml.in	\
	org.gnome.desktop.a11y.gschema.xml.in			\
	org.gnome.desktop.a11y.keyboard.gschema.xml.in		\
	org.gnome.desktop.a11y.applications.gschema.xml.in	\
	org.gnome.desktop.a11y.magnifier.gschema.xml.in		\
	org.gnome.desktop.a11y.mouse.gschema.xml.in		\
	org.gnome.desktop.thumbnailers.gschema.xml.in		\
	org.gnome.desktop.session.gschema.xml.in		\
	org.gnome.desktop.background.gschema.xml.in		\
	org.gnome.desktop.datetime.gschema.xml.in		\
	org.gnome.desktop.media-handling.gschema.xml.in		\
	org.gnome.desktop.screensaver.gschema.xml.in		\
	org.gnome.desktop.search-providers.gschema.xml.in	\
	org.gnome.desktop.wm.keybindings.gschema.xml.in		\
	org.gnome.desktop.wm.preferences.gschema.xml.in		\
	org.gnome.desktop.input-sources.gschema.xml.in		\
	org.gnome.desktop.privacy.gschema.xml.in		\
	org.gnome.desktop.notifications.gschema.xml.in		\
	org.gnome.desktop.app-folders.gschema.xml.in		\
	org.gnome.desktop.peripherals.gschema.xml.in

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
