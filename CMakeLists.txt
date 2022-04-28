cmake_minimum_required(VERSION 3.10) 
project(echo VERSION 0.1)
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")
# add_subdirectory(bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
file(GLOB_RECURSE LIB_SOURCES src/*.c)
file(GLOB LIB_HEADERS lib/*.h)
file(GLOB APP_SOURCES src
"echoservice.c"
"clientservice.c")
set(APP
	src/echoservice.c
	src/echoclient.c
)
add_library(echo STATIC ${LIB_SOURCES} ${LIB_HEADERS})
# aux_source_directory(CMAKE_SOURCE_DIR)
# add_executable(echoclient src/echoclient.c)
# file( GLOB LIB_SOURCES lib/*.cpp )
# file( GLOB LIB_HEADERS lib/*.h )
foreach(srcfile ${APP})
	get_filename_component(mainname ${srcfile} NAME_WE)
	add_executable(${mainname} ${srcfile})
	target_link_libraries(${mainname} echo)
endforeach()
