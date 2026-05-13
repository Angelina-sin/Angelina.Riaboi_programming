#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point {
    double x, y;

public:
    static int counter;

    Point():x(0), y(0) {
        counter++;
    }

    Point(double x, double y) {
        this->x=x;
        this->y=y;
        counter++;
    }

    double getX() const { return x; }
    double getY() const { return y; }

    static int getCount() {
        return counter;
    }
};

int Point::counter=0;

double dist(Point a, Point b) {
    return sqrt((a.getX()-b.getX())*(a.getX()-b.getX())+(a.getY()-b.getY())*(a.getY()-b.getY()));
}

int main() {

    vector<Point> poly;

    while (true) {
        string ans;
        cout<<"Enter vertex?(yes/no): ";
        cin>>ans;

        if (ans=="no") break;

        double x, y;
        cout<<"x y: ";
        cin>>x>>y;

        poly.push_back(Point(x, y));
    }

    int n=poly.size();

    cout<<"\nNumber of vertices:"<<n<<endl;

    double P=0;

    for (int i=0; i<n; i++) {
        P+=dist(poly[i], poly[(i+1)%n]);
    }

    cout<<"perimeter= "<<P<<endl;

    cout<<"Static counter= "<<Point::getCount()<<endl;

    return 0;
}