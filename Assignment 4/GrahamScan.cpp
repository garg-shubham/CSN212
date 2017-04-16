#include <bits/stdc++.h>
using namespace std;

const int maxn = 100005;

class Point {
public:
    int x, y;

    // comparison is done first on y coordinate and then on x coordinate
    bool operator < (Point b) {
        if (y != b.y)
            return y < b.y;
        return x < b.x;
    }
};

Point points[maxn];

Point pivot;

// returns -1 if a -> b -> c forms a counter-clockwise turn,
// +1 for a clockwise turn, 0 if they are collinear
int orientation(Point a, Point b, Point c) {
    int area = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    if (area > 0)
        return -1;
    else if (area < 0)
        return 1;
    return 0;
}

// returns square of Euclidean distance between two points
int Dist_Sqr(Point a, Point b)  {
    int dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// used for sorting points according to polar order w.r.t the pivot
bool POLAR_ORDER(Point a, Point b)  {
    int order = orientation(pivot, a, b);
    if (order == 0)
        return Dist_Sqr(pivot, a) < Dist_Sqr(pivot, b);
    return (order == -1);
}

stack<Point> solve(Point *points, int N)
{
	stack<Point> ans;

	if (N < 3)
	    return ans;

	// find the point having the least y coordinate (pivot),
	// ties are broken in favor of lower x coordinate
	int minimum_y = 0;
	for (int i = 1; i < N; i++)
		if (points[i] < points[minimum_y])
			minimum_y = i;

	// swap the pivot with the first point
	Point temp = points[0];
	points[0] = points[minimum_y];
	points[minimum_y] = temp;

	// sort the remaining point according to polar order about the pivot
	pivot = points[0];
	sort(points + 1, points + N, POLAR_ORDER);

	ans.push(points[0]);
	ans.push(points[1]);
	ans.push(points[2]);

	for (int i = 3; i < N; i++)
	{
		Point top = ans.top();
		ans.pop();
		while (orientation(ans.top(), top, points[i]) != -1)
		{
			top = ans.top();
			ans.pop();
		}
		ans.push(top);
		ans.push(points[i]);
	}
	return ans;
}

int main()
{
	int n;
	cout << "Number of points: ";
	cin >> n;

	int x, y;

	cout<<"Enter the points "<<endl;
	for(int i = 0 ; i < n; i++)
	{
		cin >> x >> y;
		points[i] = {x, y};
	}

	clock_t t;	
	t = clock();

	stack<Point> hull = solve(points, n);
	cout<<"The required points are "<<endl;
	while (!hull.empty())
	{
	    Point p = hull.top();
	    hull.pop();

	    printf("(%d, %d)\n", p.x, p.y);
	}
	t = clock() - t;
	printf ("It took %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);

	return 0;
}