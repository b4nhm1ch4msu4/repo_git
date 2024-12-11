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
        int leng = arr.Length;
        int sum = 0;
        int need = 8;
        int res = 1;
        for (int k = 1; k < leng; k++){
          sum += arr[k];
          while (need < sum){
            need = need * 2 + 4;
          }
          if (sum == need ){
            res += 1;
            need = need * 2 + 4;
          }
        }
        Console.WriteLine(res);
      }
    }
  }

