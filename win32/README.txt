Please refer to the following GNOME Live! page for more detailed
instructions on building this package with Visual C++:

https://live.gnome.org/GTK%2B/Win32/MSVCCompilationOfGTKStack

The Makefile.vc is an NMake Makefile that is meant to be used to generate
the gsettings schema files and an enumeration XML file that is to be copied
and "installed" on the running system by being copied to your gsettings
schemas folder and processed by the glib-compile-schemas tool, where
glib-compile-schemas is a part of the GLib package.

The required dependencies are as follows:

-An up-to-date GLib installation that was built with the Visual Studio version that
 you intend to run Makefile.vc with, in the location pointed
 to by $(PREFIX), which is <parentdir_of_srcroot>\vs<Visual Studio Version>\$(Platform)
 unless set as some other paths otherwise, where Platform is Win32 for 32-bit builds
 and x64 for x86-64 builds.

-The glib-mkenums PERL/Python script, that is found from the GLib sources that you have
 built and installed above.  Copy gobject\glib-mkenums.in from the GLib source tree to
 $(PREFIX)\bin\glib-mkenums, and change the @GLIB_VERSION@ in that file to match the
 version of GLib that you have built and installed, if it is not there yet.

-A working installation of PERL, which could either be built from the sources or obtained
 from distributions such as Strawberry PERL or ActiveState PERL.  This is needed if the
 GLib used is 2.52.x or earlier, or if planning to process the translations in po\.

-A working installation of Python 2.7.x+ or 3.x, which could be built from the sources or
 obtained from the installers from http://www.python.org.

For introspection building, you will also need:
-An up-to-date gobject-introspection installation that was built with the Visual Studio
 version that you intend to run Makefile.vc with, including the
 introspection files that are built with that package, in $(PREFIX).  You will need to
 ensure that the Python in your PATH (or the one specified with $(PYTHON) matches the
 Python installation and configuration that was used to build gobject-introspection.

For processing the translations, you will also need:
-intltool 0.50.1 or later.  This can be hard to install on Windows, and it requires
 the XML::Parser PERL package, which can be obtained from CPAN.  An installation of
 Cygwin or MSYS2 is also needed, with its bin\ path being added at the end of your
 PATH.  The gettext tools are also required.

Run 'nmake /f Makefile.vc' to generate the needed schema files.  If building the
introspection files is desired, run 'nmake /f Makefile.vc introspection'.  A 'clean'
target is provided to remove all the generated files.  An 'install' target is
provided to copy the generated GSchema XML files to DATADIR (please see below), and
the .h header file, the introspection file and the translation files to locations
under $(PREFIX) as appropriate.  You may also specify the following
items in the NMake command line with item=xxx:

---
PREFIX: Installation prefix, <parentdir_of_srcroot>\vs<Visual Studio Version>\<PlatformName>
        by default.

DATADIR: User-specified data directory, $(PREFIX)\share by default.

GLIB_COMPILE_SCHEMAS: Location of the glib-compile-schemas tool,
                      $(PREFIX)\bin\glib-compile-schemas.exe by default

GLIB_MKENUMS: Location of the glib-mkenums tool script, $(PREFIX)\bin\glib-mkenums by default

PYTHON: Location of the Python 2.7.x/3.x interpreter, needed if it is not in your PATH.

PERL: Location of the PERL interpreter, needed if not in your PATH.

INTROSPECTION: Build the introspection files for GSettings-Desktop-Schemas

GENERATE_MO: Process the translations provided by GSettings-Desktop-Schemas, where the
             following items are supported:

* INTLTOOL_UPDATE: Path to the intltool-update script from intltool, if it is not at
                   $(PREFIX)\bin
* INTLTOOL_EXTRACT: Path to the intltool-extract script from intltool, if it is not at
                    $(PREFIX)\bin
* XGETTEXT: Path to the xgettext tool, if it is not in your PATH.
---
Please refer to the README.txt file in $(GLib_src_root)\win32\vs<Visual Studio Version>
on how to build GLib using your version of Visual Studio, for GLib 2.56.x or earlier, or
in $(GLib_src_root)\README.win32 for GLib 2.57.x or later.  Versions 2008 through 2017 are
currently supported.

Set up the source tree as follows under some arbitrary top
folder <root>:

<root>\<this-gsettings-desktop-schemas-source-tree>

*this* file you are now reading is thus located at
<root>\<this-gsettings-desktop-schemas-source-tree>\win32\README.txt

The "install" target will copy build results and headers into their
appropriate location under $(PREFIX).
For instance, the *.schema.xml and *.enums.xml files will go into
$(PREFIX)\share\glib-2.0\schemas,
the header file goes into $(PREFIX)\include\gsettings-desktop-schemas.

--Chun-wei Fan <fanc999@gmail.com>
