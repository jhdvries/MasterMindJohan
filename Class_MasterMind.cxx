#include <iostream>
using namespace std;

class game
{
   private:
      int secret_code[4]; // will be used to construct the secret code of the code m
      int trial_code[4];  // will be used to strore the attempt of the code breaker
      void create_code();
      void read_code();
      bool code_breaking();
      bool round();
}

void game::read_code()
{
   cout << "Code maker please fill in four colors, chose from colours 1 to 6" << endl;
   cin >> secret_code[0] >> secret_code[1] >> secret_code[2] >> secret_code[3] ;

   for(int i = 0; i <= 3; i++) // this loop checks whether the colours of the secret code  are allowed. If not the programme terminates
   {
       if(secret_code[i] < 1 or secret_code[i] > 6)
       { 
           cout << "ERROR: Inserted illegal colour" << endl;
           return 0;
       }
   }
  
}

bool game::round(int g.secret_code)
{
   int red_pins(0);
   int white_pins(0);
   int sc[4];
   int trail_code;;

   for(int i = 0; i <= 3; i++)  sc[i] = secret_code[i];

   cout << "Round " << r << endl;
   cout << "You may now enter a code containing four colours (chose from colours 1 to 6)." << endl;
   cout << "Enter space between every colour." << endl;
   
   cin >> trial_code[0] >> trial_code[1] >> trial_code[2] >> trial_code[3] ;
           
   for(int i = 0; i <= 3; i++) // this loop checks whether the colours are allowed. If not it will ask the user to change the entered colour. 
   {
       if(trial_code[i] < 1 or trial_code[i] > 6)
       {    
            cout << "ERROR: Illigal colour for entry " << i+1 << " of your code, please enter valid colour for this entry." <<  endl;
            cin >> trial_code[i];            
       }
   }
   
   for(int i = 0; i <= 3; i++) // this loop counts the number of white and red pins where 4 white pins mean winning
   {            
         if(sc[i] == trial_code[i]) //same colour same position
          {   
             white_pins++;
             sc[i] = 7;          //To prevent repitition change colour to impossible colour 7  
             trial_code[i]  = 0; //To prevent repitition change colour to impossible colour 0, should be different impossible colour then sc
          }
   }
 

   for(int i = 0; i <= 3; i++) // this loop counts the number of white and red pins where 4 white pins mean winning
   {            
       for(int j = 0; j <= 3; j++) // double loop over both the secret code and the breakers' trail code
       {
          if(sc[i] == trial_code[j] && i != j) //same colour different position
          {
            red_pins++;
            sc[i] = 7;          //To prevent repitition change colour to impossible colour 7
            trial_code[j]  = 0; //To prevent repitition change colour to impossible colour 0, should be different impossible colour then sc
          }
       }
   }
   

   if(white_pins == 4)
   {
       return true;
   }
   else
   {
       cout << white_pins << " white pins" << endl;
       cout << red_pins << " red pins" << endl;

       return false;
   }
   
}

bool game::code_breaking()
{
   

   cout << "Code breaker please start your attemps to break the code. You will be allowed 12 attempts." << endl;

   for(int r = 1; r <= 12; r++) // this loop exucutes creates the rounds
   {
      if (g.round = true) return true;
   }

   return false;
}

int main()
{
   game g;

   g.read;
   
   if (g.code_breaking = true)  cout << "You broke the secret code in " << r << " rounds." << endl;
   if (g.code_breaking = false) cout << "You couldn't break the code in 12 rounds. It has been proven that you are stupid :)" << endl;

   return 0;
}

