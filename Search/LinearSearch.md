# Linear Search

**Ricerca lineare, scorre un array valutando elemento per elemento detto anche O(n)**

```c
int linearSearch(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
	{
        if (arr[i] == x)
            return i;
    }
    return -1;
}
```

**Ritorna la posizione dell'elemento può tornare anche l'elemento stesso o il bool**

```c
int *linearSearch(int *arr, int n, int x)
{
    for (int i = 0; i < n; i++)
	{
        if (arr[i] == x)
            return arr+i;
    }
    return NULL;
}
```