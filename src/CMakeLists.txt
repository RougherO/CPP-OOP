cmake_minimum_required(VERSION 3.20)
# set output filename here
set(NAME_TARGET OOP)
# ----------------------------

# set your used languages here
project(${NAME_TARGET} LANGUAGES C CXX)
# ----------------------------

# set all project files here
set(FILES_TARGET main.cpp)
add_executable(${NAME_TARGET} ${FILES_TARGET})
# ----------------------------

### -fsanitize=.. needs to be passed both in compilation and linking stage
# enable/disable sanitizer here
set(ENABLE_UB_SANITIZER ON)
# ----------------------------

# set compiler options here
set(COMPILE_OPTIONS_TARGET -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wpedantic $<$<BOOL:${ENABLE_UB_SANITIZER}>:-fsanitize=undefined -fsanitize=address> -save-temps)
target_compile_options(${NAME_TARGET} PRIVATE ${COMPILE_OPTIONS_TARGET})
# ----------------------------

# set linker options here
set(LINK_OPTIONS_TARGET $<$<BOOL:${ENABLE_UB_SANITIZER}>:-fsanitize=undefined -fsanitize=address>)
target_link_options(${NAME_TARGET} PRIVATE ${LINK_OPTIONS_TARGET})
# ----------------------------

# set include path here
set(INCLUDE_PATH_TARGET "include")
target_include_directories(${NAME_TARGET} PRIVATE ${INCLUDE_PATH_TARGET})
# ----------------------------

# set lib path here
set(LIB_PATH_TARGET "lib")
target_link_directories(${NAME_TARGET} PRIVATE ${LIB_PATH_TARGET})
# ----------------------------

# set lib files here
set(LIB_FILES "")
target_link_libraries(${NAME_TARGET} ${LIB_FILES})
# ----------------------------
