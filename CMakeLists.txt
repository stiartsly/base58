cmake_minimum_required(VERSION 3.7)

project(base58_conv)

set(SRC
    base58.c
    base64.c
    main.c
)

add_executable(base58 ${SRC})

install(TARGETS base58 DESTINATION bin)
