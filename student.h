// //***************************************************************
// //                         CLASSES
// //****************************************************************


class Student {
    // TODO: Define the member variables.
    private:
    protected:
    	std::string name;
    	int stu_num;
    public:
    	Student(std::string name, int stu_num){
    		this->name = name;
    		this->stu_num = stu_num;
    		}
	    std::string get_name() const{
	        return name;}
	    int get_id() const{
	        return stu_num;}
        virtual void get_info() =0;
        virtual std::string get_lab() const =0;
        virtual int get_class() const =0;
        // TODO: Declare get_info() as a pure virtual function.
};

class GradStudent: public Student {
    // TODO: Define the member variables.
    private:
    	std::string lab_name;
    protected:
    public:	
    	GradStudent(std::string name, int stu_num, std::string lab_name) : Student(name, stu_num), lab_name(lab_name) {}	
    	void get_info();
    	std::string get_lab()const {
    		return lab_name;};
	int get_class() const{
		return 0;};
        // TODO: Declare get_info().
};

class UndergradStudent: public Student {
    // TODO: Define the member variables.
    private:
    	int freshmen_class;
    protected:
    public:
    	UndergradStudent(std::string name, int stu_num, int freshmen_class) : Student(name, stu_num), freshmen_class(freshmen_class){}
    	void get_info();
    	int get_class() const{
    		return freshmen_class;};
	std::string get_lab()const {
		return 0;};
        // TODO: Declare get_info().
};

class Manager {
    // TODO: Define the member variables.
    private:
    	Student* stulist[300];
    	int stunum;
    protected:
    public:
    	Manager() : stunum(0) {}
        // Adds a student object in the student array.
        int add_student(std::string name, int stu_num, std::string lab_name);
        int add_student(std::string name, int stu_num, int freshmen_class);

        // Deletes a student object from the student array.
        int delete_student(std::string name, int stu_num, std::string lab_name);
        int delete_student(std::string name, int stu_num, int freshmen_class);

        // Sorts the students by stu_num.
        int sort_students(void);

        // Finds a student in the student array.
        int find_student(std::string name, int stu_num, std::string lab_name);
        int find_student(std::string name, int stu_num, int freshmen_class);

        // Finds students with similar names.
        int find_sim_students(std::string name);

        // Prints the information of students.
        int print_all();
};


