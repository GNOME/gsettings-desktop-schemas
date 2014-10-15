AC_PREREQ(2.53)
AC_INIT([gsettings-desktop-schemas], [3.14.1],
        [http://bugzilla.gnome.org/enter_bug.cgi?product=gsettings-desktop-schemas])
AC_CONFIG_SRCDIR(schemas/org.gnome.desktop.default-applications.gschema.xml.in.in)
AM_INIT_AUTOMAKE([1.9 foreign no-dist-gzip dist-xz])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_MACRO_DIR([m4])

AM_MAINTAINER_MODE([enable])

AC_PROG_SED

GIO_MIN_VERSION=[2.31.0]
PKG_CHECK_EXISTS([gio-2.0 >= $GIO_MIN_VERSION],[],
                 [AC_MSG_ERROR([Minimum Gio requirement ($GIO_MIN_VERSION) was not met])])
GLIB_GSETTINGS

GOBJECT_INTROSPECTION_CHECK([1.31.0])

GETTEXT_PACKAGE=gsettings-desktop-schemas
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.40.0])

AC_OUTPUT([
Makefile
gsettings-desktop-schemas.pc
headers/Makefile
schemas/Makefile
po/Makefile.in
])

dnl ---------------------------------------------------------------------------
dnl - Show summary
dnl ---------------------------------------------------------------------------

echo "
              gsettings-desktop-schemas $VERSION
              `echo gsettings-desktop-schemas $VERSION | sed "s/./=/g"`

        prefix:                             ${prefix}
        exec_prefix:                        ${exec_prefix}
        libdir:                             ${libdir}
        bindir:                             ${bindir}
        sbindir:                            ${sbindir}
        sysconfdir:                         ${sysconfdir}
        localstatedir:                      ${localstatedir}
        datadir:                            ${datadir}
        source code location:               ${srcdir}
        Maintainer mode:                    ${USE_MAINTAINER_MODE}
"
