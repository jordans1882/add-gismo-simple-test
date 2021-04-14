set(EXAMPLES
    build-simple-tensor-product-bspline
)

foreach(example ${EXAMPLES})
    add_executable(${example} ${example}.cpp)
    target_link_libraries(${example} ${LIBRARIES} gismo)
endforeach()
