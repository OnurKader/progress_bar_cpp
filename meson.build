project('ProgressBar++', 'cpp',
	version : '0.1',
	license : 'MIT',
	default_options : ['cpp_std=c++2a', 'buildtype=debugoptimized', 'warning_level=3',
					   'b_lto=false', 'cpp_rtti=false', 'cpp_eh=none'])

srcs = ['src/Main.cpp']

compiler_args = ['-Wformat-overflow=2', '-Wshadow', '-Wuninitialized',
				 '-Wduplicated-branches', '-Wduplicated-cond', '-Wfloat-equal',
				 '-Wconversion', '-Wcast-qual']

includes = include_directories('include')

exe = executable('progress', sources: srcs, include_directories:
includes, cpp_args: compiler_args)

test('Simple Test', exe)

subdir('examples')

