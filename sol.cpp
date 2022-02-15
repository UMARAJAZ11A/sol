#include<bits/stdc++.h>
#include <time.h>
using namespace std ;
int find(string str,int i,int n , map<string,int> &m)                      // to find the max number of strings present in the str from the input file the strings
{
	if(i>=n)
	{
		return 0 ;
	}
	else
	{
		string s = "" ;
		int max_count = 0;
		for(int j=i;j<n;j++)
		{
			s+=str[j] ;
			if(m[s]>0)
			{
				int val = find(str,j+1,n,m) ; 
				if(val!=-1)
				max_count = max( max_count ,1 +  val ) ;	
			}
		}
		if(max_count==0)
		return -1 ;
		
		return max_count ;
	}
}

int main()
{
	clock_t t;
    t = clock();
	
   fstream newfile;
   map<string,int> m ;
   vector<string> arr ;
   string input ;
   
//   cout<<"Enter the input Text file\n" ;
//   cin>>input ;
   newfile.open("input_01.txt",ios::in); 			//open a file to perform read operation using file object
   if (newfile.is_open()){ 							//checking whether the file is open
      string str;
      while(getline(newfile, str)){ 					//read data from file object and put it into string.
						
         arr.push_back(str);
         m[str]++ ;
      }
      newfile.close(); 								//close the file object.
   }
   
	int COUNT_MAX1 = 0 , COUNT_MAX2 = -1  ;
	string STR_MAX1 = "" , STR_MAX2 = "" ;

	for(int i=0;i<arr.size();i++)
	{
		int val = find( arr[i] ,0,arr[i].length(), m ) ;

		if(val>=COUNT_MAX1)
		{
			
			if(val==COUNT_MAX1)
			{
				if(arr[i].length()>STR_MAX1.length())
				STR_MAX1 = arr[i] ;
			}
			else
			{
				STR_MAX2 = STR_MAX1 ;
				COUNT_MAX2 = COUNT_MAX1 ;
				STR_MAX1 = arr[i] ;
				COUNT_MAX1 = val ;
				
			}
				
			
		}
		else if(val>=COUNT_MAX2)
		{
			if(val==COUNT_MAX2)
			{
				if(arr[i].length()>STR_MAX2.length())
				{
					STR_MAX2 = arr[i] ;	
				}
			}
			else
			{
				STR_MAX2 = arr[i] ;	
			}
			COUNT_MAX2 = val ;
			
		}
		else
		{
			
		}
		
	}
  
    
  
    
    
    t = clock() - t;
    double time_taken = ((double)t); // in seconds
  
//    printf("fun() took %f seconds to execute \n", time_taken);
	
	cout<<"\nLongest Compound Word :"<<STR_MAX1 ;
	cout<<"\nSecond Longest Compound Word :"<<STR_MAX2 ;
	cout<<"\nTime taken to process file "<<input<<" :"<<time_taken<<" milli seconds" ;
	
	return 0 ;
}
