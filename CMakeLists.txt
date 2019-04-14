cmake_minimum_required(VERSION 3.5)

project(aerial)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_BUILD_TYPE DEBUG)

find_package(mynteye REQUIRED)
find_package(OpenCV 3 REQUIRED)
find_package(PCL)

# eigen
include_directories( "/usr/include/eigen3/" )

# pcl
find_package( PCL 1.8 REQUIRED COMPONENT common io )
include_directories( "/usr/include/pcl-1.8/" )
#add_definitions( "/usr/share/pcl-1.8/" )
link_directories("/usr/lib/libpcl_common.so" "/usr/lib/libpcl_io.so")
#list (REMOVE_ITEM PCL_LIBRARIES "vtkproj4")

include_directories( ${PROJECT_SOURCE_DIR}/include)
include_directories( ${PROJECT_SOURCE_DIR}/src)
file(GLOB_RECURSE sourcefiles "src/*.cpp" )

set(__link_libs mynteye)
if(THIS_WITH_OPENCV)
    list(APPEND __link_libs ${OpenCV_LIBS})
    list(APPEND __dll_search_paths ${OpenCV_LIB_SEARCH_PATH})
endif()
if(THIS_WITH_PCL)
    list(APPEND __link_libs ${PCL_LIBRARIES})
    #list(APPEND __link_libs pcl::pcl)
    list(APPEND __dll_search_paths ${PCL_LIB_SEARCH_PATH})
endif()

add_executable(aerial main.cpp ${sourcefiles})
target_link_libraries(aerial ${__link_libs})
target_link_libraries(aerial  ${OpenCV_LIBS})
target_link_libraries(aerial ${PCL_LIBRARIES})



