/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	const int n = 3;
	std::vector<int> data;
	// [0, 1, 2, ....]�Ƃ����T�C�Yn�̔z����쐬
	for (int i = 1; i <= n; ++i) {
		data.push_back(i);
	}

	// �S�Ă̏�����o��
	do {
		std::cout << "[ " << data[0];
		for (unsigned int i = 1; i < data.size(); ++i) {
			std::cout << ", " << data[i];
		}
		std::cout << " ]" << std::endl;
	} while (next_permutation(data.begin(), data.end()));

	return 0;
}
*/