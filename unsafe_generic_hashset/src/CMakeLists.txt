#go to src/unsafe_generic_hashset/src

add_library(unsafe_hash)

file(GLOB unsafe_hash_SRC
    "*.c"
)

target_sources(unsafe_hash
			    PRIVATE	${unsafe_hash_SRC}
						)

set_target_properties(unsafe_hash PROPERTIES
						C_EXTENSION OFF
						C_STANDARD 99
						RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}
						)

target_link_libraries(unsafe_hash common_options)
