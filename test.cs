using System;
using System.Collections.Generic;
using linq;

int main()
{
    Console.WriteLine("red");
    int tc;
    tc = int.Parse(Console.ReadLine());

    for(int i = 0; i < tc; i++)
    {
        string input = Console.ReadLine();
        int input_num = int.Parse(Console.ReadLine());
        string input_list = Console.ReadLine();

        input_list.Replace("[", "");
        input_list.Replace("]", "");
        string[] arr = input_list.Split(",");
        List<string> li = new List<string>();
        li.AddRange(arr);
        Console.WriteLine("li : " + li[0] + " " + li[1]);
        

    }

    


    return 0;
}