#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int result = 0;

    for (int i = 1; i < points.size(); ++i) {
        // get the horizontal distance
        int horizontalDistance = abs(points[i][0] - points[i - 1][0]);
        // get the vertical
        int verticalDistance = abs(points[i][1] - points[i - 1][1]);

        // get the max time it took to travel
        result += max(verticalDistance, horizontalDistance);
    }

    return result;
}
