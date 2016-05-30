#include "main.h"

void init_board()
{
	for (int i = 0; i < N + 2; i++) {
		board[0][i] = wall;
	}

	for (int i = 0; i < N + 2; i++) {
		board[i][0] = wall;
	}

	for (int i = 0; i < N + 2; i++) {
		board[N + 1][i] = wall;
	}

	for (int i = 0; i < N + 2; i++) {
		board[i][N + 1] = wall;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			board[i][j] = ground;
		}
	}

	board[N / 2][N / 2] = black;
	board[N / 2 + 1][N / 2 + 1] = black;
	board[N / 2 + 1][N / 2] = white;
	board[N / 2][N / 2 + 1] = white;
}

void copy_board(int a[][N + 2], int b[][N + 2])
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void show()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			switch (board[i][j]) {
			case black:
				cout << "●";
				break;
			case white:
				cout << "○";
				break;
			case ground:
				cout << "□";
				break;
			}
		}
		cout << endl;
	}
}

int input(int x, int y, int teban)
{
	if (board[y][x] != ground) {
		return teban;
	}

	//相手の石を確認する
	int you;
	int I;
	if (teban == 5) {
		you = white;
		I = black;
	}
	else {
		you = black;
		I = white;
	}

	if (!hantei(x, y, you, I, false)) {
		//cout << "a" << endl;
		return teban;
	}
	else {
		if (teban == 5) {
			return teban + 1;
		}
		else {
			return teban - 1;
		}
	}
}

bool hantei(int x, int y, int you, int I, bool pass_flag)
{
	if (board[y][x] != ground) {
		return false;
	}

	bool flag = false;
	int x2 = 0;
	int y2 = 0;
	for (int i = 0; i < 8; i++) {
		x2 += yoko[i];
		y2 += tate[i];
		if (board[y + y2][x + x2] == you) {
			if (kaesu(x, x2, y, y2, you, I, pass_flag) == true) {
				flag = true;
			}
		}
	}

	return flag;
}

bool kaesu(int x, int x2, int y, int y2, int you, int I, bool pass_flag)
{
	int	ha_x = x + x2;
	int ha_y = y + y2;

	while (board[ha_y][ha_x] == you) {
		ha_x += x2;
		ha_y += y2;
	}

	if (board[ha_y][ha_x] == I) {
		if (pass_flag == true) return true;
		ha_x -= x2;
		ha_y -= y2;
		while (board[ha_y][ha_x] == you) {
			board[ha_y][ha_x] = I;
			ha_x -= x2;
			ha_y -= y2;
		}
		board[y][x] = I;

		return true;
	}

	return false;
}

//打てるところがあるか調べるなかったら自動でパス
bool pass(int teban)
{
	int I, you;
	if (teban == 5) {
		I = black;
		you = white;
	}
	else {
		I = white;
		you = black;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (hantei(j, i, you, I, true)) {
				//打てる場所がある
				return false;
			}
		}
	}

	//パスする
	return true;
}

int kanzyo(int& w_kazu, int& b_kazu)
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (board[i][j] == white) {
				w_kazu++;
			}
			else if (board[i][j] == black) {
				b_kazu++;
			}
		}
	}

	if (b_kazu > w_kazu) {
		return 5;
	}
	else if (w_kazu > b_kazu) {
		return 6;
	}

	//7なら引き分け
	return 7;
}

void AI(int &x, int &y, int teban)
{
	//相手の石を確認する
	int you;
	int I;
	if (teban == 5) {
		you = white;
		I = black;
	}
	else {
		you = black;
		I = white;
	}

	//関数内で黒白を入れ替える処理があるから最初は引数を逆にする
	int num = tansaku(I, you, 0, x, y);
}

