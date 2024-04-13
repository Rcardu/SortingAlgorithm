set(LIBRARY_OUTPUT_PATH ${LPATH})
include_directories(${HPATH})
aux_source_directory(./ SRC)

add_library(${SORTLIB} STATIC ${SRC})
