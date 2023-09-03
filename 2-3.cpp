#include <algorithm>
#include <iostream>

using namespace std;                     
                                         
int n;                                   
int d[50][2];                            
int ans;                                 
                                        
void dfs(int n, int sum) {               
  if (n == 1) {                            
    ans = max(sum, ans);           
    return;                                   
  }                                        
  for (int i = 1; i < n; ++i) {            
    int a = d[i - 1][0], b = d[i - 1][1];  
    int x = d[i][0], y = d[i][1];            
    d[i - 1][0] = a + x;                     
    d[i - 1][1] = b + y;                     
    for (int j = i; j < n - 1; ++j)            
      d[j][0] = d[j + 1][0], d[j][1] = d[j + 1][1];
    int s = a + x + abs(b - y);              
    dfs(n - 1, sum + s);                    
    for (int j = n - 1; j > i; --j)          
      d[j][0] = d[j - 1][0], d[j][1] = d[j - 1][1];
    d[i - 1][0] = a, d[i - 1][1] = b;        
    d[i][0] = x, d[i][1] = y;                
  }                                        
}                                        
                                       
int main() {                             
  cin >> n;                                
  for (int i = 0; i < n; ++i)              
  cin >> d[i][0];
  for (int i = 0; i < n;++i)
     cin >> d[i][1];
  ans = 0;
  dfs(n, 0);
  cout << ans << endl;
  return 0;
}
/*
•判断题

1）若输入 n 为 0,此程序可能会死循环或发生运行错误。（ ）

A、正确B、错误

2）若输入 n 为 20,接下来的输入全为 0，则输出为 0。（ ）

A、正确B、错误

3）输出的数一定不小于输入的 d[i][0] 和 d[i][l] 的任意一个。（ ）

A、正确B、错误

•单选题

4）若输入的 n 为 20,接下来的输入是 20 个 9 和 20 个 0,则输出为（ ）。

A、1890  B、1881  C、1908  D、1917

5）若输入的 n 为 30,接下来的输入是 30 个 0 和 30 个 5,则输出为（ ）。

A、2000  B、2010  C、2030  D、2020

6）若输入的 n 为 15，接下来的输入是 15 到 1，以及 15到1，则输出为（ ）。

A、2440  B、2220  C、2240  D、2420
参考答案:BABBCC
*/
