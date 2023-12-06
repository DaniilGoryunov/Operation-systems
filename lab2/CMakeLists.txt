add_executable(
               blur 
               main.c 
               include/blur.h src/blur.c 
               include/abc.h src/abc.c
               )

target_link_libraries(blur m dl)
target_include_directories(blur PRIVATE include)
