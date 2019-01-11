headers = files(
  'gdesktop-enums.h'
)

install_headers(headers, subdir: gsettings_desktop_schemas_name)

enums_xml = custom_target('org.gnome.desktop.enums.xml',
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

if not meson.is_cross_build() and get_option('introspection')
  noinst_lib = shared_library('noinst',
                              headers,
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
