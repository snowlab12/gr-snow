INCLUDE(FindPkgConfig)
PKG_CHECK_MODULES(PC_SNOW snow)

FIND_PATH(
    SNOW_INCLUDE_DIRS
    NAMES snow/api.h
    HINTS $ENV{SNOW_DIR}/include
        ${PC_SNOW_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    SNOW_LIBRARIES
    NAMES gnuradio-snow
    HINTS $ENV{SNOW_DIR}/lib
        ${PC_SNOW_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
)

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SNOW DEFAULT_MSG SNOW_LIBRARIES SNOW_INCLUDE_DIRS)
MARK_AS_ADVANCED(SNOW_LIBRARIES SNOW_INCLUDE_DIRS)

