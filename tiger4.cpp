#include <string>
#include <iostream>
using namespace std;


class Tiger
{
    int fangLength; // length of fangs
    int speed; // Speed of a tiger
    int averageDailyCourse; // Average Daily Course (metres)
    int age; // age of a tiger (years)
    string breed; // Breed of a tiger
    bool isHungry; // a tiger can be hungry or not


public:
    Tiger(int t_fangLength = 7, int t_speed = 0, string t_breed = "Bengal", int t_avgdailycourse = 4500, int t_age=4, bool t_isHungry=false ) :
       fangLength(t_fangLength), speed(t_speed), breed(t_breed), averageDailyCourse(t_avgdailycourse),
       age(t_age), isHungry(t_isHungry)
    {}

      // copy constructor
    Tiger(const Tiger& tiger): fangLength(tiger.fangLength), breed(tiger.breed), speed(tiger.speed), averageDailyCourse(tiger.averageDailyCourse), age(tiger.age), isHungry(tiger.isHungry)
    {}

    //  visualization of the tiger
    friend ostream& operator<<(ostream& output, const Tiger& tiger);

    // running
    void run(int t_speed) {
        speed = t_speed;
        cout << "Tiger is running at speed of " << speed << " km/h" << endl;
    }

    // hunting
    void hunt() {
        if (isHungry)
        {
            if (age <= 2)
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
    output << "Age: " << tiger.age << endl;
    output << "Speed: " << tiger.speed << endl;
    output << "Breed: " << tiger.breed << endl;
    output << "Average daily course: " << tiger.averageDailyCourse << endl;
    output << "Length of fangs: " << tiger.fangLength << endl;
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
