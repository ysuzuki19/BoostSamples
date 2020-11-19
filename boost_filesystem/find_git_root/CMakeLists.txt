cmake_minimum_required( VERSION 2.8 FATAL_ERROR )

project( find_git_root )

add_executable( find_git_root main.cpp )

set_property( TARGET find_git_root PROPERTY CXX_STANDARD 20 )

set( Boost_USE_STATIC_LIBS ON )
set( Boost_USE_DEBUG_LIBS OFF )
set( Boost_USE_RELEASE_LIBS ON )
find_package( Boost 1.71 REQUIRED COMPONENTS filesystem)
if( Boost_FOUND )
  include_directories( ${Boost_INCLUDE_DIRS} )
  target_link_libraries( find_git_root ${Boost_LIBRARIES} )
  target_link_libraries( find_git_root Boost::filesystem )
endif()
