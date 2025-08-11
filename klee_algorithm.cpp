#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
	int coords;
	bool is_start;
};
bool customSort(const Point& a, const Point&b){
	if(a.coords != b.coords){
		return a.coords < b.coords;
	}
	return a.is_start > b.is_start;
}
int klee_algorithm(const vector<pair<int, int>>& line){
	int result{}, Counter{};
	// for loop x.first and add it in with 1, x.second with 2
	// make a struct that makes life easier
	vector<Point> points;
	for(const auto& x : line){
		points.push_back({x.first, true});
		points.push_back({x.second, false});
	}
	sort(points.begin(), points.end(), customSort);
	/*
	for(const auto&x : points){
		cout << x.coords << ' ' << x.is_start << "\n";
	}*/
	for(unsigned int i{}; i < 2*points.size(); i++){
		if(Counter && i >0){
			result += (points[i].coords - points[i-1].coords);
		}
		(points[i].is_start)? Counter++ : Counter--;
	}

	return result;
}
vector<<pair<int, int>> take_input(){
	vector<pair<int, int>> line;
	cout << "Enter coordinates: (Example: 1 3)\n";
	int x,y; cin >> x >> y;
	line.push_back({x, y});
	return line;
}
int main(){
	// {{1, 6}, {4, 5}, {3, 8}, {7, 9}}
	// {{1, 3}, {2, 5}, {5, 6}}
	vector<pair<int, int>> line1 = take_input();
	cout << "Length of segment is: " << klee_algorithm(line1) << "\n";
}
