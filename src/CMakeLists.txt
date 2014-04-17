
set(SOURCE_FILES
    Logger.cpp
    )

add_library(goodies SHARED ${SOURCE_FILES})
install(TARGETS goodies DESTINATION lib)

