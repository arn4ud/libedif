add_library(edif STATIC "")

target_include_directories(
  edif
   PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/..
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR})

FLEX_TARGET(
  edif_lexer
    ${CMAKE_CURRENT_SOURCE_DIR}/edif_lexer.lpp
    ${CMAKE_CURRENT_BINARY_DIR}/edif_lexer.cpp)
BISON_TARGET(
  edif_parser
    ${CMAKE_CURRENT_SOURCE_DIR}/edif_parser.ypp
    ${CMAKE_CURRENT_BINARY_DIR}/edif_parser.cpp
    DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/edif_parser.h)
ADD_FLEX_BISON_DEPENDENCY(edif_lexer edif_parser)

target_sources(
  edif
   INTERFACE
    ${CMAKE_CURRENT_SOURCE_DIR}/edif_reader.h
    ${CMAKE_CURRENT_SOURCE_DIR}/edif_writer.h
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/edif_lexer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/edif_lexer.h
    ${CMAKE_CURRENT_BINARY_DIR}/edif_parser.cpp
    ${CMAKE_CURRENT_BINARY_DIR}/edif_parser.h
    ${CMAKE_CURRENT_SOURCE_DIR}/edif_reader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/edif_writer.cpp)

include(GNUInstallDirs)
install(
  TARGETS edif
    ARCHIVE
      DESTINATION ${CMAKE_INSTALL_LIBDIR}
    PUBLIC_HEADER
      DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/edif)

add_executable(edif_lexer_test edif_lexer_test.cpp)
target_include_directories(
  edif_lexer_test
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(edif_lexer_test edif gmock_main)
add_test(NAME edif_lexer_test COMMAND edif_lexer_test)

add_executable(edif_lexer_main edif_lexer_main.cpp)
target_include_directories(
  edif_lexer_main
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(edif_lexer_main edif)

add_executable(edif_parser_main edif_parser_main.cpp)
target_include_directories(
  edif_parser_main
   PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(edif_parser_main edif)

add_executable(edif_reader_main edif_reader_main.cpp)
target_link_libraries(edif_reader_main edif)

add_executable(edif_reader_test edif_reader_test.cpp)
target_link_libraries(edif_reader_test edif gmock_main)
add_test(NAME edif_reader_test COMMAND edif_reader_test)
