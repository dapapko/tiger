#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Tiger
{
    int* props; // 0 - fangLength, 1 - speed, 2 - averageDailyCourse 3 - age
    string breed; // Breed of a tiger
    bool isHungry; // a tiger can be hungry or not
    fstream file;


    void file_to_map(string filename, map<string, string>& data, string delim)
    {
        file.open(filename);
        if (file.is_open()) {
            cout << "Initialization from file" << endl;
            // Initialize object using data from file
            string row;
            int j = 0;
            while (getline(file, row) && j < 7) {
                j++;
                size_t delim_pos = row.find(delim);
                string key = row.substr(0, delim_pos);
                string value = row.substr(delim_pos + 1);
                data[key] = value;
            }
            file.close();
        }
    }

public:

    Tiger(string filename = "tiger.txt", string delim = ":")
    {
        map<string, string> data{
            {"fangLength","10"},
            {"averageDailyCourse","4800"},
            {"speed","0"},
            {"breed","Amur"},
            {"age","4"},
            {"isHungry","0"}
        };
        file_to_map(filename, data, delim);
        props = new int[4];
        try { props[0] = stoi(data["fangLength"]); }
        catch (invalid_argument) { props[0] = 10; }
        try { props[1] = stoi(data["speed"]); }
        catch (invalid_argument) { props[1] = 0; }
        try { props[2] = stoi(data["averageDailyCourse"]); }
        catch (invalid_argument) { props[2] = 4800; }
        try { props[3] = stoi(data["age"]); }
        catch (invalid_argument) { props[3] = 4; }
        isHungry = data["isHungry"] == "1";
        breed = data["breed"];

    }

    // Friendly operator function 
    friend ostream& operator<<(ostream& output, const Tiger& T);

    // hunting
    void hunt(int t_speed = 30) {
        if (!isHungry) cout << "Tiger is not hungry, so he don't hunt" << endl;
        else {
            if (props[0] < 2) cout << "Tiger is hungry, he makes known about it tigress" << endl;
            else {
                cout << "Tiger is hungry, it begins to hunt." << endl;
                run(t_speed);
            }
        }
    }

    // running
    void run(int t_speed) {
        props[1] = t_speed;
        cout << "Tiger is running at speed of " << t_speed << "km/h" << endl;
    }

    // copying constructor
    Tiger(Tiger const& tiger) :breed(tiger.breed), isHungry(tiger.isHungry)
    {
        props = new int[4];
        props[0] = tiger.props[0];
        props[1] = tiger.props[1];
        props[2] = tiger.props[2];
        props[3] = tiger.props[3];
    }

    // Destructor
    ~Tiger() {
        if (file.is_open()) file.close();
        delete[] props;
    }
};

// Friendly operator function for output
ostream& operator<<(ostream& output, const Tiger& T) {
    output << "Breed: " << T.breed << endl;
    output << "Age: " << T.props[3] << endl;
    output << "Speed: " << T.props[1] << endl;
    output << "Average daily course: " << T.props[2] << endl;
    output << "Length of fangs: " << T.props[0] << endl;
    output << (T.isHungry ? "The tiger is hungry" : "The tiger is not hungry") << endl;
    return output;
}

int main() {
    Tiger t1("tiger.txt");
    cout << t1;
    t1.hunt();
    cout << endl;
    Tiger t2 = t1;
    cout << t2;
    t1.hunt(50);
    system("PAUSE");
}
