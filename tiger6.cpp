#include <string>
#include <iostream>
#include<map>
#include<fstream>
using namespace std;

class Mammal {
  protected:
    int height;
    int weight;
    bool likeSwimming;
    bool isHerbivorous;
    bool isPredator;
public:
    static void file_to_map(string filename, map<string, string>& data, string delim)
    {
      fstream file;
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

    Mammal(map<string, string>& m) {
       try { height = stoi(m["height"]); }
        catch (invalid_argument) { height = 180; }
        try { weight = stoi(m["weight"]); }
        catch (invalid_argument) { weight = 120; }
        likeSwimming = (m["likeSwimming"] == "true" || m["likeSwimming"] == "1");
        isHerbivorous = (m["isHerbivorous"] == "true" || m["isHerbivorous"] == "1");
        isPredator = (m["isPredator"] == "true" || m["isPredator"] == "1");
    }

    Mammal(const Mammal& m):height(m.height), weight(m.weight), likeSwimming(m.likeSwimming),
    isHerbivorous(m.isHerbivorous), isPredator(m.isPredator) {}

    Mammal(int weight=5, int height=10,
    bool likeSwimming=false, bool isHerbivorous=true, bool isPredator=false):
    weight(weight), height(height), isHerbivorous(isHerbivorous), isPredator(isPredator),likeSwimming(likeSwimming){}

    virtual ~Mammal() {
      cout << "Calling virtual destructor of mammal" << endl;
    }
};

class Cats: public Mammal {
  protected:
    string colourOfSkin;
    string colourOfEyes;
    int lengthOfTail;
    string genus;

public:
    Cats(map<string, string>& m): Mammal(m), genus("pantherinae") {
       try { lengthOfTail = stoi(m["lengthOfTail"]); }
       catch (invalid_argument) { lengthOfTail = 80; }
       colourOfEyes = m["colourOfEyes"];
       colourOfSkin = m["colourOfSkin"];
    }

Cats(string colourOfEyes="blue", string colourOfSkin="brown", int lengthOfTail=70, int height=180, int weight=120, bool likeSwimming=true, bool isHerbivorous=false, bool isPredator=false, string genus = "pantherinae"):
Mammal(height, weight, likeSwimming, isHerbivorous, isPredator),
colourOfEyes(colourOfEyes), colourOfSkin(colourOfSkin), lengthOfTail(lengthOfTail),
genus(genus) {}

    Cats(const Cats& c): Mammal(c), colourOfEyes(c.colourOfEyes), colourOfSkin(c.colourOfSkin),
    lengthOfTail(c.lengthOfTail), genus(c.genus) {}
};

class Tiger: public Cats
{
    int fangLength; // length of fangs
    int speed; // Speed of a tiger
    int averageDailyCourse; // Average Daily Course (metres)
    int age; // age of a tiger (years)
    string breed; // Breed of a tiger
    bool isHungry; // a tiger can be hungry or not


public:
Tiger(string colourOfEyes="blue", string colourOfSkin="brown", int lengthOfTail=70, int height=180, int weight=120, bool likeSwimming=true, bool isHerbivorous=false, bool isPredator=false, int averageDailyCourse=4800, int age=4, string breed = "Bengal", bool isHungry=true, int speed=0, int fangLength=7): Cats(colourOfEyes, colourOfSkin, lengthOfTail, height, weight, likeSwimming, isHerbivorous, isPredator),
fangLength(fangLength), speed(speed),
averageDailyCourse(averageDailyCourse), breed(breed),
isHungry(isHungry), age(age) {}

    Tiger(map<string, string>& m):Cats(m) {
       try { fangLength = stoi(m["fangLength"]); } catch (invalid_argument) { fangLength = 7; }
       try { speed = stoi(m["speed"]); } catch (invalid_argument) { speed = 0; }
       try { averageDailyCourse = stoi(m["averageDailyCourse"]); } catch (invalid_argument) { averageDailyCourse= 4800; }
       try { age = stoi(m["age"]); } catch (invalid_argument) { age = 3; }
       breed = m["breed"];
       isHungry = (m["isHungry"] == "true" || m["isHungry"] == "1");
    }
    

      // copy constructor
    Tiger(const Tiger& tiger): Cats(tiger),fangLength(tiger.fangLength), breed(tiger.breed), speed(tiger.speed), averageDailyCourse(tiger.averageDailyCourse), age(tiger.age), isHungry(tiger.isHungry)
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
    output << "Height: " << tiger.height << endl;
    output << "Weight: " << tiger.weight << endl;
    output << "Genus: " << tiger.genus << endl;
    output << "Colour of eyes: " << tiger.colourOfEyes << endl;
    output << "Colour of skin: " << tiger.colourOfSkin << endl;
    output << "Length of tail: " << tiger.lengthOfTail << endl;
    output << "Average daily course: " << tiger.averageDailyCourse << endl;
    output << "Length of fangs: " << tiger.fangLength << endl;
    output << (tiger.isHungry ? "Tiger is hungry " : "Tiger is not hungry") << endl;
   output << (tiger.likeSwimming ? "Tiger like swimming" : "Tiger dislike swimming") << endl;
   output << (tiger.isPredator ? "Tiger is predator " : "Tiger is not predator") << endl;
   output << (tiger.isHerbivorous ? "Tiger is herbivorous " : "Tiger is not herbivorous") << endl;
    return output;
}


int main() {
  map<string,string> initmap;
   Mammal::file_to_map("tiger6.txt", initmap, "|");
   Tiger t1;
    Tiger KidTiger(initmap);
    cout << KidTiger << endl;
    KidTiger.hunt();
    cout << endl;
    Tiger ParentTiger = KidTiger;
    cout << ParentTiger << endl;
    ParentTiger.hunt();
    cout << endl << t1 << endl;
}
