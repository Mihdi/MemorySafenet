#go to src/generic_hashset/src

add_library(hash)

file(GLOB hash_SRC
    "*.c"
)

target_sources(hash
			    PRIVATE	${hash_SRC}
						)

set_target_properties(hash PROPERTIES
						C_EXTENSION OFF
						C_STANDARD 99
						RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
						)

target_link_libraries(hash
                            common_options
                            memory
                            unsafe_hash
                            )
