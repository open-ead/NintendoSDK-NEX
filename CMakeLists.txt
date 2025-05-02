cmake_minimum_required(VERSION 3.15)

project(NintendoSDK-NEX CXX)

file(GLOB_RECURSE NEX_SOURCES
  "*.cpp"
  "*.c"
)

add_compile_definitions(
  VERSION=${NN_NEX_VERSION}
  PROJ=${NN_NEX_PROJECT}
)

add_library(NintendoSDK-NEX OBJECT ${NEX_SOURCES})

target_include_directories(NintendoSDK-NEX PUBLIC
  ../NintendoSDK/include
  OnlineCore/include
  RendezVous/include
)

target_compile_options(NintendoSDK-NEX PRIVATE -fno-strict-aliasing)
target_compile_options(NintendoSDK-NEX PRIVATE -fno-exceptions)
target_compile_options(NintendoSDK-NEX PRIVATE -Wall -Wextra)
target_compile_options(NintendoSDK-NEX PRIVATE -Wno-invalid-offsetof)
target_compile_options(NintendoSDK-NEX PRIVATE -fvisibility=default -g1 -flto)
