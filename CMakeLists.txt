cmake_minimum_required(VERSION 3.10)
project(DVD_Screensaver)

add_executable(DVD_Screensaver
    src/main.cpp
    App/CApp.cpp
    Entities/CMobile.cpp
)

include_directories(DVD_Screensaver
    src
    App
    Headers
    Entities
)

add_compile_options("-Wall")

target_link_libraries(DVD_Screensaver
    sfml-system
    sfml-window
    sfml-graphics
)

 
file(
    COPY Resources/ DESTINATION Resources/
)