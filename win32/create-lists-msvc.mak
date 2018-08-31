# Convert the source listing to object listing in
# another NMake Makefile module, include it, and clean it up.
# This is a "fact-of-life" regarding NMake Makefiles...
# This file does not need to be changed unless one is maintaining the NMake Makefiles

# For those wanting to add things here:
# To add a list, do the following:
# # $(description_of_list)
# if [call create-lists.bat header $(makefile_snippet_file) $(variable_name)]
# endif
#
# if [call create-lists.bat file $(makefile_snippet_file) $(file_name)]
# endif
#
# if [call create-lists.bat footer $(makefile_snippet_file)]
# endif
# ... (repeat the if [call ...] lines in the above order if needed)
# !include $(makefile_snippet_file)
#
# (add the following after checking the entries in $(makefile_snippet_file) is correct)
# (the batch script appends to $(makefile_snippet_file), you will need to clear the file unless the following line is added)
#!if [del /f /q $(makefile_snippet_file)]
#!endif

NULL=

# For schemas

!include ..\schemas\Makefile-schemas.include

!if [call create-lists.bat header gschema-desktop-settings.mak gschemas]
!endif

!if [for %f in ($(desktop_gschemas_in)) do @call create-lists.bat file gschema-desktop-settings.mak .\outputdir\%~nf]
!endif

!if [@call create-lists.bat file gschema-desktop-settings.mak .\outputdir\org.gnome.desktop.enums.xml]
!endif

!if [call create-lists.bat footer gschema-desktop-settings.mak]
!endif

!if [call create-lists.bat header gschema-desktop-settings.mak gschemas_mo]
!endif

!if [for %f in (..\po\*.po) do @call create-lists.bat file gschema-desktop-settings.mak .\outputdir\%~nf.mo]
!endif

!if [call create-lists.bat footer gschema-desktop-settings.mak]
!endif

!include gschema-desktop-settings.mak

!if [del /f /q gschema-desktop-settings.mak]
!endif
