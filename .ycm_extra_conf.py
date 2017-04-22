def FlagsForFile( filename, **kwargs ):
  return {
    'flags': [ '-x', 'c++', '-Wall', '-Wextra', '-Werror', '-g', '-std=c++11' ],
  }
