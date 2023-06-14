//These are the only header files allowed
//-----------------------------------------
#include <iostream>//for cin and cout
#include <fstream>//for file handling
//-----------------------------------------
using namespace std;  //Define the namespace.

//*************Useful functions************************************.
//getNumberOfRecords receives a c string with the filename/fullpath
// returns the number of lines/rows, and -1 if error
int getNumberOfRecords(char fn[]) {
	//input file stream is needed
	ifstream input;
	//call the open method
	input.open(fn);
	//test if the open function was succesful
	if (!input.is_open())
		return -1; //if open() failed, return -1
	//Use an accumulator. Local variables are NOT initialized by default
	int counter = 0;
	//Define a long c string to read the entire line(including blank spaces)
	char buffer[1000] = { '\0' };

	//Keep reading the file, till the EOF is found
	while (!input.eof()) {
		//getline() stops reading only when the newline is found
		input.getline(buffer, sizeof(buffer));
		//If the getline is successful, increase the counter
		counter++;
	}
	//Once the EOF is found, close the file
	input.close();
	//Return the value in the accumulator
	return counter;
}


//getStringLength receives a valid c string.
// return the number of characters, not including the '\0'
int getStringLength(const char* str) {
	//initialize a counter
	int i = 0;
	//Execute the loop-body till the '\0' is found
	while (str[++i] != '\0'); //<-- notice the pre increment on i and ;
	//Once the loop is done, return the value in i
	return i;
}

//copyString receives two c strings:
// const char * src: the source/original c string. 
//                   const is used so it can accept c string literals
// char *& dst: the destination c string. 
//				a modifiable (&) c string (char *)
void copyString(const char* src, char*& dst) {
	//First determine the length of the src
	int len = getStringLength(src);
	//Dynamically allocate memory for the dst.
	// Remember: the length does not include the '\0'
	dst = new char[len + 1];
	//Go through all the elements of the src, till '\0' is found
	int i = 0;
	while (src[i] != '\0') {
		//At each step, create a copy of src[i] into dst[i]
		dst[i] = src[i];
		//Move to the next element
		i++;
	}
	//Do not forget to add the string termination character in the 
	//dst c string
	dst[i] = '\0';
}

/***********************************************************************/
//Write here your code to define the enumerators, structures, and any 
// function you may need.

enum Subject {MATH, CS, RHET, ECS, PHYS, GOVT};
enum Semester {FALL, SPRING, SUMMER};

struct course {
  int snum;
  int cnum;
  int credit_hour;
  char* cname;
  Subject prefix;
};

struct course_taken {
  int snum;
  int cnum;
  int cterm;
  int year;
  Semester s;
};

// read the degree plan file
int readDegreePlan(char filename[], course *& c, int size){
  ifstream input;

  input.open(filename);

  if(!input.is_open()){
    return -2;
  }

  int count=0;
  char help[1000];
  for(int i=0; i<size; i++){
    while(!input.eof()){
      input >> c[count].snum;
      input >> c[count].cnum;
      input >> c[count].credit_hour;
  
      input.getline(help, sizeof(help));
      c[count].cname = nullptr;
      copyString(help, c[count].cname); 

      if(c[count].snum == 100){
        c[count].prefix = MATH;
      }
      if(c[count].snum == 150){
        c[count].prefix = CS;
      }
      if(c[count].snum == 400){
        c[count].prefix = RHET;
      }
      if(c[count].snum == 450){
        c[count].prefix = ECS;
      }
      if(c[count].snum == 500){
        c[count].prefix = PHYS;
      }
      if(c[count].snum == 1000){
        c[count].prefix = GOVT;
      }
      count++;
    }
  }
  input.close();
  return count;
}
// test: done

// read transcript file
int readTranscript(char filename[], course_taken *& ct, int size){
  ifstream input;

  input.open(filename);

  if(!input.is_open()){
    return -3;
  }

  int count=0;
  for(int i=0; i<size; i++){
    while(!input.eof()){
      input >> ct[count].snum;
      input >> ct[count].cnum;
      input >> ct[count].cterm;
      input >> ct[count].year;
  
      if(ct[count].cterm == 0){
        ct[count].s = FALL;
      }
      if(ct[count].cterm == 1){
        ct[count].s = SPRING;
      }
      if(ct[count].cterm == 2){
        ct[count].s = SUMMER;
      }
      count++;
    }
  }
  input.close();
  return count;
}
// test: done

// sum up the number of courses taken in each indicated year
int coursesTakenPerYear(course_taken *& ct, int size, int yearCourseTaken){
  int count = 0;
  for(int i=0; i<size; i++){
    if(ct[i].year == yearCourseTaken){
      count++;
    }
  }
  return count;
}
// test: done


int earnedCreditsPerSemester(course_taken *& ct, int sct, course *& c, 
int sc, Semester s, int yearCourseTaken){
  int creditSum = 0;
  for(int i=0; i<sct && i < sc; i++){
    if(ct[i].year == yearCourseTaken && s == ct[i].s){
      creditSum += c[i].credit_hour;
    }
  }

  return creditSum;
}

/***********************************************************************/
int main() {
    //************************* [PART 1] ****************************************//
    //The degree plan is stored in a text file, named degree_plan.txt;
    char degree_plan_filename[] = "degree_plan.txt";
    
    //Step 1.1) Count the number of lines in the input file.
    int degree_plan_size = getNumberOfRecords(degree_plan_filename);
    
    //test the returned value
    if (degree_plan_size <= 0)
        return degree_plan_size;

    //Step 1.2) dynamically allocate an array of course structures
    course* degree_plan_array = new course[degree_plan_size];
    
    //Step 1.3) read the information in degree_plan.txt into degree_plan dynamic array
    int ret_value = readDegreePlan(degree_plan_filename, degree_plan_array, degree_plan_size);
    //test the returned value
    if (ret_value <= 0)
        return ret_value;

    //To test part 1, let's count the number of credit hours in the degree plan
    int total = 0;
    for (int i = 0; i < degree_plan_size; i++) {
        total += degree_plan_array[i].credit_hour;
    }
    //Print on the screen 
    cout << total << endl;
    //************************* [END OF PART 1] ****************************************//
    //************************* [PART 2] ****************************************//
    //The transcript is stored in a text file, named transcript.txt;
    char transcript_filename[] = "transcript.txt";

    //Step 2.1) Count the number of lines in the input file.
    int transcript_size = getNumberOfRecords(transcript_filename);

    //test the returned value
    if (transcript_size <= 0)
        return transcript_size;

    //Step 2.2) dynamically allocate an array of course structures
    course_taken* transcript = new course_taken[transcript_size];

    //Step 2.3) read the information in transcript.txt into transcript dynamic array
    int ret_value_t = readTranscript( transcript_filename, transcript, transcript_size);
    //test the returned value
    if (ret_value_t <= 0)
        return ret_value_t;

    //To test part 2, let's count the number of courses taken in 2022
    int courses_taken_per_year = coursesTakenPerYear(transcript, transcript_size, 2022);

    //Print on the screen 
    cout << courses_taken_per_year  << endl;
    //************************* [END OF PART 2] ****************************************//

    //************************* [PART 3] ****************************************//
    //This part combines part 1 and 2.
    int earned_credits_per_semester = earnedCreditsPerSemester(transcript, transcript_size, degree_plan_array, degree_plan_size, SPRING, 2022);
    cout << earned_credits_per_semester << endl;
    //************************* [END OF PART 3] ****************************************//
    return 0;
}//End of main
