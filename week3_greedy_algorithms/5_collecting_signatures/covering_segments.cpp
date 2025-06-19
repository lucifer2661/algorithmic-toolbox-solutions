#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

struct Segment {
    int start, end;
};

// Returns minimum set of points such that every segment contains at least one point.
vector<int> optimal_points(vector<Segment> &segments) {
    // 1. Sort segments by their end coordinate (smallest to largest)
    std::sort(segments.begin(), segments.end(),
              [](const Segment &a, const Segment &b) {
                  return a.end < b.end;
              });

    vector<int> points;
    int last_point = -1e9;  // A value smaller than any valid segment start

    // 2. Greedy selection – choose 'end' when needed
    for (auto &seg : segments) {
        if (seg.start > last_point) {
            last_point = seg.end;
            points.push_back(last_point);
        }
    }

    return points;
}

int main() {
    int n;
    std::cin >> n;
    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> segments[i].start >> segments[i].end;
    }

    vector<int> points = optimal_points(segments);
    std::cout << points.size() << "\n";
    for (int p : points)
        std::cout << p << " ";
    std::cout << "\n";

    return 0;
}
