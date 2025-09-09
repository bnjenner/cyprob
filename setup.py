import os
import sys
import sysconfig
from setuptools import setup, Extension
from setuptools.command.build_ext import build_ext
import pybind11


class get_pybind_include(object):
    """Helper class to determine the pybind11 include path."""

    def __str__(self):
        return pybind11.get_include()


ext_modules = [
    Extension(
        'cyprob',
        sources=[
            'src/main.cpp',
        ],
        include_dirs=[
            get_pybind_include(),
            'include',
        ],
        language='c++',
        extra_compile_args=['-std=c++17'],
        libraries=['boost_system'],  # or other boost libraries you use
    ),
]


class BuildExt(build_ext):
    """A custom build extension for adding compiler-specific options."""
    def build_extensions(self):
        ct = self.compiler.compiler_type
        opts = []

        if ct == 'unix':
            opts.append('-DVERSION_INFO="%s"' % self.distribution.get_version())
            opts.append('-std=c++17')
            opts.append('-O3')
            if sys.platform == 'darwin':
                opts += ['-stdlib=libc++', '-mmacosx-version-min=10.14']

        for ext in self.extensions:
            ext.extra_compile_args = opts
        build_ext.build_extensions(self)


setup(
    name='cyprob',
    version='0.1.0',
    author='Bradley',
    author_email='bnjenner@bu.edu',
    description='Python library for probability and statistics using C++, pybind11, and Boost',
    long_description='',
    ext_modules=ext_modules,
    cmdclass={'build_ext': BuildExt},
    zip_safe=False,
    python_requires=">=3.6",
)
