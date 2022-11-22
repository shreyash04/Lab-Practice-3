#include <bits/stdc++.h>


using namespace std;



// Normal Partition Method (Array's last element is taken as pivot)
int partition(vector<int>& v, int low, int high)
{
    int pivot = v[high];

    int i = low - 1;
    for(int j=low; j<=high-1; j++)
        if(v[j] <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }

    swap(v[i+1], v[high]);
    return i+1;
}


// Partition Method for Randomized Quicksort
int randomized_partition(vector<int>& v, int low, int high)
{
    int random_no = low + rand() % (high-low);
    swap(v[random_no], v[high]);
    return partition(v, low, high);
}

// Randomized Quicksort
void randomized_quicksort(vector<int>& v, int low, int high)
{
    if(low < high)
    {
        int p_idx = randomized_partition(v, low, high);
        randomized_quicksort(v, low, p_idx-1);
        randomized_quicksort(v, p_idx+1, high);
    }
}


// Deterministic Quicksort
void deterministic_quicksort(vector<int>& v, int low, int high)
{
    if(low < high)
    {
        int p_idx = partition(v, low, high);
        deterministic_quicksort(v, low, p_idx-1);
        deterministic_quicksort(v, p_idx+1, high);
    }
}


int main()
{
    int n;
    cout<<"\nEnter size of array : ";
    cin>>n;

    cout<<"Enter elements of array : ";
    vector<int> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    vector<int> v1 = v;


    deterministic_quicksort(v, 0, n-1);

    cout<<"\nSorted Array (using deterministic variant) : \n";
    for(int i=0; i<n; i++)
        cout<<v[i]<<" ";
    randomized_quicksort(v1, 0, n-1);

    cout<<"\nSorted Array (using randomized variant) : \n";
    for(int i=0; i<n; i++)
        cout<<v1[i]<<" ";


    return 0;
}
