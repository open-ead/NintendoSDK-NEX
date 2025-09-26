#include "Platform/Core/SystemError.h"
#include <cstdio>
#include <cstring>
#include "Platform/Core/GlobalVariables.h"

namespace nn::nex {
void SystemError::GetErrorString(u32 errorCode, char* buffer, u32 bufferSize) {
    u32 origBufferSize = bufferSize;

    if (errorCode == 0) {
        strncpy(buffer, "No Error", bufferSize);
        buffer[origBufferSize - 1] = 0;
        return;
    }

    if ((errorCode & 0x20000000) == 0) {
        strncpy(buffer, strerror(errorCode), bufferSize);
        buffer[origBufferSize - 1] = 0;
        return;
    }

    u32 subsystem = ((ErrorCode)errorCode).GetSubsystem();
    if (subsystem != 16) {
        const char* table = g_SubsystemErrorsTable[subsystem]->GetErrorTable()[errorCode & 0xffff];
        strncpy(buffer, table, bufferSize);
        buffer[origBufferSize - 1] = 0;
        return;
    }

    if (errorCode == 0xE0100000)
        snprintf(buffer, bufferSize, "The facade is not initialized");
}

int SystemError::GetLast() {
    return GlobalVariables::s_pGv->getLastError().GetRef();
}

void SystemError::SignalError(const char*, u32, u32 lastError, u32 lastExtError) {
    GlobalVariables::s_pGv->getLastError() = lastError;
    GlobalVariables::s_pGv->getLastExtError() = lastExtError;
}

SystemError::SystemError(const char* errorString, unsigned int errorCode) {
    m_ErrorCode = errorCode;
    m_ErrorString = errorString;
}

SystemError SystemError::SetErrorInfo(unsigned int lastError, unsigned int lastExtError) {
    m_ErrorInfo = {lastError, lastExtError};
    SystemError error;
    error.m_ErrorCode = m_ErrorCode;
    error.m_ErrorString = m_ErrorString;
    error.m_ErrorInfo = m_ErrorInfo;

    return error;
}

void SystemError::Trace(unsigned long) {
    char buffer[256];

    if (m_ErrorInfo.lastError != 0) {
        buffer[0] = 0;
        GetErrorString(m_ErrorInfo.lastError, buffer, sizeof(buffer));
    }

    if (m_ErrorInfo.lastExtError != 0) {
        buffer[0] = 0;
        GetErrorString(m_ErrorInfo.lastExtError, buffer, sizeof(buffer));
    }
}

// NON_MATCHING: The functions within ThreadVariable shouldn't be called virtually
void SystemError::EraseErrorElements(unsigned long value) {
    GlobalVariables::s_pGv->getLastError().ClearValue(value);
    GlobalVariables::s_pGv->getLastExtError().ClearValue(value);
}

// NON_MATCHING: The functions within ThreadVariable shouldn't be called virtually
void SystemError::EraseErrorElements() {
    u64 currentThread = (u64)nn::os::GetCurrentThread();
    GlobalVariables::s_pGv->getLastError().ClearValue(currentThread);
    GlobalVariables::s_pGv->getLastExtError().ClearValue(currentThread);
}

// NON_MATCHING: The functions within ThreadVariable shouldn't be called virtually
void SystemError::EraseAllErrorElements() {
    GlobalVariables::s_pGv->getLastError().ResetValues();
    GlobalVariables::s_pGv->getLastExtError().ResetValues();
}

void SystemError::ClearLast() {
    u32 lastError = 0;
    u32 lastExtError = 0;
    GlobalVariables::s_pGv->getLastError() = lastError;
    GlobalVariables::s_pGv->getLastExtError() = lastExtError;
}

int SystemError::GetLastExt() {
    return GlobalVariables::s_pGv->getLastExtError().GetRef();
}

bool SystemError::IsError() {
    return ((ErrorCode)GlobalVariables::s_pGv->getLastError().GetRef()).IsError();
}

bool SystemError::IsError(u32 errorCode) {
    return ((ErrorCode)errorCode).IsError();
}

bool SystemError::IsWarning(u32 errorCode) {
    return ((ErrorCode)errorCode).IsWarning();
}

bool SystemError::IsInformational(u32 errorCode) {
    return ((ErrorCode)errorCode).IsInformational();
}

bool SystemError::IsSuccess(u32 errorCode) {
    return ((ErrorCode)errorCode).IsSuccess();
}

void SystemError::TraceLast(unsigned long) {
    int lastError = GetLast();
    int lastExtError = GetLastExt();

    char buffer[256];

    if (lastError != 0) {
        buffer[0] = 0;
        GetErrorString(lastError, buffer, sizeof(buffer));
    }

    if (lastExtError != 0) {
        buffer[0] = 0;
        GetErrorString(lastExtError, buffer, sizeof(buffer));
    }
}

}  // namespace nn::nex
