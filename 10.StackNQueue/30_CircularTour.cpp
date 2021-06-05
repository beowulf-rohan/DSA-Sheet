#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

// Better than second one....
int tour(petrolPump p[],int n)
{
    int totalPetrol = 0, petrol = 0, s = 0;
    for(int i = 0; i < n; i++)
    {
       totalPetrol += p[i].petrol - p[i].distance;
       petrol += p[i].petrol - p[i].distance;
        if(petrol < 0)
        {
           petrol = 0;
            s = i+1;
        }
    }
    return (totalPetrol < 0) ? -1 : s;
}

int tour(petrolPump p[],int n)
{
   int start = 0, end = 1;
    int currPetrol = p[start].petrol - p[start].distance;
   while(end != start || currPetrol < 0)
    {
        while(currPetrol < 0 && start != end)
       {
           currPetrol -= p[start].petrol - p[start].distance;
           start = (start+1)%n;
            if(start == 0)
            return -1;
       }
        currPetrol += p[end].petrol - p[end].distance;
        end = (end+1)%n;
    }
    return start;
}