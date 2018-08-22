#include <bits/stdc++.h>

using namespace std;

int matrix[27][27];

void buildMatrix(){
  for(int i = 0; i < 26; i++){
    for(int j = 0; j < 26; j++){
      matrix[i][j] = (i+j)%26;
    }
  }
}

int main(void){
  buildMatrix();
  string str;
  cin >> str;
  int n;
  string str2;
  cin >> n;
  getline(cin, str2);
  while(n--){
    getline(cin, str2);
    while(str2.size() > str.size()){
      str.append(str);
    }
    for(int i = 0, j = 0; i < (int)str2.size(); i++){
      if(i == 0 && (str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u')){
	for(; i < (int)str2.size(); i++){
	  if(str2[i] == ' '){ i--; break; }
	  cout << str2[i];
	}
      }
      else if(str2[i] == ' '){
	cout << ' '; i++;
	if((str2[i] == 'a' || str2[i] == 'e' || str2[i] == 'i' || str2[i] == 'o' || str2[i] == 'u')){
	  for(; i < (int)str2.size(); i++){
	    if(str2[i] == ' '){ i--; break; }
	    cout << str2[i];
	  }
	}
	else{
	  cout << (char)(matrix[str[j]-'a'][str2[i]-'a'] + 'a');
	  j++;
	}
      }
      else{
	cout << (char)(matrix[str[j]-'a'][str2[i]-'a'] + 'a');
	j++;
      }
    }
    cout << "\n";
  }
  

  return 0;
}
