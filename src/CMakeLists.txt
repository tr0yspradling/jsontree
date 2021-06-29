message(STATUS "project_name ${PROJECT_NAME}")
message(STATUS "data_dir ${DATA_DIR}")
message(STATUS "sources_dir ${SOURCES_DIR}")

add_executable(
        ${PROJECT_NAME}
        ${SOURCES_DIR}
        ${DATA_DIR}/resources.c
)

target_link_libraries(
        ${PROJECT_NAME}
        PRIVATE rapidjson
        GTKMM
)

target_include_directories(${PROJECT_NAME} PRIVATE ${SOURCES_DIR})

# set(RAW_DATA_DIR ${})

compile_resources(
        ${DATA_DIR}/resources.c
        ${DATA_DIR/ui}
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
