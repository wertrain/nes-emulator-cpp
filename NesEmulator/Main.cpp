#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
    //�t�@�C��������o�C�i���t�@�C���œǂݍ���
    std::ifstream ifs(argv[0], std::ios::binary);

    //�Ǎ��T�C�Y�𒲂ׂ�B
    ifs.seekg(0, std::ios::end);
    long long int size = ifs.tellg();
    ifs.seekg(0);

    //�ǂݍ��񂾃f�[�^��char�^�ɏo�͂���
    char* data = new char[size];
    ifs.read(data, size);

    //�T�C�Y���o�͂���
    std::cout << "size = " << size << "\n";
    for (int i = 1; i < size + 1; i++)
    {
        //�o�͂���
        std::cout << data[i - 1] << " ";
        //16�o�C�g���ɉ��s����
        if ((i % 16) == 0)
        {
            std::cout << "\n";
        }
    }
    std::cout << "\nEnd!\n";
    delete data;

    return 0;
}