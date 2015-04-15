# libgumbo_query

# Gumbo dependency include directory.
include_directories(${Gumbo_INCLUDE_DIRS})

file(GLOB SRC_FILES *.cpp)
add_library(gumbo_query SHARED ${SRC_FILES})
add_library(gumbo_query_static STATIC ${SRC_FILES})

target_link_libraries(gumbo_query ${Gumbo_LIBRARY})
# Link our static library with the static Gumbo dependency if it exists.
if(${Gumbo_static_LIBRARY})
  target_link_libraries(gumbo_query_static ${Gumbo_static_LIBRARY})
else(${Gumbo_LIBRARY})
  target_link_libraries(gumbo_query_static ${Gumbo_LIBRARY})
endif(${Gumbo_static_LIBRARY})

set(gumbo_query_LIBRARIES gumbo_query gumbo_query_static)
set_property(TARGET ${gumbo_query_LIBRARIES} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${gumbo_query_LIBRARIES} PROPERTY CXX_STANDARD_REQUIRED ON)
