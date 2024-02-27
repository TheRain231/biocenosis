cmake_minimum_required(VERSION 3.14)
project(Biocenosis)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(SOURCE_FILES source/main.cpp
        source/field.h
        source/field.cpp
        source/entity.h
        source/entity.cpp)
add_executable(Biocenosis ${SOURCE_FILES})

# Добавление textures
FILE(
        COPY "${CMAKE_CURRENT_SOURCE_DIR}/textures"
        DESTINATION "${CMAKE_CURRENT_BINARY_DIR}"
)
if(WIN32)
    set(SFML_ROOT "C:\\SFML-2.6.1")
    set(SFML_STATIC_LIBRARIES TRUE)
else()
    include_directories(/usr/local/include)
endif()

# Поиск компонентов библиотеки
find_package(SFML 2.6.1 COMPONENTS graphics window system REQUIRED)

if(SFML_FOUND)
    # Добавление headers
    target_include_directories(Biocenosis PRIVATE ${SFML_INCLUDE_DIR})
    # Линковка библиотек
    target_link_libraries(Biocenosis PRIVATE m sfml-graphics sfml-window sfml-system)
endif()
