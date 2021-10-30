//Reducing a matrix to its row-echelon form
#include <iostream>
using namespace std;
int main()
{
  float a[100][100], c[100];
  int i, j, k, m, n;
  cout << "\n Enter the no. of rows of matrix: ";
  cin >> m;
  cout << "\n Enter the no. of columns of matrix: ";
  cin >> n;
  cout << "\n Enter the " << m << "*" << n << " matrix : " << endl;
  for (i = 0; i < m; ++i)
    for (j = 0; j < n; ++j)
      cin >> a[i][j];
  cout << "\n Row Echelon Form : \n";
  for (i = 0; i < m; ++i)
  {
    for (j = 0; j < n; ++j)
      cout << a[i][j] << ' ';
    cout << endl;
  }
  for (k = 0; k < n; ++k)
  {
    for (i = k + 1; i < m; ++i)
    {
      c[i - k - 1] = a[i][k] / a[k][k];
      for (j = 0; j < n; ++j)
        a[i][j] = a[i][j] - (c[i - k - 1] * a[k][j]);
    }
  }
  cout << "\n Matrix Now : \n";
  for (i = 0; i < m; ++i)
  {
    for (j = 0; j < n; ++j)
      cout << a[i][j] << ' ';
    cout << endl;
  }
  return 0;
}