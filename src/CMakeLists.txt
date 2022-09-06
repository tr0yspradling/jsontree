FILE(GLOB SRCFILES *.cpp *.hpp *.c *.h)

add_executable(
    ${PROJECT_NAME}
    ${DATA_DIR}/resources.c
    ${SRCFILES}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC rapidjson
    GTKMM
)

target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCES_DIR})

compile_resources(
    ${DATA_DIR}/resources.c
    main.glade
    menu.glade
    headerbar.glade
    preferences.glade
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
