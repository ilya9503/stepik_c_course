#include <stdio.h>

int main (void)
{
    /*
        ��⮢�� ������ �� 
        unsigned char = 1 ���� = 0..255 � �����筮� �ଥ
        153 + 102 = 255 = 11111111
    */
    unsigned char var = 153;        // ����筠� ������ 10011001 = 153
    unsigned char not_var = ~ var;  // ����筠� ������ 01100110 = 102

    printf("var = %d, not_var = %d\n", var, not_var);

    unsigned char flags = 5;        // ����筠� ������ 00000101 = 5
    unsigned char mask = 4;         // ����筠� ������ 00000100 = 4
    unsigned char res = flags & mask;
    printf("res = %d\n", res);
    //------------------------------------------------------------------------------------------
    // ��⮢�� ������ � & ��⮢�� 㬭������ � �� �ਬ������
    // �ᯮ������ ��� �஢�ન, ����祭 �� ���, ��������� �����
    if ((flags & mask) == mask)
        printf("bit 2 is on\n");
    else
        printf("bit 2 is off\n");

    // � ������� ��⮢�� ��᪨ mask � ����樨 &~ ����� �⪫���� �⤥��� ����
    // � ��᪥ �⠢�� 1 � ⮬ ����, ����� ��� �⨬ �몫����
    flags = flags & ~ mask;
    printf("flags = %d", flags);
    //--------------------------------------------------------------------------------------
    // ��⮢�� ������ ��� | ��⮢�� ᫮�����
    // �ᯮ������ ��� ����祭�� �⤥���� ���. ��������� �⤥���� ���
    flags = flags | mask;   // flags |= mask
    printf("flags = %d", flags);

    // ������ ��४��祭�� XOR. �ᯮ������ ��� ��஢���� ������
    // ��� ࠡ�⠥� ����� zip
    flags = flags ^ mask;   // ����砥� ���
    flags ^= mask;          // ����஢뢠��
    
    return 0;

}