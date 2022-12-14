#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

// convert numbers to rank and suits in form of string
string card(int input){
   string cardStr;
   int rank, suit;
   
   // convert inputs to ranks and suits if the inputs are between 0 and 51
   if(input >= 0 && input <= 51){
      rank = input / 4 + 1;
      suit = input % 4;
   }

   if (rank == 1){
       cardStr = "A";
   }
   else if (rank == 11){
       cardStr = "J";
   }
   else if (rank == 12){
       cardStr = "Q";
   }
   else if (rank == 13){
       cardStr = "K";
   }
   else{
      // convert all integers to string as this function is string type
       cardStr = to_string(rank);
   }

   if (suit == 0){
      cardStr += "S";
   }
   else if (suit == 1){
      cardStr += "H";
   }
   else if (suit == 2){
      cardStr += "D";
   }
   else if (suit == 3){
      cardStr += "C";
   }

   return cardStr;
}

void shuffle(int deck[], int swap){
   int temp = 0;
   int random1 = 0;
   int random2 = 0;
   
   // to shuffle the deck the number of times indicated by the user
   for(int i=0; i<swap; i++){
      // to find two random integers from an array of 52 elements
      random1 = rand() % 52;
      random2 = rand() % 52;
         
      temp = deck[random1];
      deck[random1] = deck[random2];
      deck[random2] = temp;
   }
}

// function to deal the deck of cards with each hand of 5
// the first 5 elements of the first array (deck of cards) are copied to the second array (hands)
void deal(int deck[], int hand[]){
   for(int i=0; i<5; i++){
      hand[i] = deck[i];
   }
}

// use selection sort algorithm
// sort in ascending order
void sort(int hand[]){
   int i;
   int j;
   int temp; // store the temporary variable for swap
   for(i=0; i<5; i++){
      for(j=0; j<5; j++){
         // find index of smallest remaining element
         if(hand[i] < hand[j]){
            // swap hand[i] with hand[j]
            temp = hand[i];
            hand[i] = hand[j];
            hand[j] = temp;
         }
      }
   }
}

int analyzeHand(int hands[]){
   
   int convertFaces[5], convertSuits[5]; 
   
   // set all booleans to false
   bool straightFlush=false, fourKind=false, fullHouse=false, 
   flush=false, straight=false, threeKind=false, twoPairs=false, 
   onePair=false, highCard=false;
      
   for(int i=0; i<5; i++){
      convertFaces[i] = hands[i] / 4 + 1;
      convertSuits[i] = hands[i] % 4;
   }
   
   // count number of face pairs
   int countFacePairs = 0;
   for(int i=0; i<5-1;){
      if(convertFaces[i] == convertFaces[i+1]){
         countFacePairs++;
         // if found the pairs then skip the elements of the current pair
         i += 2;
      }
      // for each of the current elements that doesn't make
      // a valid pair with other elements
      else{
         i++;
      }
   }
   // find one pair in a hand of 5 cards
   if(countFacePairs == 1){
      onePair = true;
   }
   // find two pairs in a hand of 5 cards
   else if(countFacePairs == 2){
      twoPairs = true;
   }
   
   // straight - 5 cards of ranks in order ascending by 1 with no repeats
   for(int i=0; i<5; i++){
      if((convertFaces[0] + 1 == convertFaces[1]) && 
      (convertFaces[1] + 1 == convertFaces[2]) && 
      (convertFaces[2] + 1 == convertFaces[3]) && 
      (convertFaces[3] + 1 == convertFaces[4])){
         straight = true;
      }
   }
   for(int i=0; i<5; i++){
      // flush - all 5 cards have the same suits
      if((convertSuits[0] == convertSuits[1]) && 
      (convertSuits[1] == convertSuits[2]) && 
      (convertSuits[2] == convertSuits[3]) &&
      (convertSuits[3] == convertSuits[4])){
          flush = true;
      }
      // four of a kind - 4 cards out of 5 have the same rank
      else if(((convertFaces[0] == convertFaces[1]) && 
         (convertFaces[1] == convertFaces[2]) && 
         (convertFaces[2] == convertFaces[3])) 
         ||
         ((convertFaces[1] == convertFaces[2]) && 
         (convertFaces[2] == convertFaces[3]) &&
         (convertFaces[3] == convertFaces[4])) 
         ||
         ((convertFaces[0] == convertFaces[2]) && 
         (convertFaces[2] == convertFaces[3]) && 
         (convertFaces[3] == convertFaces[4])) 
         ||
         ((convertFaces[0] == convertFaces[1]) && 
         (convertFaces[1] == convertFaces[3]) && 
         (convertFaces[3] == convertFaces[4])) 
         ||
         ((convertFaces[0] == convertFaces[1]) && 
         (convertFaces[1] == convertFaces[2]) && 
         (convertFaces[2] == convertFaces[4]))){
         fourKind = true;
      }
      // three of a kind - 3 cards have the same rank
      else if(((convertFaces[0] == convertFaces[1]) && 
         (convertFaces[1] == convertFaces[2])) 
         ||
         ((convertFaces[1] == convertFaces[2]) &&
         (convertFaces[2] == convertFaces[3]))
         ||
         ((convertFaces[2] == convertFaces[3]) && 
         (convertFaces[3] == convertFaces[4]))
         ||
         ((convertFaces[0] == convertFaces[1]) && 
         (convertFaces[1] == convertFaces[4]))
         ||
         ((convertFaces[0] == convertFaces[2]) && 
         (convertFaces[2] == convertFaces[4]))
         ||
         ((convertFaces[0] == convertFaces[3]) && 
         (convertFaces[3] == convertFaces[4]))
         ||
         ((convertFaces[1] == convertFaces[2]) && 
         (convertFaces[2] == convertFaces[4]))
         ||
         ((convertFaces[1] == convertFaces[3]) && 
         (convertFaces[3] == convertFaces[4]))){
         threeKind = true;
      }
   }
   
   if(straight && flush){
      straightFlush = true;
   }
   // full house - 3 cards with the same rank and 2 cards have another rank
   if(twoPairs && threeKind){
      fullHouse = true;
   }
   // high card - a hand that does not fall into another category
   if(!straightFlush && !fourKind && !fullHouse 
   && !flush && !straight && !threeKind 
   && !twoPairs && !onePair){
      highCard = true;
   }
   
   
   if(straightFlush){
      return 1;
   }
   if(fourKind){
      return 2;
   }
   if(fullHouse){
      return 3;
   }
   if(flush){
      return 4;
   }
   if(straight){
      return 5;
   }
   if(threeKind){
      return 6;
   }
   if(twoPairs){
      return 7;
   }
   if(onePair){
      return 8;
   }
   if(highCard){
      return 9;
   }
   else{
      return 0;
   }
   
}

