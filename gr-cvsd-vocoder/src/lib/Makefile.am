#
# Copyright 2004,2005 Free Software Foundation, Inc.
# 
# This file is part of GNU Radio
# 
# GNU Radio is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
# 
# GNU Radio is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with GNU Radio; see the file COPYING.  If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street,
# Boston, MA 02110-1301, USA.
# 

include $(top_srcdir)/Makefile.common

# Install this stuff so that it ends up as the gnuradio.vocoder module
# This usually ends up at:
#   ${prefix}/lib/python${python_version}/site-packages/gnuradio/vocoder

ourpythondir = $(grpythondir)/vocoder
ourlibdir    = $(grpyexecdir)/vocoder

INCLUDES = $(STD_DEFINES_AND_INCLUDES) $(PYTHON_CPPFLAGS)

SWIGPYTHONARGS = $(SWIGPYTHONFLAGS) $(STD_DEFINES_AND_INCLUDES)


ALL_IFILES = 				\
	$(LOCAL_IFILES)			\
	$(NON_LOCAL_IFILES)		

NON_LOCAL_IFILES =			\
	$(GNURADIO_I)


LOCAL_IFILES = 				\
	$(top_srcdir)/gr-cvsd-vocoder/src/lib/cvsd_vocoder.i

# These files are built by SWIG.  The first is the C++ glue.
# The second is the python wrapper that loads the _howto shared library
# and knows how to call our extensions.

BUILT_SOURCES = 			\
	cvsd_vocoder.cc		\
	cvsd_vocoder.py				

# This gets cvsd_vocoder.py installed in the right place
ourpython_PYTHON =			\
	__init__.py			\
	cvsd_vocoder.py

ourlib_LTLIBRARIES = _cvsd_vocoder.la

# These are the source files that go into the shared library
_cvsd_vocoder_la_SOURCES = 		\
	cvsd_decode_bs.cc		\
	cvsd_encode_sb.cc		\
	cvsd_vocoder.cc		


# magic flags
_cvsd_vocoder_la_LDFLAGS = $(NO_UNDEFINED) -module -avoid-version

# link the library against the c++ standard library
_cvsd_vocoder_la_LIBADD = 	\
	$(PYTHON_LDFLAGS)	\
	$(GNURADIO_CORE_LA)	\
	-lstdc++			

cvsd_vocoder.cc cvsd_vocoder.py: cvsd_vocoder.i $(ALL_IFILES)
	$(SWIG) $(SWIGPYTHONARGS) -module cvsd_vocoder -o cvsd_vocoder.cc $(LOCAL_IFILES)

# These headers get installed in ${prefix}/include/gnuradio
grinclude_HEADERS =			\
	cvsd_decode_bs.h		\
	cvsd_encode_sb.h		

# These swig headers get installed in ${prefix}/include/gnuradio/swig
swiginclude_HEADERS = 			\
	$(LOCAL_IFILES)


MOSTLYCLEANFILES = $(BUILT_SOURCES) *.pyc

# Don't distribute output of swig
dist-hook:
	@for file in $(BUILT_SOURCES); do echo $(RM) $(distdir)/$$file; done
	@for file in $(BUILT_SOURCES); do $(RM) $(distdir)/$$file; done
