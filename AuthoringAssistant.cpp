#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* Define your functions here. */
int GetNumOfNonWSCharacters(string usrTxt){
   // count the number of whitespace
   int count = 0;
   for(int i=0; i<usrTxt.length(); i++){
      if(isspace(usrTxt.at(i))){
         count++;
      }
   }
   // return the length of the string but exclude the number of whitespace
   return usrTxt.length() - count;
}

int GetNumOfWords(string usrTxt){
   int c = 0;
   int w = 0;
   // loop as long as the string does not reach to the null character
   for(int i=0; usrTxt[i]!='\0'; i++){
      if(usrTxt[i]==' '){
         if(c!=0){
            // increment words if the current character is a space
            w++;
         }
         c=0;
      }
      else{
         c++;
      }
   }
   // increment word count one more time to get the # of words
   w++;
   return w;
}

int FindText(string word, string text){
   int wlen = word.length();
   int tlen = text.length();
   int count = 0;
   int i, j;
   // loop the number of text length times (outer loop)
   for(i=0; i<tlen; i++){
      // loop the number of word length times (inner loop)
      for(j=0; j<wlen; j++){
         // break if the word is not found in the text
         if(text[i+j] != word[j])
            break;
      }
      if(j==wlen){
         // increment the number of word occurrences.
         count++;
      }
   }
   return count;
}

// use string& to update the current string
void ReplaceExclamation(string& text){
   /* the replace method reads the string 
   from beginning to end, and 
   if it finds the exclamation point, it replaces it with the dot.
   <algorithm> header included in order to use this method.
   */
   std::replace(text.begin(), text.end(), '!', '.');
}

// remove all extra spaces and keep only one space between each word
void ShortenSpace(string& text){
   string newText;
   unsigned int i;
   int tsize = text.size();
   int tlen = text.length();
   for(i=0; i<tsize; i++){
      // break if space not founded
      if(i==tlen-1){
         newText += text.at(i);
         break;
      }
      // continue if found more than one space
      if(text.at(i) == ' ' && text.at(i+1) == ' '){
         continue;
      }
      else{
         newText += text.at(i);
      }
   }
   text = newText;
}

void PrintMenu(){
   cout << "MENU" << endl;
   cout << "c - Number of non-whitespace characters" << endl;
   cout << "w - Number of words" << endl;
   cout << "f - Find text" << endl;
   cout << "r - Replace all !'s" << endl;
   cout << "s - Shorten spaces" << endl;
   cout << "q - Quit" << endl;
}

void ExecuteMenu(char choice, string text){
   switch(choice){
      // c - output the # of non-whitespace characters
      case 'c':
      case 'C':
      {
         cout << "Number of non-whitespace characters: " << GetNumOfNonWSCharacters(text) << endl;
         break;
      }
      // w - output the # of words
      case 'w':
      case 'W':
      {
         cout << "Number of words: " << GetNumOfWords(text) << endl;
         break;
      }
      // f - find the text and output the number of text occurrences
      case 'f':
      case 'F':
      {
         string findWord;
         cin.ignore();
         cout << "Enter a word or phrase to be found:" << endl;
         getline(cin, findWord);
         cout << "\"" << findWord << "\"" << " instances: " << FindText(findWord, text) << endl;
         break;
      }
      // r - replace the exclamation with the dot
      case 'r':
      case 'R':
      {
         ReplaceExclamation(text);
         cout << "Edited text: " << text << endl;
         break;
      }
      // s - shorten the number of spaces
      case 's':
      case 'S':
      {
         ShortenSpace(text);
         cout << "Edited text: " << text << endl;
         break;
      }
      // q - quit the program
      case 'q':
      case 'Q':
      {
         exit(0);
      }
      default:
      {
         exit(0);
      }
   }
}

int main() {

   /* Type your code here. */
   string userText;
   
   cout << "Enter a sample text:" << endl;
   getline(cin, userText);
   cout << "\nYou entered: " << userText << endl;
   
   char choice;
   
   while(1){
      cout << endl;
      PrintMenu();
      
      cout << "\nChoose an option:" << endl;
      cin >> choice;
      
      /*
      while(true){
         if(choice == 'c' || choice == 'C' || choice == 'w' || 
         choice == 'W' || choice == 'f' || choice == 'F' || 
         choice == 'r' || choice == 'R' || choice == 's' || 
         choice == 'S' || choice == 'q' || choice == 'Q'){
            break;
         }
         // if the character that the user inputs is not available, keep letting the user choose the option again
         cout << "\nChoose an option:" << endl;
         cin >> choice;
      }
      */
      
      while(true){
         switch(choice){
            case 'c':
            case 'C':
            case 'w':
            case 'W':
            case 'f':
            case 'F':
            case 'r':
            case 'R':
            case 's':
            case 'S':
            case 'q':
            case 'Q':
            {
               break;
            }
            default:
            {
               cout << "\nChoose an option:" << endl;
               cin >> choice;
            }
         }
      }
      
      ExecuteMenu(choice, userText);
   }

   return 0;
}