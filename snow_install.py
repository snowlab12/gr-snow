#!/opt/local/Library/Frameworks/Python.framework/Versions/2.7/bin/python2.7

import os

print 'Going to gr-snow directory...'
os.chdir('/Users/emon/gnuradio/gr-snow')
print 'Checking if the build directory exists...'
os.system('mkdir -p build')
os.chdir('build')
print 'Building SNOW module...'

os.system('CC=/usr/bin/gcc CXX=/usr/bin/g++ cmake ../ -DPYTHON_EXECUTABLE=/opt/local/bin/python2.7 -DPYTHON_INCLUDE_DIR=/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Headers -DPYTHON_LIBRARY=/opt/local/Library/Frameworks/Python.framework/Versions/2.7/Python -DCMAKE_INSTALL_PREFIX=/opt/local')
os.system('make')


print 'Installing SNOW module'
os.system('sudo make install')
print 'Updating dynamic library ...'
os.system('sudo update_dyld_shared_cache')
print 'Configuring python path for SNOW ...'
os.system('sudo cp -R /opt/local/lib/python2.7/site-packages/snow /opt/local/Library/Frameworks/Python.framework/Versions/2.7/lib/python2.7/site-packages/')
print 'Done!'
