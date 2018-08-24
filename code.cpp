#include <iostream>

using namespace std;

class Student{
    private:
        string ID;
        string name;
        string department;
        string semester;
        struct Subject{
            string name;
            float mark;
            int credit;
        } s1, s2, s3, s4, s5;
    
    public:
    //Constructor
        Student(string IDI, string nameI, string departmentI,
                string semesterI, string s1_n, float s1_markI, int s1_c, string s2_n, 
                float s2_markI, int s2_c, string s3_n, float s3_markI, int s3_c, string s4_n, 
                float s4_markI, int s4_c, string s5_n, float s5_markI, int s5_c){
                    ID = IDI;
                    name = nameI;
                    department = departmentI;
                    semester = semesterI;
                    s1.name = s1_n;
                    s1.mark = s1_markI;
                    s1.credit = s1_c;
                    s2.name = s2_n;
                    s2.mark = s2_markI;
                    s2.credit = s2_c;
                    s3.name = s3_n;
                    s3.mark = s3_markI;
                    s3.credit = s3_c;
                    s4.name = s4_n;
                    s4.mark = s4_markI;
                    s4.credit = s4_c;
                    s5.name = s5_n;
                    s5.mark = s5_markI;
                    s5.credit = s5_c;
                }
    //Setter functions
    //    void setID(string IDI){
    //        ID = IDI;
    //    }

    //Getter functions
        string getID(){
            return ID;
        }

        string getName(){
            return name;
        }

        string getSemester(){
            return semester;
        }
        float getMark(string subject){
            if(subject == s1.name)
                return s1.mark;
            if(subject == s2.name)
                return s2.mark;
            if(subject == s3.name)
                return s3.mark;
            if(subject == s4.name)
                return s4.mark;
            if(subject == s5.name)
                return s5.mark;
        }

    //Custom functions
        float getGP(float marks){
            if(marks>93)
                return 4.0;
            else if(marks>90)
                return 3.7;
            else if(marks>87)
                return 3.3;
            else if(marks>83)
                return 3.0;
            else if(marks>70)
                return 2.7;
            else if(marks>77)
                return 2.3;
            else if(marks>73)
                return 2.0;
            else if(marks>70)
                return 1.7;
            else if(marks>67)
                return 1.3;
            else if(marks>60)
                return 1.0;
            else
                return 0.0;
        }

        string getGrade(string subject){
            float marks = getMark(subject);
            if(marks>93)
                return "A";
            else if(marks>90)
                return "A-";
            else if(marks>87)
                return "B+";
            else if(marks>83)
                return "B";
            else if(marks>80)
                return "B-";
            else if(marks>77)
                return "C+";
            else if(marks>73)
                return "C";
            else if(marks>70)
                return "C-";
            else if(marks>67)
                return "D+";
            else if(marks>60)
                return "D";    
            else
                return "F";
        }

        float getGPA(Student std){
            float GPA = (getGP(std.getMark(s1.name)) * s1.credit + getGP(std.getMark(s2.name)) * s2.credit
                        + getGP(std.getMark(s3.name)) * s3.credit + getGP(std.getMark(s4.name)) * s4.credit
                        + getGP(std.getMark(s5.name)) * s5.credit) / (s1.credit + s2.credit + s3.credit
                        + s4.credit + s5.credit);
            return GPA;
        }

        int getScholarshipPrcnt(Student std){
            float GPA = getGPA(std);
            if(GPA > 3.94)
                return 100;
            else if(GPA > 3.75)
                return 75;
            else
                return 0;
        }

};

int main()
{
    string ID, name, department, semester, sub1, sub2, sub3, sub4, sub5;
    float s1, s2, s3, s4, s5;
    int c1, c2, c3, c4, c5;

    cout << "Enter ID: ";
    cin >> ID;
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Department: ";
    cin >> department;
    cout << "Enter Semester: ";
    cin >> semester;
    cout << "Enter Course Name: ";
    cin >> sub1;
    cout << "Enter " << sub1 << " marks: ";
    cin >> s1;
    cout << "Enter " << sub1 << " credit hour: ";
    cin >> c1;
    cout << "Enter Course Name: ";
    cin >> sub2;
    cout << "Enter " << sub2 << " marks: ";
    cin >> s2;
    cout << "Enter " << sub2 << " credit hour: ";
    cin >> c2;
    cout << "Enter Course Name: ";
    cin >> sub3;
    cout << "Enter " << sub3 << " marks: ";
    cin >> s3;
    cout << "Enter " << sub3 << " credit hour: ";
    cin >> c3;
    cout << "Enter Course Name: ";
    cin >> sub4;
    cout << "Enter " << sub4 << " marks: ";
    cin >> s4;
    cout << "Enter " << sub4 << " credit hour: ";
    cin >> c4;
    cout << "Enter Course Name: ";
    cin >> sub5;
    cout << "Enter " << sub5 << " marks: ";
    cin >> s5;
    cout << "Enter " << sub5 << " credit hour: ";
    cin >> c5;

    Student st1(ID, name, department, semester, sub1, s1, c1, sub2, s2, c2, sub3, s3, c3, sub4, s4, c4, sub5, s5, c5);

    cout << st1.getName() << " has got " << st1.getGrade(sub1) << " in " << sub1 << "." << endl;
    cout << st1.getName() << " has got " << st1.getGrade(sub2) << " in " << sub2 << "." << endl;
    cout << st1.getName() << " has got " << st1.getGrade(sub3) << " in " << sub3 << "." << endl;
    cout << st1.getName() << " has got " << st1.getGrade(sub4) << " in " << sub4 << "." << endl;
    cout << st1.getName() << " has got " << st1.getGrade(sub5) << " in " << sub5 << "." << endl;

    cout << st1.getName() << " has got " << st1.getGPA(st1) << " GPA in " << st1.getSemester() << " semester." <<  endl;

    if(st1.getScholarshipPrcnt(st1) > 0)
        cout << st1.getName() << " has got " << st1.getScholarshipPrcnt(st1) << "% scholarship." << endl;
    
    return 0;
}
