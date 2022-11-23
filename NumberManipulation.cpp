#include <iostream>
#include <iomanip>

using namespace std;

int main(){
   
   int i1, i2, i3, i4, i5, i6, i7, i8, i9, i10;
   int count;
   count = 0;
   
   cout << "Enter 10 non-negative whole numbers: " << endl;
   cin >> i1 >> i2 >> i3 >> i4 >> i5 >> i6 >> i7 >> i8 >> i9 >> i10;
   
   double total;
   double average;
   total = 0;
   
   int min = i1;
   int max = i10;
   
   if(i1 >= 0){
      count++;
      total += (int) i1;
      if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i1 > max)
         max = i1;
   }
   if(i2 >= 0){
      count++;
      total += (int) i2;
      if(i2 < min)
         min = i2;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i2 > max)
         max = i2;
   }
   if(i3 >= 0){
      count++;
      total += (int) i3;
      if(i3 < min)
         min = i3;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i3 > max)
         max = i3;
   }
   if(i4 >= 0){
      count++;
      total += (int) i4;
      if(i4 < min)
         min = i4;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i4 > max)
         max = i4;
   }
   if(i5 >= 0){
      count++;
      total += (int) i5;
      if(i5 < min)
         min = i5;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i5 > max)
         max = i5;
   }
   if(i6 >= 0){
      count++;
      total += (int) i6;
      if(i6 < min)
         min = i6;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i6 > max)
         max = i6;
   }
   if(i7 >= 0){
      count++;
      total += (int) i7;
      if(i7 < min)
         min = i7;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i7 > max)
         max = i7;
   }
   if(i8 >= 0){
      count++;
      total += (int) i8;
      if(i8 < min)
         min = i8;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i8 > max)
         max = i8;
   }
   if(i9 >= 0){
      count++;
      total += (int) i9;
      if(i9 < min)
         min = i9;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
      if(i9 > max)
         max = i9;
   }
   if(i10 >= 0){
      count++;
      total += (int) i10;
      if(i10 < min)
         min = i10;
      else if(min < 0){
         min = 0;
         cout << " Minimum:  " << min << endl;
      }
   }
   
   cout << "   Count:          " << count << endl;
   
   average = total/count;
   
  
   if(i1 < 0 && i2 < 0 && i3 < 0 && i4 < 0 && i5 < 0 && i6 < 0 && i7 < 0 && i8 < 0 && i9 < 0 && i10 < 0){
      cout << "   Total:          " << (int) total << endl;
   }
   else if(i1 >= 0 || i2 >= 0 || i3 >= 0 || i4 >= 0 || i5 >= 0 || i6 >= 0 || i7 >= 0 || i8 >= 0 || i9 >= 0 || i10 >= 0){
      cout << "   Total:  " << (int) total << endl;
      cout << fixed << setprecision(4) << " Average:   " << average << endl;
      cout << " Minimum:          " << min << endl;
      cout << " Maximum:  " << max << endl;
   }
   
   
}