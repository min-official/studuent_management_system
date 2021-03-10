#include <iostream>
#include "student.h"
#include <string>
#include <algorithm> 

// //****************************************************************
// //                   REQUIRED FUNCTIONALITIES
// //****************************************************************

// TODO: Implement the methods below.
// TODO: Implement the get_info methods for the relevant classes.

void GradStudent::get_info(){
	std::cout<<"Graduate Student : ["<<name<<"\t"<<stu_num<<"\t"<<lab_name<<"]"<<std::endl;
	/*std::cout<<"This student is Graduate Student."<<std::endl;
	std::cout<<"Student name : "<<name<<std::endl;
	std::cout<<"Student id : "<<stu_num<<std::endl;
	std::cout<<"Student lab name : "<<lab_name<<std::endl;*/
	}
void UndergradStudent::get_info(){	std::cout<<"Under Gradate Student : ["<<name<<"\t"<<stu_num<<"\t"<<freshmen_class<<"]"<<std::endl;
	/*std::cout<<"This student is Undergraduate Student."<<std::endl;
	std::cout<<"Student name : "<<name<<std::endl;
	std::cout<<"Student id : "<<stu_num<<std::endl;
	std::cout<<"Student freshmen class number : "<<freshmen_class<<std::endl;*/
	}
	
int Manager::add_student(std::string name, int stu_num, std::string lab_name)
{if(stunum==0){
Student* grad = new GradStudent(name, stu_num, lab_name);		
				stulist[stunum] = grad;
				stunum++;
				std::cout<<"saved\n There are "<<stunum<<" students"<<std::endl;
				return stunum;}
else{
 if(stu_num>0){
	int check=0; 
        for(int count = 0; count <stunum; ++count){
            if(stulist[count]->get_id() == stu_num) {
				std::cout<<"Student id should be unique."<<std::endl;
				return -1;}
			else {check++;}}
	if(check==stunum){
			Student* grad = new GradStudent(name, stu_num, lab_name);
				stulist[stunum] = grad;
				stunum++;
				std::cout<<"saved\n There are "<<stunum<<" students"<<std::endl;
				return stunum;}}
    else {
        std::cout<<"Student id should be positive integer."<<std::endl;
			return -1;}}
std::cout<<"out"<<std::endl;
return 0;    }
		
    // TODO: Add a GradStudent object using the given arguments.
    // stu_num should be positive and unique across the student array.
    // If successful, return the total number of objects in the student array. Otherwise return -1.
    
int Manager::add_student(std::string name, int stu_num, int freshmen_class)
{if(stunum==0){
Student* undergrad = new UndergradStudent(name,stu_num, freshmen_class);
				stulist[stunum] = undergrad;
				stunum++;	
				std::cout<<"saved\n There are "<<stunum<<" students"<<std::endl;		
				return stunum;}
else{
if(stu_num>0){
	int check=0; 
	for(int count = 0; count <stunum; ++count){
    		if(stulist[count]->get_id() == stu_num) {
				std::cout<<"saved\n There are "<<stunum<<" students"<<std::endl;
				return -1;}
		else {
		check++;}};
	if(check==stunum){
			Student* undergrad = new UndergradStudent(name,stu_num, freshmen_class);
				stulist[stunum] = undergrad;
				stunum++;	
				std::cout<<"saved\n There are "<<stunum<<" students"<<std::endl;	
				return stunum;}}
    else {
        std::cout<<"Student id should be positive integer."<<std::endl;
			return -1;};}
std::cout<<"out"<<std::endl;
			return 0;}
    // TODO: Add an UndergradStudent object using the given arguments.
    // The rest of the functionality is similar to when adding a GradStudent object.


int Manager::delete_student(std::string name, int stu_num, std::string lab_name)
{int check=0;
for(int count=0; count<stunum; ++count){
	if(stulist[count]->get_name()==name && stulist[count]->get_id()==stu_num && stulist[count]->get_lab()==lab_name){
	delete stulist[count];
	if(count==stunum-1){
		stunum--;
		return stunum;}
	else{
		for(int i=count; i<stunum-1;++i){
			stulist[i] = stulist[i+1];}
		stunum--;}
		std::cout<<"deleted\n There are "<<stunum<<" students"<<std::endl;	
		return stunum;}
	else{check++;}}
if(check==stunum){
	std::cout<<"There are no matching sutdent"<<std::endl;
	return -1;}
	return 0;}	
			
    // TODO: Delete the GradStudent object in the student array that matches the input arguments.
    // If the deletion is successful, return the total number of objects in the student array.
    // If there is no object that matches the arguments, return -1.

