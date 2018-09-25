// This program is a simple simulation of a cannonball.

#include <cmath> 
#include <fstream> // file i/o :)
#include <iostream> 
using namespace std;

// x = x0 + v0 * t - 0.5 * a * t * t
// position of an object


double compute_position(double x0, double v0, double a, double t){
    //x0 - initial position
    //v0 - initial velocity
    //t  - time
    //a  - acceleration due to gravity

    //formula accounts for negative accel.
    double pos = x0 + (v0 * t) + (0.5 * a * t * t);
    return pos;
}

int main(){ 
    double x0 = 0.0;
    double y0 = 0.0;

    double speed = 0.0;
    cout << "Enter a velocity:" << endl;
    cin >> speed;

    double theta = 0.0;
    cout << "Enter a launch angle (degrees):" << endl;
    cin >> theta;
    
    double pi = acos(-1);

    double vx0 = speed * cos(theta * pi / 180);
    double vy0 = speed * sin(theta * pi / 180);
    double ax = 0.0;
    double ay = -9.81;

    double time = 0.0;
    double dt = 0.25;
    
    //create a file object
    ofstream data_file("trajectory.dat");

    while (time < 10.0) {
        double x = compute_position(x0, vx0, ax, time);
        double y = compute_position(y0, vy0, ay, time);
        data_file << time << "\t\t\t" << x << "\t\t\t" << y << endl;
        time += dt;
    }

}
