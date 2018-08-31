# NMake Makefile portion for code generation and
# intermediate build directory creation
# Items in here should not need to be edited unless
# one is maintaining the NMake build files.

.SUFFIXES: .xml.in .xml

.\outputdir:
	@if not exist $@\ mkdir $@

# Generate the final xml files
{..\schemas\}.xml.in{.\outputdir\}.xml:
	@if not exist .\outputdir\ $(MAKE) /f Makefile.vc .\outputdir
	$(PYTHON) genschema.py --input=$< --output=$@ --package=$(GETTEXT_PACKAGE) $(GENSCHEMA_DATADIR_ARG)

.\outputdir\org.gnome.desktop.enums.xml: ..\headers\gdesktop-enums.h .\outputdir
	$(GLIB_MKENUMS_INTERP) $(GLIB_MKENUMS) --comments "<!-- @comment@ -->"	\
	--fhead "<schemalist>"	\
	--vhead "  <@type@ id='org.gnome.desktop.@EnumName@'>"	\
	--vprod "    <value nick='@valuenick@' value='@valuenum@'/>"	\
	--vtail "  </@type@>" --ftail "</schemalist>" ..\headers\gdesktop-enums.h	\
	> $@

.\outputdir\gsettings-desktop-schemas.pc: ..\gsettings-desktop-schemas.pc.in .\outputdir
	@echo Generating $@...
	$(PYTHON) genpc.py --prefix=$(PREFIX) --version=$(PACKAGE_VERSION)
