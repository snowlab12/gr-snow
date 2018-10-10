/* -*- c++ -*- */

#define SNOW_API

%include "gnuradio.i"			// the common stuff

//load generated python docstrings
%include "snow_swig_doc.i"

%{
#include "snow/demod.h"
%}


%include "snow/demod.h"
GR_SWIG_BLOCK_MAGIC2(snow, demod);
