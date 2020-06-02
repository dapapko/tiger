#include <string>
#include <iostream>
using namespace std;

class Tiger
{
    int* props; // 0 - fangLength, 1 - speed , 2 - averageDailyCourse, 3 - age
    string breed; // Breed of a tiger
    bool isHungry; // a tiger can be hungry or not


public:
    Tiger(int t_fangLength = 7, int t_speed = 0, string t_breed = "Bengal", int t_avgdailycourse = 4500, int t_age=4, bool t_isHungry=false ) :
        breed(t_breed), isHungry(t_isHungry)
    {
      props = new int[4];
      props[0] = t_fangLength;
      props[1] = t_speed;
      props[2] = t_avgdailycourse;
      props[3] = t_age;
    }

      // copy constructor
    Tiger(const Tiger& tiger):breed(tiger.breed),
    isHungry(tiger.isHungry)
    {
      props = new int[4];
      props[0] = tiger.props[0];
      props[1] = tiger.props[1];
      props[2] = tiger.props[2];
      props[3] = tiger.props[3];

    }

    //  visualization of the tiger
    friend ostream& operator<<(ostream& output, const Tiger& tiger);

    // running
    void run(int t_speed) {
        props[1] = t_speed;
        cout << "Tiger is running at speed of " << props[1] << " km/h" << endl;
    }

    // hunting
    void hunt() {
        if (isHungry)
        {
            if (props[3] <= 2)
            {
                cout << "Tiger is hungry, he makes known about it tigress" << endl;
            }
            else
            {
                cout << "Tiger is hungry, it begins to hunt." << endl;
                run(54);
            }
        } else
        {
            cout << "Tiger is not hungry, so he don't hunt" << endl;
        }
    }
};

// visualization of the tiger
ostream& operator<< (ostream& output, const Tiger& tiger) {
    output << "Age: " << tiger.props[3] << endl;
    output << "Speed: " << tiger.props[1] << endl;
    output << "Breed: " << tiger.breed << endl;
    output << "Average daily course: " << tiger.props[2] << endl;
    output << "Length of fangs: " << tiger.props[0] << endl;
    output << (tiger.isHungry ? "Tiger is hungry " : "Tiger is not hungry") << endl;
    return output;
}


int main() {
    Tiger KidTiger(10, 160);
    cout << KidTiger << endl;
    KidTiger.hunt();
    cout << endl;
    Tiger ParentTiger = KidTiger;
    cout << ParentTiger << endl;
    ParentTiger.hunt();
}
