cmake_minimum_required(VERSION 3.23)

project(log-file-indexing)

add_library(tokenize)

target_sources(tokenize
    PRIVATE
    src/tokenize.cxx

    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            include
        FILES
            include/tokenize.hxx
)

add_executable(main)

target_sources(main
    PRIVATE
        src/main.cxx
)

target_link_libraries(main
    PRIVATE
    tokenize
)