include_directories(${HPATH})
link_directories(${LPATH})
set(EXECUTABLE_OUTPUT_PATH ${EPATH})


set(SORTAPP sortapp)
add_executable(${SORTAPP} sort_t.cc)
target_link_libraries(${SORTAPP} ${SORTLIB})

