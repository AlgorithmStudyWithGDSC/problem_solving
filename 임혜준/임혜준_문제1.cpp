#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int limit;//���� ����
vector<int> weight;//������ ���Ը� ��� �迭
vector<int> value;//������ ��ġ�� ��� �迭
int N;//�������� ����
int val_max;//�ְ� ��ġ, ���������� �⺻�� 0���� ���õ�
void knapsack(int val, int sum, int level) {//�ε��� level�� ���ǿ� ���� ���ÿ���
	if (sum > limit)//���԰� ������ �ʰ����� ��
		return;
	if (val_max < val)//���� ��ġ�� �̶������� �ְ� ��ġ���� Ŭ �� �ְ� ��ġ�� ���� ��ġ�� ����
		val_max = val;
	if (level == N)//��� ���ǿ� ���� ���� ���ΰ� �������� ��
		return;
	knapsack(val, sum, level + 1);//���� ������ �賶�� ���� ���� ��
	knapsack(val + value[level], sum + weight[level], level + 1);//���� ������ �賶�� ���� ��
}
int main() {
	ifstream file("input.txt"); //input.txt ������ ����. 
	if (file.is_open()) {//������ ����
		string line; int tmp;
		getline(file, line);
		N = stoi(line);
		getline(file, line);
		limit = stoi(line);
		getline(file, line);
		istringstream ss(line);
		while (ss >> tmp) {
			weight.push_back(tmp);
		}
		getline(file, line);
		istringstream ss1(line);
		while (ss1 >> tmp) {
			value.push_back(tmp);
		}
		file.close();//���Ͽ��� �ʿ��� ������ ��� ���������Ƿ� ������ �ݾ��ش�.
	}
	else {//���Ͽ��⿡ ����������
		cout << "���ϰ�ΰ� �ùٸ��� Ȯ�����ּ���.";
		return 1;
	}

	cout << N << endl;
	cout << limit << endl;
	for (int i : weight)
		cout << i << " ";
	cout << endl;
	for (int j : value) 
		cout << j << " ";
	cout << endl;
	knapsack(0, 0, 0);
	cout << "������ �ִ� �� : " << val_max;


	return 0;
}


