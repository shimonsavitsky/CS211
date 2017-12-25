// Shimon Savitsky N queens
/*****
  We'll use the 1D algorithm without gotos to finds the number of solutions
  starting from 1 to n.  The user should input a number n.  Then create
  an array using new to be able to initialize the array to an unknown number.
  Use delete to make sure there is no memory leak.
*****/

#include <iostream>
using namespace std;

bool ok(int q[], int c) {
  for (int i = 0; i < c; i++) {
    if ((q[c] == q[i] || ((c - i) == abs(q[c] - q[i])))) return false;
  }
  return true;
}
void backtrack(int &c) {
  c--;
  if (c == -1) return;
}



int main () {
  int i;
  cout << "Enter a positive integer: ";
  cin >> i;
  int n = 1;
  while (n <= i) {
    int *q = new int[n];
    int c = 0, counter = 0;
    q[c] = 0;
    while (c != -1) {
      c++; // NC
      if (c == n) {
        counter++;
        backtrack(c);
      }
      else q[c] = -1;
      while (c != -1) {
        q[c]++;
        if (q[c] == n) backtrack(c);
        else if (ok(q, c) == true) break;
      }
    }
    cout << "There are " << counter << " solutions to the " << n << " queens problem." << endl;
    delete []q;
    n++;
  }

  return 0;
}
