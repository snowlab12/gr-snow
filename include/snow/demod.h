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


#ifndef INCLUDED_SNOW_DEMOD_H
#define INCLUDED_SNOW_DEMOD_H

#include <snow/api.h>
#include <gnuradio/sync_block.h>
#include <vector>

namespace gr {
  namespace snow {

    /*!
     * \brief <+description of block+>
     * \ingroup snow
     *
     */
    class SNOW_API demod : virtual public gr::sync_block
    {
     public:
      typedef boost::shared_ptr<demod> sptr;

      /*!
       * \brief Return a shared_ptr to a new instance of snow::demod.
       *
       * To avoid accidental use of raw pointers, snow::demod's
       * constructor is in a private implementation
       * class. snow::demod::make is the public interface for
       * creating new instances.
       */
      static sptr make(bool enable_log, float threshold, int fft_size, std::vector<int> subcarriers);
    };

  } // namespace snow
} // namespace gr

#endif /* INCLUDED_SNOW_DEMOD_H */

