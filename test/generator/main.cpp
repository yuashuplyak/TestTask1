//#include "stdafx.h"
#include <fstream>

int main(int argc, char* argv[])
{
    std::ofstream fout("cppstudio.txt"); // создаём объект класса ofstream для записи и связываем его с файлом cppstudio.txt
    for (std::size_t i{} ; i<10; ++i)
        fout << "{\"timestamp\":\"1583020800577000000\",\"direction\":\"-1\",\"speed\":\"23.28\",\"time\":0.0123}\n"; // запись строки в файл
    fout.close(); // закрываем файл
    std::system("pause");
    return 0;
}
