set(SSDEEP_EXTENSION_NAME "ssdeep")
set(SSDEEP_LIB_NAME "fuzzy")
set(SSDEEP_INCLUDE_FILENAME "${SSDEEP_LIB_NAME}.h")

FIND_LIBRARY(SSDEEP_LIBRARY NAMES ${SSDEEP_LIB_NAME} PATHS /lib /usr/lib /usr/local/lib)

FIND_PATH(SSDEEP_INCLUDE_DIR NAMES ${SSDEEP_INCLUDE_FILENAME} PATHS /include /usr/include /usr/local/include)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(${SSDEEP_LIB_NAME} DEFAULT_MSG SSDEEP_LIBRARY SSDEEP_INCLUDE_DIR)

mark_as_advanced(SSDEEP_INCLUDE_DIR SSDEEP_LIBRARY)

include_directories(${SSDEEP_INCLUDE_DIR})

HHVM_EXTENSION(${SSDEEP_EXTENSION_NAME} "ext_${SSDEEP_EXTENSION_NAME}.cpp")
HHVM_SYSTEMLIB(${SSDEEP_EXTENSION_NAME} "ext_${SSDEEP_EXTENSION_NAME}.php")

target_link_libraries(ssdeep ${SSDEEP_LIBRARY})
