# gr-snow
Getting Started with SNOW Implementation
---------------------------------------------------------------------

Contents
----------------------------------------------------------------------
1. Introduction
2. Requirements
3. Installations
4. Running the SNOW BS
5. Conclusion
6. References





Introduction
---------------------------------------------------------------------
SNOW is an open source Low-Power Wide-Area Network (LPWAN) over TV white
spaces. This  documentation shows you how  to install and use the SNOW 
implementation. This document will be updated parallelly with the conti-
nuous development of the full-fledged SNOW implementation. Please refer 
to [1, 2, 3] to learn more about SNOW.

Requirements
---------------------------------------------------------------------
OS: Linux/Mac OS X
Software: GNU Radio (https://www.gnuradio.org)
Hardware: USRP Bus Series (https://www.ettus.com)

Installations
---------------------------------------------------------------------
Linux:
------
1. Copy the gr-snow folder in your machine
2. cd gr-snow
3. mkdir build && cd build
4. cmake .. && make
5. sudo make install && sudo ldconfig

Mac OS X:
---------
1. Copy the gr-snow folder in your machine
2. Run the snow_install_mac.py script. Make sure your change the script
at line 6 that tells where you copied the gr-snow folder.

Running the SNOW BS
-----------------------------------------------------------------------
1. Open snow-bs.grc in GNU Radio
2. Connect USRP device to your machine
3. Specify the snow subcarriers (based on your subcarrier bandwidth and 
FFT algorithm) in the snow-bs.grc script.
4. Specify the white space frequencies and BS bandwidth in the snow-bs.
grc script.


Conclusion
------------------------------------------------------------------------
We are continuously making the SNOW implementation automated. Please feel
free to contact us at (r.mahbub, dali.ismail, saifullah)@wayne.edu with 
your questions or concerns. Happy LPWAN networking over TV white spaces.

References
------------------------------------------------------------------------

1. Abusayeed Saifullah*, Mahbubur Rahman*, Dali Ismail, Chenyang Lu, Ranveer
Chandra and Jie Liu, “SNOW: Sensor Network over White Spaces”, in ACM SenSys 
’16 (14th ACM Conference on Embedded Networked Sensor Systems); pp. 272--285;
2016. * First co-author.

2. Abusayeed Saifullah*, Mahbubur Rahman*, Dali Ismail, Chenyang Lu, Jie Liu, 
and Ranveer Chandra, “Enabling Reliable, Asynchronous, and Bidirectional Comm-
unication in Sensor Networks over White Spaces”, in ACM SenSys ’17 (15th ACM 
Conference on Embedded Networked Sensor Systems); pp. 1--14; 2017. * First 
co-author.

3. Abusayeed Saifullah*, Mahbubur Rahman*, Dali Ismail, Chenyang Lu, Jie Liu,
and Ranveer Chandra, “Low-Power Wide-Area Network over White Spaces”, in ACM/
IEEE Transactions on Networking; pp. 1--14; 2018.   * First co-author.

