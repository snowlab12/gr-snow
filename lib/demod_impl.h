/* -*- c++ -*- */
/* 
 * Copyright 2016 <+YOU OR YOUR COMPANY+>.
 * 
 * This is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 * 
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this software; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef INCLUDED_SNOW_DEMOD_IMPL_H
#define INCLUDED_SNOW_DEMOD_IMPL_H
#include <snow/demod.h>
#include <fstream>


namespace gr {
  namespace snow {

    class demod_impl : public demod
    {
     private:
      // input variables from xml
      bool d_enable_log;
      float d_threshold;
      int d_fft_size;
      std::vector<int> d_subcarriers;

      //variable to analyze data
      long long sample_count;
      //std::vector<long> multiply_factor;
      long multiply_factor[64];
      std::ofstream log_file;
      std::ofstream data_file[64];


     public:
      demod_impl(bool enable_log, float threshold, int fft_size, std::vector<int> subcarriers);
      ~demod_impl();

      // Where all the action really happens
      int work(int noutput_items,
	       gr_vector_const_void_star &input_items,
	       gr_vector_void_star &output_items);
    };

  } // namespace snow
} // namespace gr

#endif /* INCLUDED_SNOW_DEMOD_IMPL_H */

