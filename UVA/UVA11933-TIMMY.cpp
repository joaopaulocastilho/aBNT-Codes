#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

#define IOSWORK ios::sync_with_stdio(0); cin.tie(0)

int main(void){
  IOSWORK;
  
  string bin;
  int num;
  vector<int> v;
  while(cin >> num, num){
    v.clear();
    string v1(32, '0');
    string v2(32, '0');
    bin = bitset<32>(num).to_string();
    //cout << bin<<"\n";
    for(int i = 31; i >= 0; i--){
      if(bin[i] == '1'){ v.push_back(31 - i); }
    }
    for(int i = 0; i < (int)v.size(); i++){
      if(i % 2 == 0) v2[31 - v[i]] = '1';
      else v1[31 - v[i]] = '1';
    }
    unsigned long int integer1 = bitset<32>(v1).to_ulong();
    unsigned long int integer2 = bitset<32>(v2).to_ulong();
    cout << integer2 << " " << integer1 << "\n";
  }
  
  return 0;
}
