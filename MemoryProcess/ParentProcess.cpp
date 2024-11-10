#include <iostream>
#include <windows.h>

int main() {
    STARTUPINFO si = { sizeof(si) };
    PROCESS_INFORMATION pi;
    LPCSTR childProcessName = "ChildProcess.exe";

    // Создаем дочерний процесс без выделения памяти заранее
    if (!CreateProcess(NULL, const_cast<LPSTR>(childProcessName), NULL, NULL, FALSE, CREATE_SUSPENDED, NULL, NULL, &si, &pi)) {
        std::cerr << "Ошибка создания процесса." << std::endl;
        return 1;
    }

    // Выделение виртуальной памяти
    SIZE_T memSize = 1024;

    LPVOID memAddress = VirtualAllocEx(pi.hProcess, NULL, memSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);

    if (!memAddress) {
        std::cerr << "Ошибка при выделении виртуальной памяти." << std::endl;
        return 1;
    }

    // Формируем командную строку с передачей адреса
    char commandLine[256];
    sprintf_s(commandLine, "%s %p", childProcessName, memAddress);

    // Создаем дочерний процесс
    if (!CreateProcess(NULL, commandLine, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi)) {
        std::cerr << "Ошибка создания процесса." << std::endl;
        return 1;
    }

    // Ожидание, чтобы дочерний процесс записал данные
    Sleep(1000);

    // Чтение данных из виртуальной памяти дочернего процесса
    char buffer[1024];
    SIZE_T bytesRead;
    if (ReadProcessMemory(pi.hProcess, memAddress, buffer, sizeof(buffer), &bytesRead)) {
        std::cout << "Сообщение от дочернего процесса: " << buffer << std::endl;
    }
    else {
        std::cerr << "Ошибка чтения из памяти." << std::endl;
    }

    // Завершение работы
    VirtualFreeEx(pi.hProcess, memAddress, 0, MEM_RELEASE);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);

    return 0;
}
