# setup.py
from distutils.core import setup, Extension

extension_mod = Extension( 'spam', sources=['source/spammodule.cpp'])
setup( name = "spam", ext_modules=[extension_mod] )





#from setuptools import setup, find_packages, Extension
#import sys, os
#
#version = '0.1'
#
#setup(name='spam',
#      version=version,
#      description='Spam Pakcage',
#      packages=find_packages('spam', exclude=['tests']),
#      ext_modules=[
#        Extension('spam.spam', ['spam/src/spammodule.cpp'], language='c++', libraries=[''], library_dirs = ['/usr/lib'], include_dirs = ['/usr/include/'])
#        ],
#      include_package_data=True,
#      zip_safe=False,
#      )


##from distutils.core import setup, Extension
#import distutils.core as dcp
#
#module1 = dcp.Extension('spam', include_dirs=['/usr/include','/usr/include/python2.7'], libraries=['/usr/lib', '/usr/lib/x86_64-linux-gnu'],  sources=['source/spammodule.cpp'])
#
#dcp.setup( name = 'spam', 
#           version='1.0', 
#           description='Invasion percolation model', 
#           ext_modules = [module1])


#from distutils.core import setup, Extension
#
#module1 = Extension('spam',
#                    define_macros = [('MAJOR_VERSION', '1'),
#                                     ('MINOR_VERSION', '0')],
#                    include_dirs = ['/usr/local/include'],
#                    libraries = ['tcl83'],
#                    library_dirs = ['/usr/local/lib'],
#                    sources = ['source/spammodule.cpp'])
#
#setup (name = 'PackageName',
#       version = '1.0',
#       description = 'This is a demo package',
#       author = 'Martin v. Loewis',
#       author_email = 'martin@v.loewis.de',
#       url = 'https://docs.python.org/extending/building',
#       long_description = '''This is really just a demo package.''',
#       ext_modules = [module1])

