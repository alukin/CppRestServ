cmake_minimum_required (VERSION 2.8)
project(restserver)
set (CMAKE_CXX_STANDARD 14)
add_definitions(-std=c++14)
include_directories("${CMAKE_SOURCE_DIR}/include")

set(TRGT restserver)
message(" ========== building ${TRGT} =========")

add_executable(${TRGT}
  main.cpp
  src/HTTPAPIServer.cpp
  src/RequestRouter.cpp  
  src/ResourceFactory.cpp  
  src/StaticContentServ.cpp
  src/UserResource.cpp
  src/PipesResource.cpp
  src/Injectable.cpp
 ) 


find_package( Boost REQUIRED log log_setup program_options filesystem date_time system thread chrono atomic)
 if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
    target_link_libraries(${TRGT} ${Boost_LIBRARIES})
    add_definitions( -DBOOST_ALL_DYN_LINK )
 else()
    message (FATAL_ERROR "ERROR! Boost library not found. Can not continue!")
 endif (Boost_FOUND)
# === treads are always present in modern OS, but we need to lilnk it anyway
 find_package (Threads)
 target_link_libraries (${TRGT} ${CMAKE_THREAD_LIBS_INIT})

set(Casablanca_LIBRARIES "-lcpprest -licui18n -licuuc -licudata -lcrypto")

target_link_libraries(${TRGT} ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(${TRGT} ${Casablanca_LIBRARIES})





