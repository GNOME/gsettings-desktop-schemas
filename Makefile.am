NULL =

SUBDIRS = headers schemas po

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST =			\
	HACKING			\
	MAINTAINERS		\
	$(NULL)

MAINTAINERCLEANFILES = \
	$(srcdir)/m4/* \
	$(srcdir)/INSTALL \
	$(srcdir)/aclocal.m4 \
	$(srcdir)/config.guess \
	$(srcdir)/config.sub \
	$(srcdir)/install-sh \
	$(srcdir)/missing \
	$(srcdir)/mkinstalldirs \
	`find "$(srcdir)" -type f -name Makefile.in -print` \
	$(srcdir)/configure

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = gsettings-desktop-schemas.pc

-include $(top_srcdir)/git.mk
