#include <bits/stdc++.h>
using namespace std;
size_t numEntries;
struct Point {
  Point() : x(0), y(0) {}
  long long x{0};
  long long y{0};
  Point operator-(const Point &pointR) const {
    return Point{this->x - pointR.x, this->y - pointR.y};
  }
  Point operator+(const Point &pointR) const {
    return Point{this->x + pointR.x, this->y + pointR.y};
  }
  Point operator*(const Point &pointR) const {
    return Point{this->x - pointR.x, this->y - pointR.y};
  }
  bool operator==(const Point &pointR) const {
    return (this->x == pointR.x && this->y == pointR.y);
  }
  bool operator<(const Point &pointR) const {
    if (this->x < pointR.x) return true;
    return false;
  }
  Point(long long x, long long y) : x(x), y(y) {}
  Point(const Point &rhs) : x(rhs.x), y(rhs.y) {}
  int distance(const Point &rhs) const {
    auto temp = (*this) - rhs;
    return temp.x * temp.x + temp.y * temp.y;
  }
};
long long crossProduct(const Point &pointA, const Point &pointB) {
  return pointA.x * pointB.y - pointA.y * pointB.x;
}
float findXIntercept(const Point &A, const Point &B) {
  if (A.x - B.x == 0) return A.x;
  float m = (float)(A.y - B.y) / (A.x - B.x);
  if (m == 0) {
    return -1;
  }
  float b = A.y - m * A.x;
  float xIntercept = (-b) / m;
  return xIntercept;
}
int main(void) {
  std::ios::sync_with_stdio(false);
  cin >> numEntries;
  float upperBound{0};
  float lowerBound{0.0};
  int adjustX{0};
  int adjustY{0};
  int flipH{1};
  int flipV{1};
  vector<Point> points(numEntries);
  for (int i = 0; i < numEntries; ++i) {
    cin >> points[i].x;
    cin >> points[i].y;
    if (i == 0) {
      adjustX = points[i].x;
      adjustY = points[i].y;
    }
    points[i].x -= adjustX;
    points[i].y -= adjustY;
    if (i == 1) {
      if (points[i].x < 0) {
        flipV = -1;
      }
      upperBound = points[i].x * flipV;
    }
    points[i].x *= flipV;
    if (i == 2) {
      if (points[i].y < 0) {
        flipH = -1;
      }
    }
    points[i].y *= flipH;
  }
  for (int i = 1; i < numEntries; ++i) {
    int A = i - 1;
    int B = i;
    int C = (i + 1) % numEntries;
    if (crossProduct(points[C] - points[B], points[A] - points[B]) < 0) {
      auto updateB = crossProduct(points[C] - points[B], points[1] - points[B]);
      auto updateA = crossProduct(points[C] - points[B], points[0] - points[B]);
      bool skipComp{false};
      if (updateB < 0 && updateA < 0) {
        printf("0\n");
        return 0;
      } else if (updateB > 0 && updateA > 0) {
        skipComp = true;
      }
      if (!skipComp) {
        auto xIntercept = findXIntercept(points[C], points[B]);
        if (xIntercept == -1) {
          printf("0\n");
          return 0;
        }
        if (updateB < 0) {
          upperBound = min(upperBound, xIntercept);
        }
        if (updateA < 0) {
          lowerBound = max(lowerBound, xIntercept);
        }
      }
      updateB = crossProduct(points[B] - points[1], points[B] - points[A]);
      updateA = crossProduct(points[B] - points[0], points[B] - points[A]);
      if (updateB < 0 && updateA < 0) {
        printf("0\n");
        return 0;
      } else if (updateB > 0 && updateA > 0) {
        continue;
      }
      auto xIntercept = findXIntercept(points[B], points[A]);
      if (xIntercept == -1) {
        printf("0\n");
        return 0;
      }
      if (updateB < 0) {
        upperBound = min(upperBound, xIntercept);
      }
      if (updateA < 0) {
        lowerBound = max(lowerBound, xIntercept);
      }
    }
  }
  int lower = ceil(lowerBound);
  int upper = floor(upperBound);
  int answer = (upper - lower) + 1;
  if (answer > 0)
    printf("%i\n", answer);
  else
    printf("0\n");
  return 0;
}
