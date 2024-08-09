#include <bits/stdc++.h>
using namespace std;
struct stu {
	char name[2000];
	double score;
};
int main() {
	stu s;
	strcpy(s.name, "Zhandad");
	s.score = 99.999;
	cout << s.name << ' ' << s.score << endl;
	stu *stu1 = &s;
	cout << stu1->name << ' ' << stu1->score << endl;
	stu *stu2 = new stu;
	strcpy(stu2->name, "jjjaa");
	stu2->score = 98.9;
	cout << stu2->name << ' ' << stu2->score << endl;
	delete stu2; 
	return 0;
}
