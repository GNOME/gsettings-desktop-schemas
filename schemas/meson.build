schemas_in = files(
  'org.gnome.desktop.default-applications.gschema.xml.in',
  'org.gnome.desktop.interface.gschema.xml.in',
  'org.gnome.desktop.lockdown.gschema.xml.in',
  'org.gnome.system.locale.gschema.xml.in',
  'org.gnome.system.location.gschema.xml.in',
  'org.gnome.system.proxy.gschema.xml.in',
  'org.gnome.desktop.sound.gschema.xml.in',
  'org.gnome.desktop.thumbnail-cache.gschema.xml.in',
  'org.gnome.desktop.a11y.gschema.xml.in',
  'org.gnome.desktop.a11y.keyboard.gschema.xml.in',
  'org.gnome.desktop.a11y.applications.gschema.xml.in',
  'org.gnome.desktop.a11y.magnifier.gschema.xml.in',
  'org.gnome.desktop.a11y.mouse.gschema.xml.in',
  'org.gnome.desktop.thumbnailers.gschema.xml.in',
  'org.gnome.desktop.session.gschema.xml.in',
  'org.gnome.desktop.background.gschema.xml.in',
  'org.gnome.desktop.calendar.gschema.xml.in',
  'org.gnome.desktop.datetime.gschema.xml.in',
  'org.gnome.desktop.media-handling.gschema.xml.in',
  'org.gnome.desktop.screensaver.gschema.xml.in',
  'org.gnome.desktop.search-providers.gschema.xml.in',
  'org.gnome.desktop.wm.keybindings.gschema.xml.in',
  'org.gnome.desktop.wm.preferences.gschema.xml.in',
  'org.gnome.desktop.input-sources.gschema.xml.in',
  'org.gnome.desktop.privacy.gschema.xml.in',
  'org.gnome.desktop.notifications.gschema.xml.in',
  'org.gnome.desktop.app-folders.gschema.xml.in',
  'org.gnome.desktop.peripherals.gschema.xml.in',
)

conf = configuration_data()
conf.set('prefix', prefix)
conf.set('exec_prefix', prefix)
conf.set('libdir', libdir)
conf.set('bindir', bindir)
conf.set('libexecdir', libexecdir)
conf.set('datarootdir', datadir)
conf.set('datadir', datadir)
conf.set('includedir', includedir)

foreach schema: schemas_in
  generated_schema = configure_file(
    output: '@BASENAME@',
    input: schema,
    configuration: conf
  )
  install_data(generated_schema, install_dir: schemasdir)
endforeach

gnome.compile_schemas(build_by_default: true)
