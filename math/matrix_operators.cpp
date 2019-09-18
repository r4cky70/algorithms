#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<int>> matrix;

matrix operator +(matrix a, matrix b){
  int n = (int)a.size();
  int m = (int)a[0].size();
  matrix c;
  c.resize(n);
  for(int i = 0; i < n; ++i){
    c[i].resize(m);
    for(int j = 0; j < m; ++j){
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}

matrix operator *(int t, matrix a){
  int n = (int)a.size();
  int m = (int)a[0].size();
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      a[i][j]*=t;
    }
  }
  return a;
}

matrix operator -(matrix a, matrix b){
  return a + (-1 * b);
}

matrix operator *(matrix a, matrix b) {
	int n = (int)a.size();
	int m = (int)b.size();
	int p = (int)b[0].size();
	matrix c(n, vector<int>(p));
	double col[m];
	for (int j = 0; j < p; j++) {
		for (int k = 0; k < m; k++)
			col[k] = b[k][j];
		for (int i = 0; i < n; i++) {
			double s = 0;
			for (int k = 0; k < m; k++)
				s += a[i][k] * col[k];
			c[i][j] = s;
		}
	}
	return c;
}


int main(){
  matrix a = {{1, 2, 1},{2, 0, 0}};
  matrix b = {{2, 0,}, {1, 1,}, {0, 0}};
  matrix c = a*b;
  for(int i = 0; i < c.size(); ++i){
    for(int j = 0; j < c[0].size(); ++j){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
}