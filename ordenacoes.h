using namespace std;

#include <vector>

void ShellSort(vector<int>& arr, int n, int &comparacoes, int &movimentacoes) {
    comparacoes = 0;
    movimentacoes = 0;
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap; j -= gap) {
                comparacoes++;
                if (arr[j - gap] > temp) {
                    comparacoes++;
                    arr[j] = arr[j - gap];
                    movimentacoes++;
                } else {
                    break;
                }
            }
            arr[j] = temp;
            movimentacoes++;
        }
    }
}

void merge(vector<int>& arr, int left, int mid, int right, int &comparacoes, int &movimentacoes) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
        comparacoes++;
    }
    comparacoes++;
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
        comparacoes++;
    }
    comparacoes++;

    int i = 0, j = 0;
    int k = left;
    while (i < n1 and j < n2) {
        comparacoes += 2;  
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
        movimentacoes++;
        comparacoes++;
    }
    comparacoes++;

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
        movimentacoes++;
        comparacoes++;
    }
    comparacoes++;

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
        movimentacoes++;
        comparacoes++;
    }
    comparacoes++;
}

void mergeSort(vector<int>& arr, int left, int right, int &comparacoes, int &movimentacoes) {
    if (left >= right)
        return;
    comparacoes++;
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid, comparacoes, movimentacoes);
    mergeSort(arr, mid + 1, right, comparacoes, movimentacoes);
    merge(arr, left, mid, right, comparacoes, movimentacoes);
}

void heapify(vector<int>& arr, int n, int i, int &comparacoes, int &movimentacoes) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n) {
        if (arr[l] > arr[largest]) {
            largest = l;
        }
        comparacoes++;
    }
    comparacoes++; 

    if (r < n) {
        if (arr[r] > arr[largest]) {
            largest = r;
        }
        comparacoes++;
    }
    comparacoes++;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        movimentacoes++;
        heapify(arr, n, largest, comparacoes, movimentacoes);
    }
}

void heapSort(vector<int>& arr, int &comparacoes, int &movimentacoes) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparacoes, movimentacoes);
        comparacoes++;
    }
    comparacoes++;

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        movimentacoes++;
        heapify(arr, i, 0, comparacoes, movimentacoes);
        comparacoes++;
    }
    comparacoes++;
}

void printVector(vector<int>& arr) {
    for (unsigned int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
