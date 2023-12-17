FILE(GLOB SRCFILES *.cpp *.hpp *.c *.h)
FILE(GLOB GLADEFILES ${DATA_DIR}/ui/*.glade)

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
        ${GLADEFILES}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
