# Radix Sort

**Radix Sort ordina numeri per posizione delle cifre, iniziando dalla cifra meno significativa (unità) alla più significativa (decine, centinaia, ecc.). Utilizza un ordinamento stabile come il Counting Sort per ogni posizione, garantendo un ordinamento corretto ed efficiente.**

## Counting Sort: Spiegazione Semplice
Counting Sort è un algoritmo di ordinamento che ordina gli elementi contando il numero di occorrenze di ciascun valore unico nell'array. È particolarmente efficace quando l'intervallo dei valori è limitato.

## Come Funziona
Trova il valore massimo nell'array per determinare l'intervallo.
Crea un array di conteggio con lunghezza pari al valore massimo + 1.
Conta le occorrenze di ciascun valore nell'array di input e memorizza queste conte in corrispondenza dell'indice del valore nell'array di conteggio.
Calcola le posizioni cumulative nell'array di conteggio.
Costruisci l'array ordinato scorrendo l'array di input in ordine inverso e posizionando ciascun elemento nella sua posizione corretta basata sull'array di conteggio.

## Counting sort

```c++
#include <iostream>
#include <vector>
using namespace std;

void countingSort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end()); //valore massimo
    vector<int> count(max + 1, 0); //crea un vettore inizializzato a 0, di dimensioni max+1;

    // Conta le occorrenze usando hashing, posizione num
    for (int num : arr)
        count[num]++;

    // Conte cumulative
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Costruisci l'array ordinato
    vector<int> output(arr.size());
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copia l'output nell'array originale
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}
```