int Manager::delete_student(std::string name, int stu_num, int freshmen_class)
{int check =0;
for(int count=0; count<stunum; ++count){
	if(stulist[count]->get_name()==name && stulist[count]->get_id()==stu_num && stulist[count]->get_class()==freshmen_class){
	delete stulist[count];
	if(count==stunum-1){
		stunum--;
		return stunum;}
	else{
		for(int i=count; i<stunum-1;++i){
			stulist[i] = stulist[i+1];}
		stunum--;}
		std::cout<<"deleted\n There are "<<stunum<<" students"<<std::endl;
		return stunum;}
	else{check++;}}
if(check==stunum){
	std::cout<<"There are no matching sutdent"<<std::endl;
	return -1;}
	return 0;}	
    // TODO: Delete the UndergradStudent object in the student array that matches the input
    // arguments. The rest of the functionality is similar to when deleting a GradStudent object.

bool compare(const Student* x, const Student* y){
	return x->get_id() < y->get_id();}
	
int Manager::sort_students(void)
{std::sort(stulist, stulist + stunum,compare);
    // TODO: Sort the Student class pointer array by stu_num in ascending order.
    // You may use any sorting library or implement your own algorithm.
    // Return 0 if the sorting is successful and -1 otherwise.
    return 0;
};

// Operator overloading function. 
bool operator==(const Student& x , const Student& y)
{if(x.get_name()==y.get_name() && x.get_id()==y.get_id()){
	if(x.get_class()==y.get_class()){
		return true;}
	else if(x.get_lab()==y.get_lab()){
		return true;}
	else{return false;}}
else{
return false;}
return 0;}
    // TODO: Check whether two students x, y have the same information or not. 
    // Return true if two students are same and false otherwise.
    // This function must at least be used in the find_student() method.

int Manager::find_student(std::string name, int stu_num, std::string lab_name){
	int check=0;
	Student* grad = new GradStudent(name, stu_num, lab_name);
	for(int count=0; count<stunum; ++count){
		if(*stulist[count]==*grad){
			std::cout<<"found!!"<<std::endl;
			stulist[count]->get_info();
			return count;}
		else{check++;}}
	if(check==stunum){
	std::cout<<"there are no matching student"<<std::endl;
	return -1;}
	delete[] grad;
		return 0;}

    // TODO: Find the GradStudent object in the student array that matches the input arguments. 
    // Print the information about the matched student, if any.
    // Return the index of the matched student within the student array (an array index starts
    // from 0) or -1 if there is no match.

int Manager::find_student(std::string name, int stu_num, int freshmen_class)
{int check=0;
	Student* undergrad = new UndergradStudent(name, stu_num, freshmen_class);
	for(int count=0; count<stunum; ++count){
		if(*stulist[count]==*undergrad){
			std::cout<<"found!!"<<std::endl;
			stulist[count]->get_info();
			return count;}
		else{check++;}}
	if(check==stunum){
	std::cout<<"there are no matching student"<<std::endl;
	return -1;}
		return 0;}
    // TODO: Find the UndergradStudent object in the student array that matches the input
    // arguments. The rest of the functionality is similar to when finding a GradStudent object.


int Manager::find_sim_students(std::string name)
{
    // TODO: Find the students whose names are similar to the input name by calculating
    // the jaccard similarity of the names and comparing it with the fixed threshold 0.3.
    // Print the student information of all similar students.
    // Return the number of similar students or -1 if there is no such student.
    return 0;
};

int Manager::print_all()
{if(stunum==0){
	std::cout<<"There is no student information saved"<<std::endl;}
else{
std::cout<<"there are "<<stunum<<" students"<<std::endl;
for(int count = 0; count <stunum; ++count){
        stulist[count]->get_info();}}
    // TODO: Print the student information in the student array.
    // Return the total number of objects in the student array.
    return stunum;
};




