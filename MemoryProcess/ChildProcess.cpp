//#include <iostream>
//#include <windows.h>
//
//int main(int argc, char* argv[]) {
//    if (argc < 2) {
//        std::cerr << "�� ������ ����� ������." << std::endl;
//        return 1;
//    }
//
//    // ������ ������ ������ �� ��������� ������
//    LPVOID memAddress = (LPVOID)strtoull(argv[1], nullptr, 16);
//    HANDLE parentProcess = OpenProcess(PROCESS_VM_WRITE | PROCESS_VM_OPERATION, FALSE, GetCurrentProcessId());
//
//    if (!parentProcess) {
//        std::cerr << "������ �������� ������������� ��������." << std::endl;
//        return 1;
//    }
//
//    // ��������� ��� ������ � ����������� ������ ������������� ��������
//    const char* message = "������ �� ��������� ��������!";
//    SIZE_T bytesWritten;
//
//    if (WriteProcessMemory(parentProcess, memAddress, message, strlen(message) + 1, &bytesWritten)) {
//        std::cout << "��������� �������� � ����������� ������." << std::endl;
//    }
//    else {
//        std::cerr << "������ ������ � ������." << std::endl;
//    }
//
//    CloseHandle(parentProcess);
//
//    return 0;
//}
