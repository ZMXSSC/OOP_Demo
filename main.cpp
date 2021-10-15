#include <iostream>
using namespace std;

class UCSD{
    virtual void canIDrink()=0;
    /* pure virtual function lead to an abstract class, that means
     * all derived classes are required to implement this function
     */
};

class Department:public UCSD{ // You inherited an abstract class, that means you MUST implement the pure virtual function
protected:
    string studentName;
    string college;
    int age;
    static int employeeCount;
public:
    /*The purpose of static function is to access private static members. You add
    * static when you declare it, but you don't add static when you initialize it.
    * side note: regular member function can access ALL members, while static member function can only access
    * static members.
    */
    static int getEmployeeCount();
    Department(string n, string c, int a);
    void introduceYourself();
    void setStudentName(string n);
    string getStudentName();
    void setCollege(string c);
    string getCollege();
    void setAge(int a);
    int getAge();

    void canIDrink() override{ //This is how you implement it
        if(age > 21){
            cout << studentName << " can drink!" << endl;
        }
        else{
            cout << studentName << ", sorry you are underage." << endl;
        }
    }

    virtual void study(); //The CORE of polymorphism!!!!! You have to use keyword "virtual" in your base class
};
int Department::employeeCount = 0; // You have to sort of initialize the static variable first before entering
// the main function and after the class definition. Or linker error will be popped up.

Department::Department(string n, string c, int a) {
    studentName = n;
    college = c;
    age = a;
    employeeCount++;
}
void Department::introduceYourself() {
    cout<< "studentName - " << studentName << endl;
    cout<< "college - " << college << endl;
    cout<< "Age - " << age << endl;
}
void Department::setStudentName(string n) {
    studentName = n;
}
string Department::getStudentName() {
    return studentName;
}
void Department::setCollege(string c) {
    college = c;
}
string Department::getCollege() {
    return college;
}
void Department::setAge(int a) {
    age = a;
}
int Department::getAge() {
    return age;
}
void Department::study() {
    cout << studentName << " is doing Homework and study for the midterm." << endl;
}
int Department::getEmployeeCount() {
    return employeeCount;
}
/*The purpose of static function is to access private static members. You add
* static when you declare it, but you don't add static when you initialize it.
* side note: regular member function can access ALL members, while static member function can only access
* static members.
*/
class ECE:public Department{ // You have to use the keyword "public" to access public methods from the base class!
public:
    string Depth;

    ECE(string n, string c, int a, string pl);
    void selection();

    void study() override; //polymorphism
};

ECE::ECE(string n, string c, int a, string d) : Department(n, c, a) {
    Depth = d;
}
void ECE::selection() {
    cout << studentName << " is pursuing " << Depth << endl;
}
void ECE::study() {
    cout << studentName << " is suffering from " << Depth << " homework because it's too hard" << endl;
}

class CSE:public Department{ // You have to use the keyword "public" to access public methods from the base class!
public:
    string favoriteProgrammingLanguage;
    CSE(string n, string c, int a, string s);
    void fixBug();

    void study() override; //polymorphism
};

CSE::CSE(string n, string c, int a, string pl) : Department(n, c, a) {
    favoriteProgrammingLanguage = pl;
}
void CSE::fixBug() {
    cout << studentName << " fixed bug using "<< favoriteProgrammingLanguage << endl;
}
void CSE::study() {
    cout << studentName << " is writing " << favoriteProgrammingLanguage << endl;
}


int main() {
//    Department e1 = Department("Sunny", "Department", 23);
//    e1.canIDrink();

//    ECE e = ECE("Sunny", "Warren", 23, "Machine Learning and Controls");
//    CSE c = CSE("Jack", "ERC", 18, "PHP");
    
//    e.selection();
//    e.canIDrink();
//    c.fixBug();
//    c.canIDrink();
//    e.study();
//    c.study();

/*
 * The most common use of polymorphism is when a
 * parent class reference is used to refer to a child class object
 */
   Department *e1 = new ECE("Sunny", "Warren", 23, "MLC");
   Department *e2 = new CSE("Moon", "Seventh", 20, "Java");

   e1->study();
   e2->study();
   e1->canIDrink();
   e1->introduceYourself();

//   int total = Department::getEmployeeCount();
//   cout << "Total objects: " << total << endl;

}
