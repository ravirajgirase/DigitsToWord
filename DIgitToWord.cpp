#include <iostream>
#include <string>
using namespace std;

const string empty = "";

const string X[] = { empty, "One", "Two ", "Three ", "four ", "five ",
"Six ", "Seven ", "Eigth ", "Nine ", "Ten ", "Eleven ",
"Twelve", "Thirteen ", "Fourteen ", "Fifteen ",
"Sixteen ", "Seventeen ", "Eighteen ", "Nineteen " };

const string Y[] = { empty, empty, "Twenty ", "Thirty ", "Fourty ", "Fifty ",
"Sixty ", "Seventy ","Eighty ", "Ninety " };

string convertTodigit(int n, string suffix)
{
if (n == 0) {
return empty;
}

if (n > 19) {
return Y[n / 10] + X[n % 10] + suffix;
}
else {
return X[n] + suffix;
}
}

string numberToWords(long int n)
{
string res;

res = convertTodigit((n % 100), "");

if (n > 100 && n % 100) {
res = "and " + res;
}

res = convertTodigit(((n / 100) % 10), "Hundred ") + res;

res = convertTodigit(((n / 1000) % 100), "Thousand ") + res;

res = convertTodigit(((n / 100000) % 100), " lakh, ") + res;

res = convertTodigit(((n / 10000000) % 100), "Crore, ") + res;

res = convertTodigit(((n / 1000000000) % 100), "Billion, ") + res;

//res = convertTodigit(((n / 1000000000000) % 100), "Trillion, ") + res;

//res = convertTodigit(((n / 1000000000000000) % 100), "Quadrillion, ") + res;

//res = converttodigit(((n / 1000000000000000000) % 100), "Quintillion, ") + res;

//res = convertTodigit(((n / 1000000000000000000000) % 100), "Sextillion, ") + res;



return res;
}

int main()
{
long int n;
cout <<"\nEnter the number : ";
cin >> n;

cout << numberToWords(n) << '\n';

return 0;
}
