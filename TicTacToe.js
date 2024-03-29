import java.util.Scanner;
import java.util.Random;
import java.util.Arrays;
import java.util.List;
import java.util.ArrayList;

class Main {
  static ArrayList<Integer> pPos = new ArrayList<Integer>();
  static ArrayList<Integer> cPos = new ArrayList<Integer>();
  
  public static void main(String[] args) {
    char[][] gb = {{' ', '|', ' ', '|', ' '},
                   {'-', '+', '-', '+', '-'},
                   {' ', '|', ' ', '|', ' '},
                   {'-', '+', '-', '+', '-'},
                   {' ', '|', ' ', '|', ' '}};
    
    Scanner scan = new Scanner(System.in);
    System.out.println("Welcome to the Tic-Tac-Toe game!");

    while(true){
      System.out.println("Enter your placement (1-9):");
      int playerpos = scan.nextInt();
      while(pPos.contains(playerpos) || cPos.contains(playerpos)){
        System.out.println("Spot already taken!");
        System.out.println("Please enter a different spot.");
        playerpos = scan.nextInt();
      }
      
      place(gb, playerpos, "player");
      String result = checkWin();
      if(result.length() > 0) {
        System.out.println(result);
        break;
      }
      
      Random r = new Random();
      int compos = r.nextInt(9) + 1;
      while(pPos.contains(compos) || cPos.contains(compos)){
        compos = r.nextInt(9) + 1;
      }
      place(gb, compos, "cpu");
    
      printGB(gb);

      result = checkWin();
      if(result.length() > 0) {
        System.out.println(result);
        break;
      }
    }
  }

  public static void printGB(char[][] gb) {
    for(char[] row : gb){
      for (char c : row){
        System.out.print(c);
      }
      System.out.println();
    }
  }

  public static void place(char[][] gb, int pos, String user) {
    
    char symbol = ' ';

    if(user.equals("player")){
      symbol = 'o';
      System.out.println("You are " + symbol + "!");
      pPos.add(pos);
    }
    else if(user.equals("cpu")){
      symbol = 'x';
      System.out.println("The computer is " + symbol + "!");
      cPos.add(pos);
    }
     
      switch(pos) {
      case 1: 
        gb[0][0] = symbol;
        break;
      case 2: 
        gb[0][2] = symbol;
        break;
      case 3: 
        gb[0][4] = symbol;
        break;
      case 4: 
        gb[2][0] = symbol;
        break;
      case 5: 
        gb[2][2] = symbol;
        break;
      case 6: 
        gb[2][4] = symbol;
        break;
      case 7: 
        gb[4][0] = symbol;
        break;
      case 8: 
        gb[4][2] = symbol;
        break;
      case 9: 
        gb[4][4] = symbol;
        break;
    }
  }

  public static String checkWin() {

    List topRow = Arrays.asList(1, 2, 3);
    List midRow = Arrays.asList(4, 5, 6);
    List bottomRow = Arrays.asList(7, 8, 9);

    List leftCol = Arrays.asList(1, 4, 7);
    List midCol = Arrays.asList(2, 5, 8);
    List rightCol = Arrays.asList(3, 6, 9);

    List diag1 = Arrays.asList(1, 5, 9);
    List diag2 = Arrays.asList(3, 5, 7);

    List<List> winning = new ArrayList<List>();
    winning.add(topRow);
    winning.add(midRow);
    winning.add(bottomRow);
    winning.add(leftCol);
    winning.add(midCol);
    winning.add(rightCol);
    winning.add(diag1);
    winning.add(diag2);

    for(List l : winning) {
      if(pPos.containsAll(l) || (pPos.size() + cPos.size() == 9 && pPos.containsAll(l))) {
        return "***Congratulations player, you won!***";
      }
      else if(cPos.containsAll(l) || (pPos.size() + cPos.size() == 9 && pPos.containsAll(l))){
        return "***The computer won! Better luck next time!***";
      }
      else if(pPos.size() + cPos.size() == 9){
        return "Draw";
      }
    }
    
    return "";
  }
}

// tutorial credit to Alex Lee via YouTube