#include <iostream>
using std::string;

class AbstractEmployee {
    virtual void AskForPromotion()=0;
};
class Employee:AbstractEmployee {
protected:
    std::string Name;
    std::string Company;
    int Age;
public:
    //Encapsulation
    void setName(string name){
        Name = name;
    }

    string getName(){
        return Name;
    }

    void setCompany(string company){
        Company = company;
    }

    string getCompany(){
        return Company;
    }

    void setAge(int age){
        if(age>=18)
        Age = age;
    }

    int getAge(){
        return Age;
    }

    void IntroduceYourself(){
        std::cout<<"Name - "<<Name<<std::endl;
        std::cout<<"Company - "<<Company<<std::endl;
        std::cout<<"Age - "<<Age<<std::endl;
    }
    //Abstraction 
    void AskForPromotion(){
        if(Age>30)
            std::cout<<Name<<" got promoted!!!"<<std::endl;
        else
            std::cout<<Name<<" sorry, no promotion for you!!!"<<std::endl;
    }

    virtual void Work(){
        std::cout<<Name<<" is working"<<std::endl;
    }

    Employee(string name, string company, int age){
        Name = name;
        Company = company;
        Age = age;
    }
};

//Inheritance
class Developer:public Employee{
private:
    std::string Language;
public:
    void setLanguage(string language){
        Language = language;
    }

    string getLanguage(){
        return Language;
    }
    Developer(string name, string company, int age, string language):Employee(name, company, age){
        Language = language; 
    }

    void FixBug(){
        std::cout<<Name<<" fixed bug with "<<Language<<std::endl;
    }
    //Polymorphism
    /* void Work(){
        std::cout<<Name<<" is writing "<<Language<<" code"<<std::endl;
    }*/

};

class Teacher:public Employee{
protected:
    std::string Subject;
public:  
    void PrepareLesson(){
        std::cout<<Name<<" is preparing "<<Subject<<" lesson"<<std::endl;
    }

    void setSubject(string subject){
        Subject = subject;
    }

    string getSubject(){
        return Subject;
    }

    Teacher(string name, string company, int age, string subject):Employee(name,company,age){
        Subject = subject;
    }
    
     void Work(){
        std::cout<<Name<<" is teaching "<<Subject<<" lesson"<<std::endl;
    }

};

int main(){
    Employee employee0 = Employee("Farhad", "Tesla", 12);
    /*employee0.Name = "Farhad";
    employee0.Company = "Tesla";
    employee0.Age = 20;*/
    Developer developer0 = Developer("Kamal", "ABB", 32, "Pyhton");

    Teacher teacher0 = Teacher("Famil", "NASA", 12, "Control Theory");
    /*employee0.IntroduceYourself();
    employee0.setAge(19);
    employee0.IntroduceYourself();
    employee0.AskForPromotion();
    developer0.FixBug();
    developer0.AskForPromotion();
    teacher0.AskForPromotion();
    teacher0.PrepareLesson();*/
 

    //Pointers
    Employee* e1 = &developer0;
    Employee* e2 = &teacher0;

    e1->Work();
    e2->Work();

    return 0;
}