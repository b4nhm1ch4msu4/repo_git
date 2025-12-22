#include<stdio.h>

int main() {
	int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    int temp;
    for (int x = 1, x < n; x++){
        for (int i = 1; i < n; i++){
            if (arr[i] > arr[i-1]){
                arr[i] = temp;
                arr[i] = arr[i-1];
                arr[i-1] = temp; 
            }
        }
    }
    
	return 0;
}

