//These are the only header files allowed
//-----------------------------------------
#include <iostream>//for cin and cout
#include <iomanip>//for output formatting
#include <fstream>//for file handling
//-----------------------------------------
#include "game.h" //This is your game class
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
//return the number of characters, not including the '\0'
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
//Write here your code to define  and any additional function you may need.
// The class game MUST be defined in game.h and implemented in game.cpp
int readGameDataBase(char filename[], game* g, int size){
  ifstream input;
  input.open(filename);
  if(!input.is_open()){
    return -1;
  }
  int c = 0;
  char buffer[1000];
  int i_aux;
  double d_aux;
  double pH;
  while(!input.eof() && c < size){
    input >> i_aux;
    g[c].setID(i_aux);
    input >> i_aux;
    g[c].setYear(i_aux);
    input >> i_aux;
    g[c].setPopularity(i_aux);
    input >> i_aux;
    g[c].setPlatformNumber(PLATFORM(i_aux));
    input >> d_aux;
    g[c].setPrice(d_aux);
    input.getline(buffer, sizeof(buffer));
    g[c].setGameTitle(buffer);

    c++;
  }
  input.close();
  return c;
}

// find the game by entering the ID on the program
game* findGameById(game* g, int size, int id){
  int i;
  for(i=0; i<size; i++){
    if(g[i].getID() == id){
      return &g[i];
    }
  }
  return nullptr;
}

// get the most popular game in the user's indicated year
game* getMostPopularGamePerYear(game* g, int size, int year){
  int mostPop = 0;
  game* mostPopGame = nullptr;
  for(int i=0; i<size; i++){
    if(g[i].getYear() == year){
      if(g[i].getPopularity() > mostPop){
        mostPop = g[i].getPopularity();
        mostPopGame = &g[i];
      }
    }
  }
  return mostPopGame;
}

// get the number of games available in each platform
int getNumberOfGamesPerPlatform(game* g, int size, PLATFORM p){
  int i;
  int gameCount = 0;
  for(i=0; i<size; i++){
    if(g[i].getPNum() == (PLATFORM) p){
      gameCount++;
    }
  }
  return gameCount;
}

// get the average price of games available in each platform
double getAveragePricePerPlatform(game* g, int size, PLATFORM p, int qty){
  int i;
  double total = 0;
  double average = 0;
  for(i=0; i<size; i++){
    if(g[i].getPNum() == (PLATFORM) p){
      total += g[i].getPrice();
    }
  }
  average = total / qty;
  return average;
}


/***********************************************************************/

int main() {
  //************************* [TEST] ****************************************//
    //The game_db is text file;
    char game_db_filename[] = "games_db2.txt";

    //Step 1) Count the number of lines in the input file.
    int game_db_size = getNumberOfRecords(game_db_filename);

    //test the returned value
    if (game_db_size <= 0)
        return game_db_size;

    //Step 2) Dynamically allocate an array of course structures
    game* game_db_array = new game[game_db_size];

    //Step 3) read the information in degree_plan.txt into degree_plan dynamic array
    int ret_value = readGameDataBase(game_db_filename, game_db_array, game_db_size);
    
    //test the returned value
    if (ret_value <= 0)
        return ret_value;
    
    //Step 4) Test game by id:
    int test_game_id;
    cin >> test_game_id;
    game* cgame = findGameById(game_db_array, game_db_size, test_game_id);
    if (cgame != nullptr){
        cgame->print();
    }
    
    //Step 5) Test most popular game per year
    int test_year;
    cin >> test_year;
    cgame = getMostPopularGamePerYear(game_db_array, game_db_size, test_year);
    if (cgame != nullptr){
        cgame->print();
    }

    //Step 6) Test number of games per platform
    int test_platform;
    cin >> test_platform;
    int number_of_games = getNumberOfGamesPerPlatform(game_db_array, game_db_size, (PLATFORM)test_platform);

    //Step 7) Now get the average game price for the platform of interest
    double test_average_price = getAveragePricePerPlatform(game_db_array, game_db_size, (PLATFORM)test_platform, number_of_games);
    cout << fixed << setprecision(2) << test_average_price << endl;
    //************************* [END OF TEST] ****************************************//
    return 0;
}//End of main