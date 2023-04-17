#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
vector<vector<int>> visited;//���� ���ٹ��⿡ ���� �湮����//�̷��� �� ���(�迭�� �� ���)�� �̷��� ũ��(size_m) * ��(x) + ��(y)���� �����ϰ� �ĺ� �����ϹǷ� ������ ���� ������ �迭�� ��Ÿ�� �� �ִ�. visited[�̷��� Ư�� ��ġ][�� ��ġ�� ���� ���� ����]
vector<vector<int>> map;//�̷� ����
int des[2];//�ⱸ ��ǥ
int size_m;//�̷� ũ��
int cnt_case;//�׽�Ʈ ���̽� ��
//��(������ǥ���� ����) 0->��, 1->��, 2->��, 3->�� | ��(���������� �̵�) 0->����, 1->��ȸ��, 2->U�� | dx�� ��, dy�� ��
int dx[][3] = { {0,1,0}, {1,0,-1}, {0,-1,0}, {-1,0,1} };//��� ���� �̿��� ������ǥ���� �ٶ󺸴� ���⿡ ���� ����, ��ȸ��, U���� �̵��� ����
int dy[][3] = { {1,0,-1}, {0,-1,0}, {-1,0,1}, {0,1,0} };//(�߰��� ���� �� �ٶ󺸴� ������ ���� ��ġ���� �̵��� ����� �����Ƿ� ���� ó�� ���ص� ��)
bool isInside(int x, int y) {//�̵��� ��ġ�� �̷θ� ����� ���� Ȯ���ϴ� �Լ�
	return x < size_m&& y < size_m&& x >= 0 && y >= 0;
}
bool CanEscape(int x, int y, int dir) {//���ΰ� x�� ���ΰ� y�� dir�� ���� ���� �ִ� ����(������ǥ����)
	if (x == des[0] && y == des[1])//���� ��ġ�� �ⱸ���� üũ
		return true;
	if (map[x][y] == 1)//���� ��ġ�� ������ üũ
		return false;
	if (visited[size_m * x + y][dir] == 2)//���� ���� ������ ������ �������� �湮�ߴ��� üũ(������ U�� �� �ٽ� U���� ����)
		return false;
	map[x][y] = 2;//�̵��� ��� ǥ�� ���� ǥ��(������ ���� �Ա��� �ⱸ�� 0���� ǥ���)
	for (int i = 0; i < 3; i++) {//������� ���� 0->����, 1->��ȸ��, 2->U��
		int x_new = x + dx[dir][i];//������ǥ, ������ ������� ����,��ȸ��,U�Ͽ� ���� �̵��ϰ� �� ���� ��� 
		int y_new = y + dy[dir][i];//������ǥ, ������ ������� ����,��ȸ��,U�Ͽ� ���� �̵��ϰ� �� ���� ��� 
		int dir_new = (dir + i) % 4;//���� ������ ������� ����,��ȸ��,U�Ͽ� ���� �ٶ� ������ ���
		if (!isInside(x_new, y_new))//�̵��� ��ġ�� �̷θ� ������� üũ ����ٸ� ��Ƽ��
			continue;
		visited[size_m * x_new + y_new][dir_new]++;//�̵��� ���� ���ٹ����� ī��Ʈ 1�ø� -> �ѹ� �̿��ߴٴ� �ǹ�
		if (CanEscape(x_new, y_new, dir_new))//�̵��� ������ dir_new ������ ���� Ż���� �� ������ true�� ��ȯ  
			return true;
		visited[size_m * x_new + y_new][dir_new]--;//������ ���ǹ��� ������� ������ �ٸ� ���� ã�ƾ� �ϹǷ� �����ߴ� ��ο� ���� �̵��ߴ� ������ ������(���� ���Ἲ ����)
	}
	return false;//�� �������� ������ ���� ������ false����
}
int main() {
	ifstream file("input.txt"); //input.txt ������ ����. 
	if (file.is_open()) {//������ ����
		string line; int val;
		getline(file, line);
		cnt_case = stoi(line);
		for (int i = 0; i < cnt_case; i++) {
			getline(file, line);
			size_m = stoi(line);
			for (int j = 0; j < size_m; j++) {
				getline(file, line);
				istringstream ss(line);
				vector<int> tmp;
				while (ss >> val) {
					tmp.push_back(val);
					visited.push_back({ 0,0,0,0 });
				}
				map.push_back(tmp);
			}
			getline(file, line);
			istringstream ss(line);
			ss >> val; des[0] = val;
			ss >> val; des[1] = val;
			cout << "�̷� ����" << endl;
			for (int j = 0; j < size_m; j++) {//�Է¹��� �̷��� ������ ���
				for (int k = 0; k < size_m; k++)
					cout << map[j][k] << " ";
				cout << endl;
			}
			cout << "�ⱸ:" << des[0] << " " << des[1] << endl;//��ǥ��ġ�� ���
			if (CanEscape(0, 0, 0)) {//���� ������ �������� ���� �� ������ ��� �̵��� �� �����Ƿ� | Ż���� �� �ִٸ� Ż�� ��θ� ����ϰ� ����
				cout << "Yes" << endl << "�̵� ����" << endl;
				for (int x = 0; x < size_m; x++) {
					for (int y = 0; y < size_m; y++) {
						if (map[x][y] == 2 && visited[size_m * x + y][0] == 0 && visited[size_m * x + y][1] == 0 && visited[size_m * x + y][2] == 0 && visited[size_m * x + y][3] == 0)
							cout << "0 ";
						else
							cout << map[x][y] << " ";
					}
					cout << endl;
				}
				cout << endl << endl;
			}
			else {
				cout << "No" << endl << endl;
			}
			visited.clear();
			map.clear();
		}
		file.close();//���Ͽ��� �ʿ��� ������ ��� ���������Ƿ� ������ �ݾ��ش�.
	}
	else {//���Ͽ��⿡ ����������
		cout << "���ϰ�ΰ� �ùٸ��� Ȯ�����ּ���.";
		return 1;
	}

	return 0;
}


