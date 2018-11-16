headers = files(
  'gdesktop-enums.h'
)

install_headers(headers, subdir: gsettings_desktop_schemas_name)

if not meson.is_cross_build() and get_option('introspection')
  noinst_lib = shared_library ('noinst',
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
