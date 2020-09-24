# RELEVANT LINKS THAT HELPED ME CREATE THIS FILE
# https://github.com/ycm-core/ycmd#user-level-customization
# https://github.com/ycm-core/YouCompleteMe/wiki/FAQ#im-using-clangd-how-can-i-specify-a-per-project-compilation-database-path

import os.path as p

DIR_OF_THIS_SCRIPT = p.abspath(p.dirname(__file__))

def Settings(**kwargs):
  language = kwargs['language']
  if language == 'cfamily':
    # look for 'compile_commands.json' in the 'build' directory,
    # which should exist where this script is
    cmake_commands = p.join(DIR_OF_THIS_SCRIPT,
                            'build',
                            'compile_commands.json')
    if p.exists(cmake_commands):
      return {
        'ls': {
          'compilationDatabasePath': p.dirname(cmake_commands)
        }
      }
  return None
