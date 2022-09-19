#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

struct Point {
    int x, y;
};

struct Line {
    Point start;
    Point end;
};

bool operator<(const Point &l, const Point &r) {
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

void ReadFile(std::vector<Line> &vents) {
    std::ifstream infile("input.txt");
    std::string line;
    while (std::getline(infile, line)) {
        Line vent;
        sscanf(line.c_str(), "%d,%d -> %d,%d", &vent.start.x, &vent.start.y, &vent.end.x, &vent.end.y);
        vents.push_back(vent);
    }
    return;
}

unsigned long long Part1(std::vector<Line> &vents) {
    // "For now, only consider horizontal and vertical lines: lines where either x1 = x2 or y1 = y2."
    std::map<Point, int> points;
    unsigned long long overlaps(0);

    for (auto const &vent : vents) {
        Point p1(vent.start), p2(vent.end);
        if (p1.x == p2.x) {
            // vertical line
            if (p1.y > p2.y) {
                std::swap(p1, p2);
            }
            do {
                if (++points[p1] == 2) {
                    ++overlaps;
                }
            } while (++p1.y <= p2.y);
        } else if (p1.y == p2.y) {
            // horizontal line
            if (p1.x > p2.x) {
                std::swap(p1, p2);
            }
            do {
                if (++points[p1] == 2) {
                    ++overlaps;
                }
            } while (++p1.x <= p2.x);
        } else {
            continue;
        }
    }

    return overlaps;
}

unsigned long long Part2(std::vector<Line> &vents) {
    // "For now, only consider horizontal and vertical lines: lines where either x1 = x2 or y1 = y2."
    std::map<Point, int> points;
    unsigned long long overlaps(0);

    for (auto const &vent : vents) {
        Point p1(vent.start), p2(vent.end);

        // assuming all lines are either horizontal, vertical or 45° diagonal:
        int dx = p1.x < p2.x ? 1 : p1.x > p2.x ? -1
                                               : 0;
        int dy = p1.y < p2.y ? 1 : p1.y > p2.y ? -1
                                               : 0;
        for (;; p1.x += dx, p1.y += dy) {
            if (++points[p1] == 2) {
                ++overlaps;
            }
            if (!(p1.x != p2.x || p1.y != p2.y)) {
                break;
            }
        }
    }
    return overlaps;
}

int main() {
    std::vector<Line> vents;
    ReadFile(vents);

    std::printf("%llu\n", Part1(vents));
    std::printf("%llu\n", Part2(vents));
    return EXIT_SUCCESS;
}
