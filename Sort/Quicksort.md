# Quicksort

**Rioridamento di tipo divide and conquer**

>[!NOTE]
>Il pivot è un elemento dell'array a scelta!! Si può scegliere l'inizio, mezzo o anche la fine

## Fase 1.

Selezione di pivot: il pivot può essere qualsiasi numero, è un numero intermezzo che andrà a dividere i più piccoli
  di pivot stesso e i più grandi di pivot.
  il passaggio dei parametri include l'array, il punto d'inizio e il punto di fine come **INDEX** 
  (Non size ma size -1)
  Di questi selezioniamo 
  il punto d'inizio come iteratore I in questo caso,
  Iteratore J come punto di fine.

## Fase 2.

Loop principale:  
```c++
while (i <= j)
```
Contiene 2 loop, di cui 1 muove dall'inizio fino a quando non trova un numero inferiore al pivot.    
Il secondo loop fa dalla finee verso l'inizio e si ferma quando un numero è maggiore al pivot.  
In questo caso dal primo loop troviamo un numero **più piccolo del pivot e l'altro maggiore.**  

```c++
while (arr[i] < pivot) i++;  
while (arr[j] > pivot) j--;  
```

## Fase 3.
Valutazione dei 2 numeri trovati, l'iteratore I deve essere inferiore o uguale a J  
In questo modo possiamo swapparli sapendo di non essere finiti nell'altra metà gestita da iteratori diversi  
I aumenta e J scende.

```c++
if(i <= j)
{
	std::swap(arr[i], arr[j]);
	i++;
	j--;
}
```

## Fase 4.
Ora chiamiamo 2 if, una valuta "l'inizio o left" con j, se l'inizio che era 0 (almeno inizialmente) è uguale a j  
Possiamo dire che j ha finito il suo lavoro completamente e quindi quicksort non viene richiamato,  
Altrimenti si ripassa dinuovo  
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
