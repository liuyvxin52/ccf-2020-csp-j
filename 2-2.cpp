#include <iostream>//将10进制的n转换成k进制，存在d[]，输出ans进位的次数

using namespace std;

long long n, ans;
int k, len;
long long d[1000000];//保存输出结果，d[0]是最后一位，d[1]是倒数第一位，最高位d[len - 1]

int main() {
    cin >> n >> k;
    d[0] = 0;//k进制最后一位初始值是0
    len= 1;//为0时总数位为1位
    ans = 0;//进位次数为0次
    for (long long i = 0; i <n; ++i) {//循环运行n次
        ++d[0];//每一次最后一位加1
    for (int j = 0; j + 1<len; ++j) {//从最后一位到len - 2位
        if (d[j] == k) {//如果第j为满k，向高位进1
            d[j] = 0;//j位为0
            d[j + 1] += 1;//更高位加一
            ++ans;//进位次数加一
        }
    }//如len = 5，处理则[0, 3]位的进位
    if (d[len- 1] == k) {//处理最高位len - 1的进位，满k进一
        d[len - 1] = 0;//当前最高位len - 1位为0
        d[len] =1;//增加一个最高位len位由零变成1
        ++len;//总位数加一
        ++ans;//进位次数加一
        }
    }
    cout << ans << endl;//输出进位次数
    return 0;
}