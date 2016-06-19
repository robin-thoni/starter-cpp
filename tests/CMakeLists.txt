enable_testing()
include_directories(${CHECK_INCLUDE_DIRS})
include_directories(. ../src)
find_package (Threads)
set(LIBS ${LIBS} gtest pthread)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable(test-${PROJECT_NAME}
        test-main.cpp
  )
target_link_libraries(test-${PROJECT_NAME} ${LIBS})
add_test(test-${PROJECT_NAME} ${CMAKE_CURRENT_BINARY_DIR}/test-${PROJECT_NAME})
