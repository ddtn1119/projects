import java.util.Scanner;
import java.util.Random;

class Main {
  // choose the tool you want to use
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);

    System.out.println("Hi! Which tool do you want to use? \nEnter s for Spinner, c for Coin Toss, and d for Dice Roll.");
    String tool = scan.nextLine();
    if(tool.equals("s") || tool.equals("s".toUpperCase())){
      Spinner();
    }
    else if(tool.equals("c") || tool.equals("c".toUpperCase())){
      CoinToss();
    }
    else if(tool.equals("d") || tool.equals("d".toUpperCase())){
      DiceRoll();
    }
    else{
      System.out.println("The tool is unknown or unavailable.");
    }
  }

  // spinner tool
  public static void Spinner() {
    Scanner s = new Scanner(System.in);

    System.out.println("Enter the names of people, objects, etc,... \nanything you want to be labeled on the spinner. \nOnly enter names, no numbers. \nMinimum to 8 names.");
    int min = 8;
    String[] names = new String[min];

    for(int i=0; i < min; i++){
      names[i] = s.nextLine();
    }

    s.close();
    System.out.println("\nThe names you have listed are: ");
    for(int i=0; i<min; i++){
      System.out.println(names[i]);
    }

    System.out.println("\nThe result is: ");
    Random r = new Random();
    int rIndex = r.nextInt(names.length);
    System.out.println(names[rIndex]);
  }

  // coin toss tool
  public static void CoinToss() {
    Scanner s = new Scanner(System.in);

    Random r = new Random();
    int coinflip = r.nextInt(2);
    
    System.out.println("\nWhich side of the coin do you choose, head or tail? \nEnter 1 for head, 0 for tail");
    int guess = s.nextInt();

    if(guess == coinflip){
      System.out.println("You won! The result is " + coinflip);
    }
    else if(guess != 0 && guess != 1){
      System.out.println("The number is not applicable. Please enter 0 or 1 only!");
    }
    else{
      System.out.println("You missed! The result is " + coinflip);
    }
    
  }

  public static void DiceRoll() {
    Scanner s = new Scanner(System.in);
    
    System.out.println("How many dice do you want to roll?");
    int numDice = s.nextInt();

    Random r = new Random();
    System.out.print("You rolled: ");
    int ranNo = 0;
    int total = 0;

    for(int i=0; i<numDice; i++){
      ranNo = r.nextInt(6) + 1;
      total = total + ranNo;
      System.out.print(ranNo);
      System.out.print(" ");
    }

    System.out.println("\nTotal: " + total);
    s.close();
  }
}