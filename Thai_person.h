class Thai_person{
	private: 
		int nat_id;
	public: 
		Thai_person(int=0);
		~Thai_person();
    	void display_thai(); // display_person
 };

 Thai_person::Thai_person(int n1){
	// Finish constructor to set all values
		//id = i;
		//name = s;
		nat_id= n1;         
		cout<<"Thai person constructor  "<<nat_id<<endl;
			 
	  
	}
	Thai_person::~Thai_person(){
		 cout<<"-------"<<endl;
		 cout<<"Thai person destructor "<<nat_id<<endl; 
	}
	
	
	void Thai_person::display_thai(){
	  //Finish Display function
		//cout<<"ID:"<<id<<" name:"<<name<<" gpa:"<<gpa<<endl;
		//display();
		//display_person();
		cout<<"Thai id:"<<nat_id<<endl;
	}