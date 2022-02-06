#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    //ファイル名からバイナリファイルで読み込む
    std::ifstream ifs(argv[0], std::ios::binary);

    //読込サイズを調べる。
    ifs.seekg(0, std::ios::end);
    long long int size = ifs.tellg();
    ifs.seekg(0);

    //読み込んだデータをchar型に出力する
    char* data = new char[size];
    ifs.read(data, size);

    //サイズを出力する
    std::cout << "size = " << size << "\n";
    for (int i = 1; i < size + 1; i++)
    {
        //出力する
        std::cout << data[i - 1] << " ";
        //16バイト毎に改行する
        if ((i % 16) == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << "\nEnd!\n";
    delete data;

    return 0;
}