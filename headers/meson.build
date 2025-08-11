headers = files(
  'gdesktop-enums.h'
)

install_headers(headers, subdir: gsettings_desktop_schemas_name)

enums_xml = custom_target(
  'org.gnome.desktop.enums.xml',
  input: headers,
  output: 'org.gnome.desktop.enums.xml',
  command: [glib_mkenums,
            '--comments', '<!-- @comment@ -->',
            '--fhead', '<schemalist>',
            '--vhead', '<@type@ id="org.gnome.desktop.@EnumName@">',
            '--vprod', '    <value nick="@valuenick@" value="@valuenum@"/>',
            '--vtail', '  </@type@>',
            '--ftail', '</schemalist>', '@INPUT@'],
  capture: true,
  install: true,
  install_dir: schemasdir)

if get_option('introspection')
  gir_sources = headers

  # Use a dummy .c source; Visual Studio and meson 1.9.0 do not accept
  # header-only sources to build a dummy library
  gir_sources += ['dummy.c']

  noinst_lib = shared_library('noinst',
                              gir_sources,
                              install: false)

  gnome.generate_gir(noinst_lib,
    sources: headers,
    namespace: 'GDesktopEnums',
    identifier_prefix: 'GDesktop',
    nsversion : '3.0',
    install: true,
    extra_args: [
      '--header-only',
    ]
  )
endif
