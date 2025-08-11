#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int coordinate;
    bool is_start;
};

// Custom comparator for sorting points
bool comparePoints(const Point& a, const Point& b) {
    if (a.coordinate != b.coordinate) {
        return a.coordinate < b.coordinate;
    }
    // If coordinates are the same, starting points come first
    return a.is_start > b.is_start;
}

int klee_algorithm(const std::vector<std::pair<int, int>>& segments) {
    std::vector<Point> points;
    for (const auto& segment : segments) {
        points.push_back({segment.first, true});
        points.push_back({segment.second, false});
    }

    // Sort the points
    std::sort(points.begin(), points.end(), comparePoints);

    int total_length = 0;
    int counter = 0;

    for (size_t i = 0; i < points.size(); ++i) {
        if (i > 0 && counter > 0) {
            total_length += points[i].coordinate - points[i - 1].coordinate;
        }

        if (points[i].is_start) {
            counter++;
        } else {
            counter--;
        }
    }

    return total_length;
}

int main() {
    std::vector<std::pair<int, int>> segments1 = {{1, 6}, {4, 5}, {3, 8}, {7, 9}};
    std::cout << "Length of union for segments1: " << klee_algorithm(segments1) << std::endl;

    std::vector<std::pair<int, int>> segments2 = {{1, 3}, {2, 5}, {5, 6}};
    std::cout << "Length of union for segments2: " << klee_algorithm(segments2) << std::endl;

    return 0;
}
