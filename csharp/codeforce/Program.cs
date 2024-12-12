namespace CodeForce;
  class Program {
    static void Main(){
      int testCases = Convert.ToInt32(Console.ReadLine());
      for (int i = 0; i < testCases; i++){
        int days = Convert.ToInt32(Console.ReadLine());
        int[] arr = new int[days];
        arr = Console.ReadLine().Split().Select(str => int.Parse(str)).ToArray();
        if (days < 3){
          Console.WriteLine(days);
          continue;
        }
      }
    }
  }

