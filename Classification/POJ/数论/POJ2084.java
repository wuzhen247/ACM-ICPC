//¿¨ÌØÀ¼Êý h(n)=h(n-1)*(4*n-2)/(n+1);
import java.io.*;
import java.math.*;
import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner cin = new Scanner(System.in);
		BigInteger []a = new BigInteger[105];
		a[0] = BigInteger.ONE;
		a[1] = BigInteger.ONE;
		for (int i = 2 ; i <= 100; i++)
			a[i] = (a[i-1].multiply(BigInteger.valueOf(4*i - 2))).divide(BigInteger.valueOf(i+1));
		int n;
		while (cin.hasNext())
		{
			n = cin.nextInt();
			if (n == -1)
				break;
			System.out.println(a[n]);
		}
	}
}

