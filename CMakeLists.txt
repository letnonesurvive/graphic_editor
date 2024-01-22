cmake_minimum_required(VERSION 3.12)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VESRION 0.0.${PATCH_VERSION})

project(graphic_editor VERSION ${PROJECT_VESRION})

add_executable(graphic_editor 
               Controller.cpp 
               Controller.h
               Model.cpp
               Model.h
               View.cpp 
               View.h
               "Graphic Editor Prototype.cpp")

set_target_properties(graphic_editor graphic_editor PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(graphic_editor
    PRIVATE "${CMAKE_BINARY_DIR}"
)

if (MSVC)
    target_compile_options(graphic_editor PRIVATE
        /W4
    )
    target_compile_options(graphic_editor PRIVATE
        /W4
    )
else ()
    target_compile_options(graphic_editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
    target_compile_options(graphic_editor PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS graphic_editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT hippiman1221@gmail.com)
include(CPack)
