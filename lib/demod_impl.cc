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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gnuradio/io_signature.h>
#include "demod_impl.h"
#include <iostream>
#include <string>
#include <pwd.h>
#include <unistd.h>
#include <math.h>
#include <ctime>

#include <cstdlib>
#include <cfloat>
#include <stdexcept>

namespace gr {
  namespace snow {

    demod::sptr
    demod::make(bool enable_log, float threshold, int fft_size, std::vector<int> subcarriers)
    {
      return gnuradio::get_initial_sptr
        (new demod_impl(enable_log, threshold, fft_size, subcarriers));
    }

    /*
     * The private constructor
     */
    demod_impl::demod_impl(bool enable_log, float threshold, int fft_size, std::vector<int> subcarriers)
      : gr::sync_block("demod",
              gr::io_signature::make(1, 1, sizeof(gr_complex)),
              gr::io_signature::make(1, 1, sizeof(float))),
              d_enable_log(enable_log),
              d_threshold(threshold),
              d_fft_size(fft_size),
              d_subcarriers(subcarriers)
    {

        /***************************initialize the class variables*****************************************/ 

        sample_count = 0;
        //compatible cross platform output file paths
        struct passwd* pwd = getpwuid(getuid());
        std::string home;
        if(pwd) home = pwd-> pw_dir;
        if(d_enable_log) {
          std::string temp;
            temp = home;
            temp.append("/Desktop/snow-data/sample.txt");
            log_file.open(temp.c_str());
        } 

        // initialize the multiply factor for subcarriers and also to log data
        for(size_t i = 0; i < d_subcarriers.size(); i++)
        {
            multiply_factor[i] = 0;
            std::string temp = home;
            temp.append("/Desktop/snow-data/subcarrier_" + boost::to_string(d_subcarriers[i]) + ".txt");
            data_file[i].open(temp.c_str());
        }

        /***************************initialize the class variables ends*****************************************/ 


    }

    /*
     * Our virtual destructor.
     */
    demod_impl::~demod_impl()
    {
      if(log_file.is_open()){
        log_file.close();
      }

      for(size_t i = 0; i < d_subcarriers.size(); i++)
      {
        if(data_file[i].is_open())
        {
          data_file[i].close();
        }
      }
    }

    int
    demod_impl::work(int noutput_items,
			  gr_vector_const_void_star &input_items,
			  gr_vector_void_star &output_items)
    {
        const gr_complex *in = (const gr_complex *) input_items[0];
        float *out = (float *) output_items[0];

        // Do <+signal processing+>
        for(int i = 0; i < noutput_items; i++)
        {
          // calculate the sample properties
          float real = in[i].real();
          float imag = in[i].imag();
          float mag = sqrt ( pow(real, 2.0) + pow(imag, 2.0) );
          float phase = atan(imag/real);

          // if log is enabled, save log to log_file
          if(d_enable_log)
          {
            if(log_file.is_open())
            {
              log_file << "##########################################################\n";
              log_file << "                    Sample["<<sample_count <<"]\n";
              log_file << "     Real Value: " << real       << "        Imag Value: " << imag << "\n";
              //file << "     Magnitude:  " << mag        << "        Phase:  " << phase << "\n";
              //file << "     Log power:  " << log_mag_dB << " dB     OR      " <<log_mag_dBm << " dBm\n";
            }
          }


          // generate log files for the subcarriers
          for(size_t j = 0; j < d_subcarriers.size(); j++)
          {
            int sub_index = d_subcarriers[j];
            //std::cout << "Sub index " << sub_index<< std::endl;
            // example 32nd subcarrier: sample_count == (32+ (mul_factor_32 * 64))
            if(sample_count == (sub_index + (multiply_factor[j] * d_fft_size)))
            {
              //std::cout << "Inside the sample count " << sample_count << std::endl;
              if(mag >= d_threshold){
                  data_file[j] << "1";
              }
              else{
                  data_file[j] << "0";
              }

              multiply_factor[j] ++;
            } // end inner for
          }

          sample_count++;
          out[i] = mag;
        } // end original for

        // Tell runtime system how many output items we produced.
        return noutput_items;
    }

  } /* namespace snow */
} /* namespace gr */

