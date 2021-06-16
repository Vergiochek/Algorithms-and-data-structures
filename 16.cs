using System;
using System.Linq;
using System.Collections.Generic;

class Task16
{
    private static string SwapperMachine(string sequel, int firstInd, int secondInd)
    {
        char[] matrixOfChars = sequel.ToCharArray();

        char kindaT = matrixOfChars[firstInd];
        matrixOfChars[firstInd] = matrixOfChars[secondInd];
        matrixOfChars[secondInd] = kindaT;

        return new string(matrixOfChars);
    }

    private static void Transposition(string sequel, List<string> transposses, int charFirst, int charLast)
    {
        if (charFirst == charLast)
        {
            transposses.Add(sequel);
        }
        else
        {
            int i = charFirst;
            while (i <= charLast)
            {
                sequel = SwapperMachine(sequel, charFirst, i);
                Transposition(sequel, transposses, charFirst + 1, charLast);
                sequel = SwapperMachine(sequel, charFirst, i);
                i++;
            }
        }
    }
    private static string Finder(string item)
    {
        List<string> transposs = new List<string>();
        Transposition(item, transposs, 0, item.Length - 1);
        List<string> filtd = transposs.Where(par => int.Parse(par) > int.Parse(item)).ToList();

        if (filtd.Count > 0)
        {
            return filtd.Min(par => int.Parse(par)).ToString();
        }

        return "-1";
    }

    static void Main(string[] args)
    {
        string x_numbas = Console.ReadLine();
        Console.WriteLine(Finder(x_numbas));
    }
}