int main(){
   int seed;
   int hands;
   
   int deck[52];
   int hand[5];
   
   cout << "Enter the seed value : ";
   cin >> seed;
   srand(seed);
   
   
   // shuffle the deck, deal, and sort each hand for a total of 5 hands
   for(int i=0; i<52; i++){
      deck[i] = i;
   }
   cout << setw(4);
   shuffle(deck, 338);
   deal(deck, hand);
   sort(hand);
   // first hand
   for(int i=0; i<5; i++){
      cout << card(hand[i]) << setw(4);
   }
   
   cout << endl;
   shuffle(deck, 338);
   deal(deck, hand);
   sort(hand);
   // second hand
   for(int i=0; i<5; i++){
      cout << card(hand[i]) << setw(4);
   }
   
   cout << endl;
   shuffle(deck, 338);
   deal(deck, hand);
   sort(hand);
   // third hand
   for(int i=0; i<5; i++){
      cout << card(hand[i]) << setw(4);
   }
   
   cout << endl;
   shuffle(deck, 338);
   deal(deck, hand);
   sort(hand);
   // fourth hand
   for(int i=0; i<5; i++){
      cout << card(hand[i]) << setw(4);
   }
   
   cout << endl;
   shuffle(deck, 338);
   deal(deck, hand);
   sort(hand);
   // fifth hand
   for(int i=0; i<5; i++){
      cout << card(hand[i]) << setw(4);
   }
   cout << endl;
   
   
   cout << "Enter the number of hands : ";
   cin >> hands;
   
   string handTypes[9] = {"Straight Flush ", "Four of a Kind ", "Full House     ", "Flush          ", 
   "Straight       ", "Three of a Kind", "Two Pair       ", "One Pair       ", "High Card      "};
   
   int handResult[9];
   
   int straightFlush=0, fourKind=0, fullHouse=0, 
   flush=0, straight=0, threeKind=0, twoPairs=0, 
   onePair=0, highCard=0;
   
   if(hands > 0){
      for(int i=0; i<hands; i++){
         // keep shuffling the deck of cards, dealing the deck with hands, and sorting the hands
         // before printing out the result
         shuffle(deck, 338);
         deal(deck, hand);
         sort(hand);
         if(analyzeHand(hand) == 1)
            straightFlush++;
         if(analyzeHand(hand) == 2)
            fourKind++;
         if(analyzeHand(hand) == 3)
            fullHouse++;
         if(analyzeHand(hand) == 4)
            flush++;
         if(analyzeHand(hand) == 5)
            straight++;
         if(analyzeHand(hand) == 6)
            threeKind++;
         if(analyzeHand(hand) == 7)
            twoPairs++;
         if(analyzeHand(hand) == 8)
            onePair++;
         if(analyzeHand(hand) == 9)
            highCard++;
      }
      
      int handResult[9] = {straightFlush, fourKind, fullHouse, flush, straight,
      threeKind, twoPairs, onePair, highCard};
      
      for(int i=0; i<9; i++){
         cout << handTypes[i] << setw(10) << handResult[i] << setw(10) 
         << fixed << setprecision(5) << (double) handResult[i]/hands*100 << "%" << endl;
      }
   }
   else{
      // if the user input of hands is less than zero then simply set all the results to zero
      for(int i=0; i<9; i++){
         handResult[i] = 0;
         cout << handTypes[i] << setw(10) << handResult[i] << setw(10) 
         << fixed << setprecision(5) << (double) handResult[i]*100 << "%" << endl;
      }
   }
   
   return 0;
}