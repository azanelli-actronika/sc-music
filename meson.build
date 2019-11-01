project('sc-music', 'cpp',
    version: '0.1.0',
    default_options: [
      'cpp_std=c++11',
      ])

cpp_compiler = meson.get_compiler('cpp')

thread_dep = dependency('threads')

warning_flags = [
  '-Wno-unused-parameter',
  '-Wformat-nonliteral',
  '-Wformat-security',
  '-Winit-self',
  '-Wswitch-default',
  '-Wuninitialized',
  '-Wmaybe-uninitialized',
  '-Wshadow',
  '-Wframe-larger-than=4096',
  '-Wpointer-arith',
  '-Wundef',
  '-Wcast-qual',
  '-Wno-type-limits',
  '-Wno-non-virtual-dtor',
  ]

local_incdir = include_directories([
  '3rd-party/include',
  'src'
  ])

local_src = [
  'src/songs/beethoven_n9.cpp',
  'src/songs/the_heart_asks_pleasure_first.cpp',
  'src/songs/we_wish_you_a_merry_christmas.cpp',
  'src/songs/zelda_lullaby.cpp',
  'src/main.cpp',
  'src/song.cpp',
  ]

local_cxxflags = []
local_cxxflags += cpp_compiler.get_supported_arguments(warning_flags)

steam_lib_dir = join_paths(meson.source_root(),
                           '3rd-party/redistributable_bin/linux64/')

local_ldflags = ['-L' + steam_lib_dir, '-lsteam_api']

# just copy app_steamid to build dir
configure_file(input: 'steam_appid.txt', output: 'steam_appid.txt', copy: true)

exe = executable('sc-music', local_src,
    include_directories: local_incdir,
    cpp_args: local_cxxflags,
    link_args: local_ldflags,
    dependencies: thread_dep)
