cmake_minimum_required(VERSION 3.15)

project(NintendoSDK-NEX CXX)

add_compile_definitions(
  VERSION=${NN_NEX_VERSION}
  PROJ=${NN_NEX_PROJECT}
)

add_library(NintendoSDK-NEX OBJECT
OnlineCore/include/Core/BasicCache.h
OnlineCore/include/Core/Buffer.h
OnlineCore/include/Core/CacheManager.h
OnlineCore/include/Core/Checksum/EncryptionAlgorithm.h
OnlineCore/include/Core/Checksum/Interface/ChecksumAlgorithm.h
OnlineCore/include/Core/Checksum/Interface/CRC16Checksum.h
OnlineCore/include/Core/Checksum/Interface/MD5Checksum.h
OnlineCore/include/Core/Checksum/MD5/MD5.h
OnlineCore/include/Core/Checksum/RC4Encryption.h
OnlineCore/include/Core/Checksum/SHA1/SHA1.h
OnlineCore/include/Core/Chrono.h
OnlineCore/include/Core/FileStorageDevice.h
OnlineCore/include/Core/InstanceControl.h
OnlineCore/include/Core/InstanceTable.h
OnlineCore/include/Core/InstantiationContext.h
OnlineCore/include/Core/Key.h
OnlineCore/include/Core/LocalClock.h
OnlineCore/include/Core/Plugin.h
OnlineCore/include/Core/PseudoGlobalVariable.h
OnlineCore/include/Core/PseudoGlobalVariableList.h
OnlineCore/include/Core/PseudoGlobalVariableRoot.h
OnlineCore/include/Core/PseudoSingleton.h
OnlineCore/include/Core/StorageDevice.h
OnlineCore/include/Core/StorageUnit.h
OnlineCore/include/Core/SystemComponent.h
OnlineCore/include/Core/UtilitySubsystem.h

OnlineCore/include/DDLTypes/DDLDeclarations.h
OnlineCore/include/DDLTypes/DynamicRunTimeInterface.h

OnlineCore/include/Platform/Core/BadEvents.h
OnlineCore/include/Platform/Core/ConsoleIO.h
OnlineCore/include/Platform/Core/DateTime.h
OnlineCore/include/Platform/Core/EventLog.h
OnlineCore/include/Platform/Core/GlobalVariables.h
OnlineCore/include/Platform/Core/LockChecker.h
OnlineCore/include/Platform/Core/Log.h
OnlineCore/include/Platform/Core/LogDevice.h
OnlineCore/include/Platform/Core/LogDeviceConsole.h
OnlineCore/include/Platform/Core/LogFilter.h
OnlineCore/include/Platform/Core/MemAllocator.h
OnlineCore/include/Platform/Core/MemoryManager.h
OnlineCore/include/Platform/Core/MutexPrimitive.h
OnlineCore/include/Platform/Core/NonCopyable.h
OnlineCore/include/Platform/Core/OutputFormat.h
OnlineCore/include/Platform/Core/Platform.h
OnlineCore/include/Platform/Core/RefCountedObject.h
OnlineCore/include/Platform/Core/Result.h
OnlineCore/include/Platform/Core/RootObject.h
OnlineCore/include/Platform/Core/String.h
OnlineCore/include/Platform/Core/StringConversion.h
OnlineCore/include/Platform/Core/StringStream.h
OnlineCore/include/Platform/Core/SystemClock.h
OnlineCore/include/Platform/Core/SystemError.h
OnlineCore/include/Platform/Core/ThreadVariable.h
OnlineCore/include/Platform/Core/ThreadVariableRoot.h
OnlineCore/include/Platform/Core/Time.h
OnlineCore/include/Platform/Core/Variant.h
OnlineCore/include/Platform/Core/VersionInfo.h
OnlineCore/include/Platform/Core/WaterMark.h
OnlineCore/include/Platform/Host/Configuration.h
OnlineCore/include/Platform/Host/ConfigurationVariable.h
OnlineCore/include/Platform/Stack/Core/BerkeleySocketDriver.h
OnlineCore/include/Platform/Stack/Core/InetAddress.h
OnlineCore/include/Platform/Stack/Core/InterfaceInfo.h
OnlineCore/include/Platform/Stack/Core/SocketDriver.h

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

RendezVous/Core/include/Common/ClientProtocol.h
RendezVous/Core/include/Common/NintendoProtocolFoundation/NintendoAuthenticationDDLDeclarations.h
RendezVous/Core/include/Common/Protocol.h
RendezVous/Core/include/Common/ServerProtocol.h
RendezVous/include/Services/Data.h

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
target_compile_options(NintendoSDK-NEX PRIVATE -Wno-unused-parameter -Wno-unused-private-field)
