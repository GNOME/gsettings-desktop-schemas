# NMake Makefile portion for code generation and
# intermediate build directory creation
# Items in here should not need to be edited unless
# one is maintaining the NMake build files.

.SUFFIXES: .xml.in .xml

# Generate the final xml files
{..\schemas\}.xml.in{}.xml:
	$(PYTHON) genschema.py --input=$< --output=$@ --package=$(GETTEXT_PACKAGE) --prefix=$(PREFIX_POSIX)

org.gnome.desktop.enums.xml: ..\headers\gdesktop-enums.h
	$(GLIB_MKENUMS_INTERP) $(GLIB_MKENUMS) --comments "<!-- @comment@ -->"	\
	--fhead "<schemalist>"	\
	--vhead "  <@type@ id='org.gnome.desktop.@EnumName@'>"	\
	--vprod "    <value nick='@valuenick@' value='@valuenum@'/>"	\
	--vtail "  </@type@>" --ftail "</schemalist>" $**	\
	> $@

gsettings-desktop-schemas.pc: ..\gsettings-desktop-schemas.pc.in
	@echo Generating gsettings-desktop-schemas.pc...
	$(PYTHON) genpc.py --prefix=$(PREFIX) --version=$(PACKAGE_VERSION)
