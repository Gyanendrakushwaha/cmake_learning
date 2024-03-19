# If you create new headers/cpp files, add them to these list!
set(HEADER_FILES
	cpplib.h
)

set(SOURCE_FILES
  cpplib.c
)
add_library(cpplib ${SOURCE_FILES} ${HEADER_FILES})
