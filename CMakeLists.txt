include(cmake/PreventInSourceBuilds.cmake)
# include(cmake/ColorfulMessages.cmake)

project(gumbo_query CXX)
cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
file(MAKE_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")
find_package(Gumbo REQUIRED)

add_subdirectory(src)
add_subdirectory(tests)

##############################
# 	   Generate Doxygen  	   #
#		    Documentation.		   #
##############################
set(DOXYGEN_CONFIG_FILE Doxyfile.d)
find_package(Doxygen)
if(DOXYGEN_FOUND)
	if(EXISTS ${PROJECT_SOURCE_DIR}/${DOXYGEN_CONFIG_FILE})
		add_custom_target(
			doc
			${DOXYGEN_EXECUTABLE}
			${PROJECT_SOURCE_DIR}/${DOXYGEN_CONFIG_FILE}
			WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
			COMMENT "Generating API documentation with Doxygen" VERBATIM
		)
	endif(EXISTS ${PROJECT_SOURCE_DIR}/${DOXYGEN_CONFIG_FILE})
endif(DOXYGEN_FOUND)
