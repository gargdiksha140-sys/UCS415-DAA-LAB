


// #include <iostream>
// using namespace std;

// bool isPossible(int arr[], int n, int M, int limit) {
//     int segments = 1;
//     int currOR = 0;

//     for (int i = 0; i < n; i++) {
//         if ((currOR | arr[i]) <= limit) {
//             currOR |= arr[i];
//         } else {
//             segments++;
//             currOR = arr[i];
//         }
//     }
//     return segments <= M;
// }
// int main() {
//     int arr[] = {5, 1, 2, 7, 3};
//     int n = sizeof(arr) / sizeof(arr[0]);
//     int M = 2;

//     int low = 0, high = 0;
//     for (int i = 0; i < n; i++) {
//         if (arr[i] > low)
//             low = arr[i];
//         high |= arr[i];
//     }

//     int ans = high;

//     while (low <= high) {
//         int mid = (low + high) / 2;

//         if (isPossible(arr, n, M, mid)) {
//             ans = mid;
//             high = mid - 1;
//         } else {
//             low = mid + 1;
//         }
//     }

//     cout << "Minimum maximum Bitwise OR = " << ans;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// // Partition function (for ascending order)
// int partition(int A[], int low, int high) {
//     int pivot = A[high];
//     int i = low - 1;

//     for(int j = low; j < high; j++) {
//         if(A[j] <= pivot) {
//             i++;
//             int temp = A[i];
//             A[i] = A[j];
//             A[j] = temp;
//         }
//     }

//     int temp = A[i + 1];
//     A[i + 1] = A[high];
//     A[high] = temp;

//     return i + 1;
// }

// // QuickSort function
// void quickSort(int A[], int low, int high) {
//     if(low < high) {
//         int pi = partition(A, low, high);
//         quickSort(A, low, pi - 1);
//         quickSort(A, pi + 1, high);
//     }
// }
// int main() {
//     int N;
//     cin >> N;

//     int A[N];
//     for(int i = 0; i < N; i++)
//         cin >> A[i];
//     quickSort(A, 0, N - 1);
//     int l = 0, ans = 0;
//     // Sliding window
//     for(int r = 0; r < N; r++) {
//         while(A[r] - A[l] > 10) {
//             l++;
//         }
//         int len = r - l + 1;
//         if(len > ans)
//             ans = len;
//     }

//     cout << ans;
//     return 0;
// }






// #include <iostream>
// using namespace std;

// struct Result {
//     int min1; // smallest
//     int min2; // second smallest
// };

// // Divide and Conquer function
// Result findTwoMin(int A[], int left, int right) {
//     Result res;

//     // If only one element
//     if (left == right) {
//         res.min1 = A[left];
//         res.min2 = 1000000000; // large value
//         return res;
//     }

//     // If two elements
//     if (right == left + 1) {
//         if (A[left] < A[right]) {
//             res.min1 = A[left];
//             res.min2 = A[right];
//         } else {
//             res.min1 = A[right];
//             res.min2 = A[left];
//         }
//         return res;
//     }

//     // Divide
//     int mid = (left + right) / 2;
//     Result L = findTwoMin(A, left, mid);
//     Result R = findTwoMin(A, mid + 1, right);

//     // Conquer (merge results)
//     Result ans;
//     ans.min1 = (L.min1 < R.min1) ? L.min1 : R.min1;

//     int temp1 = (L.min1 > R.min1) ? L.min1 : R.min1;
//     int temp2 = (L.min2 < R.min2) ? L.min2 : R.min2;

//     ans.min2 = (temp1 < temp2) ? temp1 : temp2;

//     return ans;
// }
// int main() {
//     int N;
//     cin >> N;

//     int A[N];
//     for (int i = 0; i < N; i++)
//         cin >> A[i];

//     Result r = findTwoMin(A, 0, N - 1);

//     cout << r.min1 + r.min2;

//     return 0;
// }






