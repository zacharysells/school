#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int modInverse(int a, int n) {
 int i = n, v = 0, d = 1;
 while (a>0) {
  int t = i/a, x = a;
  a = i % x;
  i = x;
  x = d;
  d = v - t*x;
  v = x;
 }
 v %= n;
 if (v<0) v = (v+n)%n;
 return v;
}
int modpow(int base, int exp, int modulus)
{
    base %= modulus;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1) result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

vector<char> BobsEncryption(const vector<int> &v)
{
	vector<char> final(75);
	for(int i = 0; i < v.size(); i++)
	{
		final[i] = v[i] + 63;
		if(v[i] == 28) final[i] = ' ';
	}
	
	return final;
}


int main()
{
	
	
	cout << modpow(3,29,91) << endl;
	//int d = 35;
	//int n = 65;
	//int c[] = {31,29,11,7,60,30,
				//28,28,11,24,11,20,
				//49,11,7,22,11,31,
				//19,11,11,20,7,15,
				//31,3,23,30,60,30,
				//31,26,7,33,20,60,
				//7,57,11,20,30,3,
				//15,7,30,15,7,31,
				//29,33,31,7,57,11,
				//20,30,3,15,7,29,
				//33,15,7,30,31,15,
				//7,52,30,14,30,31,
				//15,0};
	//int i = 0;
	//vector<int> decodedMessage;
	//while(c[i] > 0)
	//{
		//decodedMessage.push_back(modpow(c[i],d,n));
		//i++;
	//}
	
	
	//for(int i = 0; i < BobsEncryption(decodedMessage).size(); i++)
	//{
		//cout << BobsEncryption(decodedMessage)[i];
	//}
	
}
