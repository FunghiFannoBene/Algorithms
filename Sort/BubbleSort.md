# Bubble Sort

**Riordinamento a doppia iterazione, valuta ogni elemento**

## A ogni iterazione J porta l'elemento più grande infondo all'array

```c++
void bubbleSort(std::vector<int> &arr, int n)
{
    for (int i = 0; i < n-1; i++)
	{
        for (int j = 0; j < n-i-1; j++)
		{
            if (arr[j] > arr[j+1])
				std::swap(arr[j], arr[j+1]);
    	}
	}
}
```
