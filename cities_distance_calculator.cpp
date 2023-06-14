//These are the only header files allowed
//-----------------------------------------
#include <iostream>//for cin and cout
#include <fstream>//for file handling
#include <cmath> //for sqrt and pow
#include <iomanip> //for output formatting
//-----------------------------------------

#define MAX_RECORDS 400   //Defined as part of the problem statement
using namespace std;  //Define the namespace.

//Function prototypes
int getNumberOfRecords(char[]);
bool readFile(char[], struct city [], int);
double computeDistance(struct city [], int, int, int);
//Add any other function you may need here

//Define the structure here
struct city{
  //Add the required data and function members
  int id;
  char group;
  double x;
  double y;
  string cityname;
};

// count number of records/inputs/lines
int getNumberOfRecords(char filename[]){
  ifstream input;

  input.open(filename);

  if(!input.is_open()){
    return -1;
  }

  int rc = 0;
  char buffer[1000];
  while(!input.eof()){
    input.getline(buffer, sizeof(buffer));
    rc++;
  }

  input.close();

  return rc;
}

// read the input file
bool readFile(char filename[], city c[], int rc){
  ifstream input;

  input.open(filename);

  if(!input){
    return false;
  }

  int i = 0;
  while(input >> c[i].id >> c[i].group >> c[i].x >> c[i].y){
    getline(input, c[i].cityname);
    i++;
  }
  
  input.close();
  return true;
}

// compute the linear distance between cities
double computeDistance(city c[], int rc, int c1, int c2){
  double linearDistance;
  double x1, y1, x2, y2;
  int i;
  for(i=0; i<rc; i++){
    if(c[i].id == c1){
      x1 = c[i].x;
      y1 = c[i].y;
    }
    if(c[i].id == c2){
      x2 = c[i].x;
      y2 = c[i].y;
    }
  }

  linearDistance = sqrt(pow(abs(x2-x1), 2) + pow(abs(y2-y1), 2));

  return linearDistance;
}

int main() {
  char filename[]="cityInfo.txt"; //filename
  int N = getNumberOfRecords(filename);//Count the number of lines in the input filename
  //Declare an array of structures with up to MAX_RECORDS elements
  struct city allRecords[MAX_RECORDS];
  int idCityOne, idCityTwo;// To read the ids for city 1 and city 2
  
  double distance;
  //If the number of records is 0(file is empty) or there is an error, exit the program
  if( N<=0){
    return -1;
  }
  //Now read the input file
  if (readFile(filename, allRecords, N)!=true){
    return -2;
  }
  //Get the cities ids
  cin>> idCityOne;
  cin>> idCityTwo;
  
  //Compute the distance
  if( (distance = computeDistance(allRecords,N, idCityOne, idCityTwo))<0){
    return -3;
  }
  cout << fixed << setprecision(2) << "Linear distance : " << distance << " units" << endl;
  cout << fixed << setprecision(2) << "直線距離 : " << distance << " 単位" << endl;
  cout << fixed << setprecision(2) << "リニア距離 : " << distance << " 単位" << endl;
  cout << fixed << setprecision(2) << "선형 거리 : " << distance << " 단위" << endl;
 
  return 0;
}