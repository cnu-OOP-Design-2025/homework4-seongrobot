#include "student_manager.h"
#include "student.h"

/* StudentManager */
int StudentManager::last_student_id = 1000;

void StudentManager::addStudent(char const* name, float midterm, float final) {
    int id = ++last_student_id;
    /* TODO */
    students[num_of_students] = Student(name, id, midterm, final);
    num_of_students ++;
}

void StudentManager::deleteStudent(int id) {
    int idx = findStudentByID(id);
    /* TODO */
    int numOfStudents = num_of_students;
    for(int i=idx; i <numOfStudents-1; ++i){
        students[i] = students[i+1];
    }
    num_of_students--;
}

void StudentManager::modifyStudent(const Student& student) {
     int idx = findStudentByID(student.getID());
    /* TODO */
    students[idx] = student;
}

int StudentManager::findStudentByID(int id) const {
    /* TODO */
    int numOfStudents = num_of_students;
    for(int i=0; i<numOfStudents; i++) {
        if(students[i].getID() == id) return i; 
    }
    return -1;
}

int StudentManager::findBestStudentInMidterm() const {
    /* TODO */
    float bestScore = 0.0f;
    int numOfStudents = num_of_students;
    int id = 1000;
    for(int i=0; i<numOfStudents; i++) {
        float curScore = students[i].getRecord().getMidterm();
        if(curScore > bestScore){
            bestScore = curScore;
            id = students[i].getID(); 
        }
    }
    return id;
}

int StudentManager::findBestStudentInFinal() const {
    /* TODO */
    float bestScore = 0.0f;
    int numOfStudents = num_of_students;
    int id = 1000;
    for(int i=0; i<numOfStudents; i++) {
        float curScore = students[i].getRecord().getFinal();
        if(curScore > bestScore){
            bestScore = curScore;
            id = students[i].getID();
        }
    }
    return id;
}

int StudentManager::findBestStudent() const {
    /* TODO */
    float bestScore = 0.0f;
    int numOfStudents = num_of_students;
    int id = 1000;
    for(int i=0; i<numOfStudents; i++) {
        float curScore = students[i].getRecord().getTotal();
        if(curScore > bestScore) {
            bestScore = curScore;
            id = students[i].getID();
        }
    }
    return id;
}

float StudentManager::getMidtermAverage() const {
    /* TODO */
    float total = 0.0f;
    int numOfStudents = num_of_students;
    for(int i=0; i<numOfStudents; i++) {
        float curScore = students[i].getRecord().getMidterm();
        total += curScore;
    }
    return total/numOfStudents;
}

float StudentManager::getFinalAverage() const {
    /* TODO */
    float total = 0.0f;
    int numOfStudents = num_of_students;
    for(int i=0; i<numOfStudents; i++) {
        float curScore = students[i].getRecord().getFinal();
        total += curScore;
    }
    return total/numOfStudents;
}

float StudentManager::getTotalAverage() const {
    /* TODO */
    float total = 0.0f;
    int numOfStudents = num_of_students;
    for(int i=0; i<numOfStudents; i++) {
        float curScore = students[i].getRecord().getTotal();
        total += curScore;
    }
    return total/numOfStudents;
}

