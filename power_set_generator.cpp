#include<bits/stdc++.h>

using namespace std;

string toLower(string input);
bool isElement(string key, string *arr, int Size);
void make_set(string *in_set, int Size);

void generate_powerset(string *in, vector<string> &v, int s);
void display_powerset(vector<string> &v, int s);


int main()
{

  //take input of the Size of the Set which is less than or equal to 10
    int Size;

    //handles the case of input <= 0
    do{
        cout<<"Enter Size Of Set (Size > 0): ";
        cin>>Size;

    }while(Size <= 0);

  //Dynamically create set
  string *input_set = new string[Size];


  //take input to populate set
  //make_set() function populates the set with user inputs
  make_set(input_set,Size);

  //Print Power set
  vector<string> power_set;         //Empty power set
  power_set.push_back("");          // the first elemnet is always NULL

  generate_powerset(input_set,power_set, Size);

  display_powerset(power_set, power_set.size());





  return 0;
}



string toLower(string input)
{
  //changeds given string to all lower-case and returns

  for(int i = 0;i < input.size(); i++)
  {
    if(input[i] >= 'A' && input[i] <= 'Z')    //Determines if letter is capital
      input[i] += 32;     //converts capital letter to small letter using ASCII characteristics

  }
  return input;
}

bool isElement(string key, string *arr, int Size)
{
    for(int i = 0 ; i < Size; i++)
    {
        if(key == arr[i])    //returns true if key matches the set element
            return true;
    }
    return false;
}



void make_set(string *in_set, int Size)
{
  //takes input and populates dynamically created set

  for(int i = 0 ; i < Size; i++)
  {
    string in;
    cout<<"Enter Elemnet no. "<<i+1<<": ";
    cin>>in;             //Takes Input of set
    in = toLower(in);    //Converts to all lower case

    if(! isElement(in,in_set,Size))   //inserts string in set
        in_set[i] = in;
    else
        cout<<in<<" is already in set."<<endl;
  }
}

void display_powerset(vector<string> &power_set, int Size) {
    cout<<endl<<endl<<"Power Set:"<<endl;
    cout<<"{ ";
    for(int i = 0; i < Size; i++)    //this loop iterates the power set
    {
        cout<<"{";
        cout<<power_set[i]<<"}";
        if(i != power_set.size()-1) cout<<", ";
    }
    cout<<" }"<<endl;

}

void generate_powerset(string *input_set,vector<string> &power_set, int Size) {

  for(int i = 0 ; i< Size; i++)     //this loop iterates the Set
  {
    for(int j = 0; j < power_set.size(); j++)    //this loop iterates the power set
    {
      if(power_set[j] == input_set[i]) break;    //prevents re-occurance of an element

      else        //Adds new element
      {
        string temp = power_set[j] + input_set[i];  //storing an element in temp that will be stored in power set

        power_set.push_back(temp);       //storred element is put in the power set
      }
    }
  }
}
