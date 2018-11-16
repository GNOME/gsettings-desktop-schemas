headers = files(
  'gdesktop-enums.h'
)

install_headers(headers, subdir: gsettings_desktop_schemas_name)

if not meson.is_cross_build() and get_option('introspection')
  gnome.generate_gir(
    header: headers,
    namespace: 'GDesktopEnums',
    identifier_prefix: 'GDesktop',
    nsversion : '3.0',
    install: true,
    extra_args: [
      '--header-only',
    ]
  )
endif
