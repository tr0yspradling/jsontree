add_executable(
        ${PROJECT_NAME}
        main.cpp
        application.cpp
        window.cpp
        preferences.cpp
        utils.cpp
        ${DATA_DIR}/resources.c
        model.h)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE rapidjson
        GTKMM
)

target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCES_DIR})

compile_resources(
        ${DATA_DIR}/resources.c
        window.glade
        headerbar.glade
        menu.glade
        preferences.glade
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
