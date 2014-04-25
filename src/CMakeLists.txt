
set(SOURCE_FILES
    Logger.cpp
    )

add_library(goodies SHARED ${SOURCE_FILES})
target_link_libraries(goodies ${LIBS})
install(TARGETS goodies DESTINATION lib)

