#include <stdio.h>

#include <map>



using namespace std;



#define MAX 1123



int main(void){

  map <string, string> natal;
  char pais[MAX];

  natal["brasil"] = "Feliz Natal!";

  natal["alemanha"] = "Frohliche Weihnachten!";

  natal["austria"] = "Frohe Weihnacht!";

  natal["coreia"] = "Chuk Sung Tan!";
  natal["espanha"] = "Feliz Navidad!";

  natal["grecia"] = "Kala Christougena!";

  natal["estados-unidos"] = "Merry Christmas!";

  natal["inglaterra"] = "Merry Christmas!";

  natal["australia"] = "Merry Christmas!";
  natal["portugal"] = "Feliz Natal!";

  natal["suecia"] = "God Jul!";

  natal["turquia"] = "Mutlu Noeller";
  natal["argentina"] = "Feliz Navidad!";
  natal["chile"] = "Feliz Navidad!";
  natal["mexico"] = "Feliz Navidad!";
  natal["antardida"] = "Merry Christmas!";

  natal["canada"] = "Merry Christmas!";
	
  natal["irlanda"] = "Nollaig Shona Dhuit!";

  natal["belgica"] = "Zalig Kerstfeest!";
  natal["italia"] = "Buon Natale!";

  natal["libia"] = "Buon Natale!";

  natal["siria"] = "Milad Mubarak!";

  natal["marrocos"] = "Milad Mubarak!";
  natal["japao"] = "Merii Kurisumasu!";

  while(scanf("%s ", pais) != EOF){
    //printf("%s\n", pais);
    if(natal.find(pais) != natal.end()) printf("%s\n", natal[pais].c_str());

    else printf("--- NOT FOUND ---\n");

  }


  return 0;

}