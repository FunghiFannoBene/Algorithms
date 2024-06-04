# Quicksort

**Rioridamento di tipo divide and conquer**

>[!NOTE]
>Il pivot è un elemento dell'array a scelta!! Si può scegliere l'inizio, mezzo o anche la fine

## Fase 1.

Selezione di pivot: il pivot può essere qualsiasi numero dell'array. È un numero che dividerà gli elementi più piccoli da quelli più   grandi.  
Il passaggio dei parametri include l'array, l'indice d'inizio e l'indice di fine (non la dimensione ma size - 1).  
Selezioniamo il punto d'inizio come iteratore i e il punto di fine come iteratore j.  

## Fase 2.

Loop principale:  
```c++
while (i <= j)
```
Contiene 2 loop: il primo muove dall'inizio fino a quando non trova un numero maggiore o uguale al pivot. Il secondo loop parte dalla  fine verso l'inizio e si ferma quando trova un numero minore o uguale al pivot.  

```c++
while (arr[i] < pivot) i++;  
while (arr[j] > pivot) j--;  
```

## Fase 3.
Scambio degli elementi: Se i è minore o uguale a j, si scambiano gli elementi. i incrementa e j decrementa.  

```c++
if(i <= j)
{
	std::swap(arr[i], arr[j]);
	i++;
	j--;
}
```

## Fase 4.
Ricorsione: Si richiama quicksort sui sotto-array se ci sono ancora elementi da ordinare. Se left è minore di j, ordina la parte sinistra. Se i è minore di right, ordina la parte destra.  
```c++
if (left < j) quicksort(arr, left, j);
```

Ora si fa inversamente per la i se i è inferiore a right, il suo compito non è ancora finito e si passa ricorsivamente:  

```c++
if (i < right) quicksort(arr, i, right);
```

da notare che questo fa da **left a j** e da **i a right**.  
Significa che siccome la condizione di stop è che i < j divide la parte in metà (anche non uguali in base al pivot).  


```c++
void quicksort(vector<int>& arr, int left, int right) //array, index inizio, index fine
{
    int i = left, j = right;
    int pivot = arr[left];
    while (i < j)
	{
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i < j)
		{
            std::swap(arr[i], arr[j]);
            i++; j--;
        }
    }
    if (left < j)
		quicksort(arr, left, j);
    if (i < right)
		quicksort(arr, i, right);
}
```
