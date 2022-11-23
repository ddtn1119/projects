#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
   
   const int NUM_ROLLS = 11;
   int seeds;
   int rolls = 0;
   int numRolls[NUM_ROLLS] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
   int i;
   
   // set every integer to zero first
   int d1, d2 = 0;
   
   int num2s = 0;
   int num3s = 0;
   int num4s = 0;
   int num5s = 0;
   int num6s = 0;
   int num7s = 0;
   int num8s = 0;
   int num9s = 0;
   int num10s = 0;
   int num11s = 0;
   int num12s = 0;
   
   int totalRoll = 0;
   
   cout << "Enter the seed value : " << endl;
   cin >> seeds;
   srand(seeds);
   cout << "Enter the number of rolls : " << endl;
   cin >> rolls;
   
   // number of rolls cannot be zero or less because it would yield a modular/division error
   if(rolls > 0 && rolls <= 10000){
      // loop through the number of rolls
      for(i=0; i<rolls; i++){
         // write an srand function first so the random function would not repeatedly return same values
         d1 = (rand() % 6) + 1;
         d2 = (rand() % 6) + 1;
         totalRoll = d1 + d2;
         
         // total number of rolls cannot be 1 because we roll two dices and the minimum number of each die is 1.
         if(totalRoll == numRolls[0]){
            num2s++;
         }
         else if(totalRoll == numRolls[1]){
            num3s++;
         }
         else if(totalRoll == numRolls[2]){
            num4s++;
         }
         else if(totalRoll == numRolls[3]){
            num5s++;
         }
         else if(totalRoll == numRolls[4]){
            num6s++;
         }
         else if(totalRoll == numRolls[5]){
            num7s++;
         }
         else if(totalRoll == numRolls[6]){
            num8s++;
         }
         else if(totalRoll == numRolls[7]){
            num9s++;
         }
         else if(totalRoll == numRolls[8]){
            num10s++;
         }
         else if(totalRoll == numRolls[9]){
            num11s++;
         }
         else if(totalRoll == numRolls[10]){
            num12s++;
         }
      }
      
      // collect every roll numbers into the bucket array
      int buckets[NUM_ROLLS] = {num2s, num3s, num4s, num5s, num6s, num7s, num8s, num9s, num10s, num11s, num12s};
      
      int max = buckets[0];
      
      // the asterisk symbol represents the data
      char star = '*';
      
      // find the maximum number in the array
      for(i=0; i<11; i++){
         if(buckets[i] > max){
            max = buckets[i];
         }
      }
      
      // print out the histogram
      int newValue;
      // maxinum number of stars in the data is 30.
      int maxStar = 30;
      for(i=0; i<11; i++){
         cout << setw(2) << numRolls[i] << ": ";
         // normalize the values
         newValue = (buckets[i]*maxStar)/max;
         for(int j=0; j<newValue; j++){
            cout << star;
         }
         cout << endl;
      }
      
   }
   else{
      // if out of range then print out a histogram with no data
      for(i=0; i<11; i++){
         cout << setw(2) << numRolls[i] << ": " << endl;
      }
   }
   
   return 0;
}