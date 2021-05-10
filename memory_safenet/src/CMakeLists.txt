#go to memory_safenet/src

add_library(memory)


file(GLOB memory_SRC
    "*.c"
)

target_sources(memory
			    PRIVATE	${memory_SRC}
						)

set_target_properties(memory PROPERTIES
						C_EXTENSION OFF
						C_STANDARD 99
						RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
						)

target_link_libraries(memory
                            common_options
						    unsafe_hash
						    hash
                            )
