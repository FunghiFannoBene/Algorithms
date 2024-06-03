# Binary Search

**Ricerca ottimizzata per elementi già ordinati.**

>[!NOTE]
>** Requisito: **
>L'array deve essere ordinato.

**La ricerca binaria divide ripetutamente l'array a metà, riducendo l'area di ricerca fino a trovare l'elemento desiderato o determinare che non è presente.**  

### Metodo a finestra: crea una finestra che si riduce di metà ogni volta valutando con il maggiore e minore.

## 1.
**Inizia sempre con una finestra che parte da 0 a size. Quindi la finestra più grande possibile.**


## 2.
**Il percorso prevede di chiudere la finestra con il while loop, left che è inizio, e right che è fine. La condizione di stop infatti è left > di right oppure left <= right**

## 3.
**Si cerca il punto di METà di questa finestra con l'operazione di left + (right - left) / 2;**

## 4.
**Trovata la metà si può valutare se l'elemento alla posizione mid è uguale al target e in quel caso è trovato**
**Sennò bisogna vedere se è maggiore o minore del target, e a seconda di ciò possiamo fare:**

```c++

	if (vec[mid] < target)
		left = mid + 1;
	else
		right = mid - 1;

```

```c++
int binarySearch(const vector<int>& vec, int target)
{
    int left = 0;
    int right = vec.size() - 1;

    while (left <= right)
	{
        int mid = left + (right - left) / 2;
        if (vec[mid] == target)
            return mid;
        if (vec[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}
```