#include <iostream>
using namespace std;

// MagicNumber class - sari functionality is k andr hai

class MagicNumber 
{
private:
    int* arr;   // Array ka pointer
    int size;   // Array ka size

    // Recursive function: array main maximum value dhundna
    // index: current position jahan se check kar rahain hain

    int findMax(int* a, int n, int index)
    {
        // Base case: agar sirf aik element bacha hai
        if (index == n - 1)
        {
            return a[index];
        }

        // Baki array ka maximum nikalo recursively
        int maxOfRest = findMax(a, n, index + 1);

        // Current element aur baki ka max compare karo
        return max(a[index], maxOfRest);
    }

    // Recursive function: max element ka index dhundna

    int findMaxIndex(int* a, int n, int index) 
    {
        // Base case: sirf aik element bacha
        if (index == n - 1)
        {
            return index;
        }

        // Baaki array main max index dhundo
        int maxIdx = findMaxIndex(a, n, index + 1);

        // Current vs baki max
        if (a[index] >= a[maxIdx])
        {
            return index;
        }
        return maxIdx;
    }

    // Recursive Subset Sum check:
    // Kya 'target' ko 'remaining[]' ke kisi subset se bana sakte hain?
    // idx: current index jo consider kar rahain hain

    bool subsetSum(int* remaining, int remSize, int target, int idx) 
    {
        // Base case 1: target zero ho gaya - subset mil gaya!
        if (target == 0)
        {
            return true;
        }

        // Base case 2: sary elements check ho gaye ya target negative
        if (idx == remSize || target < 0)
        {
            return false;
        }

        // Do choices:
        // 1) Current element ko subset main shamil karo
        bool include = subsetSum(remaining, remSize, target - remaining[idx], idx + 1);

        // 2) Current element ko subset main shamil na karo
        bool exclude = subsetSum(remaining, remSize, target, idx + 1);

        // Dono main se koi bhi true ho to true return karo
        if (include)
        {
            return true;
        }
        return exclude;
    }

    // Helper: array mein se aik index hata kar naya array banana
    // removeIdx: jo index hatana hai

    void removeElement(int* original, int n, int removeIdx, int* newArr)
    {
        // Recursive helper: aik aik element copy karo, removeIdx skip karo
        copyExcept(original, n, removeIdx, newArr, 0, 0);
    }

    // Recursive copy - removeIdx wala element skip karta hai
    void copyExcept(int* src, int n, int skipIdx, int* dest, int srcIdx, int destIdx) 
    {
        // Base case: source khatam ho gaya
        if (srcIdx == n)
        {
            return;
        }

        // Agar yeh woh index hai jo hatana hai toh skip karo
        if (srcIdx == skipIdx)
        {
            copyExcept(src, n, skipIdx, dest, srcIdx + 1, destIdx);
        }
        else
        {
            // Copy karo aur aage badho
            dest[destIdx] = src[srcIdx];
            copyExcept(src, n, skipIdx, dest, srcIdx + 1, destIdx + 1);
        }
    }

    // Main recursive function: magic number dhundna
    // currentArr: jo array ab check kar rahain hain
    // currentSize: us array ka size

    int findMagicNumber(int* currentArr, int currentSize)
    {
        // Base case: agar array main 1 ya 0 elements hain
        // to koi subset nahi bana sakte
        if (currentSize <= 1)
        {
            return -1;
        }

        // Step 1: Sabse bada element aur uska index dhundo
        int maxIdx = findMaxIndex(currentArr, currentSize, 0);
        int maxVal = currentArr[maxIdx];

        // Step 2: Remaining elements ka array banao (max ko hata k)
        int* remaining = new int[currentSize - 1];
        removeElement(currentArr, currentSize, maxIdx, remaining);
        int remSize = currentSize - 1;

        // Step 3: Check karo kya maxVal ko remaining se bana sakte hain
        cout << "Checking: Can " << maxVal
            << " be formed from subset of remaining ? ";

        bool found = subsetSum(remaining, remSize, maxVal, 0);

        if (found)
        {
            // Magic number mil gaya!
            cout << "YES!" << endl;
            delete[] remaining;
            return maxVal;
        }
        else 
        {
            // Nahi mila, agli baar try karo
            cout << "NO. Trying next largest..." << endl;

            // Recursive call: current max hata ke baaki array mein dhundo
            int result = findMagicNumber(remaining, remSize);
            delete[] remaining;
            return result;
        }
    }

    // Recursive array print karna

    void printArray(int* a, int n, int idx)
    {
        if (idx == n)
        {
            cout << "]" << endl;
            return;
        }
        if (idx == 0) cout << "[";
        {
            cout << a[idx];
        }
        if (idx < n - 1)
        {
            cout << ", ";
        }
        printArray(a, n, idx + 1);
    }

public:
    // Constructor: array initialize karna
    MagicNumber(int* inputArr, int inputSize) 
    {
        size = inputSize;
        arr = new int[size];
        // Array copy karo
        for (int i = 0; i < size; i++)
        {
            arr[i] = inputArr[i];
        }
    }

    // Destructor: memory free karna
    ~MagicNumber() 
    {
        delete[] arr;
    }

    // Public function: magic number solve karna aur result dikhana

    void solve()
    {
        cout << "\n----- MAGIC NUMBER WIZARD CHALLENGE -----\n" << endl;

        cout << "\nInput Array: ";
        printArray(arr, size, 0);

        cout << "\n--- Search Begin ---\n" << endl;

        int result = findMagicNumber(arr, size);

        cout << "\n--- Result ---" << endl;
        if (result != -1)
        {
            cout << "Magic Number Found: " << result << endl;
        }
        else
        {
            cout << "No Magic Number exists! Returning: -1" << endl;
        }
    }
};

// ===================== MAIN FUNCTION =====================
int main()
{
    // Test Case 1: Sample from problem
    cout << "\n===== Test Case 01 =====" << endl;
    int arr1[] = { 2, 3, 5, 8, 13 };
    MagicNumber m1(arr1, 5);
    m1.solve();

    // Test Case 2: No magic number
    cout << "\n===== Test Case 02 =====" << endl;
    int arr2[] = { 1, 2, 4 };
    MagicNumber m2(arr2, 3);
    m2.solve();

    // Test Case 3: Multiple candidates
    cout << "\n===== Test Case 03 =====" << endl;
    int arr3[] = { 1, 2, 3, 6, 10 };
    MagicNumber m3(arr3, 5);
    m3.solve();

    return 0;
}