int tansaku(int you, int I, int lim, int& x, int& y)
{
	int value = 0;
	int child = 0;
	if (lim >= YOMI) {
		return hyoka();
	}
	else {
		int te = I;
		I = you;
		you = te;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (AI_hantei(j, i, you, I, lim)) {
					modo[lim].x = j;
					modo[lim].y = i;

					//子ノードの値を取得
					child = tansaku(you, I, lim + 1, x, y);
					//show();
					//自分の時は相手が自分に最も不利な手を打ってきた時の値をとる
					if (I == white) {
						//わざと小さすぎる値をにセットして節の比較を行えるようにする。
						value = -100;
						if (child > value) {
							value = child;
							x = j;
							y = i;
							//cout << x << y << endl;
						}
					}
					//相手の時は相手が自分に最も有利な手を打ってきた時の値をとる
					else if (I == black) {
						//わざと大きすぎる値をセットして節の比較を行えるようにする。
						value = 100;
						if (child < value) {
							value = child;
						}
					}

					//一個前の局面に戻す
					modosu(you, I, lim);
					//次の場所に打つので0に戻す
					modo[lim].count = 0;
				}
			}
		}
	}
	return value;
}

int hyoka()
{
	int siro = 0, kuro = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			switch (board[i][j]) {
			case white:
				siro++;
				break;
			case black:
				kuro++;
				break;
			}
		}
	}
	return siro - kuro;
}

void modosu(int you, int I, int lim)
{
	for (int i = 0; i < modo[lim].count; i++) {
		board[modo[lim].m_y[i]][modo[lim].m_x[i]] = you;
	}

	board[modo[lim].y][modo[lim].x] = ground;
}

bool AI_hantei(int x, int y, int you, int I, int lim)
{
	if (board[y][x] != ground) {
		return false;
	}

	bool flag = false;
	int x2 = 0;
	int y2 = 0;
	for (int i = 0; i < 8; i++) {
		x2 += yoko[i];
		y2 += tate[i];
		if (board[y + y2][x + x2] == you) {
			if (AI_kaesu(x, x2, y, y2, you, I, lim) == true) {
				flag = true;
			}
		}
	}

	return flag;
}

bool AI_kaesu(int x, int x2, int y, int y2, int you, int I, int lim)
{
	int	ha_x = x + x2;
	int ha_y = y + y2;

	while (board[ha_y][ha_x] == you) {
		ha_x += x2;
		ha_y += y2;
	}

	if (board[ha_y][ha_x] == I) {
		ha_x -= x2;
		ha_y -= y2;
		while (board[ha_y][ha_x] == you) {
			//裏返した座標と枚数を記憶している。
			modo[lim].m_x[modo[lim].count] = ha_x;  
			modo[lim].m_y[modo[lim].count] = ha_y;
			modo[lim].count++;
			board[ha_y][ha_x] = I;
			ha_x -= x2;
			ha_y -= y2;
		}
		board[y][x] = I;
		return true;
	}

	return false;
}

int main()
{
	int x = 0, y = 0;
	init_board();  //盤面の初期化
	show();        //表示

	while (1) {
		switch (teban) {
		case 5:  //黒番
			if (pass(teban)) {
				cout << "打てる場所がないのでパスします。" << endl;
				pass_count++;
				teban = 6;
				break;
			}
			pass_count = 0;
			cout << "黒番です > " << endl;

			do {
				cin >> x >> y;
			} while ((x < 1 || x > 8) || (y < 1 || y > 8));

			teban = input(x, y, teban);
			break;
		case 6:  //白番
			if (pass(teban)) {
				cout << "打てる場所がないのでパスします。" << endl;
				pass_count++;
				teban = 5;
				break;
			}
			pass_count = 0;
			cout << "白番です > " << endl;

			do {
				AI(x, y, teban);
				cout << x << "," << y << endl;
				cout << pass_count << endl;
			} while ((x < 1 || x > 8) || (y < 1 || y > 8));

			teban = input(x, y, teban);
			break;
		}

		//二回連続でパスしたら終局の処理
		if (pass_count >= 2) {
			int white_kazu = 0;
			int black_kazu = 0;
			int kekka = kanzyo(white_kazu, black_kazu);

			if (kekka == 5) {
				cout << "黒の" << black_kazu - white_kazu << "石差勝ちです。" << endl;
			}
			else if (kekka == 6) {
				cout << "白の" << white_kazu - black_kazu << "石差勝ちです。" << endl;
			}
			else {
				cout << "引き分けです。" << endl;
			}
			break;
		}
		show();
	}

	return 0;
}