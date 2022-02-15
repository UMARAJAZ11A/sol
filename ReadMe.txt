Solution 

	Algorithm ->
		
	Step 1 : Read the input file using fstream class in c++
	Step 2 : While Reading the file store the string in each line in a Vector of strings
	Step 3 : Also create h hash map of each string (It will help later in matching the string)
	Step 4 : Take two variables of max1 and max2 to store max compounded string and 2nd max compounded string
	Step 5 : Read each string in the vector sequentially and find the length of compounded string in that vector string
	Step 6 : Create a recursive function to find all the continous substring that is compounded and together completes the string, 
		 if there is single mismatch in the substring then that perticulat arrangement is not a compounded word .
		 eg-> file : a , b, c , d , aad
		      str  : aab    
				a->a->b is a valid compounded substring pattern as all the substring combined formed complete str and each substring does
					contained in the file itself
				but ,
				a->ab is not a valid combination  , as explained
	Step 6 : Check if the compounded string returend by step 5 is the global max or not and update max1 and max2 and repeat step 5 untill all the string are matched



	Flow Chart ->


							-------------
						       |     Str[i]  |
						       |             |
                                                        -------------
                                                              | i<size of vector
                                                             \ /
							------------------------------------				       ----------- 	        -------------------------
						       | len =  Check lenth str[i]     	    |-------------------------------> | len>max2  |----------> |set max2 to max of length| 
						       | of compounded string present in str|  len >= max2		       -----------     NO      |between max2 and str[i]  |
                                                        ------------------------------------					    | YES		-------------------------
                                                              |   len >= max1 							   \ /
                                                             \ /							       -------------------
							-------------		    -------------------------------	      | set max2 to str[i]|
						       | len > max1  |-----------> | Set max1 to max length string | 	       -------------------
						       |             |    NO 	   | between max1 and str[i]	   |
                                                        -------------		    -------------------------------
                                                              |  YES
                                                             \ /
							------------------------------------------------
						       | update max2 string by assigning it by max1     |
						       | it by max1 and update max1 with new max string	|
                                                        ------------------------------------------------



	Time complexiety Analysis
		
		worst case analysis -> 
					if all the continous substring exist in the file
						abc - {a,b,c} , {a,bc} , {ab,c} , {abc} --  n(n-1)/2 + 1
							is equal to total number of iteration from i to n and j=i to n ;

					therefore compounded word calculation function has time complexiety of
					Li = length of ith string
					T(i) = Li(Li-1)/2 + 1 ;
					
					As algorithms is performed on all the string therefore summation of all the T(i) over length
					of vector array will give total time complexiety

					T(n) = summation(T(i))  , where i varies from 0 to size of vector array - 1

					To simlify T(i) we take upper bound only i.e T(i) = C*Li^2 + b*Li + c;
					ignore the higher order term therefore
					T(i) = O(Li^2) 

					T(n) = L0^2 + L1^2 + L2^2 ....... Ln^2 + C
					C = some directly propotional time relative to input , time required to take the input from file store in vector array and map
					C is of order O(file length) , i.e length of vector array
				
					T(n) = L0^2 + L1^2 + L2^2 ....... Ln^2 + O(n) ;

					in worst case length of all the strings are equal to the length of maximun string present in the file
					i.e -> L0=L1=L2....=Ln=L
				
					T(n) = L^2 + L^2 +...... L^2 + O(n) , L^2 n times
					T(n) = n*L^2 + O(n) ,
				
					We can ignore the higher order term , therefore
					T(n) = O(n*L^2) ;
					
					Time complexiety represented here is a loose upper bound as compounded word calculation fnction will never 
					run to its worst case every each input string , for this to happen evey string in the file must contain 
					all the other strings which is impossible , there we can bring down the time complexiety even further 

		 best case analysis -> 
					if no strig is a compounded string and mismathing with all there string
					T(i) = Li 
					T(n) = O(n*L) ;


 	Space complexiety Analysis

					Space complexiety S(n) = 2*(summation of length of all the string)
							  S(n) = O(n*L) ;


My Output of both the file 
Longest Compound Word 				intercomprehensibilities        --- contain 9 compounded words
Second Longest Compound Word 			electroencephalographically	--- contain 8 compounded words
Time taken to process file Input_02.txt 	5621 milli seconds

Longest Compound Word 				ratcatdogcat        --- contain 4 compounded words
Second Longest Compound Word 			catsdogcats	    --- contain 3 compounded words
Time taken to process file Input_02.txt 	31 milli seconds











  



















