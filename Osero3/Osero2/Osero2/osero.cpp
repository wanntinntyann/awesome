/*�I�Z���v���O����������Ă݂܂����B�L�[���͂ł��܂��B�~�j�}�b�N�X�@�܂ł�
���������Ƃ���܂ł��A�b�v���[�h���܂����B�A���t�@�x�[�^�@�𒲂׎������悤��
���Ă��܂����A�܂������̕����͖������ł��B�Ȃ̂ŃA���t�@�x�[�^�@�̎����r����
�ςȌ�����ǂ݂̊֐��̂Ƃ���ɂ���܂��B�����܂łŏC�����ׂ�������������
�R�����g���ċ����Ă��������B*/


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

void show()
{
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			switch (board[i][j]) {
			case black:
				cout << "��";
				break;
			case white:
				cout << "��";
				break;
			case ground:
				cout << "��";
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

	//����̐΂��m�F����
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

//�łĂ�Ƃ��낪���邩���ׂ�Ȃ������玩���Ńp�X
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
				//�łĂ�ꏊ������
				return false;
			}
		}
	}

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

	//7�Ȃ��������
	return 7;
}

void AI(int &x, int &y, int teban)
{
	//����̐΂��m�F����
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

	//��ǂ݂��s��
	int kizyun = 2000;
	int num = tansaku(I, you, 0, x, y, kizyun);
}

//�����炭�ċA�ł��̊֐����Ăяo�����Ƃ���kizyun���p�����Ďg��Ȃ��ƃA���t�@�x�[�^�@�͂��܂������Ȃ��B
int tansaku(int you, int I, int lim, int& x, int& y, int &kizyun)
{
	bool kaesi_flag = false;  //�����Ֆʂɋ��߂�ꏊ������Ȃ������ꍇ�̃t���O
	modo[lim].count = 0;
	int value = 0;
	int child = 0;

	if (lim >= YOMI) {
		return hyoka();
	}
	else {
		int te = I;
		I = you;
		you = te;
		//�킴�Ƒ傫������l���Z�b�g���Č�̐߂̔�r���s����悤�ɂ���B	
		if ((I == white && teban == 6) || (I == black && teban == 5)) {
			value = -1000;
			kizyun = 2000;
		}
		else {
			value = 1000;
			kizyun = -2000;
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (AI_hantei(j, i, you, I, lim)) {
					
					kaesi_flag = true;
					modo[lim].x = j;
					modo[lim].y = i;

					//�q�m�[�h�̒l���擾
					child = tansaku(you, I, lim + 1, x, y, kizyun);
					
					/*�����̎��͍ő�l��I�ԁB���łɃA���t�@�x�[�^�@
					���g�p(����ɃA���t�@�x�[�^�@�������Ă��Ȃ���������Ȃ�)*/
					if ((I == black && teban == 5) || (I == white && teban == 6)) {
						
						if (lim < YOMI - 1 && ab_count == 1) {
							if (kizyun < child) {
								modosu(you, I, lim);
								return child;
							}
						}
						
						if(child > value) {
							value = child;
							if (lim == 0) {
								x = j;
								y = i;
							}
						}
					}
					else {
						
						if (lim < YOMI - 1 && ab_count == 1) {
							if (kizyun > child) {
								modosu(you, I, lim);
								return child;
							}
						}
						
						//����̎��͍ŏ��l��I��
						if (child < value) {				
							value = child;
						}
					}
					
					//��l��ݒ�
					kizyun = value;

					//��O�̋ǖʂɖ߂�
					modosu(you, I, lim);
					//���̏ꏊ�ɑł̂�0�ɖ߂�
					modo[lim].count = 0;
				}
			}
		}
	}
	
	/*��ǂݒ��ɑł����Ȃ�����(�p�X��)�ꍇ�����̌��ɑłĂ�l�ɂ���B
	�܂�ŏ��ɐݒ肵������菬��������Δ�r���鎖���ł���*/
	if ((lim > 0 && lim < YOMI - 1) && kaesi_flag == false) {
		if ((I == black && teban == 5) || (I == white && teban == 6)) {
			value = -999;
		}
		else {
			value = 999;
		}
	}

	ab_count = 1;

	return value;
}

int hyoka()
{
	int siro = 0, kuro = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			switch (board[i][j]) {
			case white:
				siro += hyoka_board[i][j];
				break;
			case black:
				kuro += hyoka_board[i][j];
				break;
			}
		}
	}

	if (teban == 6) {
		return siro - kuro;
	}
	else {
		return kuro - siro;
	}
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
			//���Ԃ������W�Ɩ������L������B
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
	init_board();  //�Ֆʂ̏�����
	show();        //�\��

	while (1) {
		switch (teban) {
		case 5:  //����
			if (pass(teban)) {
				cout << "�łĂ�ꏊ���Ȃ��̂Ńp�X���܂��B" << endl;
				pass_count++;
				teban = 6;
				break;
			}
			pass_count = 0;
			cout << "���Ԃł� > ";

			do {
				//AI(x, y, teban);
				cin >> x >> y;
				cout << x << "," << y << endl;
			} while ((x < 1 || x > 8) || (y < 1 || y > 8));

			teban = input(x, y, teban);
			break;
		case 6:  //����
			if (pass(teban)) {
				cout << "�łĂ�ꏊ���Ȃ��̂Ńp�X���܂��B" << endl;
				pass_count++;
				teban = 5;
				break;
			}
			pass_count = 0;

			cout << "���Ԃł� > ";

			clock_t start = clock();

			do {
				AI(x, y, teban);
				//cin >> x >> y;
				cout << x << "," << y << endl;
			} while ((x < 1 || x > 8) || (y < 1 || y > 8));

			teban = input(x, y, teban);
			clock_t end = clock();

			cout << end - start << endl;
			break;
		}

		//���A���Ńp�X������I�ǂ̏���
		if (pass_count >= 2) {
			int white_kazu = 0;
			int black_kazu = 0;
			int kekka = kanzyo(white_kazu, black_kazu);

			if (kekka == 5) {
				cout << "����" << black_kazu - white_kazu << "�΍������ł��B" << endl;
			}
			else if (kekka == 6) {
				cout << "����" << white_kazu - black_kazu << "�΍������ł��B" << endl;
			}
			else {
				cout << "���������ł��B" << endl;
			}
			break;
		}
		show();
	}

	return 0;
}