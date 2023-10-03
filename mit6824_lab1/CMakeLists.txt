cmake_minimum_required(VERSION 3.0)
project(IMAGINE_DEMO_LAB1)

set(IMAGINE_SYSTEM_DIR ${PROJECT_SOURCE_DIR}/thirdparty/Imagine_System)
add_subdirectory(${IMAGINE_SYSTEM_DIR})
add_subdirectory(${IMAGINE_SYSTEM_DIR}/worker/Imagine_MapReduce)
add_subdirectory(${IMAGINE_SYSTEM_DIR}/worker/Imagine_Rpc)
add_subdirectory(${IMAGINE_SYSTEM_DIR}/worker/Imagine_ZooKeeper)
add_subdirectory(${IMAGINE_SYSTEM_DIR}/worker/Imagine_Muduo)

# include_directories(${PROJECT_SOURCE_DIR}/include)
# file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(imagine_mapreduce_master ${CMAKE_CURRENT_SOURCE_DIR}/src/master.cpp)
add_executable(imagine_mapreduce_mapper ${CMAKE_CURRENT_SOURCE_DIR}/src/mapper.cpp)
add_executable(imagine_mapreduce_reducer ${CMAKE_CURRENT_SOURCE_DIR}/src/reducer.cpp)

# add_custom_target(
#     init
#     COMMAND python3 init.py
#     WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} # 在哪个目录下执行命令
# )

add_custom_target(
    imagine_mapreduce_make
    message("Init")
)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Imagine_System/worker/Imagine_MapReduce/lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Imagine_System/worker/Imagine_Muduo/lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Imagine_System/worker/Imagine_Rpc/lib)
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/thirdparty/Imagine_System/worker/Imagine_ZooKeeper/lib)

add_dependencies(imagine_mapreduce_master init_all)
add_dependencies(imagine_mapreduce_mapper init_all)
add_dependencies(imagine_mapreduce_reducer init_all)
add_dependencies(imagine_mapreduce_master init_all imagine_mapreduce imagine_zookeeper imagine_rpc imagine_muduo)
add_dependencies(imagine_mapreduce_mapper init_all imagine_mapreduce imagine_zookeeper imagine_rpc imagine_muduo)
add_dependencies(imagine_mapreduce_reducer init_all imagine_mapreduce imagine_zookeeper imagine_rpc imagine_muduo)
add_dependencies(imagine_mapreduce_make imagine_mapreduce_master imagine_mapreduce_mapper imagine_mapreduce_reducer)

target_link_libraries(imagine_mapreduce_master pthread imagine_mapreduce imagine_rpc imagine_zookeeper imagine_muduo)
target_link_libraries(imagine_mapreduce_mapper pthread imagine_mapreduce imagine_rpc imagine_zookeeper imagine_muduo)
target_link_libraries(imagine_mapreduce_reducer pthread imagine_mapreduce imagine_rpc imagine_zookeeper imagine_muduo)