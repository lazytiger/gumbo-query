# gumbo_query tests
include_directories(${Gumbo_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/src)

file(GLOB SRC_FILES *.cpp)
add_executable(test_gumbo_query ${SRC_FILES})
target_link_libraries(test_gumbo_query gumbo_query)

set_property(TARGET test_gumbo_query PROPERTY CXX_STANDARD 11)
set_property(TARGET test_gumbo_query PROPERTY CXX_STANDARD_REQUIRED ON)
