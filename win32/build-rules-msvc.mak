# NMake Makefile portion for compilation rules
# Items in here should not need to be edited unless
# one is maintaining the NMake build files.  The format
# of NMake Makefiles here are different from the GNU
# Makefiles.  Please see the comments about these formats.

!include introspection.body.mak

introspection: setgirbuildenv GDesktopEnums-3.0.gir GDesktopEnums-3.0.typelib

setgirbuildenv:
	@set PATH=$(PREFIX)\bin;$(PATH)
	@set PKG_CONFIG_PATH=$(PREFIX)\lib\pkgconfig

install: $(gschemas) org.gnome.desktop.enums.xml gsettings-desktop-schemas.pc
	@if not exist $(INSTALL_DATA_DIR)\glib-2.0\schemas\ mkdir $(INSTALL_DATA_DIR)\glib-2.0\schemas
	@copy *.gschema.xml $(INSTALL_DATA_DIR)\glib-2.0\schemas
	@copy org.gnome.desktop.enums.xml $(INSTALL_DATA_DIR)\glib-2.0\schemas
	@if not exist $(PREFIX)\include\gsettings-desktop-schemas\ mkdir $(PREFIX)\include\gsettings-desktop-schemas
	@copy ..\headers\gdesktop-enums.h $(PREFIX)\include\gsettings-desktop-schemas
	@if exist *.gir copy *.gir $(PREFIX)\share\gir-1.0
	@if exist *.typelib copy *.typelib $(PREFIX)\lib\girepository-1.0
	$(GLIB_COMPILE_SCHEMAS) $(INSTALL_DATA_DIR)\glib-2.0\schemas
	@if not exist $(PREFIX)\share\pkgconfig\ mkdir $(PREFIX)\share\pkgconfig
	@copy gsettings-desktop-schemas.pc $(PREFIX)\share\pkgconfig

clean:
	@if exist gsettings-desktop-schemas.pc del gsettings-desktop-schemas.pc
	@if exist *.typelib del *.typelib
	@if exist *.gir del *.gir
	@-del $(gschemas)
	@-del org.gnome.desktop.enums.xml
	@if exist *.pyc del *.pyc
	@if exist __pycache__\ rmdir /s /q __pycache__
