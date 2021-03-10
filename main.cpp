#include <iostream>
#include <stdexcept>
#include <string>
#include "student.h"
#include <cstring>


// //****************************************************************
// //                   MAIN FUNCTION
// //****************************************************************

int main()
{
    char command;
    char command_test;
    std::string command_left;
    Manager manager;
    int is_grad;
    std::string name;
    int stu_num;
    std::string lab_name;
    int freshmen_class;
    int index;
    bool is_last = true;
    bool check_command = true;

    while(is_last) {
        std::cout << "\n\n\n*---------------------Welcome to Student Management" 
            << "System---------------------*" << std::endl;

        std::cout << "What do you want to do?\n - Add a student: a\n - Delete a student: d\n"
            << " - Sort the students: s\n - Find a student: f\n"
            << " - Find similar-named students: m\n - Print all student: p\n"
            << " - Quit: q" << std::endl;

        // TODO: Handle any wrong arguments here.
        std::cout << "Enter the command : " << std::endl;
        std::cin >> command;
        /*std::getline(std::cin, command_left);
        while(check_command){
        if(command_left.length()!=0){
        std::cout<<"too long command"<<std::endl;
            	std::cin.clear();
            	std::cout << "Enter the command : " << std::endl;
        std::cin >> command_test;
        std::getline(std::cin, command_left);
        continue;}
        else{
        if(command_test =='a' or command_test=='d' or command_test=='s' or command_test=='f' or command_test=='m' or command_test=='p' or command_test=='q'){
            command = command_test;
        	check_command = false;}
	    else {
		    std::cout<<"wrong command"<<std::endl;
		    std::cin.clear();
		    std::cout << "Enter the command : " << std::endl;
		    std::cin >> command_test;
            std::getline(std::cin, command_left);
            continue;}}}*/
            	


        switch(command) {
            case 'a': 
                std::cout << "Begin add student.\n\n"
                    << "Type\nUndergraduate: 0 Graduate: 1"<< std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> is_grad;
                if (is_grad == 1){
                    std::cout << "\nFormat: [name stu_num lab_name]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> lab_name;
                    manager.add_student(name, stu_num, lab_name);		  
                }

                else if (is_grad == 0){
                    std::cout << "\nFormat: [name stu_num freshmen_class] " << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> freshmen_class;
                    manager.add_student(name, stu_num, freshmen_class);		  
                }
                break;

            case 'd':
                std::cout << "Begin delete student.\n\n"
                    << "Type\nUndergraduate: 0 Graduate: 1" << std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> is_grad;

                if (is_grad == 1){
                    std::cout << "\nFormat: [name stu_num lab_name]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> lab_name;
                    manager.delete_student(name, stu_num, lab_name);
                }
                else if (is_grad == 0){
                    std::cout << "\nFormat: [name stu_num freshmen_class]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> freshmen_class;
                    manager.delete_student(name, stu_num, freshmen_class);
                }
                break;

            case 's':
                std::cout << "Begin sort students.\n\n" << std::endl;
                manager.sort_students();
                break;

            case 'f':
                std::cout << "Begin find student.\n\n"
                    << "Type\nUndergraduate: 0 Graduate: 1" << std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> is_grad;

                if (is_grad == 1){
                    std::cout << "\nFormat: [name stu_num lab_name]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> lab_name;
                    manager.find_student(name, stu_num, lab_name);
                }
                else if (is_grad == 0){
                    std::cout << "\nFormat: [name stu_num freshmen_class]" << std::endl;

                    // TODO: Handle any wrong arguments here.
                    std::cin >> name >> stu_num >> freshmen_class;
                    manager.find_student(name, stu_num, freshmen_class);
                }
                break;

            case 'm':
                std::cout << "Begin find similar-named students.\n\nType\n" << std::endl;
                std::cout << "Format: [name]" << std::endl;

                // TODO: Handle any wrong arguments here.
                std::cin >> name;
                manager.find_sim_students(name);
                break;

            case 'p':
                std::cout << "Begin print all." << std::endl;
                manager.print_all();
                break;

            case 'q':
                std::cout << "Quit." << std::endl;
                is_last = false;
                break;

            default:
                std::cout << "Invalid argument." << std::endl;
                break;
        }
    }
    return 0;
}
