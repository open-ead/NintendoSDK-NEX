cmake_minimum_required(VERSION 3.15)

project(NintendoSDK-NEX CXX)

add_compile_definitions(
  VERSION=${NN_NEX_VERSION}
  PROJ=${NN_NEX_PROJECT}
)

add_library(NintendoSDK-NEX OBJECT
OnlineCore/src/Core/Checksum/SHA1/SHA1.cpp
OnlineCore/src/Core/Chrono.cpp
OnlineCore/src/Core/FileStorageDevice.cpp
OnlineCore/src/Core/InstantiationContext.cpp
OnlineCore/src/Core/LocalClock.cpp
OnlineCore/src/Core/Plugin.cpp
OnlineCore/src/Core/StorageUnit.cpp
OnlineCore/src/Core/UtilitySubsystem.cpp

OnlineCore/src/Platform/Core/BadEvents.cpp
OnlineCore/src/Platform/Core/ConsoleIO.cpp
OnlineCore/src/Platform/Core/DateTime.cpp
OnlineCore/src/Platform/Core/LockChecker.cpp
OnlineCore/src/Platform/Core/Log.cpp
OnlineCore/src/Platform/Core/LogDeviceConsole.cpp
OnlineCore/src/Platform/Core/MemoryManager.cpp
OnlineCore/src/Platform/Core/MutexPrimitive.cpp
OnlineCore/src/Platform/Core/OutputFormat.cpp
OnlineCore/src/Platform/Core/Platform.cpp
OnlineCore/src/Platform/Core/RefCountedObject.cpp
OnlineCore/src/Platform/Core/Result.cpp
OnlineCore/src/Platform/Core/RootObject.cpp
OnlineCore/src/Platform/Core/String.cpp
OnlineCore/src/Platform/Core/SystemError.cpp
OnlineCore/src/Platform/Core/Time.cpp
OnlineCore/src/Platform/Core/Variant.cpp
OnlineCore/src/Platform/Core/VersionInfo.cpp
OnlineCore/src/Platform/Host/Configuration.cpp
OnlineCore/src/Platform/Stack/Core/InetAddress.cpp
OnlineCore/src/Platform/Stack/Core/InterfaceInfo.cpp

RendezVous/src/Services/Data.cpp
)

target_include_directories(NintendoSDK-NEX PUBLIC
  ../NintendoSDK/include
  OnlineCore/include
  RendezVous/include
  RendezVous/Core/include
)

target_compile_options(NintendoSDK-NEX PRIVATE -fno-strict-aliasing)
target_compile_options(NintendoSDK-NEX PRIVATE -fno-exceptions)
target_compile_options(NintendoSDK-NEX PRIVATE -Wall -Wextra)
target_compile_options(NintendoSDK-NEX PRIVATE -Wno-invalid-offsetof)
target_compile_options(NintendoSDK-NEX PRIVATE -fvisibility=default -g1 -flto)
