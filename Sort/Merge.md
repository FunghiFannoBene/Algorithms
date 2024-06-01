# Merge

**Riordinare con il divide and conquer**

## Fase ricorsiva di divisione  

Divide in 2 parti uguali l'array e lo ripassa alla funzione stessa, ripetendola fino ad avere 1 elemento unico che equivale  
per nozione **un numero singolo è sempre ordinato**  

>[!NOTE]
>if left < right prima o poi raggiunge la condizione di uguaglianza seguendo la formula scritta 
>successivamente, il che indica che è arrivato al singolo elemento
>Trovare sempre la posizione MID degli elementi passati tramite la formula: mid = left + (right - left) / 2;
>Può essere confusionario ma mid è l'elemento di mezzo che viene passato come fine del primo merge, punto di arrivo e  
>mid +1 è passato per la seconda chiamata del mergeSort che indica l'elemento successivo al mid.
```c
	// Ordina prima e seconda metà
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);

	// Unisci le metà ordinate
	merge(arr, left, mid, right);
```

## Fase di ricongiuzione

La ricongiunzione prende le due parti "divise"(data la posizione) appena create e le fonde, per fonderle  
crea due memorie temporanee (almeno in C) e li ordina valutando:  

```c
if (L[i] <= R[j])
{
	arr[k] = L[i];
	i++;
}
else
{
	arr[k] = R[j];
	j++;
}
```

In loop finchè una delle 2 memorie arriva alla fine.
In seguito copia anche gli elementi rimanenti della memoria non arrivata alla fine.

Questo procedimento ricongiunge sapendo che gli elementi sono ordinati e inserendoli in O(n) a ogni colpo di ricongiunzione.

```c

#include <stdio.h>
#include <stdlib.h>

// Funzione per unire due sotto-array
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Creazione di array temporanei
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // Copia dei dati negli array temporanei
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Unisci gli array temporanei
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copia gli elementi rimanenti di L[], se ci sono
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copia gli elementi rimanenti di R[], se ci sono
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Libera la memoria temporanea
    free(L);
    free(R);
}

// Funzione di ordinamento merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Ordina prima e seconda metà
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Unisci le metà ordinate
        merge(arr, left, mid, right);
    }
}

```