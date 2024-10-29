if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set(USE_FLAGS
        "--use-port=sdl2 --use-port=sdl2_image --use-port=sdl2_image --use-preload-plugins -O1 --emrun -sUSE_SDL_MIXEX=2 -sUSE_OGG-1 -s ALLOW_MEMORY_GROWTH=1"
    )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS
        "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY -s GL_ENABLE_GET_PROC_ADDRESS=1"
    )
    set(CMAKE_EXECUTABLE_SUFFIX .js)
else()
    find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)
    find_package(SDL2 REQUIRED CONFIG COMPONENTS SDL2main)
endif()

include_directories(${SDL2_INCLUDE_DIRS})

# ############### sdl_utils ################
add_library(sdl_utils SHARED sdl_utils.c)
target_link_libraries(sdl_utils PUBLIC ${SDL2_LIBRARIES} SDL2_image ${SDL2_IMAGE_LIBRARIES})

target_include_directories(
    sdl_utils
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)

if(TARGET SDL2::SDL2main)
    target_link_libraries(sdl_utils PRIVATE SDL2::SDL2main)
endif()

# ############### mmdm ################
add_executable(${PROJECT_NAME} main.c)
target_include_directories(
    ${PROJECT_NAME}
    PUBLIC $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
           $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}
)
target_link_libraries(${PROJECT_NAME} PUBLIC sdl_utils)

# set rpath to install/lib directory
set_target_properties(
    ${PROJECT_NAME} PROPERTIES INSTALL_RPATH ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR}
)

set(ASSETS ${PROJECT_SOURCE_DIR}/assets)

if(${CMAKE_SYSTEM_NAME} MATCHES "Emscripten")
    set_target_properties(
        ${PROJECT_NAME} PROPERTIES LINK_FLAGS
                                   "--preload-file=${ASSETS}@/assets -s ALLOW_MEMORY_GROWTH=1"
    )
endif()

install(
    TARGETS sdl_utils ${PROJECT_NAME}
    EXPORT ${PROJECT_NAME}-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

install(DIRECTORY ${ASSETS} DESTINATION ${CMAKE_INSTALL_BINDIR})

# add_subdirectory(example)
