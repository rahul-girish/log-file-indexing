cmake_minimum_required(VERSION 3.23)

project(http-server)

add_executable(main)

target_sources(main
    PRIVATE
        src/main.cxx
)

target_link_libraries(main
    PRIVATE
)