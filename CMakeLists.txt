# turn on all warnings
if (WIN32)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra -pedantic)
endif ()

# add subdirectories to the build
add_subdirectory(uva263)
add_subdirectory(uva10008)
add_subdirectory(uva10954)
