int binary(int low,int high,int key,int s[]){
 while (low <= high) {
 int mid = low + (high - low) / 2;
 if (s[mid] == key) {
 return mid;
 } else if (s[mid] < key) {
 low = mid + 1;
 } else {
 high = mid - 1;
 } } } 