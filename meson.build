project(
  'gsettings-desktop-schemas', 'c',
  version: '3.31.0',
  default_options: [
    'warning_level=2'
  ],
  license: 'LGPL',
  meson_version: '>= 0.46.0'
)

gsettings_desktop_schemas_name = meson.project_name()
gsettings_desktop_schemas_version = meson.project_version()

message('Building ' + gsettings_desktop_schemas_name + ' ' + gsettings_desktop_schemas_version)

cc = meson.get_compiler('c')
host_system = host_machine.system()
arch = host_machine.cpu_family()

prefix = get_option('prefix')
bindir = join_paths(prefix, get_option('bindir'))
libdir = join_paths(prefix, get_option('libdir'))
libexecdir = join_paths(prefix, get_option('libexecdir'))
includedir = join_paths(prefix, get_option('includedir'))
datadir = join_paths(prefix, get_option('datadir'))
sysconfdir = join_paths(prefix, get_option('sysconfdir'))
schemasdir = join_paths(datadir, 'glib-2.0/schemas')

gnome = import('gnome')

# Generate pc file
pkg = import('pkgconfig')

pkg.generate(name: gsettings_desktop_schemas_name,
             subdirs: gsettings_desktop_schemas_name,
             install_dir: join_paths(datadir, 'pkgconfig'),
             version: gsettings_desktop_schemas_version,
             description: 'Shared GSettings schemas for the desktop, including helper headers')

subdir('headers')
subdir('schemas')
subdir('po')
