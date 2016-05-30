#pragma once
#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

const int N = 8;
enum { wall, ground, white, black };
int board[N + 2][N + 2];    //�Ֆ�

//�u�����ꏊ�̎���ɑ���̐΂����邩���ׂ邽�߂�2�̊֐�
int yoko[] = { -1, 0, 1, 1, 0, 0, -1, -1 };
int tate[] = { 0, 1, 0, 0, -1, -1, 0, 0 };

//5������6����
int teban = 5;

//�����p�X��2��A���ő�������I��
int pass_count = 0;

//�Ֆʏ������֐�
void init_board();

//�Ֆʕ`��֐�
void show();

//�ł����͂���֐�
int input(int x, int y, int teban);

//���Ԃ��邩����
bool hantei(int x, int y, int you, int I, bool pass_flag);

//����̐΂�����ł��邩�ǂ���
bool kaesu(int x, int x2, int y, int y2, int you, int I, bool pass_flag);

//�łƂ��낪���邩���ׂ�B�Ȃ�������p�X�B
bool pass(int teban);

//�Ō�܂őł��I������獕�Ɣ��̐΂̐�������
int kanzyo(int& w_kauz, int& b_kazu);

//////////////��������AI�̏���/////////////////////////////

//�Ֆʂ̍��W�̕]���l
int hyoka_board[N + 2][N + 2] = {
	{0,   0,   0, 0, 0, 0, 0,   0,   0, 0},
	{0, 150,  -5, 5, 5, 5, 5,  -5, 150, 0},
	{0,  -5, -15, 3, 3, 3, 3, -15,  -5, 0},
	{0,   5,   3, 3, 3, 3, 3,   3,   5, 0},
	{0,   5,   3, 3, 3, 3, 3,   3,   5, 0},
	{0,   5,   3, 3, 3, 3, 3,   3,   5, 0},
	{0,   5,   3, 3, 3, 3, 3,   3,   5, 0},
	{0,  -5, -15, 3, 3, 3, 3, -15,  -5, 0},
	{0, 150,  -5, 5, 5, 5, 5,  -5, 150, 0},
	{0,   0,   0, 0, 0, 0, 0,   0,   0, 0},
};

/*�Ֆʂ����ɖ߂��Ƃ��Ɏg���\����
���Ԃ����ꏊ�Ƒł����ꏊ�A�������Ԃ��������L��*/

const int YOMI = 7;  //�ǂ݂̐[���B�����܂œǂނ��B

struct Modo {
	int m_x[50];
	int m_y[50];
	int x;
	int y;
	int count;
};
Modo modo[YOMI];

//���̎�̕]���l�ƍ��W���L������\����
struct Hyoka {
	int hyo;
	int x;
	int y;
};

//AI�̎v�l�֐�
void AI(int& x, int& y, int teban);

//��ǂ݊֐�
int tansaku(int you, int I, int lim, int& x, int& y);

//�Ֆʂ�O�ɖ߂�����
void modosu(int you, int I, int lim);                                   //�ЂƂO�̔Ֆʂɖ߂��B
bool AI_hantei(int x, int y, int you, int I, int lim);                  //�łĂ邩�ǂ������肷��֐��B��{�I�ɂ͌��̊֐��Ɠ���
bool AI_kaesu(int x, int x2, int y, int y2, int you, int I, int lim);   //��{�I�ɂ͌��̗��Ԃ��֐��Ɠ���
int hyoka(); //�Ֆʂ�]������֐