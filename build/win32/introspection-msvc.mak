# Common Utility NMake Makefile Template
# Used to Generate Introspection files for various Projects

# Can Override with env vars as needed
# You will need to have built gobject-introspection for this to work.
# Change or pass in or set the following to suit your environment

BASEDIR = $(PREFIX)
GIR_SUBDIR = share\gir-1.0
GIR_TYPELIBDIR = lib\girepository-1.0
G_IR_SCANNER = $(BASEDIR)\bin\g-ir-scanner
G_IR_COMPILER = $(BASEDIR)\bin\g-ir-compiler.exe
G_IR_INCLUDEDIR = $(BASEDIR)\$(GIR_SUBDIR)
G_IR_TYPELIBDIR = $(BASEDIR)\$(GIR_TYPELIBDIR)

# Note: The PYTHON2 must be a Python 2.6.x or 2.7.x Interpretor!
# Either having python.exe from Python 2.6.x/2.7.x in your PATH will work
# or passing in PYTHON2=<full path to your Python 2.6.x/2.7.x interpretor> will do

# This is required, and gobject-introspection needs to be built
# before this can be successfully run.
!if "$(PYTHON2)" == ""
PYTHON2=python
!endif

# Don't change anything following this line!
VALID_PKG_CONFIG_PATH = FALSE

MSG_INVALID_PKGCONFIG = You must set or specifiy a valid PKG_CONFIG_PATH
MSG_INVALID_CFG = You need to specify or set CFG to be release or debug to use this Makefile to build the Introspection Files

ERROR_MSG =

BUILD_INTROSPECTION = TRUE

!if ![pkg-config --print-errors --errors-to-stdout $(CHECK_PACKAGE) > pkgconfig.x]	\
	&& ![setlocal]	\
	&& ![set file="pkgconfig.x"]	\
	&& ![FOR %A IN (%file%) DO @echo PKG_CHECK_SIZE=%~zA > pkgconfig.chksize]	\
	&& ![del $(ERRNUL) /q/f pkgconfig.x]
!endif

!include pkgconfig.chksize
!if "$(PKG_CHECK_SIZE)" == "0"
VALID_PKG_CONFIG_PATH = TRUE
!else
VALID_PKG_CONFIG_PATH = FALSE
!endif

!if ![del $(ERRNUL) /q/f pkgconfig.chksize]
!endif

VALID_CFGSET = FALSE
!if "$(CFG)" == "release" || "$(CFG)" == "debug"
VALID_CFGSET = TRUE
!endif

!if "$(VALID_PKG_CONFIG_PATH)" != "TRUE"
BUILD_INTROSPECTION = FALSE
ERROR_MSG = $(MSG_INVALID_PKGCONFIG)
!endif

!if "$(VALID_CFGSET)" != "TRUE"
BUILD_INTROSPECTION = FALSE
ERROR_MSG = $(MSG_INVALID_CFG)
!endif
