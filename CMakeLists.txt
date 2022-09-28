cmake_minimum_required(VERSION 2.8)
project(kong)


set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_FLAGS "$ENV{CXXFLAGS} -ggdb -O -std=c++14  -L/usr/lib64/mysql -lmysqlclient")

include_directories(.)
include_directories(/usr/local/include)
link_directories(/usr/local/lib)



set(LIB_SRC    
    kong/Buffer.cc
    kong/Epoller.cc
    kong/httpconn.cc
    kong/httprequest.cc
    kong/httpresponse.cc
    kong/Log.cc
    kong/Mutex.cc
    kong/sqlconnpool.cc
    kong/Thread.cc
    kong/Timer.cc
    kong/Util.cc
    kong/WebServer.cc
    )


add_library(kong SHARED ${LIB_SRC})
add_library(kong_static STATIC ${LIB_SRC})
SET_TARGET_PROPERTIES (kong_static PROPERTIES OUTPUT_NAME "kong")


set(LIB_LIB
    kong
    pthread
)


add_executable(main kong/main.cc)
add_dependencies(main kong)
target_link_libraries(main kong ${LIB_LIB})

add_executable(test_log tests/test_log.cc)
add_dependencies(test_log kong)
target_link_libraries(test_log kong ${LIB_LIB})

add_executable(test_sql tests/test_sql.cc)
add_dependencies(test_sql kong)
target_link_libraries(test_sql kong ${LIB_LIB})

add_executable(test_thread tests/test_thread.cc)
add_dependencies(test_thread kong)
target_link_libraries(test_thread kong ${LIB_LIB})

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)




