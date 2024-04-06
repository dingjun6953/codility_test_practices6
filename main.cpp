/*
A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.

For example, consider an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20
The number of semiprimes within each of these ranges is as follows:

(1, 26) is 10,
(4, 10) is 4,
(16, 20) is 0.
Write a function:

class Solution { public int[] solution(int N, int[] P, int[] Q); }

that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

For example, given an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20
the function should return the values [10, 4, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
M is an integer within the range [1..30,000];
each element of arrays P and Q is an integer within the range [1..N];
P[i] ≤ Q[i].
Copyright 2009–2024 by Codility Limited. All Rights Reserved. Unauthorized copying, publication or disclosure prohibited.

*/
#include <iostream>
#include <vector>

using namespace std;

// Defining the function
int primenumber(int number)
{
    int i;
    // Condition for checking the
    // given number is prime or not
    for (i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)   return 1;
    }
    return 0; //prime number when returning 0
}


vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // Implement your solution here
    auto size=P.size();
    vector<int> result(size);
    for(int m=0; m<size; m++){
        result[m]=0;
    }
    
    int temp;
    for (int i=0; i<Q.size();i++)
    {
        if(P[i]<4) P[i]=4;
        for (int j=P[i]; j<=Q[i];j++){
            if(primenumber(j)!=0){
            for (int k=2; k<j; k++){
                temp=j/k;
                if(primenumber(temp)==0 && primenumber(k)==0 && j==temp*k){
                        cout<<"j="<<j<<endl;
                        result[i]++;
                        break;
                }
            }
            }
        }
    }
    return result;
}

int main()
{
    vector<int> P={1,4,16};
    vector<int> Q={26,10,20};
    vector<int> result= solution(26,P,Q);
    for(int i=0;i<result.size();i++){
         cout<<result[i]<<" ";
    }
    return 0;
}
