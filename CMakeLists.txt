cmake_minimum_required(VERSION 3.16)
project( 2D_SVG_RENDERER CXX) 

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(MAKE_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/www")
file(MAKE_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}/build")

include(FetchContent)
FetchContent_Declare(
	nodepp
	GIT_REPOSITORY   https://github.com/NodeppOfficial/nodepp-wasm
	GIT_TAG          origin/main
	GIT_PROGRESS     ON
)
FetchContent_MakeAvailable(nodepp)

include(FetchContent)
FetchContent_Declare(
	nodepp-raylib
	GIT_REPOSITORY   https://github.com/NodeppOfficial/nodepp-raylib
	GIT_TAG          origin/main
	GIT_PROGRESS     ON
)
FetchContent_MakeAvailable(nodepp-raylib)

include(FetchContent)
FetchContent_Declare(
	nodepp-ungine
	GIT_REPOSITORY   https://github.com/NodeppOfficial/nodepp-ungine
	GIT_TAG          origin/main
	GIT_PROGRESS     ON
)
FetchContent_MakeAvailable(nodepp-ungine)

set(EMCC_LINK_FLAGS
    "SHELL:-s EXPORTED_RUNTIME_METHODS=['HEAPF32']"
	"SHELL:--preload-file ${CMAKE_CURRENT_SOURCE_DIR}/assets/sprites@/assets/sprites"
)


add_executable( main ./main.cpp )
set_target_properties( main PROPERTIES SUFFIX ".html")
target_link_options  ( main PRIVATE ${EMCC_LINK_FLAGS})
target_link_libraries( main PUBLIC nodepp nodepp-raylib nodepp-ungine )

set_target_properties( main PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/www"
    OUTPUT_NAME "index"
)