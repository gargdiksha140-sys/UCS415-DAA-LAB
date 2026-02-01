

// #include <iostream>
// using namespace std;

// int binarySearch(int arr[], int low, int high, int key) {
//     if (low > high)
//         return -1;

//     int mid = (low + high) / 2;

//     if (arr[mid] == key)
//         return mid;
//     else if (arr[mid] > key)
//         return binarySearch(arr, low, mid - 1, key);
//     else
//         return binarySearch(arr, mid + 1, high, key);
// }




// int main() {
//     int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int key = 23;

//     int result = binarySearch(arr, 0, n - 1, key);

//     if (result != -1)
//         cout << "Element found at index " << result;
//     else
//         cout << "Element not found";

//     return 0;
// }





// #include <iostream>
// using namespace std;

// void merge(int arr[], int low, int mid, int high) {
//     int n1 = mid - low + 1;
//     int n2 = high - mid;
//     int L[n1], R[n2];
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[low + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];
//     int i = 0, j = 0, k = low;
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j])
//             arr[k++] = L[i++];
//         else
//             arr[k++] = R[j++];
//     }
//     while (i < n1)
//         arr[k++] = L[i++];

//     while (j < n2)
//         arr[k++] = R[j++];
// }

// void mergesort(int arr[], int low, int high) {
//     if (low < high) {
//         int mid = (low + high) / 2;
//         mergesort(arr, low, mid);
//         mergesort(arr, mid + 1, high);
//         merge(arr, low, mid, high);
//     }
// }

// int main() {
//     int arr[] = {12, 11, 13, 5, 6, 7};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     mergesort(arr, 0, n - 1);
//     cout << "Sorted array: ";
//     for (int i = 0; i < n; i++)
//         cout << arr[i] << " ";

//     return 0;
// }







// #include <iostream>
// using namespace std;

// int partition(int arr[],int low,int high){
//     int pivot= arr[high];
//     int i=low-1;
//     int j=low;
//     for(j=low;j<high;j++){
//         if(arr[j]<pivot)
//         {
//             i++;
//             swap(arr[i],arr[j]);
//         }
//     }
//     swap(arr[i+1],arr[high]);
//     return (i+1);
// }

// void quicksort(int arr[],int low,int high){
//     if(low<high){
//         int pi= partition(arr,low,high);
//         quicksort(arr,low,pi-1);
//         quicksort(arr,pi+1,high);
//     }
// }

// int main(){
//     int arr[]={ 4, 2, 6, 9, 2 };
//     int n= sizeof(arr)/sizeof(arr[0]);
//     quicksort(arr,0,n-1);
//     cout<<"Sorted array: ";
//     for(int i=0;i<n;i++)
//         cout<<arr[i]<<" ";

//     return 0;
        
// }





// #include <iostream>
// #include <climits>
// using namespace std;

// // Function to find maximum sum crossing the middle
// int maxCrossingSum(int arr[], int low, int mid, int high) {
//     int sum = 0;
//     int leftSum = INT_MIN;

//     for (int i = mid; i >= low; i--) {
//         sum += arr[i];
//         if (sum > leftSum)
//             leftSum = sum;
//     }

//     sum = 0;
//     int rightSum = INT_MIN;

//     for (int i = mid + 1; i <= high; i++) {
//         sum += arr[i];
//         if (sum > rightSum)
//             rightSum = sum;
//     }

//     return leftSum + rightSum;
// }

// // Divide and Conquer function
// int maxSubArraySum(int arr[], int low, int high) {
//     if (low == high)
//         return arr[low];

//     int mid = (low + high) / 2;

//     return max(
//         max(maxSubArraySum(arr, low, mid),
//             maxSubArraySum(arr, mid + 1, high)),
//         maxCrossingSum(arr, low, mid, high)
//     );
// }

// int main() {
//     int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     cout << "Maximum Subarray Sum: "
//          << maxSubArraySum(arr, 0, n - 1);

//     return 0;
// }


