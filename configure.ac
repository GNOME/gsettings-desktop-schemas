m4_define([gds_major_version],[0])
m4_define([gds_minor_version],[0])
m4_define([gds_micro_version],[1])
m4_define([gds_extra_version],[])
m4_define([gds_version],[gds_major_version.gds_minor_version.gds_micro_version()gds_extra_version])

m4_define([gds_api_version],[1.0])

AC_PREREQ(2.53)
AC_INIT([GNOME Desktop GSettings Schemas],
        [gds_version],
        [http://bugzilla.gnome.org/enter_bug.cgi?product=gsettings-desktop-schemas],
        [gsettings-desktop-schemas])

AC_CONFIG_SRCDIR(schemas/org.gnome.desktop.default-applications.gschema.xml)
AM_INIT_AUTOMAKE([1.9 foreign no-dist-gzip dist-bzip2])
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
AC_CONFIG_MACRO_DIR([m4])

AM_MAINTAINER_MODE([enable])

dnl make sure we keep ACLOCAL_FLAGS around for maintainer builds to work
AC_SUBST(ACLOCAL_AMFLAGS, "$ACLOCAL_FLAGS")

# -----------------------------------------------------------------------------

AC_PROG_SED
PKG_PROG_PKG_CONFIG

LT_PREREQ([2.2])
LT_INIT

GLIB_GSETTINGS

GLIB_MKENUMS="$($PKG_CONFIG --variable=glib_mkenums glib-2.0)"
AC_SUBST([GLIB_MKENUMS])

PKG_CHECK_MODULES([GOBJECT],[gobject-2.0])

# -----------------------------------------------------------------------------
# i18n
# -----------------------------------------------------------------------------

GETTEXT_PACKAGE=gsettings-desktop-schemas
AC_SUBST(GETTEXT_PACKAGE)
AM_GLIB_GNU_GETTEXT
IT_PROG_INTLTOOL([0.40.0])

# -----------------------------------------------------------------------------
# API documentation
# -----------------------------------------------------------------------------

GTK_DOC_CHECK([1.13],[--flavour no-tmpl])

AC_SUBST([GLIB_PREFIX],[$($PKG_CONFIG --variable=prefix glib-2.0)])

# -----------------------------------------------------------------------------

AC_SUBST([GDS_API_VERSION],[gds_api_version])

# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------

AC_OUTPUT([
Makefile
docs/Makefile
docs/reference/Makefile
docs/reference/version.xml
gsettings-desktop-schemas.pc
schemas/Makefile
src/Makefile
po/Makefile.in
])

# -----------------------------------------------------------------------------
# Show summary
# -----------------------------------------------------------------------------

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
