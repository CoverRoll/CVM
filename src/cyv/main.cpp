#include "../cvm/cvm.hpp"
using namespace canyon;

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

#define cases(c, label, jmp_label) case c: label: mem_reallen *= 1024; goto jmp_label; break;

#if defined(_WIN32) && !defined(_WIN64)
#pragma message "The Project is compiling on the Win32 platform"
#elif defined(__ANDROID__)
#pragma message "The Project is compiling on the Android platform"
#error Error: This Project can not run on the Android platform!
#elif defined(__APPLE__)
#pragma message "The Project is compiling on the Apple platform"
#error Error: This Project can not run on the Apple platform!
#elif defined(_linux)
#pragma message "The Project is compiling on the Linux platform"
#elif defined(_unix) || defined(_unix_)
#pragma message "The Project is compiling on the Unix platform"
#elif !(defined(_WIN64))
#error Unknown platform
#endif

int main(int args, char * argv[]){
    if(args > 1){
        cout << "�������ڴ��С:";
        uint64_t mem_reallen;
        cin >> mem_reallen;
        char mode;
        cout << "�ڴ������λ(֧��K, M, G, T, P, E, ����D�������Ǵ˷�Χ����ĸ��ʹ���ֽڼ���):";
        cin >> mode;
        mode = toupper(mode);
        cout << mode << endl;
        switch (mode){
            cases('E', case_eb, case_pb) cases('P', case_pb, case_tb) cases('T', case_tb, case_gb) cases('G', case_gb, case_mb) cases('M', case_mb, case_kb)
            case 'K':
                case_kb:
                mem_reallen *= 1024;
                break;
            default:
                break;
        }
        cout << mem_reallen << endl;
        char * mem = (char *)calloc(mem_reallen, sizeof(char));
        uint64_t memlen = 0;
        for(int i = 1; i<args; i++){
            ifstream f;
            command tmp = {};
            cout << argv[i] << endl;
            f.open(argv[i], ios::in | ios::binary);
            if(f.is_open() == false){
                cout << "����: ���ļ�: \"" << argv[i] << "\" ʱʧ��!" << endl;
                continue;
            }
            while (f.read((char *)&tmp, sizeof(command))){
                //mem = (char *)realloc(mem, memlen + sizeof(command));
                for (uint64_t j = 0; j<sizeof(command); j++){
                    mem[memlen + j] = ((char *)&tmp)[j];
                }
                memlen += sizeof(command);
            }
        }
        VM mainvm(mem, mem_reallen);
        mainvm.run(0);
        free(mem);
    }
    else{
        cout << "����: û�в���" << endl;
    }
    return(0);
}

#undef cases
