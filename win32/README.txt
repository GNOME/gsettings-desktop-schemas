Please refer to the following GNOME Live! page for more detailed
instructions on building this package with Visual C++:

https://live.gnome.org/GTK%2B/Win32/MSVCCompilationOfGTKStack

The gsettings-desktop-schemas-msvc.mak is an NMake Makefile that is meant
to be used to generate the gsettings schema files and an enumeration
XML file that is to be copied and "installed" on the running system
by being copied to your gsettings schemas folder and processed by the
glib-compile-schemas tool, where glib-compile-schemas is a part of the
GLib package.

The required dependencies are as follows:

-An up-to-date GLib installation that was built with the Visual Studio version that
 you intend to run gsettings-desktop-schemas-msvc.mak with, in the location pointed
 to by $(PREFIX), which is <parentdir_of_srcroot>\vs<Visual Studio Version>\$(Platform)
 unless set as some other paths otherwise, where Platform is Win32 for 32-bit builds
 and x64 for x86-64 builds.

-The glib-mkenums PERL script, that is found from the GLib sources that you have built
 and installed above.  Copy gobject\glib-mkenums.in from the GLib source tree to
 $(PREFIX)\bin\glib-mkenums, and change the
 @GLIB_VERSION@ in that file to match the version of GLib that you have built and
 installed, if it is not there yet.

-A working installation of PERL, which could either be built from the sources or obtained
 from distributions such as Strawberry PERL or ActiveState PERL.

-A working installation of Python 2.7.x+ or 3.x, which could be built from the sources or
 obtained from the installers from http://www.python.org.

For introspection building, you will also need:
-An up-to-date gobject-introspection installation that was built with the Visual Studio
 version that you intend to run gsettings-desktop-schemas-msvc.mak with, including the
 introspection files that are built with that package, in $(PREFIX).  Currently,
 for introspection building, Python 2.7.x must be used; Python 3.x is currently not
 supported.

Run 'nmake /f gsettings-desktop-schemas-msvc.mak' to generate the needed schema files.
If building the introspection files is desired, run 
'nmake /f gsettings-desktop-schemas-msvc.mak introspection'.  A 'clean' target is
provided to remove all the generated files.

Please refer to the README.txt file in $(GLib_src_root)\build\win32\vs<Visual Studio Version>
on how to build GLib using your version of Visual Studio.  Versions 2008 through 2015 are
currently supported.

Set up the source tree as follows under some arbitrary top
folder <root>:

<root>\<this-gsettings-desktop-schemas-source-tree>
<root>\<Visual Studio Version>\<PlatformName>

*this* file you are now reading is thus located at
<root>\<this-gsettings-desktop-schemas-source-tree>\build\README.txt

The "install" target will copy build results and headers into their
appropriate location under <root>\vs<Visual Studio Version>\<PlatformName>.
For instance, the *.schema.xml and *.enums.xml files will go into
<root>\vs<Visual Studio Version>\<PlatformName>\share\glib-2.0\schemas,
the header file goes into
<root>\vs<Visual Studio Version>\<PlatformName>\include\gsettings-desktop-schemas.

--Chun-wei Fan <fanc999@gmail.com>
