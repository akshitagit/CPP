#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

struct Point {
    int x, y;
};

double calculateDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double tspDynamicProgramming(const vector<Point>& cities) {
    int numCities = cities.size();

    // dp[mask][i] represents the minimum distance to visit all cities in the set represented by the bitmask 'mask', ending at city 'i'
    vector<vector<double>> dp(1 << numCities, vector<double>(numCities, numeric_limits<double>::max()));

    // Initialize base case: starting from the first city
    dp[1][0] = 0;

    // Iterate through all subsets of cities
    for (int mask = 1; mask < (1 << numCities); ++mask) {
        for (int i = 0; i < numCities; ++i) {
            // Check if city 'i' is in the subset represented by the bitmask
            if ((mask & (1 << i)) != 0) {
                for (int j = 0; j < numCities; ++j) {
                    // Check if city 'j' is in the subset and different from 'i'
                    if ((mask & (1 << j)) != 0 && i != j) {
                        dp[mask][i] = min(dp[mask][i], dp[mask ^ (1 << i)][j] + calculateDistance(cities[j], cities[i]));
                    }
                }
            }
        }
    }

    // Calculate the minimum distance to return to the starting city
    double minDistance = numeric_limits<double>::max();
    for (int i = 1; i < numCities; ++i) {
        minDistance = min(minDistance, dp[(1 << numCities) - 1][i] + calculateDistance(cities[i], cities[0]));
    }

    return minDistance;
}

int main() {
    // Example usage
    vector<Point> cities = {{0, 0}, {1, 2}, {2, 4}, {3, 1}};

    double minDistance = tspDynamicProgramming(cities);

    cout << "Minimum distance: " << minDistance << endl;

    return 0;
}
