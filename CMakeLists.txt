project(lab4)

add_executable(lab4 main.cpp)


install(TARGETS lab4 RUNTIME DESTINATION bin)

add_library(lab4_lib STATIC mat_utils.cpp)

target_link_libraries(lab4 lab4_lib)




