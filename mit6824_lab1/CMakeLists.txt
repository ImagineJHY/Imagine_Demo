cmake_minimum_required(VERSION 3.0)
project(IMAGINE_DEMO_LAB1)

message("[Constructing PROJECT][Imagine Demo_LAB1]: Starting project building, project name is ${PROJECT_NAME}...")

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g  -std=c++17 -Wall -Werror")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++17 -Wall -Werror")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g -O0")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g -O0")
# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -g")
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")


set(IS_MAKE_PROJECT true)
set(IMAGINE_SYSTEM_DIR ${PROJECT_SOURCE_DIR}/thirdparty/Imagine_System)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(IMAGINE_LIB_WORKER_DIR ${PROJECT_SOURCE_DIR}/thirdparty/Imagine_System/worker)

if(EXISTS ${IMAGINE_SYSTEM_DIR}/CMakeLists.txt)
    message("[Constructing PROJECT][Imagine Demo_LAB1]: thirdparty Imagine_System exists, add subModule...")
    add_subdirectory(${IMAGINE_SYSTEM_DIR})
else()
    message("[Constructing PROJECT][Imagine Demo_LAB1]: thirdparty Imagine_System NOT exists, cin make init to init it!")
endif()

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin)
add_executable(imagine_mapreduce_master ${CMAKE_CURRENT_SOURCE_DIR}/src/master.cpp)
add_executable(imagine_mapreduce_mapper ${CMAKE_CURRENT_SOURCE_DIR}/src/mapper.cpp)
add_executable(imagine_mapreduce_reducer ${CMAKE_CURRENT_SOURCE_DIR}/src/reducer.cpp)
add_executable(imagine_rpc_zookeeper ${CMAKE_CURRENT_SOURCE_DIR}/src/RpcZooKeeperMain.cpp)

add_custom_target(
    init
    COMMAND python3 init.py
    echo "[Constructing PROJECT][Imagine Demo_LAB1]: Starting project target init is building..."
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} # 在哪个目录下执行命令
)

if(EXISTS ${IMAGINE_SYSTEM_DIR}/CMakeLists.txt)
    add_custom_target(
        prepare
        echo "[Constructing PROJECT][Imagine Demo_LAB1]: thirdparty Imagine_System exists, Starting project target prepare building..."
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} # 在哪个目录下执行命令
    )
    add_dependencies(prepare system_prepare)

    if(TARGET system_build)
        add_custom_target(
            build
            echo "[Constructing PROJECT][Imagine Demo_LAB1]: Starting project target build building..."
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR} # 在哪个目录下执行命令
        )
        target_link_libraries(imagine_mapreduce_master imagine_mapreduce)
        target_link_libraries(imagine_mapreduce_mapper imagine_mapreduce)
        target_link_libraries(imagine_mapreduce_reducer imagine_mapreduce)
        target_link_libraries(imagine_rpc_zookeeper imagine_rpc)
        add_dependencies(imagine_mapreduce_master system_build)
        add_dependencies(imagine_mapreduce_mapper system_build)
        add_dependencies(imagine_mapreduce_reducer system_build)
        add_dependencies(imagine_rpc_zookeeper system_build)
        add_dependencies(build imagine_mapreduce_master imagine_mapreduce_mapper imagine_mapreduce_reducer imagine_rpc_zookeeper)
    else()
        message("[Constructing PROJECT][Imagine Demo_LAB1]: Please cin make prepare to make every subModule ready!")
    endif()
else()
    message("[Constructing PROJECT][Imagine Demo_LAB1]: thirdparty Imagine_System NOT exists, cin make init to init it!")
endif()