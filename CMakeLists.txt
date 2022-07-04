cmake_minimum_required(VERSION 3.17)

# set the project name
project(bomberman)

include_directories(include/)
include_directories(include/global/)
include_directories(ressources/)
include_directories(src/)
include_directories(src/game/)
include_directories(src/game/Audio/)
include_directories(src/game/Engine/)
include_directories(src/game/Error/)
include_directories(src/game/Event/)
include_directories(src/game/Graphics/)
include_directories(src/game/Map/)
include_directories(src/game/Object/)
include_directories(src/game/Object/Model3d/)
include_directories(src/game/Object/Model3d/Player/)
include_directories(src/game/Object/Model3d/Player/Bomb/)
include_directories(src/game/Object/UI/)
include_directories(src/game/Object/UI/Button/)
include_directories(src/game/Object/UI/Button/TextField/)
include_directories(src/game/Object/UI/Movable/)
include_directories(src/game/Object/UI/Movable/Sprite)
include_directories(src/game/Object/UI/Movable/Text)
include_directories(src/game/Object/UI/Toggle/)
include_directories(src/game/Scene/)
include_directories(src/game/Type/)

find_package(raylib 3.8 QUIET)
if (APPLE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -stdlib=libc++")
endif()

# add the executable
add_executable(bomberman
    src/game/Audio/Audio.cpp
    src/game/Engine/Engine.cpp
    src/game/Error/Error.cpp
    src/game/Event/Event.cpp
    src/game/Graphics/Graphics.cpp
    src/game/Graphics/window.cpp
    src/game/Map/Map.cpp
    src/game/Object/AObject.cpp
    src/game/Object/Model3d/Model3d.cpp
    src/game/Object/Model3d/Player/Player.cpp
    src/game/Object/Model3d/Player/Bomb/Bomb.cpp
    src/game/Object/Ui/Ui.cpp
    src/game/Object/Ui/Button/Button.cpp
    src/game/Object/Ui/Button/TextField/TextField.cpp
    src/game/Object/Ui/Movable/Movable.cpp
    src/game/Object/Ui/Movable/Sprite/Sprite.cpp
    src/game/Object/Ui/Movable/Text/Text.cpp
    src/game/Object/Ui/Toggle/Toggle.cpp
    src/game/Scene/AScene.cpp
    src/game/Scene/Game.cpp
    src/game/Scene/Info.cpp
    src/game/Scene/Menu.cpp
    src/game/Scene/SceneManager.cpp
    src/game/Scene/Settings.cpp
    src/game/Main.cpp
)

if (NOT raylib_FOUND) # If there's none, fetch and build raylib
    include(FetchContent)

    FetchContent_Declare(
            raylib
            URL https://github.com/raysan5/raylib/archive/master.tar.gz
    )

    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)

        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples

        # build raylib
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

    endif()

endif()

target_link_libraries(${PROJECT_NAME} raylib)
