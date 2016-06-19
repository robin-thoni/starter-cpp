include_directories(.)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES
  main.cpp
  Interface/MainClass.cpp
  Interface/MainClass.h
  Interface/CommandLineParser.cpp
  Interface/CommandLineParser.h
  DBO/CommandLineOption.cpp
  DBO/CommandLineOption.h
  DBO/Result.hxx
  DBO/Result.h
  )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${LIBS})
