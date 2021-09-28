
// Bai 1
#include <iostream>
using namespace std;
int main ()
{
    string str;
    getline(cin, str);
    int str_length = str.size();
    for (int i = 0; i < str_length; i++)
        cout << str[str_length - i - 1];
    return 0;
}

// Bai 2
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

class Point {
public:
    double x;
    double y;

    Point () {};
    void set_xy ()
    {
        cin >> x;
        cin >> y;
    }
    void print()
    {
        cout << fixed << setprecision(2) << x << " ";
        cout << fixed << setprecision(2) << y << endl;
    }
};

class Line {   // the line will be follow form y = ax + b;  => we have to get a, b firstly;

public:
    Line () {};
    double v_x (Point A, Point B)
    {
        return A.x - B.x;
    }
    double v_y (Point A, Point B)
    {
        return A.y - B.y;
    }
    double const_a (Point A, Point B)
    {
        return (double) (A.y-B.y)/(A.x-B.x);
    }
    double const_b (Point A, Point B)
    {
        return (double) ((A.y+B.y)-(A.y-B.y)*(A.x+B.x)/(A.x-B.x))/2.00;
    }
};

Point locate(double a1, double b1, double a2, double b2) // y = a1.x+ b1 and y = a2.x+b2;
{
    Point intersect;
    if (a1 == a2 && b1 == b2)
        cout << "MANY";
    else
        if (a1 == a2 && b1 != b2)
            cout << "NO";
    else {                          // giai he phuong trinh
        double D, Dx, Dy;
        D = -a1 + a2;
        Dx = b1 - b2;
        Dy = -a1*b2 + a2*b1;
        intersect.x = Dx/D;
        intersect.y = Dy/D;
        return intersect;                       // - a1.x + y = b1 & -a2.x + y = b2
    }

}

int main ()
{
    Point A, B, C, D;
    A.set_xy();
    B.set_xy();
    C.set_xy();
    D.set_xy();
    Line AB, CD;

    Point inter = locate(AB.const_a(A, B), AB.const_b(A, B), CD.const_a(C, D), CD.const_b(C, D));
    inter.print();

}

// Bai 3
#include <iostream>
using namespace std;

int gcd (int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (b == 0) return a;
    return gcd(b, a%b);
}

int main ()
{
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl;
    return 0;
}

// Bai 4
 #include <iostream>
#include <algorithm>
using namespace std;

int main ()
{
    int n;
    int a[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        for(int j = i+1; j < n; j++)
            if (a[i] > a[j])
    {
        swap(a[i] , a[j]);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}

// Bai 5
#include <iostream>
using namespace std;

int main ()
{
    int number = 5;
    double a[number];
    for (int i = 0; i < number; i++)
        cin >> a[i];
    double MAX = a[0];
    double MIN = a[0];
    for (int i = 0; i < number; i++)
    {
        if (a[i] > MAX)
        {
            MAX = a[i];
        }
        if (a[i] < MIN)
        {
            MIN = a[i];
        }
    }
    cout << MAX + MIN;
}

