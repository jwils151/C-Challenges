//Jerrica Wilson
//CS 102
//Case 6-Lets Go Shopping

#include<sstream>
#include<fstream>
#include<string>
#include<iostream>
#include<iomanip>
#include<vector>

using namespace std;



class ShoppingItem{             //declare class Shoppingitem
  private:
   int quantity;
   double Costello;
   string name;
  public:
   ShoppingItem();
   ShoppingItem(int qty, double _cost,const string &_name);
   int getQuantity() const;
   double getCost() const;
   string getName() const;
   double getTotalCost() const;
};

double MinMax(const vector<ShoppingItem>&a, ShoppingItem &b, ShoppingItem &c);

void Sort(vector<ShoppingItem>&a);

ShoppingItem::ShoppingItem(){

}
ShoppingItem::ShoppingItem(int qty, double _cost,const string &_name){
   quantity=qty;
   cost=_cost;
   name=_name;
}

int ShoppingItem::getQuantity() const{
return quantity;
}

double ShoppingItem::getCost() const{
return cost;
}

string ShoppingItem::getName() const{
return name;
}

double ShoppingItem::getTotalCost() const{
 double Total_Cost=quantity*cost;
 return Total_Cost;
}


int main(int argc, char *argv[]){      //int main

ShoppingItem SI;
string line,item, first, last;
int qty;
double price;
vector<ShoppingItem>totalItem;
double Total_Cost;
ShoppingItem min, max;
double sum;


   
ifstream fin;                      //initialize file
char *file_in = argv[1];           //file name is 1st comm.line arg.
ofstream fout;
char *file_out = argv[2];         //file name is 2nd comm.line arg.


fin.open(file_in);               //open file and if file does not open
if(fin.fail()){
cout<<"Unable to open input file.";
}
fout.open(file_out);


while(getline(fin,line)){       //while loop reads file into vector
stringstream sin;

   while(line==""){            //if a line is blank, go to next line

      getline(fin,line);

   }
    sin.str(line);
   sin>>qty;

   if(qty!=-1){             //when qty=-1, reads vector to output file
   sin>>price>>item;
   SI= ShoppingItem(qty,price,item);
   totalItem.push_back(SI);
   }//if
   else{
   sin>>first>>last;
   
   Sort(totalItem);            //call Sort function
   for(int i=0;i<totalItem.size();i++){
      
fout<<fixed<<setprecision(2);

fout.width(15);
fout<<left;

fout<<totalItem[i].getName()<<" ";  //reads in item name


fout.width(3);
fout<<right;

fout<<totalItem[i].getQuantity()<<" ";  //reads in quantity


fout.width(6);
fout<<right;
fout<<totalItem[i].getCost()<<" ";       //reads in cost



fout.width(7);
fout<<right;

fout<<totalItem[i].getTotalCost()<<endl;    //reads in total cost

       }//for


double TC=MinMax(totalItem,min,max);      //call MinMax fuction
         fout<<endl;
         fout<<"cheapest item = "<<min.getName()<<endl;
         fout<<"most expensive item = "<<max.getName()<<endl;
         fout<<"total cost = "<<TC<<endl;
         
         for(int i=1;i<first.size();i++){    //Capitalization
         if(first[i]>=65 && first[i]<=90){
            first[i]+=32;
         }
         }
         for(int i=1;i<last.size();i++){
         if(last[i]>=65 && last[i]<=90){
            last[i]+=32;
         }
         }
         if(first[0]>=97 && first[0]<=122){
            first[0]-=32;
         }
         if(last[0]>=97 && first[0]<=122){
            last[0]-=32;
         }
         

         fout<<"shopper = "<<last<<" "<<first<<endl;
         fout<<endl;
         totalItem.clear();              //clears vector
}//else
}//while 

        

        
      
      

      
     

      
      


fin.close();                      //close input/output files
fout.close();
} //int main

double MinMax(const vector<ShoppingItem>&totalItem, ShoppingItem &min, ShoppingItem &max){
  double sum=0;
  ofstream fout;
  double MINIMUM=totalItem[0].getCost();
   min = totalItem[0];
  double MAXIMUM=totalItem[0].getCost();
   max=totalItem[0];
  
    for(int i=0; i<totalItem.size();i++){      
         if(totalItem[i].getCost()<MINIMUM){
            min=totalItem[i];
            MINIMUM = min.getCost();
         }
         if(totalItem[i].getCost()>MAXIMUM){
            max=totalItem[i];
            MAXIMUM = max.getCost();
         }

         sum += totalItem[i].getTotalCost();
         
   }
     return sum;    
}

void Sort(vector<ShoppingItem>&totalItem){
bool sorted;

ShoppingItem temp;
do{
sorted=true;
for(int i=1;i<totalItem.size();i++){
   if(totalItem[i-1].getCost()>totalItem[i].getCost()){
      sorted=false;
      temp=totalItem[i];
      totalItem[i]=totalItem[i-1];
      totalItem[i-1]=temp;
     }
    }

      
}while(sorted==false);
}