// #include <iostream>
// using namespace std;

// // Partition function for descending order
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high];
//     int i = low - 1;

//     for(int j = low; j < high; j++) {
//         if(arr[j] > pivot) {   // '>' for descending
//             i++;
//             int temp = arr[i];
//             arr[i] = arr[j];
//             arr[j] = temp;
//         }
//     }
//     int temp = arr[i + 1];
//     arr[i + 1] = arr[high];
//     arr[high] = temp;

//     return i + 1;
// }
// // QuickSort function
// void quickSort(int arr[], int low, int high) {
//     if(low < high) {
//         int pi = partition(arr, low, high);
//         quickSort(arr, low, pi - 1);
//         quickSort(arr, pi + 1, high);
//     }
// }
// int main() {
//     int n, k;
//     cin >> n >> k;

//     int A[n];
//     for(int i = 0; i < n; i++)
//         cin >> A[i];

//     // Sort in descending order using QuickSort
//     quickSort(A, 0, n - 1);

//     long long specialty = 0;

//     // Sum all except k largest
//     for(int i = k; i < n; i++) {
//         specialty += A[i];
//     }
//     cout << specialty;

//     return 0;
// }





// #include <iostream>
// using namespace std;

// int main() {
//     long long N, W, H;
//     cin >> N >> W >> H;

//     long long low = max(W, H);
//     long long high = max(W, H) * N;
//     long long ans = high;

//     while (low <= high) {
//         long long mid = (low + high) / 2;

//         long long count = (mid / W) * (mid / H);

//         if (count >= N) {
//             ans = mid;        // possible answer
//             high = mid - 1;   // try smaller square
//         } else {
//             low = mid + 1;    // need bigger square
//         }
//     }
//     cout << ans;
//     return 0;
// }







// #include <iostream>
// #include <algorithm>
// #include <cmath>
// #include <vector>
// using namespace std;

// struct Point {
//     int x, y;
// };

// double dist(Point a, Point b) {
//     return sqrt((double)((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y)));
// }

// // Brute force for small range
// double brute(Point P[], int l, int r) {
//     double mn = 1e9;
//     for(int i = l; i <= r; i++) {
//         for(int j = i+1; j <= r; j++) {
//             mn = min(mn, dist(P[i], P[j]));
//         }
//     }
//     return mn;
// }

// bool compareY(Point a, Point b) {
//     return a.y < b.y;
// }

// // Main divide & conquer function
// double closestPair(Point P[], int l, int r) {
//     if(r - l <= 3)
//         return brute(P, l, r);

//     int mid = (l + r) / 2;
//     double dl = closestPair(P, l, mid);
//     double dr = closestPair(P, mid+1, r);

//     double d = min(dl, dr);

//     // Build strip using vector
//     vector<Point> strip;
//     for(int i = l; i <= r; i++) {
//         if(abs(P[i].x - P[mid].x) < d) {
//             strip.push_back(P[i]);
//         }
//     }

//     // Sort strip by y-coordinate
//     sort(strip.begin(), strip.end(), compareY);

//     // Check strip points
//     for(int i = 0; i < strip.size(); i++) {
//         for(int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
//             d = min(d, dist(strip[i], strip[j]));
//         }
//     }

//     return d;
// }

// bool compareX(Point a, Point b) {
//     return a.x < b.x;
// }

// int main() {
//     Point P[] = {
//         {9,3}, {2,6}, {15,3}, {5,1}, {1,2}, {12,4}, {7,2}, {4,7},
//         {16,5}, {3,3}, {10,5}, {6,4}, {14,6}, {8,6}, {11,1}, {13,2}
//     };

//     int n = sizeof(P)/sizeof(P[0]);

//     // Sort points by x-coordinate
//     sort(P, P+n, compareX);

//     double ans = closestPair(P, 0, n-1);

//     cout << "Minimum distance = " << ans << endl;
//     return 0;
// }


