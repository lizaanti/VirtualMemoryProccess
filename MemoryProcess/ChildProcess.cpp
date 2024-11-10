//#include <iostream>
//#include <windows.h>
//
//int main(int argc, char* argv[]) {
//    if (argc < 2) {
//        std::cerr << "Не указан адрес памяти." << std::endl;
//        return 1;
//    }
//
//    // Чтение адреса памяти из командной строки
//    LPVOID memAddress = (LPVOID)strtoull(argv[1], nullptr, 16);
//    HANDLE parentProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, GetCurrentProcessId());
//
//    if (!parentProcess) {
//        std::cerr << "Ошибка открытия родительского процесса." << std::endl;
//        return 1;
//    }
//
//    // Сообщение для записи в виртуальную память родительского процесса
//    const char* message = "Привет от дочернего процесса!";
//    SIZE_T bytesWritten;
//
//    if (WriteProcessMemory(parentProcess, memAddress, message, strlen(message) + 1, &bytesWritten)) {
//        std::cout << "Сообщение записано в виртуальную память." << std::endl;
//    }
//    else {
//        std::cerr << "Ошибка записи в память." << std::endl;
//    }
//
//    CloseHandle(parentProcess);
//
//    return 0;
//}
