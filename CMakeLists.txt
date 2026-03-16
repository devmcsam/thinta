cmake_minimum_required(VERSION 4.2)
project(thinta VERSION 0.1.0 LANGUAGES C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    set(CMAKE_C_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
endif ()

add_link_options("-fuse-ld=lld")

set(COMMON_WARNINGS
        -Wall -Wextra -Wpedantic -Wshadow -Wcast-align
        -Wconversion -Wsign-conversion -Wfloat-equal
        -Wpointer-arith -Wundef -Wformat=2
)

set(RELEASE_CFLAGS
        -O3 -fno-strict-aliasing
        -fno-unsafe-math-optimizations -fno-math-errno
)

set(DEBUG_SANITIZERS
        -fsanitize=address,undefined,leak
        -fsanitize=signed-integer-overflow
        -fno-omit-frame-pointer
        -fno-optimize-sibling-calls
)

set(DEBUG_CFLAGS
        -Og -g ${COMMON_WARNINGS} ${DEBUG_SANITIZERS}
)

set(RELWITHDEBINFO_CFLAGS
        -g -fno-omit-frame-pointer ${RELEASE_CFLAGS}
)

add_library(thinta STATIC
        src/thinta.c
        include/thinta.h
        src/internal/small_ints.h
        src/internal/small_floats.h
        include/integers/fixed.h
        src/integers/conversion.c
        src/integers/ops.c
)

target_include_directories(thinta PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(thinta PRIVATE ${PROJECT_SOURCE_DIR}/src)

include(CheckIPOSupported)
check_ipo_supported(RESULT ipo_supported OUTPUT error)
if (ipo_supported)
    set_target_properties(thinta PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELEASE TRUE)
    set_target_properties(thinta PROPERTIES INTERPROCEDURAL_OPTIMIZATION_RELWITHDEBINFO TRUE)
endif ()

target_compile_options(thinta PRIVATE
        $<$<CONFIG:Release>:${RELEASE_CFLAGS}>
        $<$<CONFIG:Debug>:${DEBUG_CFLAGS}>
        $<$<CONFIG:RelWithDebInfo>:${RELWITHDEBINFO_CFLAGS}>
)

target_link_options(thinta PRIVATE
        $<$<CONFIG:Debug>:${DEBUG_SANITIZERS}>
)

target_compile_definitions(thinta PRIVATE
        $<$<CONFIG:Release>:NDEBUG>
        $<$<CONFIG:Debug>:DEBUG>
        $<$<CONFIG:RelWithDebInfo>:NDEBUG>
)