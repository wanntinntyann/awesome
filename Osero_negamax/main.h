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
int board[N + 2][N + 2];    //盤面

//置いた場所の周りに相手の石があるか調べるための2つの関数
int yoko[] = { -1, 0, 1, 1, 0, 0, -1, -1 };
int tate[] = { 0, 1, 0, 0, -1, -1, 0, 0 };

//5が黒で6が白
int teban = 5;

//もしパスが2回連続で続いたら終局
int pass_count = 0;

//盤面初期化関数
void init_board();

//盤面描画関数
void show();

//打つ手を入力する関数
int input(int x, int y, int teban);

//裏返せるか判定
bool hantei(int x, int y, int you, int I, bool pass_flag);

//相手の石を挟んでいるかどうか
bool kaesu(int x, int x2, int y, int y2, int you, int I, bool pass_flag);

//打つところがあるか調べる。なかったらパス。
bool pass(int teban);

//最後まで打ち終わったら黒と白の石の数を勘定
int kanzyo(int& w_kauz, int& b_kazu);

//////////////ここからAIの処理/////////////////////////////

//盤面の座標の評価値
int hyoka_board[N + 2][N + 2] = {
	{0,   0,   0, 0, 0, 0, 0,   0,   0, 0},
	{0, 180,  -2, 6, 6, 6, 6,  -2, 180, 0},
	{0,  -2, -20, 3, 3, 3, 3, -20,  -2, 0},
	{0,   6,   3, 3, 3, 3, 3,   3,   6, 0},
	{0,   6,   3, 3, 3, 3, 3,   3,   6, 0},
	{0,   6,   3, 3, 3, 3, 3,   3,   6, 0},
	{0,   6,   3, 3, 3, 3, 3,   3,   6, 0},
	{0,  -2, -20, 3, 3, 3, 3, -20,  -2, 0},
	{0, 180,  -2, 6, 6, 6, 6,  -2, 180, 0},
	{0,   0,   0, 0, 0, 0, 0,   0,   0, 0},
};

/*盤面を元に戻すときに使う構造体
裏返した場所と打った場所、何枚裏返したかを記憶*/

const int YOMI = 6;  //読みの深さ。何手先まで読むか。

//どこを何枚裏返したかと自分がどこに打ったかの情報
struct Modo {
	int m_x[50];
	int m_y[50];
	int x;
	int y;
	int count;
};
Modo modo[YOMI];

//AIの思考関数
void AI(int& x, int& y, int teban);

//アルファベータ法を使用する時の基準値を保存する配列
int kizyun[YOMI];
//先読み関数
int tansaku(int you, int I, int lim, int& x, int& y);

//盤面を前に戻す処理
void modosu(int you, int I, int lim);                                   //ひとつ前の盤面に戻す。
bool AI_hantei(int x, int y, int you, int I, int lim);                  //打てるかどうか判定する関数。基本的には元の関数と同じ
bool AI_kaesu(int x, int x2, int y, int y2, int you, int I, int lim);   //基本的には元の裏返す関数と同じ
int hyoka(); //盤面を評価する関数